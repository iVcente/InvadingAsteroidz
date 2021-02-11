#ifndef SHIP_H
#define SHIP_H

#include "AABB.h"
#include "GameObject.h"
#include "Model.h"
#include "Vector.h"

class Ship: public GameObject {
    private:
        Structs::Vector direction;
        float speed = 6.0f;
        float rotationAngle = 10.0f;
        // float currentRotation = 0.0f;

    public:
        Ship();
        Ship(Model& model);
        void setModel(Model& model);
        void moveForward();
        void moveBackward();
        void rotateLeft();
        void rotateRight();
};

#endif