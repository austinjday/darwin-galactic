//
// Created by aday on 10/14/2016.
//

#include <cassert>

#include "../common/Constants.h"
#include "Ship.h"
#include "../utility/IntegerMath.h"

Ship::Ship(int bodyLength, int bodyWidth) {
    this->bodyLength = bodyLength;
    this->bodyWidth = bodyWidth;
    this->mass = bodyLength * bodyWidth * SHIP_BODY_DENSITY;
    position = {bodyWidth * -1 / 2, 0};
    forceOutput = 0;
    speed = 0;
}

Ship::~Ship() {}

bool Ship::asteroidIsCandidateForContact(const Asteroid* asteroid) const {
    if (asteroid->getRightBound() <= getLeftBound()) {
        return false;
    }
    if (asteroid->getLeftBound() >= getRightBound()) {
        return false;
    }
    if (asteroid->getLowerBound() >= getUpperBound()) {
        return false;
    }
    return asteroid->getUpperBound() > getLowerBound();
}

bool Ship::asteroidIsTouchingComponent(Point origin, int length, int width, const Asteroid* asteroid) const {
    Point asteroidCenter = asteroid->getCenter();
    Point nearestPointOnRectangle = asteroidCenter;
    if (nearestPointOnRectangle.x < origin.x) {
        nearestPointOnRectangle.x = origin.x;
    }
    else if (nearestPointOnRectangle.x > origin.x + width) {
        nearestPointOnRectangle.x = origin.x + width;
    }
    if (nearestPointOnRectangle.y < origin.y) {
        nearestPointOnRectangle.y = origin.y;
    }
    else if (nearestPointOnRectangle.y > origin.y + length) {
        nearestPointOnRectangle.y = origin.y + length;
    }
    return asteroid->getSquaredDistanceToCenter(nearestPointOnRectangle) - IntegerMath::square(asteroid->getRadius()) < 0;
}

int Ship::getBodyLength() const{
    return bodyLength;
}

int Ship::getBodyWidth() const{
    return bodyWidth;
}

int Ship::getMass() const{
    return mass;
}

void Ship::setLeftThruster(Thruster* leftThruster) {
    this->leftThruster = leftThruster;
    mass += leftThruster->getMass();
}

void Ship::setRightThruster(Thruster* rightThruster) {
    this->rightThruster = rightThruster;
    mass += rightThruster->getMass();
}

void Ship::setLaser(Laser* laser) {
    this->laser = laser;
    mass += laser->getMass();
}

bool Ship::leftThrusterIsIntact() const{
    return leftThruster != NULL;
}

bool Ship::rightThrusterIsIntact() const{
    return rightThruster != NULL;
}

bool Ship::laserIsIntact() const{
    return laser != NULL;
}

bool Ship::isIntact() const{
    return intact;
}

void Ship::removeLeftThruster() {
    assert(leftThruster != NULL);
    assert(mass >= leftThruster->getMass());
    mass -= leftThruster->getMass();
    leftThruster = NULL;
}

void Ship::removeRightThruster() {
    assert(rightThruster != NULL);
    assert(mass >= rightThruster->getMass());
    mass -= rightThruster->getMass();
    rightThruster = NULL;
}

void Ship::removeLaser() {
    assert(laser != NULL);
    assert(mass >= laser->getMass());
    mass -= laser->getMass();
    laser = NULL;
}

void Ship::setForceOutput(int forceOutput) {
    this->forceOutput = forceOutput;
}

int Ship::getForceOutput() const{
    return forceOutput;
}

int Ship::getSpeed() const{
    return speed;
}

void Ship::tickMotion() {
    position.x += speed;
    speed += forceOutput;
}

Point Ship::getPosition() const{
    return position;
}

int Ship::getX() const{
    return position.x;
}

int Ship::getY() const{
    return position.y;
}

int Ship::getLowerBound() const{
    return position.y;
}

int Ship::getUpperBound() const{
    if (laserIsIntact()) {
        return position.y + bodyLength + laser->getLength();
    }
    return position.y + bodyLength;
}

int Ship::getLeftBound() const{
    if (leftThrusterIsIntact()) {
        return position.x - leftThruster->getWidth();
    }
    return position.x;
}

int Ship::getRightBound() const{
    if (rightThrusterIsIntact()) {
        return position.x + bodyWidth + rightThruster->getWidth();
    }
    return position.x + bodyWidth;
}

void Ship::handleContact(const Asteroid* asteroid) {
    if (asteroidIsCandidateForContact(asteroid)) {
        if (asteroidIsTouchingComponent(position, bodyLength, bodyWidth, asteroid)) {
            intact = false;
        }
        else {
            if (leftThrusterIsIntact()) {
                Point leftThrusterPosition = {getLeftBound(), position.y + leftThruster->getPosition()};
                if (asteroidIsTouchingComponent(leftThrusterPosition, leftThruster->getLength(), leftThruster->getWidth(), asteroid)) {
                    removeLeftThruster();
                }
            }
            if (rightThrusterIsIntact()) {
                Point rightThrusterPosition = {position.x + bodyWidth, position.y + rightThruster->getPosition()};
                if (asteroidIsTouchingComponent(rightThrusterPosition, rightThruster->getLength(), rightThruster->getWidth(), asteroid)) {
                    removeRightThruster();
                }
            }
            if (laserIsIntact()) {
                Point laserPosition = {position.x + laser->getPosition(), position.y + bodyLength};
                if (asteroidIsTouchingComponent(laserPosition, laser->getLength(), laser->getWidth(), asteroid)) {
                    removeLaser();
                }
            }
        }
    }
}