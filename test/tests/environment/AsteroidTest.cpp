//
// Created by aday on 11/21/2016.
//

#include "../../../src/common/Point.h"
#include "../../../src/environment/Asteroid.h"
#include "gtest/gtest.h"

class AsteroidTest : public testing::Test {
protected:
    Point position = {50, 100};
    int radius = 10;
    int density = 50;
    int speed = 20;
};

/**
 * Check position is updated on tick.
 */
TEST_F(AsteroidTest, tickCheckPosition) {
    Asteroid asteroid(position, radius, density, speed);
    asteroid.tick();
    int expected = position.y - speed;
    EXPECT_EQ(asteroid.getX(), position.x);
    EXPECT_EQ(asteroid.getY(), expected);
}

/**
 * Check asteroid is still in bounds on tick.
 */
TEST_F(AsteroidTest, tickCheckInBounds) {
    Asteroid asteroid(position, radius, density, speed);
    asteroid.tick();
    ASSERT_TRUE(asteroid.isInBounds());
}

/**
 * One tick puts the asteroid in the last position before going out of bounds.
 */
TEST_F(AsteroidTest, tickCheckAlmostOutOfBounds) {
    int customSpeed = position.y + radius;
    Asteroid asteroid(position, radius, density, customSpeed);
    asteroid.tick();
    ASSERT_TRUE(asteroid.isInBounds());
}

/**
 * One tick puts the asteroid in the first position out of bounds.
 */
TEST_F(AsteroidTest, tickCheckOutOfBounds) {
    int customSpeed = position.y + radius + 1;
    Asteroid asteroid(position, radius, density, customSpeed);
    asteroid.tick();
    ASSERT_FALSE(asteroid.isInBounds());
}

/**
 * Check that density is updated when hit by laser.
 */
TEST_F(AsteroidTest, hitCheckDensity) {
    int power = 10;
    Asteroid asteroid(position, radius, density, speed);
    asteroid.hit(power);
    int expected = density - power;
    ASSERT_EQ(asteroid.getDensity(), expected);
}

/**
 * Check that asteroid has not exploded after being hit by laser.
 */
TEST_F(AsteroidTest, hitNotExploded) {
    Asteroid asteroid(position, radius, density, speed);
    asteroid.hit(10);
    ASSERT_FALSE(asteroid.hasExploded());
}

/**
 * Check that asteroid has exploded after being hit by laser.
 */
TEST_F(AsteroidTest, hitExploded) {
    Asteroid asteroid(position, radius, density, speed);
    asteroid.hit(density);
    ASSERT_TRUE(asteroid.hasExploded());
}

/**
 * Check inclusive left bound is correct.
 */
TEST_F(AsteroidTest, getLeftBound) {
    Asteroid asteroid(position, radius, density, speed);
    ASSERT_EQ(asteroid.getLeftBound(), position.x - radius);
}

/**
 * Check inclusive lower bound is correct.
 */
TEST_F(AsteroidTest, getLowerBound) {
    Asteroid asteroid(position, radius, density, speed);
    ASSERT_EQ(asteroid.getLowerBound(), position.y - radius);
}

/**
 * Check exclusive right bound is correct.
 */
TEST_F(AsteroidTest, getRightBound) {
    Asteroid asteroid(position, radius, density, speed);
    ASSERT_EQ(asteroid.getRightBound(), position.x + radius + 1);
}

/**
 * Check exclusive upper bound is correct.
 */
TEST_F(AsteroidTest, getUpperBound) {
    Asteroid asteroid(position, radius, density, speed);
    ASSERT_EQ(asteroid.getUpperBound(), position.y + radius + 1);
}

/**
 * Point is the asteroid's center. Squared distance to center should be zero.
 */
TEST_F(AsteroidTest, getSquaredDistanceToCenterPointIsCenter) {
    Asteroid asteroid = Asteroid(position, radius, density, speed);
    ASSERT_EQ(asteroid.getSquaredDistanceToCenter(position), 0);
}

/**
 * Points are on the edge of the asteroid.
 */
