#include "PersonaManager.h"
#include "Binary.h"
#include "JSON.h"

using namespace std;

int main(){
    Persona persona1("Juan",10,1);
    Persona persona2("Juana",20,2);
    Persona persona3("Mario",30,3);
    Persona persona4("Maria",40,4);

    vector<Persona> personas;
    personas.push_back(persona1);
    personas.push_back(persona2);
    personas.push_back(persona3);
    personas.push_back(persona4);


    PersonaManager manager;
    Binary* binario=new Binary;
    JSON* json=new JSON;

    manager.savePersona(json,personas);

    return 0;
}
