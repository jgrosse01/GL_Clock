//
// Created by jgros on 9/19/2022.
//

#include "Clock.h"
#include <ctime>
#include "../geometry/Shapes.h"

Clock::Clock() = default;

// for whatever reason, when we draw the clock, we get a strobing mess of gradient colors.
// unsure as to why... will try to fix later
void Clock::draw(int dx, int dy, float scaleFactor) {
    circle(dx, dy, scaleFactor*1.04, new Color(0, 0, 0));
    circle(dx, dy, scaleFactor, new Color(50, 50, 255));
    // clock hands here
    clockTicks(dx,dy,scaleFactor);

    clockHands(dx, dy, time(nullptr), scaleFactor);

    circle(dx, dy, scaleFactor * 0.04, new Color(0,0,0));
}

void Clock::setTimeZone(int hoursFromGMT) {

}

float Clock::timeToDeg(struct tm* lt, int unit) {
    switch (unit) {
        case 0:
            return (-1.0f * lt->tm_hour + 3.0f) * 30.0f - (lt->tm_min/2.0f);
        case 1:
            return (-1.0f * lt->tm_min + 15.0f) * 6.0f - (lt->tm_sec/10.0f);
        case 2:
            return (-1.0f * lt->tm_sec + 15.0f) * 6.0f;
    }
}

// theoretically temporary implementation of get time since my compiler does not support threading to keep track of time on a thread
struct tm* Clock::getTimeStruct() {
    time_t t = time(nullptr);
    struct tm* local = localtime(&t);
    return local;
}
