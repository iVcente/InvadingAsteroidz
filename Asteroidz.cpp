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

#include <fstream>
#include <iostream>
#include <map>
#include <vector>

#include "Headers/Ant.h"
#include "Headers/Crab.h"
#include "Headers/GameObject.h"
#include "Headers/Matrix.h"
#include "Headers/Model.h"
#include "Headers/Octopus.h"
#include "Headers/Ship.h"
#include "Headers/Square.h"
#include "Headers/Squid.h"
#include "Headers/Vector.h"

using namespace Structs;

std::vector<Vector> backgroundStars;
std::map<std::string, Model> models;
Ship player = Ship();
std::vector<GameObject> gameObjs;

void loadBackgroundStars(std::string filePath) {
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "ERROR! Could not find: " << filePath << "\n";
        exit(EXIT_FAILURE);
    }

    float x = 0.0f;
    float y = 0.0f;

    while (file >> x >> y) {
        Vector v (x, y);
        backgroundStars.push_back(v);
    }
}

void drawBackgroundStars() {
    glPointSize(1.5f);
    //glColor3ub(150, 0, 100); // Pink
    glColor3ub(119, 28, 217); // Purple
    //glColor3ub(230, 208, 16); // Yellow
    glBegin(GL_POINTS);
        for (auto& star : backgroundStars)
            glVertex2f(star.x, star.y);
    glEnd();
}

void loadModels() {
    loadModel("Assets/Ship.txt", "Ship", models);
    loadModel("Assets/Ant.txt", "Ant", models);
    loadModel("Assets/Crab.txt", "Crab", models);
    loadModel("Assets/Octopus.txt", "Octopus", models);
    loadModel("Assets/Squid.txt", "Squid", models);
}

void loadGameObjects() {
    player.setModel(models.at("Ship"));
    player.initAABB();
    player.printAABB();

    int x = -90;
    int y = 90;

    int nAnts = 15;
    for (int i = 0; i < nAnts; i++) {
        if (x > 90) {
            x = -90;
            y -= 15;
        }
        
        Vector pos(x, y);
        Ant ant = Ant(models.at("Ant"), pos);
        gameObjs.push_back(ant);
        x += 15;
    }

    int nCrabs = 15;
    for (int i = 0; i < nCrabs; i++) {
        if (x > 90) {
            x = -90;
            y -= 15;
        }
        Vector pos(x, y);
        Crab crab = Crab(models.at("Crab"), pos);
        gameObjs.push_back(crab);
        x += 15;
    }

    int nOctopus = 15;
    for (int i = 0; i < nOctopus; i++) {
        if (x > 90) {
            x = -90;
            y -= 15;
        }
        Vector pos(x, y);
        Octopus octopus = Octopus(models.at("Octopus"), pos);
        gameObjs.push_back(octopus);
        x += 15;
    }

    int nSquid = 15;
    for (int i = 0; i < nSquid; i++) {
        if (x > 90) {
            x = -90;
            y -= 15;
        }
        Vector pos(x, y);
        Squid squid = Squid(models.at("Squid"), pos);
        gameObjs.push_back(squid);
        x += 15;
    }
}

void drawGameObjects() {
    player.draw();
    
    for (GameObject& obj : gameObjs) {
        obj.draw();
    }
}

void init() {
    glClearColor(0.1f, 0.0f, 0.2f, 1.0f); // Background color

    // glShadeModel(GL_SMOOTH);						
	// glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    loadBackgroundStars("Assets/BackgroundStars.txt");
    loadModels();
    loadGameObjects();
}

void drawAxes() {
	glColor3ub(255, 255, 255);

    glBegin(GL_LINES);
        // Horizontal axis
        glVertex2f(-100.0f, 0.0f);
        glVertex2f( 100.0f, 0.0f);
        // Vertical axis
        glVertex2f( 0.0f, -100.0f);
        glVertex2f( 0.0f,  100.0f);
    glEnd();
}

void drawGameObjectsAABBs() {
    player.drawAABB();
    
    for (GameObject& obj : gameObjs) {
        obj.drawAABB();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

    // drawAxes();
    drawBackgroundStars();
    drawGameObjects();
    drawGameObjectsAABBs();
    glutSwapBuffers();
    glutPostRedisplay();
}

void reshape(int w, int h) {
    // Reset the coordinate system before modifying
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Defines the OpenGL area to be used within the window
    glViewport(0, 0, w, h);
    // Defines the OpenGL area logical limits within the window
    glOrtho(-100, 100, -100, 100, 0, 1);

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
        case 'w':
            player.moveForward();
            glutPostRedisplay();
            break;
        case 's':
            player.moveBackward();
            glutPostRedisplay();
            break;
        case 'a':
            player.rotateLeft();
            glutPostRedisplay();
            break;
        case 'd':
            player.rotateRight();
            glutPostRedisplay();
            break;
        case 'f':
			glutFullScreen();
            break;
        case 'g':
			glutPositionWindow(50,50);
			glutReshapeWindow(700, 500);
            break;
		case 27: // Esc
			exit(0);
			break;      
    	default:        
      		break;
  	}
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(700, 500);
    glutCreateWindow("Asteroidz");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	// glutSpecialFunc(arrowKeys);
	// glutIdleFunc(glutPostRedisplay)
	glutMainLoop();

    return EXIT_SUCCESS;
}