//
// Created by aday on 10/14/2016.
//

#include "Asteroid.h"
#include "../utility/IntegerMath.h"
#include "../common/Constants.h"

#include <cmath>
#include <random>

const int Asteroid::INTERNAL = 0;

int Asteroid::counter = 0;

Asteroid::Asteroid(Point center, int radius, int density, int speed) {
    this->center = center;
    this->radius = radius;
    this->density = density;
    this->speed = speed;
    counter++;
}

Asteroid::Asteroid(std::pair<Point, int> spacialProfile, int speed) {
    this->center = spacialProfile.first;
    this->radius = spacialProfile.second;
    this->density = randomDensity();
    this->speed = speed;
    counter++;
}

Asteroid::~Asteroid() {
    counter--;
}

int Asteroid::getRadius() const {
    return radius;
}

int Asteroid::getDensity() const {
    return density;
}

int Asteroid::getSpeed() const {
    return speed;
}

bool Asteroid::isInBounds() const {
    return inBounds;
}

bool Asteroid::hasExploded() const {
    return exploded;
}

bool Asteroid::isValid() const {
    return inBounds && !exploded;
}

int Asteroid::randomDensity() {
    return rand() % (MAX_ASTEROID_DENSITY - MIN_ASTEROID_DENSITY + 1) + MIN_ASTEROID_DENSITY;
}

void Asteroid::tick() {
    center.y -= speed;
    if (getUpperBound() <= 0) {
        inBounds = false;
    }
}

void Asteroid::hit(int power) {
    density -= power;
    if (density <= 0) {
        exploded = true;
    }
}

Point Asteroid::getCenter() const {
    return center;
}

int Asteroid::getX() const {
    return center.x;
}

int Asteroid::getY() const {
    return center.y;
}

int Asteroid::getLeftBound() const {
    return center.x - radius;
}

int Asteroid::getLowerBound() const {
    return center.y - radius;
}

int Asteroid::getRightBound() const {
    return center.x + radius + 1;
}

int Asteroid::getUpperBound() const {
    return center.y + radius + 1;
}

int Asteroid::getSquaredDistanceToCenter(Point point) const {
    int xDistance = point.x - center.x;
    int yDistance = point.y - center.y;
    return IntegerMath::square(xDistance) + IntegerMath::square(yDistance);
}

int Asteroid::getDistanceToEdge(Point point) const {
    int squaredDistanceToCenter = getSquaredDistanceToCenter(point);
    int distanceToEdge = (int) std::floor(std::sqrt((double) squaredDistanceToCenter)) - radius;
    return distanceToEdge <= 0 ? INTERNAL : distanceToEdge;
}