#include "PersonaManager.h"
#include "Binary.h"
#include "JSON.h"

int main(){
    Persona persona1("Juan",1000,1);

    PersonaManager manager;
    Binary* binario=new Binary;
    JSON* json=new JSON;

    manager.savePersona(json,&persona1);

    return 0;
}
