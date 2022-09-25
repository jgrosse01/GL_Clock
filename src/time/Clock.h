//
// Created by jgros on 9/19/2022.
//

#ifndef CLOCK_H
#define CLOCK_H


#include <ctime>


class Clock {

public:
    Clock();
    void draw(int dx, int dy, float scaleFactor);
    void setTimeZone(int hoursFromGMT);
    static float timeToDeg(struct tm* lt, int unit);
    struct tm* getTimeStruct();
};


#endif //GL_CLOCK_CLOCK_H
