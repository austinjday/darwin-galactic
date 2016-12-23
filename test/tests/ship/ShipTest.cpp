//
// Created by aday on 11/22/2016.
//

#include "../../../src/ship/Ship.h"
#include "gtest/gtest.h"
#include "../../../src/common/Constants.h"

class ShipTest : public testing::Test {
protected:
    int bodyLength = 100;
    int bodyWidth = 50;

    int thrusterLength = 30;
    int thrusterWidth = 30;
    int thrusterPosition = 10;

    int radius = 30;
    int density = 50;
    int asteroidSpeed = 15;

    int minimumThrusterPosition = 0;

    int laserPosition = 30;
    int fireRate = 10;
    int firepower = 10;
    int laserLength = 20;
    int laserWidth = 4;

    int forceOutput = 2;
};

/**
 * Add equipment to a ship and check that mass is updated correctly for each item added.
 *
 * Then remove each item and make sure mass is updated.
 */
TEST_F(ShipTest, massAccumulation) {
    Ship ship = Ship(bodyLength, bodyWidth);
    int mass = bodyLength * bodyWidth * SHIP_BODY_DENSITY;
    ASSERT_EQ(ship.getMass(), mass);

    Thruster leftThruster = Thruster(thrusterPosition, thrusterLength, thrusterWidth);
    ship.setLeftThruster(&leftThruster);
    mass += leftThruster.getMass();
    ASSERT_EQ(ship.getMass(), mass);

    Thruster rightThruster = Thruster(thrusterPosition, thrusterLength, thrusterWidth);
    ship.setRightThruster(&rightThruster);
    mass += rightThruster.getMass();
    ASSERT_EQ(ship.getMass(), mass);

    Laser laser = Laser(fireRate, firepower, laserPosition, laserLength, laserWidth);
    ship.setLaser(&laser);
    mass += laser.getMass();
    ASSERT_EQ(ship.getMass(), mass);

    ship.removeLeftThruster();
    mass -= leftThruster.getMass();
    ASSERT_EQ(ship.getMass(), mass);

    ship.removeRightThruster();
    mass -= rightThruster.getMass();
    ASSERT_EQ(ship.getMass(), mass);

    ship.removeLaser();
    mass -= laser.getMass();
    ASSERT_EQ(ship.getMass(), mass);
}

/**
 * Give the ship a force output and check that speed and position respond correctly for a few ticks.
 *
 * Then reverse the force output, do one tick, and check speed and position.
 *
 * Finally set force output to zero and check that ship glides.
 */
TEST_F(ShipTest, tickMotionCheckSpeed) {
    Ship ship = Ship(bodyLength, bodyWidth);
    int speed = 0;
    Point position = ship.getPosition();

    ship.setForceOutput(forceOutput);
    ASSERT_EQ(ship.getSpeed(), speed);
    ASSERT_EQ(ship.getPosition(), position);

    ship.tickMotion();
    speed += forceOutput;
    ASSERT_EQ(ship.getSpeed(), speed);
    ASSERT_EQ(ship.getPosition(), position);

    ship.tickMotion();
    position.x += speed;
    speed += forceOutput;
    ASSERT_EQ(ship.getSpeed(), speed);
    ASSERT_EQ(ship.getPosition(), position);

    ship.setForceOutput(forceOutput * -1);
    ship.tickMotion();
    position.x += speed;
    speed -= forceOutput;
    ASSERT_EQ(ship.getSpeed(), speed);
    ASSERT_EQ(ship.getPosition(), position);

    ship.setForceOutput(0);
    ship.tickMotion();
    position.x += speed;
    ASSERT_EQ(ship.getSpeed(), speed);
    ASSERT_EQ(ship.getPosition(), position);

    ship.tickMotion();
    position.x += speed;
    ASSERT_EQ(ship.getSpeed(), speed);
    ASSERT_EQ(ship.getPosition(), position);

    ship.tickMotion();
    position.x += speed;
    ASSERT_EQ(ship.getSpeed(), speed);
    ASSERT_EQ(ship.getPosition(), position);
}

/**
 * Left bound of the ship without any equipment.
 */
TEST_F(ShipTest, leftBoundNoEquipment) {
    Ship ship = Ship(bodyLength, bodyWidth);
    ASSERT_EQ(ship.getLeftBound(), ship.getX());
}

/**
 * Left bound of the ship with a left thruster.
 */
TEST_F(ShipTest, leftBoundWithLeftThruster) {
    Thruster leftThruster = Thruster(thrusterPosition, thrusterLength, thrusterWidth);
    Ship ship = Ship(bodyLength, bodyWidth);
    ship.setLeftThruster(&leftThruster);
    ASSERT_EQ(ship.getLeftBound(), ship.getX() - thrusterWidth);
}

/**
 * Right bound of the ship without any equipment.
 */
