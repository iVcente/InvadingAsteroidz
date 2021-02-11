#ifndef AABB_H
#define AABB_H

#include "Vector.h"

#include <iostream>

namespace Structs {
    struct AABB {
        Vector a, b, c, d;

        AABB(): a(Vector(0.0f, 0.0f)), b(Vector(0.0f, 0.0f)), c(Vector(0.0f, 0.0f)), d(Vector(0.0f, 0.0f)) { }
        AABB(Vector a, Vector b, Vector c, Vector d): a(a), b(b), c(c), d(d) { }

        void print() {
            std::cout << "A = (" << a.x << ", " << a.y  << ")\n";
            std::cout << "B = (" << b.x << ", " << b.y  << ")\n";
            std::cout << "C = (" << c.x << ", " << c.y  << ")\n";
            std::cout << "D = (" << d.x << ", " << d.y  << ")\n";
        }

        AABB operator+(const AABB& k) {
            AABB aabb = AABB();
            aabb.a = Vector(a.x + k.a.x, a.y + k.a.y);
            aabb.b = Vector(b.x + k.b.x, b.y + k.b.y);
            aabb.c = Vector(c.x + k.c.x, c.y + k.c.y);
            aabb.d = Vector(d.x + k.d.x, d.y + k.d.y);

            return aabb;
        }

        AABB operator-(const AABB& k) {
            AABB aabb = AABB();
            aabb.a = Vector(a.x - k.a.x, a.y - k.a.y);
            aabb.b = Vector(b.x - k.b.x, b.y - k.b.y);
            aabb.c = Vector(c.x - k.c.x, c.y - k.c.y);
            aabb.d = Vector(d.x - k.d.x, d.y - k.d.y);

            return aabb;
        }

        AABB operator*(const float k) {
            AABB aabb = AABB();
            aabb.a = Vector(a.x * k, a.y * k);
            aabb.b = Vector(b.x * k, b.y * k);
            aabb.c = Vector(c.x * k, c.y * k);
            aabb.d = Vector(d.x * k, d.y * k);

            return aabb;
        }
    };
}

#endif