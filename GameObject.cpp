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

Vector GameObject::getDimensions() const {
    return model.dimensions;
}

Vector GameObject::getPosition() const {
    return position;
}

AABB GameObject::getHitBox() const {
    return hitBox;
}

GameObject::GameObject(Model model, float speed): 
    model(model), position(Vector(0.0f, 0.0f)), speed(speed), hitBox(initHitBox())
{ }

GameObject::GameObject(Model model, Vector pos, float speed): 
    model(model), position(pos), speed(speed), hitBox(initHitBox())
{ }

GameObject::GameObject(Model model, float speed, Vector direction): 
    model(model), speed(speed), hitBox(initHitBox()), direction(direction)
{ }

void GameObject::draw() const {
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

void GameObject::drawHitBox() const {
    glColor3ub(255, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(hitBox.center.x - hitBox.halfSize, position.y + hitBox.halfSize);
        glVertex2f(hitBox.center.x + hitBox.halfSize, hitBox.center.y + hitBox.halfSize);
        glVertex2f(hitBox.center.x + hitBox.halfSize, hitBox.center.y - hitBox.halfSize);
        glVertex2f(hitBox.center.x - hitBox.halfSize, hitBox.center.y - hitBox.halfSize);
    glEnd();
}

void GameObject::printAABB() const {
    hitBox.print();
}

AABB GameObject::initHitBox() {
    float m = getDimensions().y * scale;
    float n = getDimensions().x * scale;

    return AABB(position, m >= n ? (m/2) : (n/2));
}

void GameObject::gotHit() { }
bool GameObject::isDead() const { return true; }
void GameObject::moveForward() { }
void GameObject::moveBackward() { }
void GameObject::rotateLeft() { }
void GameObject::rotateRight() { }