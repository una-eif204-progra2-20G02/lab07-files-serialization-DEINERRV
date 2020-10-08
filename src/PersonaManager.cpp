#include "PersonaManager.h"

void PersonaManager::savePersona(ISave *metodo, Persona *persona) {
    metodo->save(persona);
}

void PersonaManager::savePersona(ISave *metodo, std::vector<Persona> personas) {
    metodo->save(personas);
}