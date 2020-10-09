#include "JSON.h"
#include <fstream>
#include "../lib/nlohmann/json.hpp"

using namespace std;
using json=nlohmann::json;

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

    vector<json> Serializacion;

    for (int i=0;i<personas.size();i++){

        json PersonaJSON;
        PersonaJSON["nombre"]=personas[i].getNombre();
        PersonaJSON["edad"]=personas[i].getEdad();
        PersonaJSON["id"]=personas[i].getId();

        Serializacion.push_back(PersonaJSON);
    }

    archivo << Serializacion << '\n';

    archivo.close();
}


void from_json(const json& j, Persona& sb) {
    sb.setNombre(j.at("nombre"));
    sb.setEdad(j.at("edad"));
    sb.setId(j.at("id"));
}


void from_json(const json& j, vector<Persona>& s) {
    const json& sj = j;
    s.resize(sj.size());
    std::copy(sj.begin(), sj.end(), s.begin());
}

std::vector<Persona> JSON::read() {

    ifstream archivo;

    try { archivo.open("ArchivoJSON.json", ios::binary); }

    catch (ifstream::failure a) {
        cout << "no se pudo abrir el archivo";
        exit(1);
    }

    json j;
    archivo>>j;

    archivo.close();

    vector<Persona> x = j;
    return x;
}