//
// Created by aday on 10/17/2016.
//

#ifndef DARWINGALACTIC_ENVIRONMENT_H
#define DARWINGALACTIC_ENVIRONMENT_H

#include <set>
#include <random>
#include <memory>

#include "Asteroid.h"
#include "../common/Constants.h"
#include "LaserShot.h"
#include "../ship/Ship.h"
#include "AsteroidManager.h"

class Environment {
private:

    /**
     * All lasers in the environment.
     */
    std::unordered_set<std::unique_ptr<LaserShot>> laserShots;

    std::mt19937 generator;

    int width;
    int length;

    Ship* ship = NULL;

    AsteroidManager asteroidManager;

    void generateAsteroidOnXAxis(int y, int interval);

    void generateAsteroidOnYAxis(int x, int interval);

    /**
     * Update all laser shots in the environment.
     *
     * Find a target for each laser shot if it doesn't already have one, do the motion for this tick. If it leaves the
     * environment, remove it and free the memory. If it makes impact with an asteroid, send it to the impacting laser shots
     * set.
     */
    void updateLaserShots();

    void handleShipAsteroidContact();

    void updateTarget(LaserShot*);

public:
    Environment(int height, int width);

    void setShip(Ship*);

    void tick();
};


#endif //DARWINGALACTIC_ENVIRONMENT_H
