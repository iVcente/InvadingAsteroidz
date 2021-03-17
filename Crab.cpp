#include "Headers/Crab.h"
#include "Headers/GameObject.h"
#include "Headers/Model.h"
#include "Headers/Vector.h"

using namespace Structs;

Crab::Crab(Model& model, Vector pos, float speed): GameObject(model, pos, speed)
{ }