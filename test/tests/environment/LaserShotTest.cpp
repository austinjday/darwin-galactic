//
// Created by aday on 11/22/2016.
//

#include "../../../src/environment/LaserShot.h"
#include "gtest/gtest.h"
#include "../../../src/common/Constants.h"

class LaserShotTest : public testing::Test {
protected:
    int power = 30;
    Point position = {10, 10};
    int terminus = 1200;
    int density = 50;
};

/**
 * Construct a laser shot. Check everything is initialized correctly.
 */
TEST_F(LaserShotTest, constructor) {
    LaserShot laserShot(position, power);
    EXPECT_EQ(laserShot.getPower(), power);
    EXPECT_EQ(laserShot.getPosition(), position);
    EXPECT_TRUE(laserShot.getTarget() == NULL);
}

/**
 * A laser shot is in bounds and has no target. A tick updates the position and the laser shot is well within bounds.
 *
 * 1. Check position is updated correctly.
 */
TEST_F(LaserShotTest, tickNoTargetInBoundsCheckPosition) {
    LaserShot laserShot(position, power);
    laserShot.tick();
    Point expected = {position.x, position.y + LASER_SHOT_SPEED};
    ASSERT_EQ(laserShot.getPosition(), expected);
}

/**
 * 2. Check laser shot is still in bounds.
 */
TEST_F(LaserShotTest, tickNoTargetInBoundsCheckInBounds) {
    LaserShot laserShot(position, power);
    laserShot.tick();
    ASSERT_TRUE(laserShot.isInBounds());
}

/**
 * A laser shot is in bounds and has no target.
 * A tick sends it to the last possible position before going out of bounds.
 */
TEST_F(LaserShotTest, tickNoTargetAlmostOutOfBounds) {
    Point customPosition = {0, terminus - LASER_SHOT_SPEED - 1};
    LaserShot laserShot(customPosition, power);
    laserShot.tick();
    ASSERT_TRUE(laserShot.isInBounds());
}


/**
 * A laser shot is in bounds and has no target. A tick updates the position and the laser shot goes out of bounds.
 */
TEST_F(LaserShotTest, tickNoTargetOutOfBounds) {
    Point customPosition = {0, terminus - LASER_SHOT_SPEED};
    LaserShot laserShot(customPosition, power);
    laserShot.tick();
    ASSERT_FALSE(laserShot.isInBounds());
}

/**
 * A laser shot is in bounds and has a target. The laser shot does not hit the target or go out of bounds on the tick.
 *
 * The laser shot moves forward to hit the target.
 */
TEST_F(LaserShotTest, tickTargetNoImpactInBounds) {
    int x = 0;
    Point asteroidPosition = {x, 300};
    int asteroidSpeed = 10;
    int asteroidRadius = 10;
    Asteroid asteroid(asteroidPosition, asteroidRadius, density, asteroidSpeed);

    Point laserShotPosition = {x, asteroidPosition.y - asteroidRadius - asteroidSpeed - LASER_SHOT_SPEED - LASER_SHOT_LENGTH};
    LaserShot laserShot(laserShotPosition, power);
    laserShot.setTarget(&asteroid);
    laserShot.tick();

    // 1. Check center is updated correctly.
    Point expected = {x, laserShotPosition.y + LASER_SHOT_SPEED};
    EXPECT_EQ(laserShot.getPosition(), expected);

    // 2. Check that the laser shot is in bounds.
    EXPECT_TRUE(laserShot.isInBounds());

    // 3. Check that the laser shot has not made impact.
    EXPECT_FALSE(laserShot.hasMadeImpact());

    // 4. Check that the target has not been damaged.
    EXPECT_EQ(asteroid.getDensity(), density);
}

/**
 * A laser shot is in bounds and hits its target while in bounds.
 */
TEST_F(LaserShotTest, tickTargetImpactInBounds) {
    int x = 0;
    Point asteroidPosition = {x, 300};
    int asteroidSpeed = 10;
    int asteroidRadius = 10;
    Asteroid asteroid(asteroidPosition, asteroidRadius, density, asteroidSpeed);

    Point laserShotPosition = {x, asteroidPosition.y - asteroidRadius - asteroidSpeed - LASER_SHOT_SPEED - LASER_SHOT_LENGTH + 1};
    LaserShot laserShot(laserShotPosition, power);
    laserShot.setTarget(&asteroid);
    laserShot.tick();

    // 1. Check that center is updated correctly.
    Point expected = {x, asteroidPosition.y - asteroidSpeed - LASER_SHOT_LENGTH};
    EXPECT_EQ(laserShot.getPosition(), expected);

    // 2. Check that laser shot has made impact.
    EXPECT_TRUE(laserShot.hasMadeImpact());

    // 3. Check that asteroid has been damaged.
    EXPECT_NE(asteroid.getDensity(), density);
}

/**
 * A laser shot is in bounds and has a target. The laser shot does not hit the target but it does go out of bounds.
 */
TEST_F(LaserShotTest, tickTargetNoImpactOutOfBounds) {
    int x = 0;
    Point asteroidPosition = {x, terminus + 100};
    int asteroidSpeed = 5;
    int asteroidRadius = 5;
    Asteroid asteroid(asteroidPosition, asteroidRadius, density, asteroidSpeed);

    Point laserShotPosition = {x, terminus - 1};
    LaserShot laserShot(laserShotPosition, power);
    laserShot.setTarget(&asteroid);
    laserShot.tick();

    // 1. Check that the laser shot is out of bounds.
    EXPECT_FALSE(laserShot.isInBounds());

    // 2. Check that the laser shot has not made impact.
    EXPECT_FALSE(laserShot.hasMadeImpact());

    // 3. Check that the target has not been damaged.
    EXPECT_EQ(asteroid.getDensity(), density);
}

/**
 * A laser shot is in bounds and has a target. The laser shot hits the target out of bounds.
 *
 * The laser shot does not move as a result of asteroid's movement.
 */
TEST_F(LaserShotTest, tickTargetImpactOutOfBounds) {
    int x = 0;
    Point asteroidPosition = {x, terminus + 10};
    int asteroidSpeed = 5;
    int asteroidRadius = 5;
    Asteroid asteroid(asteroidPosition, asteroidRadius, density, asteroidSpeed);

    Point laserShotPosition = {x, terminus - 1};
    LaserShot laserShot(laserShotPosition, power);
    laserShot.setTarget(&asteroid);
    laserShot.tick();

    // 1. Check that center is updated correctly.
    EXPECT_EQ(laserShot.getPosition(), laserShotPosition);

    // 2. Check that laser shot is not marked as out of bounds.
    EXPECT_TRUE(laserShot.isInBounds());

    // 3. Check that laser shot has made impact.
    EXPECT_TRUE(laserShot.hasMadeImpact());

    // 4. Check that the asteroid has been damaged.
    EXPECT_NE(asteroid.getDensity(), density);
}




