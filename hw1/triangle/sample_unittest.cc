#include <limits.h>
#include "sample.h"
#include "gtest/gtest.h"

namespace {
  TEST(IsTriangleTest, NormalBoundary_Normal) {
    EXPECT_STREQ("Isosceles", IsTriangle(1, 100, 100));
    EXPECT_STREQ("Isosceles", IsTriangle(2, 100, 100));
    EXPECT_STREQ("Isosceles", IsTriangle(199, 100, 100));
    EXPECT_STREQ("Isosceles", IsTriangle(200, 100, 100));
    EXPECT_STREQ("Isosceles", IsTriangle(100, 100, 1));
    EXPECT_STREQ("Isosceles", IsTriangle(100, 100, 2));
    EXPECT_STREQ("Isosceles", IsTriangle(100, 100, 199));
    EXPECT_STREQ("Not a triangle", IsTriangle(100, 100, 200));
    EXPECT_STREQ("Isosceles", IsTriangle(100, 1, 100));
    EXPECT_STREQ("Isosceles", IsTriangle(100, 2, 100));
    EXPECT_STREQ("Isosceles", IsTriangle(100, 199, 100));
    EXPECT_STREQ("Not a triangle", IsTriangle(100, 200, 100));
    EXPECT_STREQ("Equilateral", IsTriangle(100, 100, 100));
  }
  
  TEST(IsTriangleTest, NormalBoundary_Worst) {
    EXPECT_STREQ("Equilateral", IsTriangle(1, 1, 1));
    EXPECT_STREQ("Not a triangle", IsTriangle(1, 1, 2));
    EXPECT_STREQ("Not a triangle", IsTriangle(1, 1, 100));
    EXPECT_STREQ("Not a triangle", IsTriangle(1, 1, 199));
    EXPECT_STREQ("Not a triangle", IsTriangle(1, 1, 200));
    EXPECT_STREQ("Not a triangle", IsTriangle(1, 2, 1));
    EXPECT_STREQ("Isosceles", IsTriangle(1, 2, 2));
    EXPECT_STREQ("Not a triangle", IsTriangle(1, 2, 100));
    EXPECT_STREQ("Not a triangle", IsTriangle(1, 2, 199));
    EXPECT_STREQ("Not a triangle", IsTriangle(1, 2, 200));
    EXPECT_STREQ("Not a triangle", IsTriangle(1, 100, 1));
    EXPECT_STREQ("Not a triangle", IsTriangle(1, 100, 2));
    EXPECT_STREQ("Isosceles", IsTriangle(1, 100, 100));
    EXPECT_STREQ("Not a triangle", IsTriangle(1, 100, 199));
    EXPECT_STREQ("Not a triangle", IsTriangle(1, 100, 200));
    EXPECT_STREQ("Not a triangle", IsTriangle(1, 199, 1));
    EXPECT_STREQ("Not a triangle", IsTriangle(1, 199, 2));
    EXPECT_STREQ("Not a triangle", IsTriangle(1, 199, 100));
    EXPECT_STREQ("Isosceles", IsTriangle(1, 199, 199));
    EXPECT_STREQ("Not a triangle", IsTriangle(1, 199, 200));
    EXPECT_STREQ("Not a triangle", IsTriangle(1, 200, 1));
    EXPECT_STREQ("Not a triangle", IsTriangle(1, 200, 2));
    EXPECT_STREQ("Not a triangle", IsTriangle(1, 200, 100));
    EXPECT_STREQ("Not a triangle", IsTriangle(1, 200, 199));
    EXPECT_STREQ("Isosceles", IsTriangle(1, 200, 200));

    EXPECT_STREQ("Not a triangle", IsTriangle(2, 1, 1));
    EXPECT_STREQ("Isosceles", IsTriangle(2, 1, 2));
    EXPECT_STREQ("Not a triangle", IsTriangle(2, 1, 100));
    EXPECT_STREQ("Not a triangle", IsTriangle(2, 1, 199));
    EXPECT_STREQ("Not a triangle", IsTriangle(2, 1, 200));
    EXPECT_STREQ("Isosceles", IsTriangle(2, 199, 199));
    EXPECT_STREQ("Scalene", IsTriangle(2, 199, 200));
    EXPECT_STREQ("Not a triangle", IsTriangle(100, 2, 199));
    EXPECT_STREQ("Not a triangle", IsTriangle(100, 2, 200));
    EXPECT_STREQ("Isosceles", IsTriangle(100, 100, 1));
    EXPECT_STREQ("Isosceles", IsTriangle(100, 100, 2));
    EXPECT_STREQ("Equilateral", IsTriangle(100, 100, 100));
    EXPECT_STREQ("Isosceles", IsTriangle(100, 100, 199));
    EXPECT_STREQ("Scalene", IsTriangle(199, 100, 200));
    EXPECT_STREQ("Isosceles", IsTriangle(199, 199, 1));
    EXPECT_STREQ("Isosceles", IsTriangle(199, 199, 2));
    EXPECT_STREQ("Isosceles", IsTriangle(199, 199, 100));
    EXPECT_STREQ("Equilateral", IsTriangle(199, 199, 199));
    EXPECT_STREQ("Isosceles", IsTriangle(199, 199, 200));
    EXPECT_STREQ("Not a triangle", IsTriangle(200, 100, 1));
    EXPECT_STREQ("Not a triangle", IsTriangle(200, 100, 2));
    EXPECT_STREQ("Not a triangle", IsTriangle(200, 100, 100));
    EXPECT_STREQ("Isosceles", IsTriangle(200, 199, 199));
    EXPECT_STREQ("Isosceles", IsTriangle(200, 199, 200));
  }
  
