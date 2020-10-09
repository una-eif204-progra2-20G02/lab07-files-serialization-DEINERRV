#include "Persona.h"
#include <string.h>
#include <sstream>

Persona::Persona() {}

Persona::Persona(std::string _name, int _edad, int _id) {
    strcpy(nombre,_name.c_str());
    edad=_edad;
    id=_id;
}

int Persona::getEdad() const {
    return edad;
}

void Persona::setEdad(int edad) {
    Persona::edad = edad;
}

int Persona::getId() const {
    return id;
}

void Persona::setId(int id) {
    Persona::id = id;
}

std::string Persona::getNombre() const {
    return nombre;
}

void Persona::setNombre(std::string nom) {
    strcpy(nombre,nom.c_str());
}

std::string Persona::toString() {
    std::stringstream s;

    s<<"nombre: "<<nombre<<std::endl;
    s<<"edad: "<<edad<<std::endl;
    s<<"id: "<<id<<std::endl;

    return s.str();
}