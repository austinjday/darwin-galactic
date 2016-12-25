#include <iostream>
#include <ctime>
#include "ship/equipment/Thruster.h"
#include "ship/equipment/Laser.h"
#include "ship/Ship.h"
#include "environment/Environment.h"
#include "common/Point.h"
#include "utility/IntegerMath.h"
#include "common/Constants.h"

int main() {
    Ship ship(MAX_BODY_HEIGHT, MAX_BODY_WIDTH);

    Environment environment(6000, 4000);

    environment.setShip(&ship);

    int tick = 0;
    clock_t start = clock();
    for (;tick < 10000 && ship.isIntact(); tick++) {
        environment.tick();
    }
    double duration = double( clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout << "done on tick: " << tick << std::endl;
    std::cout << "time: " << duration << " seconds." << std::endl;
    std::cout << "ticks per second: " << (double) tick / duration << std::endl << std::endl;

    return 0;
}