
#include <GL/freeglut.h>
#include <algorithm>
#include "src/geometry/Shapes.h"
#include "src/time/Clock.h"

int sWidth = 500, sHeight = 500;

int size = std::min(sWidth, sHeight);

int dx = size/2, dy = size/2;

float scaleFactor = float(size) / 250.0f;

Clock* analogClock = new Clock();

void init() {
    glClearColor(0.2,0.2,0.22,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, glutGet(GLUT_WINDOW_WIDTH), 0.0, glutGet(GLUT_WINDOW_HEIGHT), -1.0, 1.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    analogClock->draw(dx, dy, scaleFactor);
    glutSwapBuffers();
    glutPostRedisplay();
}

void idle() {}

void reshape(int width, int height) {
    size = std::min(width, height);
    glViewport(GLint(float(width - size) / 2.0f), GLint(float(height - size) / 2.0f), size, size);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(sWidth, sHeight);
    glutInitWindowPosition(150, 150);
    glutCreateWindow("Trig is Hard");

    init();

    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}


