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

int Environment::randomRadius() {
    double result = radiusDistribution(generator);
    return (int) std::floor(result);
}

int Environment::randomClearance() {
    double result = clearanceDistribution(generator);
    return (int) std::floor(result);
}

int Environment::randomInRange(int elements) {
    std::uniform_int_distribution<> distribution(0, elements - 1);
    return distribution(generator);
}

void Environment::generateAsteroidInRange(Point begin, Point end, int interval) {

    // create a list of randomly generated potential asteroid spacial profiles (at most one spacial profile per point in
    // range)
    std::vector<std::pair<Point, int>> asteroidSpacialProfiles;
    int offset = randomInRange(interval);

    // give the interval an offset
    begin.x == end.x ? begin.y += offset : begin.x += offset;

    /*
     * This for-loop works for both vertical and horizontal ranges. With equal x-values for begin and end, will iterate
     * over y-range. With equal y-values, will iterate over x-range.
     */
    for (Point point = begin; point.x <= end.x && point.y <= end.y; begin.x == end.x ? point.y += interval : point.x += interval) {
        int distanceToNearestAsteroid = getDistanceToNearestAsteroid(point);

        // only consider this point if it is possible for the smallest allowable asteroid to fit there
        if (MIN_ASTEROID_RADIUS + MIN_ASTEROID_CLEARANCE < distanceToNearestAsteroid) {

            // maximum allowable radius for this point
            int maxAllowableRadius = distanceToNearestAsteroid - MIN_ASTEROID_CLEARANCE;

            // get a random radius and its clearance
            int radius = randomRadius();
            int clearance = distanceToNearestAsteroid - radius;

            // get the minimum allowable clearance
            int acceptableClearance = randomClearance();
            if (acceptableClearance < MIN_ASTEROID_CLEARANCE) {
                acceptableClearance = MEAN_ASTEROID_CLEARANCE;
            }

            /*
             * Create an asteroid spacial profile if both the following hold:
             * radius is within bounds
             * clearance is not less than the minimum allowable
             */
            if (radius >= MIN_ASTEROID_RADIUS && radius <= maxAllowableRadius && clearance >= acceptableClearance) {
                if (rand() % 30 == 17) {
                    std::cout << clearance << std::endl;
                }
                asteroidSpacialProfiles.push_back(std::make_pair(point, radius));
            }
        }
    }

    // pick a spacial profile to create
    if (!asteroidSpacialProfiles.empty()) {
        int idx = randomInRange(asteroidSpacialProfiles.size());
        asteroids.insert(std::make_shared<Asteroid>(asteroidSpacialProfiles[idx], BASE_ASTEROID_SPEED));
    }
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
    this->length = height;
    this->width = width;
    clearanceDistribution = std::normal_distribution<double> ((double) MEAN_ASTEROID_CLEARANCE, (double) ASTEROID_CLEARANCE_STD_DEV);
    radiusDistribution = std::normal_distribution<double> ((double) MEAN_ASTEROID_RADIUS, (double) ASTEROID_RADIUS_STD_DEV);
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
    assert (ship != NULL);
    generateAsteroidOnXAxis(length * 2 + MAX_ASTEROID_RADIUS, length / 35);
    updateLaserShots();
    updateAsteroids();
    ship->tickMotion();
    handleShipAsteroidContact();
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