TEST_F(AsteroidTest, getSquaredDistanceToCenterPointsOnEdge) {
    Point customPosition = {0, 0};
    int customRadius = 3;
    Asteroid asteroid(customPosition, customRadius, density, speed);

    // quadrant 1
    EXPECT_EQ(asteroid.getSquaredDistanceToCenter({3, 1}), 10);
    EXPECT_EQ(asteroid.getSquaredDistanceToCenter({2, 2}), 8);

    // quadrant 2
    EXPECT_EQ(asteroid.getSquaredDistanceToCenter({-3, 1}), 10);
    EXPECT_EQ(asteroid.getSquaredDistanceToCenter({-2, 2}), 8);

    // quadrant 3
    EXPECT_EQ(asteroid.getSquaredDistanceToCenter({-3, -1}), 10);
    EXPECT_EQ(asteroid.getSquaredDistanceToCenter({-2, -2}), 8);

    // quadrant 4
    EXPECT_EQ(asteroid.getSquaredDistanceToCenter({3, -1}), 10);
    EXPECT_EQ(asteroid.getSquaredDistanceToCenter({2, -2}), 8);
}

/**
 * Point is asteroid's center.
 */
TEST_F(AsteroidTest, getDistanceToEdgeCenter) {
    Asteroid asteroid(position, radius, density, speed);
    ASSERT_EQ(asteroid.getDistanceToEdge(position), Asteroid::INTERNAL);
}

/**
 * Boundary test of getting distance from edge of asteroid. All these points are one point to the interior of the edge
 * of the asteroid. For each point, the distance should return the constant indicating the point is interior.
 */
TEST_F(AsteroidTest, getDistanceToEdgeInteriorPoints) {
    Point customPosition = {0, 0};
    int customRadius = 3;
    Asteroid asteroid(customPosition, customRadius, density, speed);

    // quadrant 1
    EXPECT_EQ(asteroid.getDistanceToEdge({2, 0}), Asteroid::INTERNAL);
    EXPECT_EQ(asteroid.getDistanceToEdge({2, 1}), Asteroid::INTERNAL);
    EXPECT_EQ(asteroid.getDistanceToEdge({1, 2}), Asteroid::INTERNAL);

    // quadrant 2
    EXPECT_EQ(asteroid.getDistanceToEdge({0, 2}), Asteroid::INTERNAL);
    EXPECT_EQ(asteroid.getDistanceToEdge({-1, 2}), Asteroid::INTERNAL);
    EXPECT_EQ(asteroid.getDistanceToEdge({-2, 1}), Asteroid::INTERNAL);

    // quadrant 3
    EXPECT_EQ(asteroid.getDistanceToEdge({-2, 0}), Asteroid::INTERNAL);
    EXPECT_EQ(asteroid.getDistanceToEdge({-2, -1}), Asteroid::INTERNAL);
    EXPECT_EQ(asteroid.getDistanceToEdge({-1, -2}), Asteroid::INTERNAL);

    // quadrant 4
    EXPECT_EQ(asteroid.getDistanceToEdge({0, -2}), Asteroid::INTERNAL);
    EXPECT_EQ(asteroid.getDistanceToEdge({1, -2}), Asteroid::INTERNAL);
    EXPECT_EQ(asteroid.getDistanceToEdge({2, -1}), Asteroid::INTERNAL);
}

/**
 * Boundary test of getting distance from edge of asteroid. All these points are one point to the exterior of the edge
 * of the asteroid. For each point, the distance should return something greater than or equal to zero, since floor of
 * square root is used.
 */
