#include <iostream>
#include <ctime>
#include "ship/equipment/Thruster.h"
#include "ship/equipment/Laser.h"
#include "ship/Ship.h"
#include "environment/Environment.h"
#include "common/Point.h"
#include "utility/IntegerMath.h"
#include "common/Constants.h"
#include "logging/TimeLog.h"

TimeLog timeLog;

int main() {
    int timeLogIdx = timeLog.newTimeLog("main");

//    for (int run = 0; run < 20; run++) {
//        clock_t start = clock();
//
//        for (unsigned long i = 0; i < 100000; i++) {
//            unsigned long x = IntegerMath::squareRoot(62321);
//        }
//        clock_t end = clock();
//        std::cout << "custom: " << ((double) (end - start)) / (double) CLOCKS_PER_SEC << std::endl;
//
//        start = clock();
//        for (unsigned long i = 0; i < 100000; i++) {
//            unsigned long x = (unsigned long) std::floor(std::sqrt(62321));
//        }
//        end = clock();
//        std::cout << "std: " << ((double) (end - start)) / (double) CLOCKS_PER_SEC << std::endl;
//    }
//    std::cout << IntegerMath::squareRoot(62321) << std::endl;
//    std::cout << (unsigned long) std::floor(std::sqrt(62321));
//    return 0;

    Ship ship(MAX_BODY_HEIGHT, MAX_BODY_WIDTH);

    Environment environment(6000, 4000);

    environment.setShip(&ship);

    int tick = 0;
    clock_t start = clock();
    timeLog.tick(timeLogIdx);
    for (;tick < 300000 /*&& ship.isIntact()*/; tick++) {
        environment.tick();
    }
    timeLog.tock(timeLogIdx);
    double duration = double( clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout << "done on tick: " << tick << std::endl;
    std::cout << "time: " << duration << " seconds." << std::endl;
    std::cout << "ticks per second: " << (double) tick / duration << std::endl << std::endl;
    std::cout << timeLog;

    return 0;
}