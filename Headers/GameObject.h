#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "AABB.h"
#include "Model.h"
#include "Vector.h"

class GameObject {
    protected:
        Structs::Vector position;
        Structs::Vector direction;
        Structs::AABB boundingBox;
        float speed;
        float scale = 0.5f;
        float currentRotation = 0.0f;
        Model model;
        GameObject();
        GameObject(Model& model);
        GameObject(Model& model, Structs::Vector position);

    public:
        void draw();
        void drawAABB();
        Structs::AABB initAABB();
        Structs::Vector getDimensions();
        Structs::Vector getPosition();
        void printAABB();
};

#endif