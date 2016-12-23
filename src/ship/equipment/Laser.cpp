//
// Created by aday on 10/14/2016.
//

#include "../../common/Constants.h"
#include "Laser.h"
#include "../../environment/LaserShot.h"

Laser::Laser(int fireRate, int firepower, int position, int length, int width) {
    this->fireRate = fireRate;
    this->firepower = firepower;
    this->position = position;
    this->length = length;
    this->width = width;
    this->mass = LASER_BASE_MASS + fireRate * MASS_PER_FIRE_RATE + firepower * MASS_PER_FIREPOWER;
}

Laser::~Laser() {}

int Laser::getPosition() const{
    return position;
}

int Laser::getFireRate() const{
    return fireRate;
}

int Laser::getFirepower() const{
    return firepower;
}

int Laser::getMass() const{
    return mass;
}

int Laser::getLength() const{
    return length;
}

int Laser::getWidth() const{
    return width;
}

void Laser::tick() {
    fireCounter--;
}

bool Laser::readyToFire() const {
    return fireCounter <= 0;
}

void Laser::fire() {
    fireCounter = fireRate;
}









