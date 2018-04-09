#include <limits.h>
#include "sample.h"
#include "gtest/gtest.h"

namespace {

  TEST(NectDateTest, NormalBoundary_Normal) {
    EXPECT_TRUE(cmp_date(datetime(1918, 06, 16), NextDate(1918, 6, 15)));
    EXPECT_TRUE(cmp_date(datetime(1919, 06, 16), NextDate(1919, 6, 15)));
    EXPECT_TRUE(cmp_date(datetime(1968, 06, 16), NextDate(1968, 6, 15)));
    EXPECT_TRUE(cmp_date(datetime(2017, 06, 16), NextDate(2017, 6, 15)));
    EXPECT_TRUE(cmp_date(datetime(2018, 06, 16), NextDate(2018, 6, 15)));
    EXPECT_TRUE(cmp_date(datetime(1968, 01, 16), NextDate(1968, 1, 15)));
    EXPECT_TRUE(cmp_date(datetime(1968, 02, 16), NextDate(1968, 2, 15)));
    EXPECT_TRUE(cmp_date(datetime(1968, 06, 16), NextDate(1968, 6, 15)));
    EXPECT_TRUE(cmp_date(datetime(1968, 11, 16), NextDate(1968, 11, 15)));
    EXPECT_TRUE(cmp_date(datetime(1968, 12, 16), NextDate(1968, 12, 15)));
    EXPECT_TRUE(cmp_date(datetime(1968, 06, 02), NextDate(1968, 6, 1)));
    EXPECT_TRUE(cmp_date(datetime(1968, 06, 03), NextDate(1968, 6, 2)));
    EXPECT_TRUE(cmp_date(datetime(1968, 06, 16), NextDate(1968, 6, 15)));
    EXPECT_TRUE(cmp_date(datetime(1968, 07, 01), NextDate(1968, 6, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 6, 31)));
  }

