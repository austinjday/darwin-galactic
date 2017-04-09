//
// Created by austin on 4/8/2017.
//

#ifndef DARWINGALACTIC_ASTEROIDMANAGER_H
#define DARWINGALACTIC_ASTEROIDMANAGER_H

#include <set>
#include <random>
#include <memory>
#include <ctime>

#include "Asteroid.h"
#include "../common/Constants.h"

typedef std::pair<std::unordered_set<std::shared_ptr<Asteroid>>::const_iterator, std::unordered_set<std::shared_ptr<Asteroid>>::const_iterator> AsteroidIts;


/**
 * Exactly what it sounds like. All the asteroids
 */
class AsteroidManager {

private:

    /**
     * All asteroids in the environment.
     */
    std::unordered_set<std::shared_ptr<Asteroid>> asteroids;

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

    // length or width of environment frame.
    int maxDimension;

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


public:

    AsteroidManager();

    /**
     * Create an instance of Asteroid Manager.
     * @param length - length of window over which to generate asteroids
     * @param width - width " ... "
     */
    AsteroidManager(int length, int width);

    /**
     * Update all asteroids in the environment.
     *
     * Do the motion for this tick for each asteroid. If it leaves the environment, remove it and free the memory. If it is
     * destroyed, send it to the exploding asteroids set.
     */
    void updateAsteroids();

    /**
     * This may or may not generate a new asteroid on the specified hyperplane. A list (possibly empty) of candidate
     * asteroids is generated, from which, if not empty, an asteroid is selected and created.
     * @param begin - lower bound on hyperplane
     * @param end - upper bound on hyperplane
     * @param interval - interval on which to try points as potential asteroid centers
     */
    void generateAsteroidInRange(Point begin, Point end, int interval);

    /**
     * Find the distance from the given point to the edge of the nearest asteroid.
     * @param point - from which to measure.
     * @return distance
     */
    int getDistanceToNearestAsteroid(Point point) const;

    /**
     * Provided a left bound and right bound, find the asteroid within the bounds nearest to the x-axis.
     * @param leftInclusive - left bound of path.
     * @param rightExclusive - right bound of path.
     * @return closest asteroid within bounds.
     */
    std::shared_ptr<Asteroid> getClosestAsteroidInPath(int leftInclusive, int rightExclusive) const;

    /**
     * Expose iterators for the asteroids.
     */
    std::pair<std::unordered_set<std::shared_ptr<Asteroid>>::const_iterator, std::unordered_set<std::shared_ptr<Asteroid>>::const_iterator> its() const;

};


#endif //DARWINGALACTIC_ASTEROIDMANAGER_H
