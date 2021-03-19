#include "Headers/Physics.h"
#include "Headers/Ship.h"
#include "Headers/Vector.h"

#include <iostream>

using namespace Structs;

Ship::Ship(Model model, float speed): GameObject(model, speed, Vector(0.0f, 1.0f))
{ }

void Ship::gotHit() {
    lives--;
    std::cout << "You have been hit!\n";
}

bool Ship::isDead() const {
    return (lives <= 0);
}

void Ship::moveForward() {
    Vector newPosition = position + (direction * speed);
    if (insideBoundaries(hitBox, newPosition)) {
        position = newPosition;
        hitBox.center = position;
    }
}

void Ship::moveBackward() {
    Vector newPosition = position - (direction * speed);
    if (insideBoundaries(hitBox, newPosition)) {
        position = newPosition;
        hitBox.center = position;
    }
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