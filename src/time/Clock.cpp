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
    circle(dx, dy, scaleFactor, new Color(240, 0, 240));
    clockTicks(dx,dy,scaleFactor);
}

void Clock::setTimeZone(int hoursFromGMT) {

}

// theoretically temporary implementation of get time since my compiler does not support threading to keep track of time on a thread
struct tm* Clock::getTime() {
    time_t t = time(0);
    struct tm* local = localtime(&t);
    return local;
}
