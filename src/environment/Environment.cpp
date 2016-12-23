//
// Created by aday on 10/17/2016.
//

#include <cstddef>
#include <cassert>
#include <vector>
#include <iostream>
#include <ctime>
#include "Environment.h"
#include "../common/Constants.h"
#include "../utility/IntegerMath.h"

int Environment::randomRadius(int min, int max) {
    assert (min <= max);
    std::binomial_distribution<int> distribution(max - min + 1, 0.5);
    //std::uniform_int_distribution<> distribution(min, max);
    return distribution(generator) + min;
}

int Environment::randomClearance() {
    int result = clearanceDistribution(generator);
    //clearanceDistribution.reset();
    //std::uniform_int_distribution<> distribution(MIN_ASTEROID_CLEARANCE, AVERAGE_ASTEROID_CLEARANCE * 2);
    //return distribution(generator);
    return result;
}

int Environment::randomInRange(int elements) {
    std::uniform_int_distribution<> distribution(0, elements - 1);
    return distribution(generator);
}

void Environment::generateAsteroidInRange(Point begin, Point end, int interval) {

    // create a list of randomly generated potential asteroid spacial profiles (at most one spacial profile per point in
    // range)
    std::vector<std::pair<Point, int>> asteroidSpacialProfiles;
//    if (end.x - begin.x == 0) {
//        asteroidSpacialProfiles.reserve((unsigned) (end.y - begin.y) / 10 + 1);
//    }
//    else {
//        asteroidSpacialProfiles.reserve((unsigned) (end.x - begin.x) / 10 + 1);
//    }
    int offset = randomInRange(interval);
    if (begin.x == end.x) {
        begin.y += offset;
    }
    else {
        begin.x += offset;
    }
    for (Point point = begin; point.x <= end.x && point.y <= end.y; begin.x == end.x ? point.y += interval : point.x += interval) {
        timeLog.tick(timeLogIdx);
        int distanceToNearestAsteroid = getDistanceToNearestAsteroid(point);
        timeLog.tock(timeLogIdx);

        if (MIN_ASTEROID_RADIUS + MIN_ASTEROID_CLEARANCE < distanceToNearestAsteroid) {
            // find the maximum allowable radius for this point.
            int max = MIN_ASTEROID_RADIUS;
            for (; max < MAX_ASTEROID_RADIUS && max + MIN_ASTEROID_CLEARANCE < distanceToNearestAsteroid; max++);

            // get a random radius and clearance distribution.
            int radius = randomRadius(MIN_ASTEROID_RADIUS, max);
            int acceptableClearance = randomClearance();

            // Only continue with this radius if it has a clearance greater than or equal to the chosen acceptable
            // clearance cut-off.
            if (distanceToNearestAsteroid - radius >= acceptableClearance) {
                if (rand() % 30 == 17) {
                    std::cout << distanceToNearestAsteroid - radius << std::endl;
                }
                asteroidSpacialProfiles.push_back(std::make_pair(point, radius));
            }
        }
    }
    //std::cout << std::endl << std::endl << std::endl;
    //std::cout << "Asteroid Spacial Profiles in pool: " << asteroidSpacialProfiles.size();

    // pick a spacial profile to create
    if (!asteroidSpacialProfiles.empty()) {
        int idx = randomInRange(asteroidSpacialProfiles.size());
        asteroids.insert(std::make_shared<Asteroid>(asteroidSpacialProfiles[idx], BASE_ASTEROID_SPEED));
        //std::cout << " -- " << asteroidSpacialProfiles[idx].second << std::endl;
    }
    //std::cout << std::endl;
}

void Environment::generateAsteroidOnXAxis(int y, int interval) {
    Point begin = {ship->getLeftBound() - width / 2 - MAX_ASTEROID_RADIUS, y};
    Point end = {ship->getRightBound() + width / 2 + MAX_ASTEROID_RADIUS, y};
    generateAsteroidInRange(begin, end, interval);
}

