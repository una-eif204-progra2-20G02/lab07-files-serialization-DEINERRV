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

    manager.savePersona(binario,personas);
    manager.savePersona(json,personas);


    cout<<"BINARIO"<<endl;

    vector<Persona> aux;

    aux=manager.readPersona(binario);

    for(Persona auxPersona : aux){
        cout<<auxPersona.toString()<<endl;
    }


    cout<<"\n\n\nJSON"<<endl;

    vector<Persona> aux2;

    aux2=manager.readPersona(json);

    for(Persona auxPersona : aux2){
        cout<<auxPersona.toString()<<endl;
    }

    return 0;
}
