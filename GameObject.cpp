#ifdef WIN32
#include <windows.h>
#include <glut.h>
#else
#include <sys/time.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#endif

#ifdef __linux__
#include <glut.h>
#endif

#include "Headers/GameObject.h"
#include "Headers/Model.h"
#include "Headers/Square.h"

#include <iostream>

using namespace Structs;

GameObject::GameObject(): position(0.0f, 0.0f)
{ }

GameObject::GameObject(Model& model): model(model), position(0.0f, 0.0f), boundingBox(initAABB())
{ }

GameObject::GameObject(Model& model, Vector pos): model(model), position(pos), boundingBox(initAABB())
{ }

void GameObject::drawAABB() {
    glColor3ub(255, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(boundingBox.a.x, boundingBox.a.y);
        glVertex2f(boundingBox.b.x, boundingBox.b.y);
        glVertex2f(boundingBox.c.x, boundingBox.c.y);
        glVertex2f(boundingBox.d.x, boundingBox.d.y);
    glEnd();
}

void GameObject::draw() {
    Vector dimensions = model.dimensions;
    int rows = model.pixels.getNumRows();
    int columns = model.pixels.getNumColumns();
    int x = 0;
    int y = 0;

    glPushMatrix();
    glTranslatef(position.x, position.y, 0.0f);
    glRotatef(currentRotation, 0.0f, 0.0f, 1.0f);
        glPushMatrix();
        glScalef(scale, scale, 0.0f);
        glTranslatef(-(columns/2), rows/2, 0.0f);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    int colorID = model.pixels.at(i, j);
                    if (colorID == 0) {
                        x++;
                        continue;
                    }
                    Color color = model.colors.at(colorID);
                    glPushMatrix();
                    glColor3ub(color.r, color.g, color.b);
                    glTranslatef(x, y, 0.0f);
                    drawSquare();                    
                    glPopMatrix();
                    x++;
                }
                x = 0;
                y--;
            }
        glPopMatrix();
    glPopMatrix();
}

Vector GameObject::getPosition() {
    return position;
}

Vector GameObject::getDimensions() {
    return model.dimensions;
}

AABB GameObject::initAABB() {
    float m = getDimensions().x * 0.7;
    float n = getDimensions().y * scale;

    Vector a = Vector(position.x - (m / 2), position.y + (n / 2));
    Vector b = Vector(position.x + (m / 2), position.y + (n / 2));
    Vector c = Vector(position.x + (m / 2), position.y - (n / 2));
    Vector d = Vector(position.x - (m / 2), position.y - (n / 2));

    return AABB(a, b, c, d);
}

void GameObject::printAABB() {
    boundingBox.print();
}