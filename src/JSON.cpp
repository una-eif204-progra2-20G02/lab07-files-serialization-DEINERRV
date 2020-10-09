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

    json Serializacion;

    for (int i=0;i<personas.size();i++){
        Serializacion["Personas"] += {personas[i].getNombre(),personas[i].getEdad(),personas[i].getId()};
    }

    string personaSerializada=Serializacion.dump(4);
    archivo << personaSerializada << '\n';

    archivo.close();
}