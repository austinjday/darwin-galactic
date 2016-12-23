#include "../../../src/utility/IntegerMath.h"
#include "gtest/gtest.h"

class IntegerMathTest : public testing::Test {

};

TEST_F(IntegerMathTest, rootOfZero) {
    ASSERT_EQ(IntegerMath::squareRoot(0), 0);
}

TEST_F(IntegerMathTest, positives) {
    EXPECT_EQ(IntegerMath::squareRoot(1), 1);
    EXPECT_EQ(IntegerMath::squareRoot(2), 1);
    EXPECT_EQ(IntegerMath::squareRoot(3), 1);
    EXPECT_EQ(IntegerMath::squareRoot(4), 2);
    EXPECT_EQ(IntegerMath::squareRoot(5), 2);
    EXPECT_EQ(IntegerMath::squareRoot(6), 2);
    EXPECT_EQ(IntegerMath::squareRoot(7), 2);
    EXPECT_EQ(IntegerMath::squareRoot(8), 2);
    EXPECT_EQ(IntegerMath::squareRoot(9), 3);

    EXPECT_EQ(IntegerMath::squareRoot(9999), 99);
    EXPECT_EQ(IntegerMath::squareRoot(10000), 100);
    EXPECT_EQ(IntegerMath::squareRoot(10001), 100);

    EXPECT_EQ(IntegerMath::squareRoot(999999), 999);
    EXPECT_EQ(IntegerMath::squareRoot(1000000), 1000);
    EXPECT_EQ(IntegerMath::squareRoot(1000001), 1000);
}

TEST_F(IntegerMathTest, calculateTwice) {
    EXPECT_EQ(IntegerMath::squareRoot(40), 6);
    EXPECT_EQ(IntegerMath::squareRoot(40), 6);
}

TEST_F(IntegerMathTest, squareOfNegative) {
    EXPECT_EQ(IntegerMath::square(-1), 1);
    EXPECT_EQ(IntegerMath::square(-2), 4);
}

TEST_F(IntegerMathTest, squareOfZero) {
    EXPECT_EQ(IntegerMath::square(0), 0);
}

TEST_F(IntegerMathTest, squareOfPositive) {
    EXPECT_EQ(IntegerMath::square(1), 1);
    EXPECT_EQ(IntegerMath::square(2), 4);
    EXPECT_EQ(IntegerMath::square(10), 100);
    EXPECT_EQ(IntegerMath::square(1000), 1000000);
}

TEST_F(IntegerMathTest, absoluteValueOfZero) {
    ASSERT_EQ(IntegerMath::abs(0), 0);
}

TEST_F(IntegerMathTest, absoluteValueOfNegative) {
    ASSERT_EQ(IntegerMath::abs(-10), 10);
}

TEST_F(IntegerMathTest, absoluteValueOfPositive) {
    ASSERT_EQ(IntegerMath::abs(6306), 6306);
}