TEST_F(ShipTest, rightBoundNoEquipment) {
    Ship ship = Ship(bodyLength, bodyWidth);
    ASSERT_EQ(ship.getRightBound(), ship.getX() + bodyWidth);
}

/**
 * Right bound of the ship with a right thruster.
 */
TEST_F(ShipTest, rightBoundWithRightThruster) {
    Thruster rightThruster = Thruster(thrusterPosition, thrusterLength, thrusterWidth);
    Ship ship = Ship(bodyLength, bodyWidth);
    ship.setRightThruster(&rightThruster);
    ASSERT_EQ(ship.getRightBound(), ship.getX() + bodyWidth + thrusterWidth);
}

/**
 * Upper bound of the ship without any equipment.
 */
TEST_F(ShipTest, upperBoundNoEquipment) {
    Ship ship = Ship(bodyLength, bodyWidth);
    ASSERT_EQ(ship.getUpperBound(), ship.getY() + bodyLength);
}

/**
 * Upper bound of the ship with a laser.
 */
TEST_F(ShipTest, upperBoundWithLaser) {
    Laser laser = Laser(fireRate, firepower, laserPosition, laserLength, laserWidth);
    Ship ship = Ship(bodyLength, bodyWidth);
    ship.setLaser(&laser);
    ASSERT_EQ(ship.getUpperBound(), ship.getY() + bodyLength + laserLength);
}

/**
 * Lower bound of the ship without any equipment.
 */
TEST_F(ShipTest, lowerBoundNoEquipment) {
    Ship ship = Ship(bodyLength, bodyWidth);
    ASSERT_EQ(ship.getLowerBound(), ship.getY());
}

/**
 * Lower bound of the ship with both thrusters set to lowest position.
 */
TEST_F(ShipTest, lowerBoundWithEquipment) {
    Thruster leftThruster = Thruster(minimumThrusterPosition, thrusterLength, thrusterWidth);
    Thruster rightThruster = Thruster(minimumThrusterPosition, thrusterLength, thrusterWidth);
    Ship ship = Ship(bodyLength, bodyWidth);
    ship.setLeftThruster(&leftThruster);
    ship.setRightThruster(&rightThruster);
    ASSERT_EQ(ship.getLowerBound(), ship.getY());
}

/**
 * A ship has no equipment. There is an asteroid immediately to the left of the ship. The ship should be intact after
 * handling contact.
 */
TEST_F(ShipTest, handleContactNoEquipmentAsteroidOnLeftNoContact) {
    Ship ship = Ship(bodyLength, bodyWidth);
    Point asteroidPosition = {ship.getLeftBound() - radius, 0};
    Asteroid asteroid = Asteroid(asteroidPosition, radius, density, asteroidSpeed);
    ship.handleContact(&asteroid);
    ASSERT_TRUE(ship.isIntact());
}

/**
 * A ship has no equipment. There is an asteroid immediately to the right of the ship. The ship should be intact after
 * handling contact.
 */
TEST_F(ShipTest, handleContactNoEquipmentAsteroidOnRightNoContact) {
    Ship ship = Ship(bodyLength, bodyWidth);
    Point asteroidPosition = {ship.getRightBound() + radius , 0};
    Asteroid asteroid = Asteroid(asteroidPosition, radius, density, asteroidSpeed);
    ship.handleContact(&asteroid);
    ASSERT_TRUE(ship.isIntact());
}

/**
 * A ship has no equipment. There is an asteroid immediately above the ship. The ship should be intact after handling
 * contact.
 */
TEST_F(ShipTest, handleContactNoEquipmentAsteroidAboveNoContact) {
    Ship ship = Ship(bodyLength, bodyWidth);
    Point asteroidPosition = {0, ship.getUpperBound() + radius};
    Asteroid asteroid = Asteroid(asteroidPosition, radius, density, asteroidSpeed);
    ship.handleContact(&asteroid);
    ASSERT_TRUE(ship.isIntact());
}

/**
 * A ship has no equipment. There is an asteroid immediately below the ship. The ship should be intact after handling
 * contact.
 */
TEST_F(ShipTest, handleContactNoEquipmentAsteroidBelowNoContact) {
    Ship ship = Ship(bodyLength, bodyWidth);
    Point asteroidPosition = {0, ship.getLowerBound() - radius};
    Asteroid asteroid = Asteroid(asteroidPosition, radius, density, asteroidSpeed);
    ship.handleContact(&asteroid);
    ASSERT_TRUE(ship.isIntact());
}

/**
 * A ship has no equipment. There is an asteroid immediately above and to the right of the ship. If the asteroid were
 * bound by a square, the ship would be making contact, but due to the tight circular binding, there is no contact.
 */