TEST_F(AsteroidTest, getDistanceToEdgeExteriorPoints) {
    Point customPosition = {0, 0};
    int customRadius = 3;
    Asteroid asteroid(customPosition, customRadius, density, speed);

    // quadrant 1
    EXPECT_TRUE(asteroid.getDistanceToEdge({4, 0}) >= 0);
    EXPECT_TRUE(asteroid.getDistanceToEdge({4, 1}) >= 0);
    EXPECT_TRUE(asteroid.getDistanceToEdge({4, 2}) >= 0);
    EXPECT_TRUE(asteroid.getDistanceToEdge({3, 2}) >= 0);
    EXPECT_TRUE(asteroid.getDistanceToEdge({3, 3}) >= 0);
    EXPECT_TRUE(asteroid.getDistanceToEdge({2, 3}) >= 0);
    EXPECT_TRUE(asteroid.getDistanceToEdge({2, 4}) >= 0);
    EXPECT_TRUE(asteroid.getDistanceToEdge({1, 4}) >= 0);

    // quadrant 2
    EXPECT_TRUE(asteroid.getDistanceToEdge({0, 4}) >= 0);
    EXPECT_TRUE(asteroid.getDistanceToEdge({-1, 4}) >= 0);
    EXPECT_TRUE(asteroid.getDistanceToEdge({-2, 4}) >= 0);
    EXPECT_TRUE(asteroid.getDistanceToEdge({-2, 3}) >= 0);
    EXPECT_TRUE(asteroid.getDistanceToEdge({-3, 3}) >= 0);
    EXPECT_TRUE(asteroid.getDistanceToEdge({-3, 2}) >= 0);
    EXPECT_TRUE(asteroid.getDistanceToEdge({-4, 2}) >= 0);
    EXPECT_TRUE(asteroid.getDistanceToEdge({-4, 1}) >= 0);

    // quadrant 3
    EXPECT_TRUE(asteroid.getDistanceToEdge({-4, 0}) >= 0);
    EXPECT_TRUE(asteroid.getDistanceToEdge({-4, -1}) >= 0);
    EXPECT_TRUE(asteroid.getDistanceToEdge({-4, -2}) >= 0);
    EXPECT_TRUE(asteroid.getDistanceToEdge({-3, -2}) >= 0);
    EXPECT_TRUE(asteroid.getDistanceToEdge({-3, -3}) >= 0);
    EXPECT_TRUE(asteroid.getDistanceToEdge({-2, -3}) >= 0);
    EXPECT_TRUE(asteroid.getDistanceToEdge({-2, -4}) >= 0);
    EXPECT_TRUE(asteroid.getDistanceToEdge({-1, -4}) >= 0);

    // quadrant 4
    EXPECT_TRUE(asteroid.getDistanceToEdge({0, -4}) >= 0);
    EXPECT_TRUE(asteroid.getDistanceToEdge({1, -4}) >= 0);
    EXPECT_TRUE(asteroid.getDistanceToEdge({2, -4}) >= 0);
    EXPECT_TRUE(asteroid.getDistanceToEdge({2, -3}) >= 0);
    EXPECT_TRUE(asteroid.getDistanceToEdge({3, -3}) >= 0);
    EXPECT_TRUE(asteroid.getDistanceToEdge({3, -2}) >= 0);
    EXPECT_TRUE(asteroid.getDistanceToEdge({4, -2}) >= 0);
    EXPECT_TRUE(asteroid.getDistanceToEdge({4, -1}) >= 0);
}

/**
 * Point is outside asteroid.
 *
 * Test pi/4, 3pi/4, 7pi/4, and 11pi/4 angles.
 */
TEST_F(AsteroidTest, getDistanceToEdgeFarExterior) {
    int customRadius = 5;
    int x = 16;
    int y = 12;
    int expected = 15;
    Asteroid asteroid(position, customRadius, density, speed);

    Point quadrant1 = {position.x + x, position.y + y};
    EXPECT_EQ(asteroid.getDistanceToEdge(quadrant1), expected);

    Point quadrant2 = {position.x - x, position.y + y};
    EXPECT_EQ(asteroid.getDistanceToEdge(quadrant2), expected);

    Point quadrant3 = {position.x - x, position.y - y};
    EXPECT_EQ(asteroid.getDistanceToEdge(quadrant3), expected);

    Point quadrant4 = {position.x + x, position.y - y};
    EXPECT_EQ(asteroid.getDistanceToEdge(quadrant4), expected);
}























