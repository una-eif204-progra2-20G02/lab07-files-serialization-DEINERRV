#ifndef MY_PROJECT_NAME_PERSONA_H
#define MY_PROJECT_NAME_PERSONA_H
#include <iostream>

class Persona {
private:
    int edad;
    int id;
    char nombre[50];
public:
    Persona();
    Persona(std::string ,int, int);

    int getEdad() const;

    void setEdad(int edad);

    int getId() const;

    void setId(int id);

    std::string getNombre() const;

    std::string toString();
};


#endif //MY_PROJECT_NAME_PERSONA_H
