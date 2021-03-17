#ifndef AABB_H
#define AABB_H

#include "Vector.h"

#include <iostream>

namespace Structs {
    struct AABB {
        Vector position;
        float halfSize;

        AABB(): position(Vector(0.0f, 0.0f)), halfSize(0.0f) 
        { }
        AABB(Vector position, float halfSize): position(position), halfSize(halfSize)
        { }

        void print() const {
            std::cout << "Half size = " << halfSize  << "\n";
        }
    };
}

#endif