TEST_F(ShipTest, handleContactNoEquipmentAsteroidAboveAndRightNoContact) {
    Ship ship = Ship(bodyLength, bodyWidth);
    int customRadius = 10;
    Point asteroidPosition = {ship.getRightBound() + 6, ship.getUpperBound() + 8};
    Asteroid asteroid = Asteroid(asteroidPosition, customRadius, density, asteroidSpeed);
    ship.handleContact(&asteroid);
    ASSERT_TRUE(ship.isIntact());
}

/**
 * A ship has no equipment. There is an asteroid immediately above and to the right of the ship (but overlapping on the
 * very corner). If the asteroid were bound any more to the inside of the circle, the ship would NOT be making contact,
 * but due to the tight circular binding, there is no contact.
 */
TEST_F(ShipTest, handleContactNoEquipmentAsteroidAboveAndRightContactWithBody) {
    Ship ship = Ship(bodyLength, bodyWidth);
    int customRadius = 10;
    Point asteroidPosition = {ship.getRightBound() + 7, ship.getUpperBound() + 7};
    Asteroid asteroid = Asteroid(asteroidPosition, customRadius, density, asteroidSpeed);
    ship.handleContact(&asteroid);
    ASSERT_FALSE(ship.isIntact());
}

/**
 * A ship has no equipment. There is an asteroid touching it. The ship should not be intact after handling contact.
 */
TEST_F(ShipTest, handleContactNoEquipmentAsteroidTouchingContactWithBody) {
    Ship ship = Ship(bodyLength, bodyWidth);
    Asteroid asteroid = Asteroid(ship.getPosition(), radius, density, asteroidSpeed);
    ship.handleContact(&asteroid);
    ASSERT_FALSE(ship.isIntact());
}

/**
 * A ship has a laser. There is an asteroid immediately above the laser. The ship and laser should be intact after
 * handling contact.
 */
TEST_F(ShipTest, handleContactLaserAsteroidAboveNoContact) {
    Laser laser = Laser(fireRate, firepower, laserPosition, laserLength, laserWidth);
    Ship ship = Ship(bodyLength, bodyWidth);
    ship.setLaser(&laser);
    Point asteroidPosition = {ship.getX() + laserPosition, ship.getUpperBound() + radius};
    Asteroid asteroid = Asteroid(asteroidPosition, radius, density, asteroidSpeed);
    ship.handleContact(&asteroid);
    EXPECT_TRUE(ship.isIntact());
    EXPECT_TRUE(ship.laserIsIntact());
}

/**
 * A ship has a laser. There is an asteroid touching the laser but not the ship body. The ship should be intact after
 * handling contact but the laser should not be.
 */
TEST_F(ShipTest, handleContactLaserAsteroidAboveContactWithLaser) {
    Laser laser = Laser(fireRate, firepower, laserPosition, laserLength, laserWidth);
    Ship ship = Ship(bodyLength, bodyWidth);
    ship.setLaser(&laser);
    Point asteroidPosition = {ship.getX() + laserPosition, ship.getUpperBound() + radius - 1};
    Asteroid asteroid = Asteroid(asteroidPosition, radius, density, asteroidSpeed);
    ship.handleContact(&asteroid);
    EXPECT_TRUE(ship.isIntact());
    EXPECT_FALSE(ship.laserIsIntact());
}

/**
 * A ship has a left thruster. There is an asteroid immediately to the left of the left thruster. The ship and thruster
 * should be intact after handling contact.
 */
TEST_F(ShipTest, handleContactLeftThrusterAsteroidOnLeftNoContact) {
    Thruster leftThruster = Thruster(thrusterPosition, thrusterLength, thrusterWidth);
    Ship ship = Ship(bodyLength, bodyWidth);
    ship.setLeftThruster(&leftThruster);
    Point asteroidPosition = {ship.getLeftBound() - radius, thrusterPosition};
    Asteroid asteroid = Asteroid(asteroidPosition, radius, density, asteroidSpeed);
    ship.handleContact(&asteroid);
    EXPECT_TRUE(ship.isIntact());
    EXPECT_TRUE(ship.leftThrusterIsIntact());
}

/**
 * A ship has a left thruster. There is an asteroid touching the thruster but not the ship body. The ship should be
 * intact after handling contact but the left thruster should be destroyed.
 */
TEST_F(ShipTest, handleContactLeftThrusterAsteroidOnLeftContactWithThruster) {
    Thruster leftThruster = Thruster(thrusterPosition, thrusterLength, thrusterWidth);
    Ship ship = Ship(bodyLength, bodyWidth);
    ship.setLeftThruster(&leftThruster);
    Point asteroidPosition = {ship.getLeftBound() - radius + 1, thrusterPosition};
    Asteroid asteroid = Asteroid(asteroidPosition, radius, density, asteroidSpeed);
    ship.handleContact(&asteroid);
    EXPECT_TRUE(ship.isIntact());
    EXPECT_FALSE(ship.leftThrusterIsIntact());
}

