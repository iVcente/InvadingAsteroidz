#include "Headers/Crab.h"
#include "Headers/Model.h"
#include "Headers/Vector.h"

Crab::Crab(Model& model): GameObject(model)
{ }

Crab::Crab(Model& model, Structs::Vector pos): GameObject(model, pos)
{ }