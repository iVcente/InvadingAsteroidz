#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

namespace Structs {
    struct Vector {
        float x, y;

        Vector(): x(0.0f), y(0.0f) { }
        Vector(float x, float y): x(x), y(y) { }

        void print() {
            std::cout << "(" << x << ", " << y << ")\n";
        }

        Vector operator+(const Vector& v) {
            return Vector(x + v.x, y + v.y);
        }

        Vector operator-(const Vector& v) {
            return Vector(x - v.x, y - v.y);
        }

        Vector operator*(const float k) {
            return Vector(x * k, y * k);
        }
    };
}

#endif