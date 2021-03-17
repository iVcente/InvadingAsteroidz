#ifndef SQUID_H
#define SQUID_H

#include "GameObject.h"
#include "Model.h"
#include "Vector.h"

class Squid: public GameObject {
    public:
        Squid(Model& model, Structs::Vector pos, float speed);
};

#endif