#ifndef CRAB_H
#define CRAB_H

#include "GameObject.h"
#include "Model.h"
#include "Vector.h"

class Crab: public GameObject {
    public:
        Crab(Model& model);
        Crab(Model& model, Structs::Vector pos);
};

#endif