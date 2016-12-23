//
// Created by aday on 12/20/2016.
//

#ifndef DARWINGALACTIC_TIMELOG_H
#define DARWINGALACTIC_TIMELOG_H

#include <unordered_map>
#include <ctime>
#include <string>
#include <iostream>
#include <vector>

class TimeLog {
private:

    struct Loglet {
        std::string name;
        double accumulatedTime = 0.0;
        int hits = 0;
        clock_t lastTick;
    };

    std::vector<Loglet> loglets;

public:

    void tick(int idx);
    void tock(int idx);

    int newTimeLog(std::string name);

    friend std::ostream& operator<<(std::ostream& os, const TimeLog& timeLog);
};


#endif //DARWINGALACTIC_TIMELOG_H
