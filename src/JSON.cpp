#include "JSON.h"
#include <fstream>
#include "../lib/nlohmann/json.hpp"

using namespace std;
using json=nlohmann::json;

void to_json(json &_json, const Persona &_person) {
    _json = json{
            {"id",   _person.getId()},
            {"nombre", _person.getNombre()},
            {"edad", _person.getEdad()},
    };
}

void from_json(const json &_json, Persona &_person) {
    _person.setId(_json.at("id").get<int>());
    _person.setNombre(_json.at("nombre").get<std::string>());
    _person.setEdad(_json.at("edad").get<int>());
}



void JSON::save(Persona *persona) {
    json Serializacion;
    Serializacion["nombre"]=persona->getNombre();
    Serializacion["edad"]=persona->getEdad();
    Serializacion["id"]=persona->getId();

    string personaSerializada=Serializacion.dump(4);

    ofstream archivo;

    try { archivo.open("ArchivoJSON.json", ios::binary); }

    catch (ifstream::failure a) {
        cout << "no se pudo abrir el archivo";
        exit(1);
    }

    archivo << personaSerializada << '\n';

    archivo.close();
}



void JSON::save(std::vector<Persona> personas) {
    ofstream archivo;

    try { archivo.open("ArchivoJSON.json", ios::binary); }

    catch (ifstream::failure a) {
        cout << "no se pudo abrir el archivo";
        exit(1);
    }

    json JsonData(personas);
    string Serializacion=JsonData.dump();

    archivo << Serializacion << '\n';

    archivo.close();
}



std::vector<Persona> JSON::read() {

    ifstream archivo;

    try { archivo.open("ArchivoJSON.json", ios::binary); }


    catch (ifstream::failure a) {
        cout << "no se pudo abrir el archivo";
        exit(1);
    }


    string datos;
    archivo>>datos;

    json j=json::parse(datos);

    archivo.close();

    vector<Persona> x = j;
    return x;
}