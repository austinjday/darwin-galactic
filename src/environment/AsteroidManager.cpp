//
// Created by austin on 4/8/2017.
//

#include <cassert>
#include "AsteroidManager.h"

int AsteroidManager::randomRadius() {
    double result = radiusDistribution(generator);
    return (int) std::floor(result);
}

int AsteroidManager::randomClearance() {
    double result = clearanceDistribution(generator);
    return (int) std::floor(result);
}

int AsteroidManager::randomInRange(int elements) {
    std::uniform_int_distribution<> distribution(0, elements - 1);
    return distribution(generator);
}

AsteroidManager::AsteroidManager() {
    maxDimension = 0;
}

AsteroidManager::AsteroidManager(int length, int width) {
    maxDimension = length > width ? length : width;
    clearanceDistribution = std::normal_distribution<double> ((double) MEAN_ASTEROID_CLEARANCE, (double) ASTEROID_CLEARANCE_STD_DEV);
    radiusDistribution = std::normal_distribution<double> ((double) MEAN_ASTEROID_RADIUS, (double) ASTEROID_RADIUS_STD_DEV);
    srand((unsigned) time(NULL));
    generator = std::mt19937((unsigned) rand());
}

void AsteroidManager::generateAsteroidInRange(Point begin, Point end, int interval) {

    // create a list of randomly generated potential asteroid spacial profiles (at most one spacial profile per point in
    // range)
    std::vector<std::pair<Point, int>> asteroidSpacialProfiles;
    int offset = randomInRange(interval);

    // give the interval an offset
    begin.x == end.x ? begin.y += offset : begin.x += offset;

    /*
     * This for-loop works for both vertical and horizontal ranges. With equal x-values for begin and end, will iterate
     * over y-range. With equal y-values, will iterate over x-range.
     */
    for (Point point = begin; point.x <= end.x && point.y <= end.y; begin.x == end.x ? point.y += interval : point.x += interval) {
        int distanceToNearestAsteroid = getDistanceToNearestAsteroid(point);

        // only consider this point if it is possible for the smallest allowable asteroid to fit there
        if (MIN_ASTEROID_RADIUS + MIN_ASTEROID_CLEARANCE < distanceToNearestAsteroid) {

            // maximum allowable radius for this point
            int maxAllowableRadius = distanceToNearestAsteroid - MIN_ASTEROID_CLEARANCE;

            // get a random radius and its clearance
            int radius = randomRadius();
            int clearance = distanceToNearestAsteroid - radius;

            // get the minimum allowable clearance
            int acceptableClearance = randomClearance();
            if (acceptableClearance < MIN_ASTEROID_CLEARANCE) {
                acceptableClearance = MEAN_ASTEROID_CLEARANCE;
            }

            /*
             * Create an asteroid spacial profile if both the following hold:
             * radius is within bounds
             * clearance is not less than the minimum allowable
             */
            if (radius >= MIN_ASTEROID_RADIUS && radius <= maxAllowableRadius && clearance >= acceptableClearance) {
                if (rand() % 30 == 17) {
                    std::cout << clearance << std::endl;
                }
                asteroidSpacialProfiles.push_back(std::make_pair(point, radius));
            }
        }
    }

    // pick a spacial profile to create
    if (!asteroidSpacialProfiles.empty()) {
        int idx = randomInRange(asteroidSpacialProfiles.size());
        asteroids.insert(std::make_shared<Asteroid>(asteroidSpacialProfiles[idx], BASE_ASTEROID_SPEED));
    }
}

void AsteroidManager::updateAsteroids() {
    for (auto it = asteroids.begin(); it != asteroids.end();) {
        auto current = it++;
        (*current)->tick();
        if (!(*current)->isValid()) {
            asteroids.erase(current);
        }
    }
}

int AsteroidManager::getDistanceToNearestAsteroid(Point point) const {
    int shortestDistance = maxDimension * 2;
    for (auto it = asteroids.begin(); it != asteroids.end() && shortestDistance > 0; it++) {
        int current = (*it)->getDistanceToEdge(point);
        if (current < shortestDistance) {
            shortestDistance = current;
        }
    }
    return shortestDistance;
}

std::shared_ptr<Asteroid> AsteroidManager::getClosestAsteroidInPath(int leftInclusive, int rightExclusive) const {
    assert(leftInclusive < rightExclusive);
    std::shared_ptr<Asteroid> closest;
    for (auto it = asteroids.begin(); it != asteroids.end(); it++) {
        if (rightExclusive > (*it)->getLeftBound() && leftInclusive < (*it)->getRightBound()) {
            // the asteroid is in this path
            if (closest.use_count() == 0 || (*it)->getY() < closest->getY()) {
                closest = *it;
            }
        }
    }
    return closest;
}

std::pair<std::unordered_set<std::shared_ptr<Asteroid>>::const_iterator, std::unordered_set<std::shared_ptr<Asteroid>>::const_iterator> AsteroidManager::its() const {
    return std::make_pair<>(asteroids.begin(), asteroids.end());
};
