//
// Created by aday on 12/20/2016.
//

#include "TimeLog.h"

void TimeLog::tick(int idx) {
    clock_t time = clock();
    loglets[idx].lastTick = time;
}

void TimeLog::tock(int idx) {
    clock_t time = clock();
    Loglet& loglet = loglets[idx];
    loglet.accumulatedTime += (double) (time - loglet.lastTick);
    loglet.hits += 1;
}

int TimeLog::newTimeLog(std::string name) {
    int idx = loglets.size();
    Loglet loglet;
    loglet.name = name;
    loglets.push_back(loglet);
    return idx;
}

std::ostream& operator<<(std::ostream& os, const TimeLog& timeLog) {
    os << "Time log report:" << std::endl;
    for (auto it = timeLog.loglets.begin(); it != timeLog.loglets.end(); it++) {
        os << it->name << ": " << it->accumulatedTime / (double) CLOCKS_PER_SEC << ", " << it->hits << std::endl;
    }
    return os;
}