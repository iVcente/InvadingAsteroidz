#ifndef ANT_H
#define ANT_H

#include "GameObject.h"
#include "Model.h"
#include "Vector.h"

class Ant: public GameObject {
    public:
        Ant(Model& model);
        Ant(Model& model, Structs::Vector pos);
};

#endif