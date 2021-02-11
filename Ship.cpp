#include "Headers/Physics.h"
#include "Headers/Ship.h"
#include "Headers/Vector.h"

using namespace Structs;

Ship::Ship(): GameObject(), direction(0, 1)
{ }

Ship::Ship(Model& model): GameObject(model), direction(0, 1)
{ }

void Ship::setModel(Model& m) {
    model = m;
}

void Ship::moveForward() {
    position = position + (direction * speed);
}

void Ship::moveBackward() {
    position = position - (direction * speed);
}

void Ship::rotateLeft() {
    float rotationAngleRadians = degreesToRadian(rotationAngle);
    float newX = (cosf(rotationAngleRadians) * direction.x) - (sinf(rotationAngleRadians) * direction.y);
    float newY = (sinf(rotationAngleRadians) * direction.x) + (cosf(rotationAngleRadians) * direction.y);

    direction = Vector(newX, newY);

    currentRotation += rotationAngle;
}

void Ship::rotateRight() {
    float rotationAngleRadians = degreesToRadian(rotationAngle);
    float newX = (cosf(rotationAngleRadians) * direction.x) + (sinf(rotationAngleRadians) * direction.y);
    float newY = (-sinf(rotationAngleRadians) * direction.x) + (cosf(rotationAngleRadians) * direction.y);

    direction = Vector(newX, newY);

    currentRotation -= rotationAngle;
}