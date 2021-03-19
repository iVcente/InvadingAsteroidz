#ifndef SHIP_H
#define SHIP_H

#include "AABB.h"
#include "GameObject.h"
#include "Model.h"
#include "Vector.h"

class Ship: public GameObject {
    public:
        Ship(Model model, float speed);
        void gotHit() override;
        bool isDead() const override;
        void moveForward() override;
        void moveBackward() override;
        void rotateLeft() override;
        void rotateRight() override;
    
    private:
        int lives = 3;
        float rotationAngle = 17.5f;
};

#endif