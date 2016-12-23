//
// Created by aday on 10/14/2016.
//

#ifndef DARWINGALACTIC_CONSTANTS_H
#define DARWINGALACTIC_CONSTANTS_H

// body mass
static const int SHIP_BODY_DENSITY = 4;

// thruster mass
static const int THRUSTER_DENSITY = 8;
static const int MAX_FORCE_OUTPUT_PER_AREA = 2;

// laser mass
static const int MASS_PER_FIRE_RATE = 4;
static const int MASS_PER_FIREPOWER = 4;
static const int LASER_BASE_MASS = 10;

// laser shot properties
static const int LASER_SHOT_LENGTH = 10;
static const int LASER_SHOT_WIDTH = 4;
static const int LASER_SHOT_SPEED = 20;

// scanner mass
static const int MASS_PER_ACCURACY = 4;
static const int MASS_PER_RANGE = 4;
static const int VISUAL_SCANNER_BASE_MASS = 4;
static const int RADAR_SCANNER_BASE_MASS = 8;
static const int DENSITY_SCANNER_BASE_MASS = 12;

// asteroid constraints
static const int BASE_ASTEROID_SPEED = 4;
static const int MIN_ASTEROID_DENSITY = 5;
static const int MAX_ASTEROID_DENSITY = 100;
static const int MIN_ASTEROID_RADIUS = 2;
static const int MAX_ASTEROID_RADIUS = 100;
static const int ASTEROID_RADIUS_RANGE = MAX_ASTEROID_RADIUS - MIN_ASTEROID_RADIUS;
static const int MIN_ASTEROID_CLEARANCE = 15;
static const int AVERAGE_ASTEROID_CLEARANCE = 300;

// ship constraints
static const int MIN_BODY_WIDTH = 10;
static const int MAX_BODY_WIDTH = 100;
static const int MIN_BODY_HEIGHT = 30;
static const int MAX_BODY_HEIGHT = 300;

// laser constraints
static const int MIN_FIRE_RATE = 1;
static const int MAX_FIRE_RATE = 100;
static const int MIN_FIREPOWER = 1;
static const int MAX_FIREPOWER = 100;

// thruster constraints
static const int MIN_FORCE_OUTPUT = 1;
static const int MAX_FORCE_OUTPUT = 10;
static const int MIN_X_THRUSTER_POSITION = 0;
static const int MAX_X_THRUSTER_POSITION = 50;

// scanner constraints
static const int MIN_ERROR = 0;
static const int MAX_ERROR = 30;
static const int MIN_RANGE = 200;
static const int MAX_RANGE = 1000;


#endif //DARWINGALACTIC_CONSTANTS_H
