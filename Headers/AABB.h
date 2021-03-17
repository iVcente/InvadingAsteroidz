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
        // AABB(Vector a, Vector b, Vector c, Vector d): direction(Vector(0.0f, 1.0f)), position(Vector(0.0f, 0.0f)),
        //                                               a(a), b(b), c(c), d(d)
        // { }

        void print() const {
            std::cout << "Half size = " << halfSize  << "\n";
        }

        // AABB operator+(const AABB& k) {
        //     AABB aabb = AABB();
        //     aabb.a = Vector(a.x + k.a.x, a.y + k.a.y);
        //     aabb.b = Vector(b.x + k.b.x, b.y + k.b.y);
        //     aabb.c = Vector(c.x + k.c.x, c.y + k.c.y);
        //     aabb.d = Vector(d.x + k.d.x, d.y + k.d.y);

        //     return aabb;
        // }

        // AABB operator-(const AABB& k) {
        //     AABB aabb = AABB();
        //     aabb.a = Vector(a.x - k.a.x, a.y - k.a.y);
        //     aabb.b = Vector(b.x - k.b.x, b.y - k.b.y);
        //     aabb.c = Vector(c.x - k.c.x, c.y - k.c.y);
        //     aabb.d = Vector(d.x - k.d.x, d.y - k.d.y);

        //     return aabb;
        // }

        // AABB operator*(const float k) {
        //     AABB aabb = AABB();
        //     aabb.a = Vector(a.x * k, a.y * k);
        //     aabb.b = Vector(b.x * k, b.y * k);
        //     aabb.c = Vector(c.x * k, c.y * k);
        //     aabb.d = Vector(d.x * k, d.y * k);

        //     return aabb;
        // }

        // AABB& operator+(const AABB& k) {
        //     a = Vector(a.x + k.a.x, a.y + k.a.y);
        //     b = Vector(b.x + k.b.x, b.y + k.b.y);
        //     c = Vector(c.x + k.c.x, c.y + k.c.y);
        //     d = Vector(d.x + k.d.x, d.y + k.d.y);

        //     return *this;
        // }

        // AABB& operator-(const AABB& k) {
        //     a = Vector(a.x - k.a.x, a.y - k.a.y);
        //     b = Vector(b.x - k.b.x, b.y - k.b.y);
        //     c = Vector(c.x - k.c.x, c.y - k.c.y);
        //     d = Vector(d.x - k.d.x, d.y - k.d.y);

        //     return *this;
        // }

        // AABB& operator*(const float k) {
        //     a = Vector(a.x * k, a.y * k);
        //     b = Vector(b.x * k, b.y * k);
        //     c = Vector(c.x * k, c.y * k);
        //     d = Vector(d.x * k, d.y * k);

        //     return *this;
        // }
    };
}

#endif