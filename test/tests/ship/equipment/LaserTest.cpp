//
// Created by aday on 11/30/2016.
//

#include "gtest/gtest.h"
#include "../../../../src/ship/equipment/Laser.h"

class LaserTest : public testing::Test {
protected:
    int fireRate = 3;
    int firepower = 10;
    int position = 0;
    int length = 45;
    int width = 5;
};

TEST_F(LaserTest, readyToFireOnCreation) {
    Laser laser(fireRate, firepower, position, length, width);
    ASSERT_TRUE(laser.readyToFire());
}

TEST_F(LaserTest, readyToFireAfterTicksWithoutFiring) {
    Laser laser(fireRate, firepower, position, length, width);
    laser.tick();
    EXPECT_TRUE(laser.readyToFire());

    laser.tick();
    EXPECT_TRUE(laser.readyToFire());

    laser.tick();
    EXPECT_TRUE(laser.readyToFire());

    laser.tick();
    EXPECT_TRUE(laser.readyToFire());
}

TEST_F(LaserTest, readyToFireNotReadyAfterFiringUntilEnoughTicksPass) {
    Laser laser(fireRate, firepower, position, length, width);
    laser.fire();
    EXPECT_FALSE(laser.readyToFire());

    laser.tick();
    EXPECT_FALSE(laser.readyToFire());

    laser.tick();
    EXPECT_FALSE(laser.readyToFire());

    laser.tick();
    EXPECT_TRUE(laser.readyToFire());
}


