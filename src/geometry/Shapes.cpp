//
// Created by jgros on 9/20/2022.
//

#include "Shapes.h"
#include "../Color/Color.h"
#include <cmath>
#include <GL/freeglut.h>

// clock parts here

void clockTicks(int dx, int dy, float scaleFactor) {
    float radius = 110.0f * scaleFactor;

    glBegin(GL_LINES);
    for (int i = 0; i < 361; i += 6) {

        glColor3ub(255,255,255);
        glVertex2d(radius * cos(degToRad(i)) + dx, radius * sin(degToRad(i)) + dy);

        float tickLength = (i % 5 == 0) ? 15.0f * scaleFactor : 8.0f * scaleFactor;
        glVertex2d((radius-tickLength) * cos(degToRad(i)) + dx, (radius-tickLength) * sin(degToRad(i)) + dy);
    }
    glEnd();
}

void clockHands(int dx, int dy, float scaleFactor, Color* color) {

}

void hourHand(int dx, int dy, float scaleFactor, Color color) {

}

void minuteHand(int dx, int dy, float scaleFactor, Color color) {

}

void secondHand(int dx, int dy, float scaleFactor, Color color) {

}

// circle for clock

void circle(int dx, int dy, float scaleFactor, Color* color) {
    float radius = 110.0f * scaleFactor;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 1441; i++) {
        glColor3ub(color->getRed(), color->getGreen(), color->getBlue());
        glVertex2d(radius * cos(degToRad(i/4.0f)) + dx, radius * sin(degToRad(i/4.0f)) + dy);
    }
    glEnd();
}

float degToRad(float deg) {
    return deg * (M_PI/180.0f);
}

float radToDeg(float rad) {

}

