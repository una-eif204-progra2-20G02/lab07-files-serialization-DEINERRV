#ifndef MY_PROJECT_NAME_IREAD_H
#define MY_PROJECT_NAME_IREAD_H
#include<vector>
#include"Persona.h"


class IRead {
public:
    virtual std::vector<Persona> read()=0;
    ~IRead();
};


#endif //MY_PROJECT_NAME_IREAD_H
