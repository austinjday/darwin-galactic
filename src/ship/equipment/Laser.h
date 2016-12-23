//
// Created by aday on 10/14/2016.
//

#ifndef DARWINGALACTIC_LASER_H
#define DARWINGALACTIC_LASER_H


#include "../../common/Point.h"

class Laser {
private:
    int fireRate;
    int firepower;
    int mass;

    int fireCounter = 0;

    // this center is relative to the ship's center.
    int position;
    int length;
    int width;

public:
    Laser(int fireRate, int firepower, int position, int length, int width);
    ~Laser();

    int getFireRate() const;
    int getFirepower() const;
    int getMass() const;

    int getPosition() const;
    int getLength() const;
    int getWidth() const;

    void tick();

    bool readyToFire() const;

    void fire();
};


#endif //DARWINGALACTIC_LASER_H
