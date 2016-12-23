//
// Created by aday on 10/14/2016.
//

#ifndef DARWINGALACTIC_ASTEROID_H
#define DARWINGALACTIC_ASTEROID_H

#include <unordered_set>
#include <vector>
#include <map>
#include <unordered_map>
#include "../common/Point.h"

class Asteroid {
private:
    Point center;
    int radius;
    int density;
    int speed;
    bool inBounds = true;
    bool exploded = false;
    int id;

public:
    Asteroid(Point center, int radius, int density, int speed);
    Asteroid(std::pair<Point, int> spacialProfile, int speed);
    ~Asteroid();
    static int counter;

    static const int INTERNAL;

    int getRadius() const;
    int getDensity() const;
    int getSpeed() const;
    bool isInBounds() const;
    bool hasExploded() const;
    bool isValid() const;

    static int randomDensity();

    /**
     * Do a tick for this asteroid.
     */
    void tick();

    /**
     * Hit the asteroid with a laser shot of the given power.
     * @param power of laser shot.
     */
    void hit(int power);

    Point getCenter() const;
    int getX() const;
    int getY() const;

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

    int getSquaredDistanceToCenter(Point) const;

    /**
     * From the given position, find the linear distance to the edge of this asteroid.
     * Note: this is an approximation as it uses integer square root.
     * @param position outside of asteroid.
     * @return distance if point is external, or 0 if given point is internal.
     */
    int getDistanceToEdge(Point) const;
};

#endif //DARWINGALACTIC_ASTEROID_H