  TEST(NextDateTest, NormalBoundary_Worst) {
    EXPECT_TRUE(cmp_date(datetime(1918, 01, 02), NextDate(1918, 1, 1)));
    EXPECT_TRUE(cmp_date(datetime(1918, 01, 03), NextDate(1918, 1, 2)));
    EXPECT_TRUE(cmp_date(datetime(1918, 01, 16), NextDate(1918, 1, 15)));
    EXPECT_TRUE(cmp_date(datetime(1918, 01, 31), NextDate(1918, 1, 30)));
    EXPECT_TRUE(cmp_date(datetime(1918, 02, 01), NextDate(1918, 1, 31)));
    EXPECT_TRUE(cmp_date(datetime(1918, 02, 02), NextDate(1918, 2, 1)));
    EXPECT_TRUE(cmp_date(datetime(1918, 02, 03), NextDate(1918, 2, 2)));
    EXPECT_TRUE(cmp_date(datetime(1918, 02, 16), NextDate(1918, 2, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1918, 2, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1918, 2, 31)));
    EXPECT_TRUE(cmp_date(datetime(1918, 06, 02), NextDate(1918, 6, 1)));
    EXPECT_TRUE(cmp_date(datetime(1918, 06, 03), NextDate(1918, 6, 2)));
    EXPECT_TRUE(cmp_date(datetime(1918, 06, 16), NextDate(1918, 6, 15)));
    EXPECT_TRUE(cmp_date(datetime(1918, 07, 01), NextDate(1918, 6, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1918, 6, 31)));
    EXPECT_TRUE(cmp_date(datetime(1918, 11, 02), NextDate(1918, 11, 1)));
    EXPECT_TRUE(cmp_date(datetime(1918, 11, 03), NextDate(1918, 11, 2)));
    EXPECT_TRUE(cmp_date(datetime(1918, 11, 16), NextDate(1918, 11, 15)));
    EXPECT_TRUE(cmp_date(datetime(1918, 12, 01), NextDate(1918, 11, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1918, 11, 31)));
    EXPECT_TRUE(cmp_date(datetime(1918, 12, 02), NextDate(1918, 12, 1)));
    EXPECT_TRUE(cmp_date(datetime(1918, 12, 03), NextDate(1918, 12, 2)));
    EXPECT_TRUE(cmp_date(datetime(1918, 12, 16), NextDate(1918, 12, 15)));
    EXPECT_TRUE(cmp_date(datetime(1918, 12, 31), NextDate(1918, 12, 30)));
    EXPECT_TRUE(cmp_date(datetime(1919, 01, 01), NextDate(1918, 12, 31)));
    EXPECT_TRUE(cmp_date(datetime(1919, 01, 02), NextDate(1919, 1, 1)));
    EXPECT_TRUE(cmp_date(datetime(1919, 01, 03), NextDate(1919, 1, 2)));
    EXPECT_TRUE(cmp_date(datetime(1919, 01, 16), NextDate(1919, 1, 15)));
    EXPECT_TRUE(cmp_date(datetime(1919, 01, 31), NextDate(1919, 1, 30)));
    EXPECT_TRUE(cmp_date(datetime(1919, 02, 01), NextDate(1919, 1, 31)));
    EXPECT_TRUE(cmp_date(datetime(1919, 02, 02), NextDate(1919, 2, 1)));
    EXPECT_TRUE(cmp_date(datetime(1919, 02, 03), NextDate(1919, 2, 2)));
    EXPECT_TRUE(cmp_date(datetime(1919, 02, 16), NextDate(1919, 2, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1919, 2, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1919, 2, 31)));
    EXPECT_TRUE(cmp_date(datetime(1919, 06, 02), NextDate(1919, 6, 1)));
    EXPECT_TRUE(cmp_date(datetime(1919, 06, 03), NextDate(1919, 6, 2)));
    EXPECT_TRUE(cmp_date(datetime(1919, 06, 16), NextDate(1919, 6, 15)));
    EXPECT_TRUE(cmp_date(datetime(1919, 07, 01), NextDate(1919, 6, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1919, 6, 31)));
    EXPECT_TRUE(cmp_date(datetime(1919, 11, 02), NextDate(1919, 11, 1)));
    EXPECT_TRUE(cmp_date(datetime(1919, 11, 03), NextDate(1919, 11, 2)));
    EXPECT_TRUE(cmp_date(datetime(1919, 11, 16), NextDate(1919, 11, 15)));
    EXPECT_TRUE(cmp_date(datetime(1919, 12, 01), NextDate(1919, 11, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1919, 11, 31)));
    EXPECT_TRUE(cmp_date(datetime(1919, 12, 02), NextDate(1919, 12, 1)));
    EXPECT_TRUE(cmp_date(datetime(1919, 12, 03), NextDate(1919, 12, 2)));
    EXPECT_TRUE(cmp_date(datetime(1919, 12, 16), NextDate(1919, 12, 15)));
    EXPECT_TRUE(cmp_date(datetime(1919, 12, 31), NextDate(1919, 12, 30)));
    EXPECT_TRUE(cmp_date(datetime(1920, 01, 01), NextDate(1919, 12, 31)));
    EXPECT_TRUE(cmp_date(datetime(1968, 01, 02), NextDate(1968, 1, 1)));
    EXPECT_TRUE(cmp_date(datetime(1968, 01, 03), NextDate(1968, 1, 2)));
    EXPECT_TRUE(cmp_date(datetime(1968, 01, 16), NextDate(1968, 1, 15)));
    EXPECT_TRUE(cmp_date(datetime(1968, 01, 31), NextDate(1968, 1, 30)));
    EXPECT_TRUE(cmp_date(datetime(1968, 02, 01), NextDate(1968, 1, 31)));
    EXPECT_TRUE(cmp_date(datetime(1968, 02, 02), NextDate(1968, 2, 1)));
    EXPECT_TRUE(cmp_date(datetime(1968, 02, 03), NextDate(1968, 2, 2)));
    EXPECT_TRUE(cmp_date(datetime(1968, 02, 16), NextDate(1968, 2, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 2, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 2, 31)));
    EXPECT_TRUE(cmp_date(datetime(1968, 06, 02), NextDate(1968, 6, 1)));
    EXPECT_TRUE(cmp_date(datetime(1968, 06, 03), NextDate(1968, 6, 2)));
    EXPECT_TRUE(cmp_date(datetime(1968, 06, 16), NextDate(1968, 6, 15)));
    EXPECT_TRUE(cmp_date(datetime(1968, 07, 01), NextDate(1968, 6, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 6, 31)));
    EXPECT_TRUE(cmp_date(datetime(1968, 11, 02), NextDate(1968, 11, 1)));
    EXPECT_TRUE(cmp_date(datetime(1968, 11, 03), NextDate(1968, 11, 2)));
    EXPECT_TRUE(cmp_date(datetime(1968, 11, 16), NextDate(1968, 11, 15)));
    EXPECT_TRUE(cmp_date(datetime(1968, 12, 01), NextDate(1968, 11, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 11, 31)));
    EXPECT_TRUE(cmp_date(datetime(1968, 12, 02), NextDate(1968, 12, 1)));
    EXPECT_TRUE(cmp_date(datetime(1968, 12, 03), NextDate(1968, 12, 2)));
    EXPECT_TRUE(cmp_date(datetime(1968, 12, 16), NextDate(1968, 12, 15)));
    EXPECT_TRUE(cmp_date(datetime(1968, 12, 31), NextDate(1968, 12, 30)));
    EXPECT_TRUE(cmp_date(datetime(1969, 01, 01), NextDate(1968, 12, 31)));
    EXPECT_TRUE(cmp_date(datetime(2017, 01, 02), NextDate(2017, 1, 1)));
    EXPECT_TRUE(cmp_date(datetime(2017, 01, 03), NextDate(2017, 1, 2)));
    EXPECT_TRUE(cmp_date(datetime(2017, 01, 16), NextDate(2017, 1, 15)));
    EXPECT_TRUE(cmp_date(datetime(2017, 01, 31), NextDate(2017, 1, 30)));
    EXPECT_TRUE(cmp_date(datetime(2017, 02, 01), NextDate(2017, 1, 31)));
    EXPECT_TRUE(cmp_date(datetime(2017, 02, 02), NextDate(2017, 2, 1)));
    EXPECT_TRUE(cmp_date(datetime(2017, 02, 03), NextDate(2017, 2, 2)));
    EXPECT_TRUE(cmp_date(datetime(2017, 02, 16), NextDate(2017, 2, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2017, 2, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2017, 2, 31)));
    EXPECT_TRUE(cmp_date(datetime(2017, 06, 02), NextDate(2017, 6, 1)));
    EXPECT_TRUE(cmp_date(datetime(2017, 06, 03), NextDate(2017, 6, 2)));
    EXPECT_TRUE(cmp_date(datetime(2017, 06, 16), NextDate(2017, 6, 15)));
    EXPECT_TRUE(cmp_date(datetime(2017, 07, 01), NextDate(2017, 6, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2017, 6, 31)));
    EXPECT_TRUE(cmp_date(datetime(2017, 11, 02), NextDate(2017, 11, 1)));
    EXPECT_TRUE(cmp_date(datetime(2017, 11, 03), NextDate(2017, 11, 2)));
    EXPECT_TRUE(cmp_date(datetime(2017, 11, 16), NextDate(2017, 11, 15)));
    EXPECT_TRUE(cmp_date(datetime(2017, 12, 01), NextDate(2017, 11, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2017, 11, 31)));
    EXPECT_TRUE(cmp_date(datetime(2017, 12, 02), NextDate(2017, 12, 1)));
    EXPECT_TRUE(cmp_date(datetime(2017, 12, 03), NextDate(2017, 12, 2)));
    EXPECT_TRUE(cmp_date(datetime(2017, 12, 16), NextDate(2017, 12, 15)));
    EXPECT_TRUE(cmp_date(datetime(2017, 12, 31), NextDate(2017, 12, 30)));
    EXPECT_TRUE(cmp_date(datetime(2018, 01, 01), NextDate(2017, 12, 31)));
    EXPECT_TRUE(cmp_date(datetime(2018, 01, 02), NextDate(2018, 1, 1)));
    EXPECT_TRUE(cmp_date(datetime(2018, 01, 03), NextDate(2018, 1, 2)));
    EXPECT_TRUE(cmp_date(datetime(2018, 01, 16), NextDate(2018, 1, 15)));
    EXPECT_TRUE(cmp_date(datetime(2018, 01, 31), NextDate(2018, 1, 30)));
    EXPECT_TRUE(cmp_date(datetime(2018, 02, 01), NextDate(2018, 1, 31)));
    EXPECT_TRUE(cmp_date(datetime(2018, 02, 02), NextDate(2018, 2, 1)));
    EXPECT_TRUE(cmp_date(datetime(2018, 02, 03), NextDate(2018, 2, 2)));
    EXPECT_TRUE(cmp_date(datetime(2018, 02, 16), NextDate(2018, 2, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 2, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 2, 31)));
    EXPECT_TRUE(cmp_date(datetime(2018, 06, 02), NextDate(2018, 6, 1)));
    EXPECT_TRUE(cmp_date(datetime(2018, 06, 03), NextDate(2018, 6, 2)));
    EXPECT_TRUE(cmp_date(datetime(2018, 06, 16), NextDate(2018, 6, 15)));
    EXPECT_TRUE(cmp_date(datetime(2018, 07, 01), NextDate(2018, 6, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 6, 31)));
    EXPECT_TRUE(cmp_date(datetime(2018, 11, 02), NextDate(2018, 11, 1)));
    EXPECT_TRUE(cmp_date(datetime(2018, 11, 03), NextDate(2018, 11, 2)));
    EXPECT_TRUE(cmp_date(datetime(2018, 11, 16), NextDate(2018, 11, 15)));
    EXPECT_TRUE(cmp_date(datetime(2018, 12, 01), NextDate(2018, 11, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 11, 31)));
    EXPECT_TRUE(cmp_date(datetime(2018, 12, 02), NextDate(2018, 12, 1)));
    EXPECT_TRUE(cmp_date(datetime(2018, 12, 03), NextDate(2018, 12, 2)));
    EXPECT_TRUE(cmp_date(datetime(2018, 12, 16), NextDate(2018, 12, 15)));
    EXPECT_TRUE(cmp_date(datetime(2018, 12, 31), NextDate(2018, 12, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 12, 31)));
  }

