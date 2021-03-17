#ifndef OCTOPUS_H
#define OCTOPUS_H

#include "GameObject.h"
#include "Model.h"
#include "Vector.h"

class Octopus: public GameObject {
    public:
        Octopus(Model& model, Structs::Vector pos, float speed);
};

#endif