/**
 * A ship has a right thruster. There is an asteroid immediately to the right of the right thruster. The ship and
 * thruster should be intact after handling contact.
 */
TEST_F(ShipTest, handleContactRightThrusterAsteroidOnRightNoContact) {
    Thruster rightThruster = Thruster(thrusterPosition, thrusterLength, thrusterWidth);
    Ship ship = Ship(bodyLength, bodyWidth);
    ship.setRightThruster(&rightThruster);
    Point asteroidPosition = {ship.getRightBound() + radius, thrusterPosition};
    Asteroid asteroid = Asteroid(asteroidPosition, radius, density, asteroidSpeed);
    ship.handleContact(&asteroid);
    EXPECT_TRUE(ship.isIntact());
    EXPECT_TRUE(ship.rightThrusterIsIntact());
}

/**
 * A ship has a right thruster. There is an asteroid touching the thruster but not the ship body. The ship should be
 * intact after handling contact but the right thruster should be destroyed.
 */
TEST_F(ShipTest, handleContactRightThrusterAsteroidOnRightContactWithThruster) {
    Thruster rightThruster = Thruster(thrusterPosition, thrusterLength, thrusterWidth);
    Ship ship = Ship(bodyLength, bodyWidth);
    ship.setRightThruster(&rightThruster);
    Point asteroidPosition = {ship.getRightBound() + radius - 1, thrusterPosition};
    Asteroid asteroid = Asteroid(asteroidPosition, radius, density, asteroidSpeed);
    ship.handleContact(&asteroid);
    EXPECT_TRUE(ship.isIntact());
    EXPECT_FALSE(ship.rightThrusterIsIntact());
}

/**
 * A ship has all equipment. There is an asteroid touching the body. The ship should not be intact after handling
 * contact. It doesn't matter if the equipment is intact or not.
 */
TEST_F(ShipTest, handleContactAllEquipmentContactWithBody) {
    Thruster rightThruster = Thruster(thrusterPosition, thrusterLength, thrusterWidth);
    Thruster leftThruster = Thruster(thrusterPosition, thrusterLength, thrusterWidth);
    Laser laser = Laser(fireRate, firepower, laserPosition, laserLength, laserWidth);
    Ship ship = Ship(bodyLength, bodyWidth);
    ship.setLeftThruster(&leftThruster);
    ship.setRightThruster(&rightThruster);
    ship.setLaser(&laser);
    Asteroid asteroid = Asteroid(ship.getPosition(), radius, density, asteroidSpeed);
    ship.handleContact(&asteroid);
    ASSERT_FALSE(ship.isIntact());
}

/**
 * A ship has all equipment. There is an asteroid touching both the right thruster and laser. The ship should be intact
 * after contact but both the right thruster and the laser should be destroyed.
 */
TEST_F(ShipTest, handleContactAllEquipmentContactWithThrusterAndLaser) {
    Ship ship = Ship(bodyLength, bodyWidth);
    int customRadius = 10;
    Point asteroidPosition = {ship.getRightBound() + 6, ship.getUpperBound() + 8};
    Asteroid asteroid = Asteroid(asteroidPosition, customRadius, density, asteroidSpeed);

    Thruster rightThruster = Thruster(ship.getBodyLength() - thrusterLength, thrusterLength, thrusterWidth);
    Thruster leftThruster = Thruster(ship.getBodyLength() - thrusterLength, thrusterLength, thrusterWidth);
    Laser laser = Laser(fireRate, firepower, ship.getBodyWidth() - laserWidth, laserLength, laserWidth);
    ship.setLeftThruster(&leftThruster);
    ship.setRightThruster(&rightThruster);
    ship.setLaser(&laser);
    ship.handleContact(&asteroid);
    EXPECT_TRUE(ship.isIntact());
    EXPECT_TRUE(ship.leftThrusterIsIntact());
    EXPECT_FALSE(ship.rightThrusterIsIntact());
    EXPECT_FALSE(ship.laserIsIntact());
}

/**
 * A ship has all equipment. It is completely contained within an asteroid. The ship will not be intact after handling
 * contact.
 */
TEST_F(ShipTest, handleContactAllEquipmentShipIsCompletelyInsideAsteroid) {
    Thruster rightThruster = Thruster(0, 3, 3);
    Thruster leftThruster = Thruster(0, 3, 3);
    Laser laser = Laser(fireRate, firepower, 0, 3, 1);
    Ship ship = {10, 5};
    ship.setLeftThruster(&leftThruster);
    ship.setRightThruster(&rightThruster);
    ship.setLaser(&laser);
    Asteroid asteroid = Asteroid(ship.getPosition(), 30, density, asteroidSpeed);
    ship.handleContact(&asteroid);
    ASSERT_FALSE(ship.isIntact());
}
