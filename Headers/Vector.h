#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

namespace Structs {
    struct Vector {
        float x, y;

        Vector(): x(0.0f), y(0.0f) 
        { }
        Vector(float x, float y): x(x), y(y) 
        { }

        void print() const {
            std::cout << "(" << x << ", " << y << ")\n";
        }

        Vector operator+(const Vector& v) {
            Vector vector = Vector();
            vector.x = x + v.x;
            vector.y = y + v.y;

            return vector;
        }

        Vector operator-(const Vector& v) {
            Vector vector = Vector();
            vector.x = x - v.x;
            vector.y = y - v.y;

            return vector;
        }

        Vector operator*(const float k) {
            Vector vector = Vector();
            vector.x = x * k;
            vector.y = y * k;

            return vector;
        }

        // Vector& operator+(const Vector& v) {
        //     x = x + v.x;
        //     y = y + v.y;

        //     return *this;
        // }

        // Vector& operator-(const Vector& v) {
        //     x = x - v.x;
        //     y = y - v.y;

        //     return *this;
        // }

        // Vector& operator*(const float k) {
        //     x = x * k;
        //     y = y * k;

        //     return *this;
        // }
    };
}

#endif