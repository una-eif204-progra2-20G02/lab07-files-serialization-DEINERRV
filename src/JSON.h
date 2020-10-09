#ifndef MY_PROJECT_NAME_JSON_H
#define MY_PROJECT_NAME_JSON_H
#include "ISave.h"
#include "IRead.h"

class JSON: public ISave,public IRead{
public:
    void save(Persona *) override;
    void save(std::vector<Persona>)override;
    std::vector<Persona> read() override;
};


#endif //MY_PROJECT_NAME_JSON_H
