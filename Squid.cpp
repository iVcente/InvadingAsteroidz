#include "Headers/Model.h"
#include "Headers/Squid.h"
#include "Headers/Vector.h"

Squid::Squid(Model& model): GameObject(model)
{ }

Squid::Squid(Model& model, Structs::Vector pos): GameObject(model, pos)
{ }