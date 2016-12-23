//
// Created by aday on 10/17/2016.
//

#ifndef DARWINGALACTIC_POSITION_H
#define DARWINGALACTIC_POSITION_H

#include <iostream>

struct Point {
    int x;
    int y;
};

static bool operator==(const Point &position1, const Point &position2) {
    return position1.x == position2.x && position1.y == position2.y;
}

static bool operator!=(const Point &position1, const Point &position2) {
    return !(position1 == position2);
}

static std::ostream& operator<<(std::ostream& os, const Point& position) {
    os << "(" << position.x << ", " << position.y << ")";
}

#endif //DARWINGALACTIC_POSITION_H
