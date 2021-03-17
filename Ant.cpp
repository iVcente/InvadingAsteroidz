#include "Headers/Ant.h"
#include "Headers/GameObject.h"
#include "Headers/Model.h"
#include "Headers/Vector.h"

using namespace Structs;

Ant::Ant(Model& model, Vector pos, float speed): GameObject(model, pos, speed)
{ }