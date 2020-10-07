#include "PersonaManager.h"

void PersonaManager::savePersona(ISave *metodo, Persona *persona) {
    metodo->save(persona);
}