  TEST(IsTriangleTest, RobustBoundary_Normal) {
    EXPECT_STREQ("Value of a is not in the range of permited values", IsTriangle(0, 100, 100));
    EXPECT_STREQ("Isosceles", IsTriangle(1, 100, 100));
    EXPECT_STREQ("Isosceles", IsTriangle(2, 100, 100));
    EXPECT_STREQ("Isosceles", IsTriangle(199, 100, 100));
    EXPECT_STREQ("Not a triangle", IsTriangle(200, 100, 100));
    EXPECT_STREQ("Value of a is not in the range of permited values", IsTriangle(201, 100, 100));
    EXPECT_STREQ("Value of b is not in the range of permited values", IsTriangle(100, 0, 100));
    EXPECT_STREQ("Isosceles", IsTriangle(100, 1, 100));
    EXPECT_STREQ("Isosceles", IsTriangle(100, 2, 100));
    EXPECT_STREQ("Isosceles", IsTriangle(100, 199, 100));
    EXPECT_STREQ("Not a triangle", IsTriangle(100, 200, 100));
    EXPECT_STREQ("Value of b is not in the range of permited values", IsTriangle(100, 201, 100));
    EXPECT_STREQ("Value of c is not in the range of permited values", IsTriangle(100, 100, 0));
    EXPECT_STREQ("Isosceles", IsTriangle(100, 100, 1));
    EXPECT_STREQ("Isosceles", IsTriangle(100, 100, 2));
    EXPECT_STREQ("Isosceles", IsTriangle(100, 100, 199));
    EXPECT_STREQ("Not a triangle", IsTriangle(100, 100, 200));
    EXPECT_STREQ("Value of c is not in the range of permited values", IsTriangle(100, 100, 201));
    EXPECT_STREQ("Equilateral", IsTriangle(100, 100, 100));
  }

