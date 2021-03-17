#include "Headers/GameObject.h"
#include "Headers/Model.h"
#include "Headers/Squid.h"
#include "Headers/Vector.h"

using namespace Structs;

Squid::Squid(Model& model, Vector pos, float speed): GameObject(model, pos, speed)
{ }