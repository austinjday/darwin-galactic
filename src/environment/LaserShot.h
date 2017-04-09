//
// Created by aday on 10/25/2016.
//

#ifndef DARWINGALACTIC_LASERSHOT_H
#define DARWINGALACTIC_LASERSHOT_H


#include <memory>
#include "../common/Point.h"
#include "Asteroid.h"

class LaserShot {
private:
    Point position;
    bool inBounds = true;
    bool impacted = false;
    int power;
    int id;

    std::shared_ptr<Asteroid> target;

    void updateActive();

    bool impactOnNextTick() const;

public:
    LaserShot(Point, int power);
    ~LaserShot();

    void tick();

    bool isInBounds() const;

    bool targetIsValid() const;

    bool hasMadeImpact() const;

    Point getPosition() const;
    int getX() const;
    int getY() const;

    void setTarget(std::shared_ptr<Asteroid>);
    std::shared_ptr<Asteroid> getTarget() const;

    /**
     * Inclusive.
     */
    int getLeftBound() const;
    int getLowerBound() const;

    /**
     * Exclusive.
     */
    int getRightBound() const;
    int getUpperBound() const;

    int getPower() const;
};


#endif //DARWINGALACTIC_LASERSHOT_H
