#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "AABB.h"
#include "Model.h"
#include "Vector.h"

class GameObject {
    public:
        Structs::Vector getDimensions() const;
        Structs::Vector getPosition() const;
        virtual void draw() const;
        virtual void drawHitBox() const;
        virtual void moveForward();
        virtual void moveBackward();
        virtual void rotateLeft();
        virtual void rotateRight();
        void printAABB() const;

    protected:
        GameObject(Model model, float speed);
        GameObject(Model model, Structs::Vector pos, float speed);
        GameObject(Model model, float speed, Structs::Vector direction);
        const float scale = 0.5f;
        const Model model;
        float currentRotation = 0.0f;
        float speed;
        Structs::Vector position;
        Structs::Vector direction;
        Structs::AABB hitBox;

    private:
        Structs::AABB initHitBox();
};

#endif