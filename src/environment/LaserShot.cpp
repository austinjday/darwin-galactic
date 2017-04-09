//
// Created by aday on 10/25/2016.
//

#include <cstddef>
#include <cassert>
#include "LaserShot.h"
#include "../common/Constants.h"

LaserShot::LaserShot(Point position, int power) {
    this->position = position;
    this->power = power;
    this->target = std::shared_ptr<Asteroid>(NULL);
}

LaserShot::~LaserShot() {}

/**
 * Check if the laser shot is currently beyond the upper bound of the environment. If it is, set the active flag to
 * false. Otherwise, do nothing.
 */
void LaserShot::updateActive() {
    if (position.y >= 1200) {
        inBounds = false;
    }
}

bool LaserShot::impactOnNextTick() const{
    if (target.use_count() == 0) {
        return false;
    }
    return getUpperBound() + LASER_SHOT_SPEED > target->getLowerBound() - target->getSpeed();
}

/**
 * Do a tick for this laser shot. The laser shot will either hit an asteroid or it will not.
 *
 * If it will hit an asteroid, update the position so the end of the laser shot is at the center of the asteroid
 * (on the next tick). However, don't do this if it causes the laser shot to move backward. In this case (the laser shot
 * is already beyond where the center of the asteroid will be next tick), do not update the position at all.
 *
 * If it will not hit an asteroid, update the position normally and check if it goes out of bounds.
 *
 * NOTE: the asteroids have not yet been ticked.
 */
void LaserShot::tick() {
    if (impactOnNextTick()) {
        int targetYOnNextTick = target->getY() - target->getSpeed();
        if (getUpperBound() < targetYOnNextTick) {
            position.y = targetYOnNextTick - LASER_SHOT_LENGTH;
        }
        impacted = true;
        target->hit(power);
    }
    else {
        position.y += LASER_SHOT_SPEED;
        updateActive();
    }
}

bool LaserShot::isInBounds() const{
    return inBounds;
}

bool LaserShot::targetIsValid() const {
    // if this is the only reference to this asteroid, then it is no longer active and obviously if there's no managed
    // asteroid, the target is not valid
    if (target.use_count() < 2) {
        return false;
    }
    return target->isValid();
}

bool LaserShot::hasMadeImpact() const{
    return impacted;
}

Point LaserShot::getPosition() const{
    return position;
}

int LaserShot::getX() const{
    return position.x;
}

int LaserShot::getY() const{
    return position.y;
}

void LaserShot::setTarget(std::shared_ptr<Asteroid> asteroid) {
    target = asteroid;
}

std::shared_ptr<Asteroid> LaserShot::getTarget() const {
    return target;
}

int LaserShot::getLeftBound() const{
    return position.x;
}

int LaserShot::getLowerBound() const{
    return position.y;
}

int LaserShot::getRightBound() const{
    return position.x + LASER_SHOT_WIDTH;
}

int LaserShot::getUpperBound() const{
    return position.y + LASER_SHOT_LENGTH;
}

int LaserShot::getPower() const{
    return power;
}