//
// Created by jgros on 9/20/2022.
//

#ifndef SHAPES_H
#define SHAPES_H

#include "../Color/Color.h"
#include <cmath>
#include <GL/freeglut.h>
#include <ctime>

void clockTicks(int dx, int dy, float scaleFactor);

void clockHands(int dx, int dy, time_t time, float scaleFactor);

void hand(int dx, int dy, float deg, float scaleFactor, float lineWidth, Color* color, float radiusScale);
void hourHand(int dx, int dy, float deg, float scaleFactor, Color* color);
void minuteHand(int dx, int dy, float deg, float scaleFactor, Color* color);
void secondHand(int dx, int dy, float deg, float scaleFactor, Color* color);

void ssdHorizontalBlock(int dx, int dy, float scaleFactor);
void ssdVerticalBlock(int dx, int dy, float scaleFactor);

void circle(int dx, int dy, float scaleFactor, Color* color);

float degToRad(float deg);

#endif //SHAPES_H
