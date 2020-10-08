#ifndef MY_PROJECT_NAME_ISAVE_H
#define MY_PROJECT_NAME_ISAVE_H
#include "Persona.h"
#include<vector>


class ISave {
public:
    virtual void save(Persona*)=0;
    virtual void save(std::vector<Persona>)=0;

    ~ISave();
};


#endif //MY_PROJECT_NAME_ISAVE_H
