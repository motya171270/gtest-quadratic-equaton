#ifndef FIBONACHI_H
#define FIBONACHI_H

#include <gtest/gtest.h>

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

extern "C" {
#include "qequation.h"
}

TEST(quadraticEquationTest, less0) {
    double x1, x2;
    int errorCode;
    solveQuadraticEquation(-3.0, 3.0, -3.0, &x1, &x2, &errorCode);
    ASSERT_EQ(errorCode, 1);
}
TEST(quadraticEquationTest, equal0) {
    double x1, x2;
    int errorCode;
    solveQuadraticEquation(3.0, 6.0, 3.0, &x1, &x2, &errorCode);
    ASSERT_DOUBLE_EQ(x1, -1.0);
    ASSERT_DOUBLE_EQ(x2, -1.0);
    ASSERT_EQ(errorCode, 0);
}
TEST(quadraticEquationTest, greater0) {
    double x1, x2;
    int errorCode;
    solveQuadraticEquation(1.0, 2.0, -3.0, &x1, &x2, &errorCode);
    ASSERT_DOUBLE_EQ(x1, 1.0);
    ASSERT_DOUBLE_EQ(x2, -3.0);
    ASSERT_EQ(errorCode, 0);
}
TEST(quadraticEquationTest, abc0) {
    double x1, x2;
    int errorCode;
    solveQuadraticEquation(0.0, 0.0, 0.0, &x1, &x2, &errorCode);
    ASSERT_EQ(errorCode, 1);
}
TEST(quadraticEquationTest, ab0) {
    double x1, x2;
    int errorCode;
    solveQuadraticEquation(0.0, 0.0, 3.0, &x1, &x2, &errorCode);
    ASSERT_EQ(errorCode, 1);
}
TEST(quadraticEquationTest, a0) {
    double x1, x2;
    int errorCode;
    solveQuadraticEquation(0.0, 2.0, 3.0, &x1, &x2, &errorCode);
    ASSERT_DOUBLE_EQ(x1, -1.5);
    ASSERT_DOUBLE_EQ(x2, -1.5);
    ASSERT_EQ(errorCode, 0);
}

#endif // FIBONACHI_H
