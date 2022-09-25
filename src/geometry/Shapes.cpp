//
// Created by jgros on 9/20/2022.
//

#include <cmath>
#include <GL/freeglut.h>
#include <ctime>

#include "Shapes.h"
#include "../time/Clock.h"

// clock parts here

void clockTicks(int dx, int dy, float scaleFactor) {
    float radius = 110.0f * scaleFactor;

    glBegin(GL_LINES);
    for (int i = 0; i < 361; i += 6) {

        glColor3ub(255,240,0);
        glVertex2d(radius * cos(degToRad(i)) + dx, radius * sin(degToRad(i)) + dy);

        float tickLength = (i % 5 == 0) ? 15.0f * scaleFactor : 8.0f * scaleFactor;
        glVertex2d((radius-tickLength) * cos(degToRad(i)) + dx, (radius-tickLength) * sin(degToRad(i)) + dy);
    }
    glEnd();
}

void clockHands(int dx, int dy, time_t time, float scaleFactor) {
    struct tm* lt = localtime(&time);
    float hourDeg = Clock::timeToDeg(lt, 0);
    float minuteDeg = Clock::timeToDeg(lt, 1);
    float secondDeg = Clock::timeToDeg(lt, 2);

    // adding the minute to the hour hand for smooth movement we have to divide the minute degs by 60 then multiply by 12 to convert to the units of hours on this clock.
    hourHand(dx, dy, hourDeg, scaleFactor, new Color(255,215,0));
    minuteHand(dx, dy, minuteDeg, scaleFactor, new Color(255, 215, 0));
    secondHand(dx, dy, secondDeg, scaleFactor, new Color(200,0,0));
}

void hand(int dx, int dy, float deg, float scaleFactor, float lineWidth, Color* color, float radiusScale) {
    float radius = 110.0f * scaleFactor;

    glLineWidth(lineWidth);
    glBegin(GL_LINES);
    glColor3ub(color->getRed(), color->getGreen(), color->getBlue());
    glVertex2d(dx, dy);
    glVertex2d((radius*radiusScale) * cos(degToRad(deg)) + dx, (radius*radiusScale)* sin(degToRad(deg)) + dy);
    glEnd();
}

void hourHand(int dx, int dy, float deg, float scaleFactor, Color* color) {
    hand(dx, dy, deg, scaleFactor, 3.0f*scaleFactor, color, 0.45);
}

void minuteHand(int dx, int dy, float deg, float scaleFactor, Color* color) {
    hand(dx, dy, deg, scaleFactor, 2.0f*scaleFactor, color, 0.7);
}

void secondHand(int dx, int dy, float deg, float scaleFactor, Color* color) {
    hand(dx, dy, deg, scaleFactor, 1.2f*scaleFactor, color, 0.85);
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

