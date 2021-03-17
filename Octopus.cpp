#include "Headers/GameObject.h"
#include "Headers/Model.h"
#include "Headers/Octopus.h"
#include "Headers/Vector.h"

using namespace Structs;

Octopus::Octopus(Model& model, Vector pos, float speed): GameObject(model, pos, speed)
{ }