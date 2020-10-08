#ifndef MY_PROJECT_NAME_BINARY_H
#define MY_PROJECT_NAME_BINARY_H
#include "ISave.h"

class Binary: public ISave{
public:
    void save(Persona *) override;
    void save(std::vector<Persona>)override;
};


#endif //MY_PROJECT_NAME_BINARY_H
