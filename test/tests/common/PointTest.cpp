//
// Created by aday on 11/23/2016.
//

#include "../../../src/common/Point.h"
#include "gtest/gtest.h"

class PointTest : public testing::Test {
protected:
    Point point1 = {0, 0};
    Point point2 = {0, 0};
    Point point3 = {0, 5};
};

TEST_F(PointTest, identity) {
    ASSERT_TRUE(point1 == point1);
}

TEST_F(PointTest, equals) {
    ASSERT_TRUE(point1 == point2);
}

TEST_F(PointTest, notEquals) {
    ASSERT_TRUE(point2 != point3);
}

