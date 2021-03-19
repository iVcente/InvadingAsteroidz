#ifndef PHYSICS_H
#define PHYSICS_H

#include "AABB.h"
#include "Vector.h"

#include <cmath>

const float MAX_X = +100.0f;
const float MAX_Y = +100.0f;
const float MIN_X = -100.0f;
const float MIN_Y = -100.0f;

inline bool checkCollision(Structs::AABB b1, Structs::AABB b2 ) {
    if (abs(b1.center.x - b2.center.x) > (b1.halfSize + b2.halfSize))
        return false;
    if (abs(b1.center.y - b2.center.y) > (b1.halfSize + b2.halfSize))
        return false;

    return true;
}

inline float degreesToRadian(float angleInDegrees) {
    return (angleInDegrees * M_PI) / 180.0;
}

inline bool insideBoundaries(Structs::AABB hitBox, Structs::Vector newPosition) {
    float top = newPosition.y + hitBox.halfSize;
    float bottom = newPosition.y - hitBox.halfSize;
    float left = newPosition.x - hitBox.halfSize;
    float right = newPosition.x + hitBox.halfSize;

    if ((top < MAX_Y) && (bottom > MIN_Y) && (left > MIN_X) && (right < MAX_X))
        return true;

    return false;
}

#endif