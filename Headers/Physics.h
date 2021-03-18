#ifndef PHYSICS_H
#define PHYSICS_H

#include "AABB.h"
#include "Vector.h"

#include <cmath>

const float MAX_X = +100.0f;
const float MAX_Y = +100.0f;
const float MIN_X = -100.0f;
const float MIN_Y = -100.0f;

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

    // if ((top >= -MAX_DEPTH) && (bottom <= -MIN_DEPTH) && (left >= MIN_WIDTH) && (right <= (MAX_WIDTH/2 - 0.5f)))
    //     return true;

    // return false;

    /*
    if ((top <= -MAX_DEPTH) || (bottom >= -MIN_DEPTH) || (left <= MIN_WIDTH) || (right >= (MAX_WIDTH/2 - 0.5f)))
        return false;

    return true;
    */
}

#endif