  TEST(IsTriangleTest, RobustBoundary_Worst) {
    EXPECT_STREQ("Value of a is not in the range of permited values", IsTriangle(0, 0, 0));
    EXPECT_STREQ("Value of a is not in the range of permited values", IsTriangle(0, 0, 1));
    EXPECT_STREQ("Value of a is not in the range of permited values", IsTriangle(0, 0, 2));
    EXPECT_STREQ("Value of a is not in the range of permited values", IsTriangle(0, 0, 100));
    EXPECT_STREQ("Value of a is not in the range of permited values", IsTriangle(0, 0, 199));
    EXPECT_STREQ("Value of a is not in the range of permited values", IsTriangle(0, 0, 200));
    EXPECT_STREQ("Value of a is not in the range of permited values", IsTriangle(0, 0, 201));
    EXPECT_STREQ("Value of a is not in the range of permited values", IsTriangle(0, 201, 100));
    EXPECT_STREQ("Value of a is not in the range of permited values", IsTriangle(0, 201, 199));
    EXPECT_STREQ("Value of a is not in the range of permited values", IsTriangle(0, 201, 200));
    EXPECT_STREQ("Value of a is not in the range of permited values", IsTriangle(0, 201, 201));
    EXPECT_STREQ("Value of b is not in the range of permited values", IsTriangle(1, 0, 0));
    EXPECT_STREQ("Value of b is not in the range of permited values", IsTriangle(1, 0, 1));
    EXPECT_STREQ("Value of b is not in the range of permited values", IsTriangle(1, 0, 2));
    EXPECT_STREQ("Value of b is not in the range of permited values", IsTriangle(1, 0, 100));
    EXPECT_STREQ("Value of b is not in the range of permited values", IsTriangle(1, 0, 199));
    EXPECT_STREQ("Value of b is not in the range of permited values", IsTriangle(1, 0, 200));
    EXPECT_STREQ("Value of b is not in the range of permited values", IsTriangle(1, 0, 201));
    EXPECT_STREQ("Value of c is not in the range of permited values", IsTriangle(1, 1, 0));
    EXPECT_STREQ("Equilateral", IsTriangle(1, 1, 1));
    EXPECT_STREQ("Not a triangle", IsTriangle(1, 1, 2));
    EXPECT_STREQ("Not a triangle", IsTriangle(1, 1, 100));
    EXPECT_STREQ("Not a triangle", IsTriangle(1, 1, 199));
    EXPECT_STREQ("Not a triangle", IsTriangle(1, 1, 200));
    EXPECT_STREQ("Value of c is not in the range of permited values", IsTriangle(1, 1, 201));
    EXPECT_STREQ("Value of c is not in the range of permited values", IsTriangle(1, 2, 0));
    EXPECT_STREQ("Not a triangle", IsTriangle(1, 2, 1));
    EXPECT_STREQ("Isosceles", IsTriangle(1, 2, 2));
    EXPECT_STREQ("Value of c is not in the range of permited values", IsTriangle(1, 2, 201));
    EXPECT_STREQ("Value of c is not in the range of permited values", IsTriangle(1, 200, 201));
    EXPECT_STREQ("Value of c is not in the range of permited values", IsTriangle(2, 1, 0));
    EXPECT_STREQ("Not a triangle", IsTriangle(200, 199, 1));
    EXPECT_STREQ("Scalene", IsTriangle(200, 199, 2));
    EXPECT_STREQ("Scalene", IsTriangle(200, 199, 100));
    EXPECT_STREQ("Isosceles", IsTriangle(200, 199, 199));
    EXPECT_STREQ("Isosceles", IsTriangle(200, 199, 200));
    EXPECT_STREQ("Value of c is not in the range of permited values", IsTriangle(200, 199, 201));
    EXPECT_STREQ("Value of c is not in the range of permited values", IsTriangle(200, 200, 0));
    EXPECT_STREQ("Isosceles", IsTriangle(200, 200, 1));
    EXPECT_STREQ("Isosceles", IsTriangle(200, 200, 2));
    EXPECT_STREQ("Isosceles", IsTriangle(200, 200, 100));
    EXPECT_STREQ("Isosceles", IsTriangle(200, 200, 199));
    EXPECT_STREQ("Equilateral", IsTriangle(200, 200, 200));
    EXPECT_STREQ("Value of c is not in the range of permited values", IsTriangle(200, 200, 201));
  }

}
