//
// Created by aday on 10/14/2016.
//

#ifndef DARWINGALACTIC_SHIP_H
#define DARWINGALACTIC_SHIP_H

#include <cstddef>
#include <vector>

#include "equipment/Thruster.h"
#include "equipment/Laser.h"
#include "../environment/Asteroid.h"

class Ship {
private:
    int bodyLength;
    int bodyWidth;
    int mass;

    int forceOutput;
    int speed;
    Point position;

    bool intact = true;
    int id;

    Thruster* leftThruster = NULL;
    Thruster* rightThruster = NULL;
    Laser* laser = NULL;

    bool asteroidIsCandidateForContact(const Asteroid*) const;

    bool asteroidIsTouchingComponent(Point center, int length, int width, const Asteroid* asteroid) const;

public:
    Ship(int bodyLength, int bodyWidth);
    ~Ship();

    int getBodyLength() const;
    int getBodyWidth() const;
    int getMass() const;

    void setLeftThruster(Thruster*);
    void setRightThruster(Thruster*);
    void setLaser(Laser*);

    bool leftThrusterIsIntact() const;
    bool rightThrusterIsIntact() const;
    bool laserIsIntact() const;
    bool isIntact() const;

    void removeLeftThruster();
    void removeRightThruster();
    void removeLaser();

    void setForceOutput(int);
    int getForceOutput() const;

    int getSpeed() const;

    void tickMotion();

    Point getPosition() const;
    int getX() const;
    int getY() const;

    int getLowerBound() const;
    int getUpperBound() const;
    int getLeftBound() const;
    int getRightBound() const;

    void handleContact(const Asteroid*);

};

#endif //DARWINGALACTIC_SHIP_H