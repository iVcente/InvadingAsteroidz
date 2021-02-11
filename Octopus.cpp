#include "Headers/Model.h"
#include "Headers/Octopus.h"
#include "Headers/Vector.h"

Octopus::Octopus(Model& model): GameObject(model)
{ }

Octopus::Octopus(Model& model, Structs::Vector pos): GameObject(model, pos)
{ }