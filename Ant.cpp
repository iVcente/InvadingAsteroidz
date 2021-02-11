#include "Headers/Ant.h"
#include "Headers/Model.h"
#include "Headers/Vector.h"

Ant::Ant(Model& model): GameObject(model)
{ }

Ant::Ant(Model& model, Structs::Vector pos): GameObject(model, pos)
{ }