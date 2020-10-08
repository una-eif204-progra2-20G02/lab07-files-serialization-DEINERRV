#ifndef MY_PROJECT_NAME_PERSONAMANAGER_H
#define MY_PROJECT_NAME_PERSONAMANAGER_H
#include "ISave.h"

class PersonaManager {
public:
   void savePersona(ISave*,Persona*);
   void savePersona(ISave*,std::vector<Persona>);
};


#endif //MY_PROJECT_NAME_PERSONAMANAGER_H