void Environment::generateAsteroidOnYAxis(int x, int interval) {
    Point begin = {x, ship->getLeftBound() - width / 2 - MAX_ASTEROID_RADIUS};
    Point end = {x, ship->getRightBound() + width / 2 + MAX_ASTEROID_RADIUS};
    generateAsteroidInRange(begin, end, interval);
}

void Environment::setShip(Ship* ship) {
    assert (this->ship == NULL);
    this->ship = ship;
}

void Environment::updateTarget(LaserShot* laserShot) {
    if (!laserShot->targetIsValid()) {
        laserShot->setTarget(getClosestAsteroidInPath(laserShot->getLeftBound(), laserShot->getRightBound()));
    }
}

void Environment::updateLaserShots() {
    // tick all laser shots. After ticking, check if it has made impact or gone out of bounds and if so, remove.
    for (auto it = laserShots.begin(); it != laserShots.end();) {
        auto current = it++;
        // update the laser's target before ticking because the target may have already been destroyed
        updateTarget(current->get());
        (*current)->tick();
        if (!(*current)->isInBounds() || (*current)->hasMadeImpact()) {
            laserShots.erase(current);
        }
    }
}

void Environment::updateAsteroids() {
    for (auto it = asteroids.begin(); it != asteroids.end();) {
        auto current = it++;
        (*current)->tick();
        if (!(*current)->isValid()) {
            asteroids.erase(current);
        }
    }
}

void Environment::handleShipAsteroidContact() {
    for (auto it = asteroids.begin(); it != asteroids.end(); it++) {
        ship->handleContact(it->get());
    }
}

/**
 * Create an environment of the given height and width.
 * @param height.
 * @param width.
 * @return newly constructed environment object.
 */
Environment::Environment(int height, int width) {
    timeLogIdx = timeLog.newTimeLog("nearest asteroid");
    this->length = height;
    this->width = width;
    clearanceDistribution = std::binomial_distribution<int>(AVERAGE_ASTEROID_CLEARANCE * 2, 0.5);
    srand((unsigned) time(NULL));
    generator = std::mt19937((unsigned) rand());
}

/**
 * Destroy.
 */
Environment::~Environment() {}

/**
 * Do a tick for this environment.
 *
 * Generate new asteroid(s).
 * Decide ship actions.
 * Perform ship actions.
 *
 * Update laser shots.
 * Update asteroids.
 * Handle laser-asteroid impacts.
 * Tick ship's motion.
 * Handle asteroid-ship impact.
 *
 */
void Environment::tick() {
    generateAsteroidOnXAxis(length * 2 + MAX_ASTEROID_RADIUS, length / 35);
    updateLaserShots();
    updateAsteroids();
//    if (rand() % 10 == 5) {
//        std::cout << "num asteroids: " << asteroids.size() << std::endl;
//    }
//    assert(ship != NULL);
//    ship->tickMotion();
    if (ship != NULL) {
        ship->tickMotion();
        handleShipAsteroidContact();
    }
}

int Environment::getDistanceToNearestAsteroid(Point point) const {
    int shortestDistance = length * 2;
    for (auto it = asteroids.begin(); it != asteroids.end() && shortestDistance > 0; it++) {
        int current = (*it)->getDistanceToEdge(point);
        if (current < shortestDistance) {
            shortestDistance = current;
        }
    }
    return shortestDistance;
}

Asteroid* Environment::getClosestAsteroidInPath(int leftInclusive, int rightExclusive) const {
    assert(leftInclusive < rightExclusive);
    std::shared_ptr<Asteroid> closest(NULL);
    for (std::shared_ptr<Asteroid> asteroid : asteroids) {
        if (rightExclusive > asteroid->getLeftBound() && leftInclusive < asteroid->getRightBound()) {
            // the asteroid is in this path
            if (closest == NULL || asteroid->getY() < closest->getY()) {
                closest = asteroid;
            }
        }
    }
    return closest.get();
}
