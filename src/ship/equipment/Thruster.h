//
// Created by aday on 10/14/2016.
//

#ifndef DARWINGALACTIC_THRUSTER_H
#define DARWINGALACTIC_THRUSTER_H


class Thruster {
private:
    int position;
    int length;
    int width;
    int maxForceOutput;
    int mass;

public:
    Thruster(int position, int length, int width);
    ~Thruster();

    int getPosition() const;
    int getLength() const;
    int getWidth() const;
    int getMaxForceOutput() const;
    int getMass() const;

};

#endif //DARWINGALACTIC_THRUSTER_H