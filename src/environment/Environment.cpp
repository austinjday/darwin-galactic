//
// Created by aday on 10/17/2016.
//

#include <cstddef>
#include <cassert>
#include <vector>
#include <iostream>
#include "Environment.h"
#include "../common/Constants.h"
#include "../utility/IntegerMath.h"

void Environment::generateAsteroidOnXAxis(int y, int interval) {
    Point begin = {ship->getLeftBound() - width / 2 - MAX_ASTEROID_RADIUS, y};
    Point end = {ship->getRightBound() + width / 2 + MAX_ASTEROID_RADIUS, y};
    asteroidManager.generateAsteroidInRange(begin, end, interval);
}

void Environment::generateAsteroidOnYAxis(int x, int interval) {
    Point begin = {x, ship->getLeftBound() - width / 2 - MAX_ASTEROID_RADIUS};
    Point end = {x, ship->getRightBound() + width / 2 + MAX_ASTEROID_RADIUS};
    asteroidManager.generateAsteroidInRange(begin, end, interval);
}

void Environment::setShip(Ship* ship) {
    assert (this->ship == NULL);
    this->ship = ship;
}

void Environment::updateTarget(LaserShot* laserShot) {
    if (!laserShot->targetIsValid()) {
        laserShot->setTarget(asteroidManager.getClosestAsteroidInPath(laserShot->getLeftBound(), laserShot->getRightBound()));
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

void Environment::handleShipAsteroidContact() {
    AsteroidIts asteroidIts = asteroidManager.its();
    for (auto it = asteroidIts.first; it != asteroidIts.second; it++) {
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
    asteroidManager = AsteroidManager(height, width);
    return;
}

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
    asteroidManager.updateAsteroids();
    ship->tickMotion();
    handleShipAsteroidContact();
}