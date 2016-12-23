//
// Created by aday on 10/18/2016.
//

#include <cassert>
#include <cmath>

#include "IntegerMath.h"

unsigned long IntegerMath::squareRoot(unsigned long square) {
    if (square == 0 || square == 1) {
        return square;
    }
    unsigned long left = 1;
    unsigned long right = square;
    while (right - left > 1) {
        unsigned long guess = (right + left) / 2;
        unsigned long squaredGuess = guess * guess;
        if (squaredGuess >= square) {
            right = guess;
        }
        if (squaredGuess <= square) {
            left = guess;
        }
    }
    return left;
}

int IntegerMath::square(int root) {
    return root * root;
}

int IntegerMath::abs(int n) {
    return n < 0 ? n * -1 : n;
}