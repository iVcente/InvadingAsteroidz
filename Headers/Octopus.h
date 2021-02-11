#ifndef OCTOPUS_H
#define OCTOPUS_H

#include "GameObject.h"
#include "Model.h"
#include "Octopus.h"
#include "Vector.h"

class Octopus: public GameObject {
    public:
        Octopus(Model& model);
        Octopus(Model& model, Structs::Vector pos);
};

#endif