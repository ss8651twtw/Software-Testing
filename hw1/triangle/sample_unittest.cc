#include <limits.h>
#include "sample.h"
#include "gtest/gtest.h"

namespace {
  TEST(IsTriangleTest, NormalBoundary_Normal) {
    EXPECT_EQ(1, IsTriangle(1, 100, 100));
    EXPECT_EQ(1, IsTriangle(2, 100, 100));
    EXPECT_EQ(1, IsTriangle(199, 100, 100));
    EXPECT_EQ(0, IsTriangle(200, 100, 100));
    EXPECT_EQ(1, IsTriangle(100, 100, 1));
    EXPECT_EQ(1, IsTriangle(100, 100, 2));
    EXPECT_EQ(1, IsTriangle(100, 100, 199));
    EXPECT_EQ(0, IsTriangle(100, 100, 200));
    EXPECT_EQ(1, IsTriangle(100, 1, 100));
    EXPECT_EQ(1, IsTriangle(100, 2, 100));
    EXPECT_EQ(1, IsTriangle(100, 199, 100));
    EXPECT_EQ(0, IsTriangle(100, 200, 100));
    EXPECT_EQ(1, IsTriangle(100, 100, 100));
  }

}
