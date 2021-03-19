#ifndef AABB_H
#define AABB_H

#include "Vector.h"

#include <iostream>

namespace Structs {
    struct AABB {
        Vector center;
        float halfSize;

        AABB(): center(Vector(0.0f, 0.0f)), halfSize(0.0f) 
        { }
        AABB(Vector center, float halfSize): center(center), halfSize(halfSize)
        { }

        void print() const {
            std::cout << "Half size = " << halfSize  << "\n";
        }
    };
}

#endif