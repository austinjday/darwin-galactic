//
// Created by aday on 10/14/2016.
//

#include "../../common/Constants.h"
#include "Thruster.h"

Thruster::Thruster(int position, int length, int width) {
    this->position = position;
    this->length = length;
    this->width = width;
    this->maxForceOutput = length * width * MAX_FORCE_OUTPUT_PER_AREA;
    this->mass = length * width * THRUSTER_DENSITY;
}

Thruster::~Thruster() {}

int Thruster::getPosition() const{
    return position;
}

int Thruster::getLength() const{
    return length;
}

int Thruster::getWidth() const{
    return width;
}

int Thruster::getMaxForceOutput() const{
    return maxForceOutput;
}

int Thruster::getMass() const{
    return mass;
}
