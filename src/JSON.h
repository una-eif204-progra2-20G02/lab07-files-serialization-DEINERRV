#ifndef MY_PROJECT_NAME_JSON_H
#define MY_PROJECT_NAME_JSON_H
#include "ISave.h"

class JSON: public ISave {
public:
    void save(Persona *) override;
};


#endif //MY_PROJECT_NAME_JSON_H