  TEST(NextDateTest, RobustBoundary_Normal) {
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 6, 15)));
    EXPECT_TRUE(cmp_date(datetime(1918, 06, 16), NextDate(1918, 6, 15)));
    EXPECT_TRUE(cmp_date(datetime(1919, 06, 16), NextDate(1919, 6, 15)));
    EXPECT_TRUE(cmp_date(datetime(1968, 06, 16), NextDate(1968, 6, 15)));
    EXPECT_TRUE(cmp_date(datetime(2017, 06, 16), NextDate(2017, 6, 15)));
    EXPECT_TRUE(cmp_date(datetime(2018, 06, 16), NextDate(2018, 6, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 6, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 0, 15)));
    EXPECT_TRUE(cmp_date(datetime(1968, 01, 16), NextDate(1968, 1, 15)));
    EXPECT_TRUE(cmp_date(datetime(1968, 02, 16), NextDate(1968, 2, 15)));
    EXPECT_TRUE(cmp_date(datetime(1968, 06, 16), NextDate(1968, 6, 15)));
    EXPECT_TRUE(cmp_date(datetime(1968, 11, 16), NextDate(1968, 11, 15)));
    EXPECT_TRUE(cmp_date(datetime(1968, 12, 16), NextDate(1968, 12, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 13, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 6, 0)));
    EXPECT_TRUE(cmp_date(datetime(1968, 06, 02), NextDate(1968, 6, 1)));
    EXPECT_TRUE(cmp_date(datetime(1968, 06, 03), NextDate(1968, 6, 2)));
    EXPECT_TRUE(cmp_date(datetime(1968, 06, 16), NextDate(1968, 6, 15)));
    EXPECT_TRUE(cmp_date(datetime(1968, 07, 01), NextDate(1968, 6, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 6, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 6, 32)));
  }

  TEST(NextDateTest, RobustBoundary_Worst) {
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 0, 0)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 0, 1)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 0, 2)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 0, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 0, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 0, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 0, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 1, 0)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 1, 1)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 1, 2)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 1, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 1, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 1, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 1, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 2, 0)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 2, 1)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 2, 2)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 2, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 2, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 2, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 2, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 6, 0)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 6, 1)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 6, 2)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 6, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 6, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 6, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 6, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 11, 0)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 11, 1)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 11, 2)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 11, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 11, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 11, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 11, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 12, 0)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 12, 1)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 12, 2)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 12, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 12, 30)));
    EXPECT_TRUE(cmp_date(datetime(1918, 01, 01), NextDate(1917, 12, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 12, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 13, 0)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 13, 1)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 13, 2)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 13, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 13, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 13, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1917, 13, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1918, 0, 0)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1918, 0, 1)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1918, 0, 2)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1918, 0, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1918, 0, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1918, 0, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1918, 0, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1918, 1, 0)));
    EXPECT_TRUE(cmp_date(datetime(1918, 01, 02), NextDate(1918, 1, 1)));
    EXPECT_TRUE(cmp_date(datetime(1918, 01, 03), NextDate(1918, 1, 2)));
    EXPECT_TRUE(cmp_date(datetime(1918, 01, 16), NextDate(1918, 1, 15)));
    EXPECT_TRUE(cmp_date(datetime(1918, 01, 31), NextDate(1918, 1, 30)));
    EXPECT_TRUE(cmp_date(datetime(1918, 02, 01), NextDate(1918, 1, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1918, 1, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1918, 2, 0)));
    EXPECT_TRUE(cmp_date(datetime(1918, 02, 02), NextDate(1918, 2, 1)));
    EXPECT_TRUE(cmp_date(datetime(1918, 02, 03), NextDate(1918, 2, 2)));
    EXPECT_TRUE(cmp_date(datetime(1918, 02, 16), NextDate(1918, 2, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1918, 2, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1918, 2, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1918, 2, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1918, 6, 0)));
    EXPECT_TRUE(cmp_date(datetime(1918, 06, 02), NextDate(1918, 6, 1)));
    EXPECT_TRUE(cmp_date(datetime(1918, 06, 03), NextDate(1918, 6, 2)));
    EXPECT_TRUE(cmp_date(datetime(1918, 06, 16), NextDate(1918, 6, 15)));
    EXPECT_TRUE(cmp_date(datetime(1918, 07, 01), NextDate(1918, 6, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1918, 6, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1918, 6, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1918, 11, 0)));
    EXPECT_TRUE(cmp_date(datetime(1918, 11, 02), NextDate(1918, 11, 1)));
    EXPECT_TRUE(cmp_date(datetime(1918, 11, 03), NextDate(1918, 11, 2)));
    EXPECT_TRUE(cmp_date(datetime(1918, 11, 16), NextDate(1918, 11, 15)));
    EXPECT_TRUE(cmp_date(datetime(1918, 12, 01), NextDate(1918, 11, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1918, 11, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1918, 11, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1918, 12, 0)));
    EXPECT_TRUE(cmp_date(datetime(1918, 12, 02), NextDate(1918, 12, 1)));
    EXPECT_TRUE(cmp_date(datetime(1918, 12, 03), NextDate(1918, 12, 2)));
    EXPECT_TRUE(cmp_date(datetime(1918, 12, 16), NextDate(1918, 12, 15)));
    EXPECT_TRUE(cmp_date(datetime(1918, 12, 31), NextDate(1918, 12, 30)));
    EXPECT_TRUE(cmp_date(datetime(1919, 01, 01), NextDate(1918, 12, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1918, 12, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1918, 13, 0)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1918, 13, 1)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1918, 13, 2)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1918, 13, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1918, 13, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1918, 13, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1918, 13, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1919, 0, 0)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1919, 0, 1)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1919, 0, 2)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1919, 0, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1919, 0, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1919, 0, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1919, 0, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1919, 1, 0)));
    EXPECT_TRUE(cmp_date(datetime(1919, 01, 02), NextDate(1919, 1, 1)));
    EXPECT_TRUE(cmp_date(datetime(1919, 01, 03), NextDate(1919, 1, 2)));
    EXPECT_TRUE(cmp_date(datetime(1919, 01, 16), NextDate(1919, 1, 15)));
    EXPECT_TRUE(cmp_date(datetime(1919, 01, 31), NextDate(1919, 1, 30)));
    EXPECT_TRUE(cmp_date(datetime(1919, 02, 01), NextDate(1919, 1, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1919, 1, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1919, 2, 0)));
    EXPECT_TRUE(cmp_date(datetime(1919, 02, 02), NextDate(1919, 2, 1)));
    EXPECT_TRUE(cmp_date(datetime(1919, 02, 03), NextDate(1919, 2, 2)));
    EXPECT_TRUE(cmp_date(datetime(1919, 02, 16), NextDate(1919, 2, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1919, 2, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1919, 2, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1919, 2, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1919, 6, 0)));
    EXPECT_TRUE(cmp_date(datetime(1919, 06, 02), NextDate(1919, 6, 1)));
    EXPECT_TRUE(cmp_date(datetime(1919, 06, 03), NextDate(1919, 6, 2)));
    EXPECT_TRUE(cmp_date(datetime(1919, 06, 16), NextDate(1919, 6, 15)));
    EXPECT_TRUE(cmp_date(datetime(1919, 07, 01), NextDate(1919, 6, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1919, 6, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1919, 6, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1919, 11, 0)));
    EXPECT_TRUE(cmp_date(datetime(1919, 11, 02), NextDate(1919, 11, 1)));
    EXPECT_TRUE(cmp_date(datetime(1919, 11, 03), NextDate(1919, 11, 2)));
    EXPECT_TRUE(cmp_date(datetime(1919, 11, 16), NextDate(1919, 11, 15)));
    EXPECT_TRUE(cmp_date(datetime(1919, 12, 01), NextDate(1919, 11, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1919, 11, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1919, 11, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1919, 12, 0)));
    EXPECT_TRUE(cmp_date(datetime(1919, 12, 02), NextDate(1919, 12, 1)));
    EXPECT_TRUE(cmp_date(datetime(1919, 12, 03), NextDate(1919, 12, 2)));
    EXPECT_TRUE(cmp_date(datetime(1919, 12, 16), NextDate(1919, 12, 15)));
    EXPECT_TRUE(cmp_date(datetime(1919, 12, 31), NextDate(1919, 12, 30)));
    EXPECT_TRUE(cmp_date(datetime(1920, 01, 01), NextDate(1919, 12, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1919, 12, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1919, 13, 0)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1919, 13, 1)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1919, 13, 2)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1919, 13, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1919, 13, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1919, 13, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1919, 13, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 0, 0)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 0, 1)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 0, 2)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 0, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 0, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 0, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 0, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 1, 0)));
    EXPECT_TRUE(cmp_date(datetime(1968, 01, 02), NextDate(1968, 1, 1)));
    EXPECT_TRUE(cmp_date(datetime(1968, 01, 03), NextDate(1968, 1, 2)));
    EXPECT_TRUE(cmp_date(datetime(1968, 01, 16), NextDate(1968, 1, 15)));
    EXPECT_TRUE(cmp_date(datetime(1968, 01, 31), NextDate(1968, 1, 30)));
    EXPECT_TRUE(cmp_date(datetime(1968, 02, 01), NextDate(1968, 1, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 1, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 2, 0)));
    EXPECT_TRUE(cmp_date(datetime(1968, 02, 02), NextDate(1968, 2, 1)));
    EXPECT_TRUE(cmp_date(datetime(1968, 02, 03), NextDate(1968, 2, 2)));
    EXPECT_TRUE(cmp_date(datetime(1968, 02, 16), NextDate(1968, 2, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 2, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 2, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 2, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 6, 0)));
    EXPECT_TRUE(cmp_date(datetime(1968, 06, 02), NextDate(1968, 6, 1)));
    EXPECT_TRUE(cmp_date(datetime(1968, 06, 03), NextDate(1968, 6, 2)));
    EXPECT_TRUE(cmp_date(datetime(1968, 06, 16), NextDate(1968, 6, 15)));
    EXPECT_TRUE(cmp_date(datetime(1968, 07, 01), NextDate(1968, 6, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 6, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 6, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 11, 0)));
    EXPECT_TRUE(cmp_date(datetime(1968, 11, 02), NextDate(1968, 11, 1)));
    EXPECT_TRUE(cmp_date(datetime(1968, 11, 03), NextDate(1968, 11, 2)));
    EXPECT_TRUE(cmp_date(datetime(1968, 11, 16), NextDate(1968, 11, 15)));
    EXPECT_TRUE(cmp_date(datetime(1968, 12, 01), NextDate(1968, 11, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 11, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 11, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 12, 0)));
    EXPECT_TRUE(cmp_date(datetime(1968, 12, 02), NextDate(1968, 12, 1)));
    EXPECT_TRUE(cmp_date(datetime(1968, 12, 03), NextDate(1968, 12, 2)));
    EXPECT_TRUE(cmp_date(datetime(1968, 12, 16), NextDate(1968, 12, 15)));
    EXPECT_TRUE(cmp_date(datetime(1968, 12, 31), NextDate(1968, 12, 30)));
    EXPECT_TRUE(cmp_date(datetime(1969, 01, 01), NextDate(1968, 12, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 12, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 13, 0)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 13, 1)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 13, 2)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 13, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 13, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 13, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(1968, 13, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2017, 0, 0)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2017, 0, 1)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2017, 0, 2)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2017, 0, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2017, 0, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2017, 0, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2017, 0, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2017, 1, 0)));
    EXPECT_TRUE(cmp_date(datetime(2017, 01, 02), NextDate(2017, 1, 1)));
    EXPECT_TRUE(cmp_date(datetime(2017, 01, 03), NextDate(2017, 1, 2)));
    EXPECT_TRUE(cmp_date(datetime(2017, 01, 16), NextDate(2017, 1, 15)));
    EXPECT_TRUE(cmp_date(datetime(2017, 01, 31), NextDate(2017, 1, 30)));
    EXPECT_TRUE(cmp_date(datetime(2017, 02, 01), NextDate(2017, 1, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2017, 1, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2017, 2, 0)));
    EXPECT_TRUE(cmp_date(datetime(2017, 02, 02), NextDate(2017, 2, 1)));
    EXPECT_TRUE(cmp_date(datetime(2017, 02, 03), NextDate(2017, 2, 2)));
    EXPECT_TRUE(cmp_date(datetime(2017, 02, 16), NextDate(2017, 2, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2017, 2, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2017, 2, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2017, 2, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2017, 6, 0)));
    EXPECT_TRUE(cmp_date(datetime(2017, 06, 02), NextDate(2017, 6, 1)));
    EXPECT_TRUE(cmp_date(datetime(2017, 06, 03), NextDate(2017, 6, 2)));
    EXPECT_TRUE(cmp_date(datetime(2017, 06, 16), NextDate(2017, 6, 15)));
    EXPECT_TRUE(cmp_date(datetime(2017, 07, 01), NextDate(2017, 6, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2017, 6, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2017, 6, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2017, 11, 0)));
    EXPECT_TRUE(cmp_date(datetime(2017, 11, 02), NextDate(2017, 11, 1)));
    EXPECT_TRUE(cmp_date(datetime(2017, 11, 03), NextDate(2017, 11, 2)));
    EXPECT_TRUE(cmp_date(datetime(2017, 11, 16), NextDate(2017, 11, 15)));
    EXPECT_TRUE(cmp_date(datetime(2017, 12, 01), NextDate(2017, 11, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2017, 11, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2017, 11, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2017, 12, 0)));
    EXPECT_TRUE(cmp_date(datetime(2017, 12, 02), NextDate(2017, 12, 1)));
    EXPECT_TRUE(cmp_date(datetime(2017, 12, 03), NextDate(2017, 12, 2)));
    EXPECT_TRUE(cmp_date(datetime(2017, 12, 16), NextDate(2017, 12, 15)));
    EXPECT_TRUE(cmp_date(datetime(2017, 12, 31), NextDate(2017, 12, 30)));
    EXPECT_TRUE(cmp_date(datetime(2018, 01, 01), NextDate(2017, 12, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2017, 12, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2017, 13, 0)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2017, 13, 1)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2017, 13, 2)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2017, 13, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2017, 13, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2017, 13, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2017, 13, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 0, 0)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 0, 1)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 0, 2)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 0, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 0, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 0, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 0, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 1, 0)));
    EXPECT_TRUE(cmp_date(datetime(2018, 01, 02), NextDate(2018, 1, 1)));
    EXPECT_TRUE(cmp_date(datetime(2018, 01, 03), NextDate(2018, 1, 2)));
    EXPECT_TRUE(cmp_date(datetime(2018, 01, 16), NextDate(2018, 1, 15)));
    EXPECT_TRUE(cmp_date(datetime(2018, 01, 31), NextDate(2018, 1, 30)));
    EXPECT_TRUE(cmp_date(datetime(2018, 02, 01), NextDate(2018, 1, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 1, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 2, 0)));
    EXPECT_TRUE(cmp_date(datetime(2018, 02, 02), NextDate(2018, 2, 1)));
    EXPECT_TRUE(cmp_date(datetime(2018, 02, 03), NextDate(2018, 2, 2)));
    EXPECT_TRUE(cmp_date(datetime(2018, 02, 16), NextDate(2018, 2, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 2, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 2, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 2, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 6, 0)));
    EXPECT_TRUE(cmp_date(datetime(2018, 06, 02), NextDate(2018, 6, 1)));
    EXPECT_TRUE(cmp_date(datetime(2018, 06, 03), NextDate(2018, 6, 2)));
    EXPECT_TRUE(cmp_date(datetime(2018, 06, 16), NextDate(2018, 6, 15)));
    EXPECT_TRUE(cmp_date(datetime(2018, 07, 01), NextDate(2018, 6, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 6, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 6, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 11, 0)));
    EXPECT_TRUE(cmp_date(datetime(2018, 11, 02), NextDate(2018, 11, 1)));
    EXPECT_TRUE(cmp_date(datetime(2018, 11, 03), NextDate(2018, 11, 2)));
    EXPECT_TRUE(cmp_date(datetime(2018, 11, 16), NextDate(2018, 11, 15)));
    EXPECT_TRUE(cmp_date(datetime(2018, 12, 01), NextDate(2018, 11, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 11, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 11, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 12, 0)));
    EXPECT_TRUE(cmp_date(datetime(2018, 12, 02), NextDate(2018, 12, 1)));
    EXPECT_TRUE(cmp_date(datetime(2018, 12, 03), NextDate(2018, 12, 2)));
    EXPECT_TRUE(cmp_date(datetime(2018, 12, 16), NextDate(2018, 12, 15)));
    EXPECT_TRUE(cmp_date(datetime(2018, 12, 31), NextDate(2018, 12, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 12, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 12, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 13, 0)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 13, 1)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 13, 2)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 13, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 13, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 13, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2018, 13, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 0, 0)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 0, 1)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 0, 2)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 0, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 0, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 0, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 0, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 1, 0)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 1, 1)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 1, 2)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 1, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 1, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 1, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 1, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 2, 0)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 2, 1)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 2, 2)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 2, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 2, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 2, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 2, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 6, 0)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 6, 1)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 6, 2)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 6, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 6, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 6, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 6, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 11, 0)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 11, 1)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 11, 2)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 11, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 11, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 11, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 11, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 12, 0)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 12, 1)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 12, 2)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 12, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 12, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 12, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 12, 32)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 13, 0)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 13, 1)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 13, 2)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 13, 15)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 13, 30)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 13, 31)));
    EXPECT_TRUE(cmp_date(datetime(0, 0, 0, 1), NextDate(2019, 13, 32)));
  }

}
