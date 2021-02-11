#ifndef SQUID_H
#define SQUID_H

#include "GameObject.h"
#include "Model.h"
#include "Vector.h"

class Squid: public GameObject {
    public:
        Squid(Model& model);
        Squid(Model& model, Structs::Vector pos);
};

#endif