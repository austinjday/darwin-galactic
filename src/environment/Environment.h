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

class Environment {
private:

    /**
     * All asteroids in the environment.
     */
    std::unordered_set<std::shared_ptr<Asteroid>> asteroids;

    /**
     * All lasers in the environment.
     */
    std::unordered_set<std::unique_ptr<LaserShot>> laserShots;

    /**
     * Normal distribution for clearances.
     */
    std::normal_distribution<double> clearanceDistribution;

    /**
     * Normal distribution for radii.
     */
     std::normal_distribution<double> radiusDistribution;

    //std::random_device randomDevice;
    std::mt19937 generator;

    int width;
    int length;
    int id;

    Ship* ship = NULL;

    /**
     * Get a random radius based on the radius distribution set up in the constructor.
     * @return random radius.
     */
    int randomRadius();

    /**
     * Get a random clearance based on the clearance distribution set up in the constructor.
     * @return random clearance.
     */
    int randomClearance();

    /**
     * Get a random integer from the range [0, elements).
     * @param elements upper exclusive bound.
     * @return random integer.
     */
    int randomInRange(int elements);

    /**
     * This may or may not generate a new asteroid on the specified hyperplane. A list (possibly empty) of candidate
     * asteroids is generated, from which, if not empty, an asteroid is selected and created.
     * @param begin - lower bound on hyperplane
     * @param end - upper bound on hyperplane
     * @param interval - interval on which to try points as potential asteroid centers
     */
    void generateAsteroidInRange(Point begin, Point end, int interval);
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

    /**
     * Update all asteroids in the environment.
     *
     * Do the motion for this tick for each asteroid. If it leaves the environment, remove it and free the memory. If it is
     * destroyed, send it to the exploding asteroids set.
     */
    void updateAsteroids();

    void handleShipAsteroidContact();

    void updateTarget(LaserShot*);

public:
    Environment(int height, int width);
    ~Environment();

    void setShip(Ship*);

    void tick();

    int getDistanceToNearestAsteroid(Point point) const;

    Asteroid* getClosestAsteroidInPath(int leftInclusive, int rightExclusive) const;
};


#endif //DARWINGALACTIC_ENVIRONMENT_H
