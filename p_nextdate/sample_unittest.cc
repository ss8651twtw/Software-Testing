#include <limits.h>
#include "sample.h"
#include "gtest/gtest.h"

namespace {

    TEST(NextDateTest, NormalBoundary_Normal) {
        EXPECT_STREQ("Tomorrow's date is 1918 06 16", NextDate(1918, 6, 15));
        EXPECT_STREQ("Tomorrow's date is 1919 06 16", NextDate(1919, 6, 15));
        EXPECT_STREQ("Tomorrow's date is 1968 06 16", NextDate(1968, 6, 15));
        EXPECT_STREQ("Tomorrow's date is 2017 06 16", NextDate(2017, 6, 15));
        EXPECT_STREQ("Tomorrow's date is 2018 06 16", NextDate(2018, 6, 15));
        EXPECT_STREQ("Tomorrow's date is 1968 01 16", NextDate(1968, 1, 15));
        EXPECT_STREQ("Tomorrow's date is 1968 02 16", NextDate(1968, 2, 15));
        EXPECT_STREQ("Tomorrow's date is 1968 06 16", NextDate(1968, 6, 15));
        EXPECT_STREQ("Tomorrow's date is 1968 11 16", NextDate(1968, 11, 15));
        EXPECT_STREQ("Tomorrow's date is 1968 12 16", NextDate(1968, 12, 15));
        EXPECT_STREQ("Tomorrow's date is 1968 06 02", NextDate(1968, 6, 1));
        EXPECT_STREQ("Tomorrow's date is 1968 06 03", NextDate(1968, 6, 2));
        EXPECT_STREQ("Tomorrow's date is 1968 06 16", NextDate(1968, 6, 15));
        EXPECT_STREQ("Tomorrow's date is 1968 07 01", NextDate(1968, 6, 30));
        EXPECT_STREQ("Cannot have 1968 06 31", NextDate(1968, 6, 31));
    }

    TEST(NextDateTest, NormalBoundary_Worst) {
        EXPECT_STREQ("Tomorrow's date is 1918 01 02", NextDate(1918, 1, 1));
        EXPECT_STREQ("Tomorrow's date is 1918 01 03", NextDate(1918, 1, 2));
        EXPECT_STREQ("Tomorrow's date is 1918 01 16", NextDate(1918, 1, 15));
        EXPECT_STREQ("Tomorrow's date is 1918 01 31", NextDate(1918, 1, 30));
        EXPECT_STREQ("Tomorrow's date is 1918 02 01", NextDate(1918, 1, 31));
        EXPECT_STREQ("Tomorrow's date is 1918 02 02", NextDate(1918, 2, 1));
        EXPECT_STREQ("Tomorrow's date is 1918 02 03", NextDate(1918, 2, 2));
        EXPECT_STREQ("Tomorrow's date is 1918 02 16", NextDate(1918, 2, 15));
        EXPECT_STREQ("Cannot have 1918 02 30", NextDate(1918, 2, 30));
        EXPECT_STREQ("Cannot have 1918 02 31", NextDate(1918, 2, 31));
        EXPECT_STREQ("Tomorrow's date is 1918 06 02", NextDate(1918, 6, 1));
        EXPECT_STREQ("Tomorrow's date is 1918 06 03", NextDate(1918, 6, 2));
        EXPECT_STREQ("Tomorrow's date is 1918 06 16", NextDate(1918, 6, 15));
        EXPECT_STREQ("Tomorrow's date is 1918 07 01", NextDate(1918, 6, 30));
        EXPECT_STREQ("Cannot have 1918 06 31", NextDate(1918, 6, 31));
        EXPECT_STREQ("Tomorrow's date is 1918 11 02", NextDate(1918, 11, 1));
        EXPECT_STREQ("Tomorrow's date is 1918 11 03", NextDate(1918, 11, 2));
        EXPECT_STREQ("Tomorrow's date is 1918 11 16", NextDate(1918, 11, 15));
        EXPECT_STREQ("Tomorrow's date is 1918 12 01", NextDate(1918, 11, 30));
        EXPECT_STREQ("Cannot have 1918 11 31", NextDate(1918, 11, 31));
        EXPECT_STREQ("Cannot have 1919 11 31", NextDate(1919, 11, 31));
        EXPECT_STREQ("Tomorrow's date is 1919 12 02", NextDate(1919, 12, 1));
        EXPECT_STREQ("Tomorrow's date is 1919 12 03", NextDate(1919, 12, 2));
        EXPECT_STREQ("Tomorrow's date is 1919 12 16", NextDate(1919, 12, 15));
        EXPECT_STREQ("Tomorrow's date is 1919 12 31", NextDate(1919, 12, 30));
        EXPECT_STREQ("Tomorrow's date is 1920 01 01", NextDate(1919, 12, 31));
        EXPECT_STREQ("Tomorrow's date is 1968 01 02", NextDate(1968, 1, 1));
        EXPECT_STREQ("Tomorrow's date is 1968 01 03", NextDate(1968, 1, 2));
        EXPECT_STREQ("Tomorrow's date is 1968 01 16", NextDate(1968, 1, 15));
        EXPECT_STREQ("Tomorrow's date is 1968 01 31", NextDate(1968, 1, 30));
        EXPECT_STREQ("Tomorrow's date is 1968 02 01", NextDate(1968, 1, 31));
        EXPECT_STREQ("Tomorrow's date is 1968 02 02", NextDate(1968, 2, 1));
        EXPECT_STREQ("Tomorrow's date is 1968 02 03", NextDate(1968, 2, 2));
        EXPECT_STREQ("Tomorrow's date is 1968 02 16", NextDate(1968, 2, 15));
        EXPECT_STREQ("Cannot have 2018 06 31", NextDate(2018, 6, 31));
        EXPECT_STREQ("Tomorrow's date is 2018 11 02", NextDate(2018, 11, 1));
        EXPECT_STREQ("Tomorrow's date is 2018 11 03", NextDate(2018, 11, 2));
        EXPECT_STREQ("Tomorrow's date is 2018 11 16", NextDate(2018, 11, 15));
        EXPECT_STREQ("Tomorrow's date is 2018 12 01", NextDate(2018, 11, 30));
        EXPECT_STREQ("Cannot have 2018 11 31", NextDate(2018, 11, 31));
        EXPECT_STREQ("Tomorrow's date is 2018 12 02", NextDate(2018, 12, 1));
        EXPECT_STREQ("Tomorrow's date is 2018 12 03", NextDate(2018, 12, 2));
        EXPECT_STREQ("Tomorrow's date is 2018 12 16", NextDate(2018, 12, 15));
        EXPECT_STREQ("Tomorrow's date is 2018 12 31", NextDate(2018, 12, 30));
        EXPECT_STREQ("2019 is over", NextDate(2018, 12, 31));
    }

    TEST(NextDateTest, RobustBoundary_Normal) {
        EXPECT_STREQ("1917 is over", NextDate(1917, 6, 15));
        EXPECT_STREQ("Tomorrow's date is 1918 06 16", NextDate(1918, 6, 15));
        EXPECT_STREQ("Tomorrow's date is 1919 06 16", NextDate(1919, 6, 15));
        EXPECT_STREQ("Tomorrow's date is 1968 06 16", NextDate(1968, 6, 15));
        EXPECT_STREQ("Tomorrow's date is 2017 06 16", NextDate(2017, 6, 15));
        EXPECT_STREQ("Tomorrow's date is 2018 06 16", NextDate(2018, 6, 15));
        EXPECT_STREQ("2019 is over", NextDate(2019, 6, 15));
        EXPECT_STREQ("Cannot have 1968 00 15", NextDate(1968, 0, 15));
        EXPECT_STREQ("Tomorrow's date is 1968 01 16", NextDate(1968, 1, 15));
        EXPECT_STREQ("Tomorrow's date is 1968 02 16", NextDate(1968, 2, 15));
        EXPECT_STREQ("Tomorrow's date is 1968 06 16", NextDate(1968, 6, 15));
        EXPECT_STREQ("Tomorrow's date is 1968 11 16", NextDate(1968, 11, 15));
        EXPECT_STREQ("Tomorrow's date is 1968 12 16", NextDate(1968, 12, 15));
        EXPECT_STREQ("Cannot have 1968 13 15", NextDate(1968, 13, 15));
        EXPECT_STREQ("Cannot have 1968 06 00", NextDate(1968, 6, 0));
        EXPECT_STREQ("Tomorrow's date is 1968 06 02", NextDate(1968, 6, 1));
        EXPECT_STREQ("Tomorrow's date is 1968 06 03", NextDate(1968, 6, 2));
        EXPECT_STREQ("Tomorrow's date is 1968 06 16", NextDate(1968, 6, 15));
        EXPECT_STREQ("Tomorrow's date is 1968 07 01", NextDate(1968, 6, 30));
        EXPECT_STREQ("Cannot have 1968 06 31", NextDate(1968, 6, 31));
        EXPECT_STREQ("Cannot have 1968 06 32", NextDate(1968, 6, 32));
    }

    TEST(NextDateTest, RobustBoundary_Worst) {
        EXPECT_STREQ("1917 is over", NextDate(1917, 0, 0));
        EXPECT_STREQ("1917 is over", NextDate(1917, 0, 1));
        EXPECT_STREQ("1917 is over", NextDate(1917, 0, 2));
        EXPECT_STREQ("1917 is over", NextDate(1917, 0, 15));
        EXPECT_STREQ("1917 is over", NextDate(1917, 0, 30));
        EXPECT_STREQ("1917 is over", NextDate(1917, 0, 31));
        EXPECT_STREQ("1917 is over", NextDate(1917, 0, 32));
        EXPECT_STREQ("1917 is over", NextDate(1917, 13, 31));
        EXPECT_STREQ("1917 is over", NextDate(1917, 13, 32));
        EXPECT_STREQ("Cannot have 1918 00 00", NextDate(1918, 0, 0));
        EXPECT_STREQ("Tomorrow's date is 1918 02 01", NextDate(1918, 1, 31));
        EXPECT_STREQ("Cannot have 1918 01 32", NextDate(1918, 1, 32));
        EXPECT_STREQ("Cannot have 1918 02 00", NextDate(1918, 2, 0));
        EXPECT_STREQ("Tomorrow's date is 1918 02 02", NextDate(1918, 2, 1));
        EXPECT_STREQ("Cannot have 1919 00 00", NextDate(1919, 0, 0));
        EXPECT_STREQ("Tomorrow's date is 1919 01 31", NextDate(1919, 1, 30));
        EXPECT_STREQ("Tomorrow's date is 1919 02 01", NextDate(1919, 1, 31));
        EXPECT_STREQ("Cannot have 1919 01 32", NextDate(1919, 1, 32));
        EXPECT_STREQ("Tomorrow's date is 1968 06 02", NextDate(1968, 6, 1));
        EXPECT_STREQ("Tomorrow's date is 1968 06 03", NextDate(1968, 6, 2));
        EXPECT_STREQ("Tomorrow's date is 1968 06 16", NextDate(1968, 6, 15));
        EXPECT_STREQ("Tomorrow's date is 1968 07 01", NextDate(1968, 6, 30));
        EXPECT_STREQ("Cannot have 1968 06 31", NextDate(1968, 6, 31));
        EXPECT_STREQ("Tomorrow's date is 2018 01 01", NextDate(2017, 12, 31));
        EXPECT_STREQ("Cannot have 2017 12 32", NextDate(2017, 12, 32));
        EXPECT_STREQ("Cannot have 2017 13 00", NextDate(2017, 13, 0));
        EXPECT_STREQ("Tomorrow's date is 2018 12 31", NextDate(2018, 12, 30));
        EXPECT_STREQ("2019 is over", NextDate(2018, 12, 31));
        EXPECT_STREQ("Cannot have 2018 12 32", NextDate(2018, 12, 32));
        EXPECT_STREQ("2019 is over", NextDate(2019, 1, 0));
        EXPECT_STREQ("2019 is over", NextDate(2019, 1, 1));
        EXPECT_STREQ("2019 is over", NextDate(2019, 12, 15));
        EXPECT_STREQ("2019 is over", NextDate(2019, 12, 30));
        EXPECT_STREQ("2019 is over", NextDate(2019, 12, 31));
    }

    TEST(NextDateTest, WeakNormal) {
        EXPECT_STREQ("Tomorrow's date is 1940 03 03", NextDate(1940, 3, 2));
        EXPECT_STREQ("Tomorrow's date is 1940 09 17", NextDate(1940, 9, 16));
        EXPECT_STREQ("Tomorrow's date is 1969 09 03", NextDate(1969, 9, 2));
    }

    TEST(NextDateTest, StrongNormal) {
        EXPECT_STREQ("Tomorrow's date is 1953 03 06", NextDate(1953, 3, 5));
        EXPECT_STREQ("Tomorrow's date is 1953 03 27", NextDate(1953, 3, 26));
        EXPECT_STREQ("Tomorrow's date is 1953 07 06", NextDate(1953, 7, 5));
        EXPECT_STREQ("Tomorrow's date is 1953 07 27", NextDate(1953, 7, 26));
        EXPECT_STREQ("Tomorrow's date is 1993 03 06", NextDate(1993, 3, 5));
        EXPECT_STREQ("Tomorrow's date is 1993 03 27", NextDate(1993, 3, 26));
        EXPECT_STREQ("Tomorrow's date is 1993 07 06", NextDate(1993, 7, 5));
        EXPECT_STREQ("Tomorrow's date is 1993 07 27", NextDate(1993, 7, 26));
    }

    TEST(NextDateTest, WeakRobust) {
        EXPECT_STREQ("Cannot have 1918 04 00", NextDate(1918, 4, 0));
        EXPECT_STREQ("Cannot have 2015 13 32", NextDate(2015, 13, 32));
        EXPECT_STREQ("Tomorrow's date is 2015 09 01", NextDate(2015, 8, 31));
        EXPECT_STREQ("Tomorrow's date is 2015 04 12", NextDate(2015, 4, 11));
        EXPECT_STREQ("2019 is over", NextDate(2019, 8, 31));
        EXPECT_STREQ("1917 is over", NextDate(1917, 4, 32));
    }

    TEST(NextDateTest, StrongRobust) {
        EXPECT_STREQ("1917 is over", NextDate(1917, 0, 0));
        EXPECT_STREQ("1917 is over", NextDate(1917, 0, 32));
        EXPECT_STREQ("1917 is over", NextDate(1917, 0, 11));
        EXPECT_STREQ("1917 is over", NextDate(1917, 0, 17));
        EXPECT_STREQ("1917 is over", NextDate(1917, 13, 0));
        EXPECT_STREQ("1917 is over", NextDate(1917, 13, 32));
        EXPECT_STREQ("1917 is over", NextDate(1917, 13, 11));
        EXPECT_STREQ("1917 is over", NextDate(1917, 13, 17));
        EXPECT_STREQ("1917 is over", NextDate(1917, 2, 0));
        EXPECT_STREQ("1917 is over", NextDate(1917, 2, 32));
        EXPECT_STREQ("1917 is over", NextDate(1917, 2, 11));
        EXPECT_STREQ("1917 is over", NextDate(1917, 2, 17));
        EXPECT_STREQ("1917 is over", NextDate(1917, 7, 0));
        EXPECT_STREQ("1917 is over", NextDate(1917, 7, 32));
        EXPECT_STREQ("1917 is over", NextDate(1917, 7, 11));
        EXPECT_STREQ("1917 is over", NextDate(1917, 7, 17));
        EXPECT_STREQ("2019 is over", NextDate(2019, 0, 0));
        EXPECT_STREQ("2019 is over", NextDate(2019, 0, 32));
        EXPECT_STREQ("2019 is over", NextDate(2019, 0, 11));
        EXPECT_STREQ("2019 is over", NextDate(2019, 0, 17));
        EXPECT_STREQ("2019 is over", NextDate(2019, 13, 0));
        EXPECT_STREQ("2019 is over", NextDate(2019, 13, 32));
        EXPECT_STREQ("2019 is over", NextDate(2019, 13, 11));
        EXPECT_STREQ("2019 is over", NextDate(2019, 13, 17));
        EXPECT_STREQ("2019 is over", NextDate(2019, 2, 0));
        EXPECT_STREQ("2019 is over", NextDate(2019, 2, 32));
        EXPECT_STREQ("2019 is over", NextDate(2019, 2, 11));
        EXPECT_STREQ("2019 is over", NextDate(2019, 2, 17));
        EXPECT_STREQ("2019 is over", NextDate(2019, 7, 0));
        EXPECT_STREQ("2019 is over", NextDate(2019, 7, 32));
        EXPECT_STREQ("2019 is over", NextDate(2019, 7, 11));
        EXPECT_STREQ("2019 is over", NextDate(2019, 7, 17));
        EXPECT_STREQ("Cannot have 1958 00 00", NextDate(1958, 0, 0));
        EXPECT_STREQ("Cannot have 1958 00 32", NextDate(1958, 0, 32));
        EXPECT_STREQ("Cannot have 1958 00 11", NextDate(1958, 0, 11));
        EXPECT_STREQ("Cannot have 1958 00 17", NextDate(1958, 0, 17));
        EXPECT_STREQ("Cannot have 1958 13 00", NextDate(1958, 13, 0));
        EXPECT_STREQ("Cannot have 1958 13 32", NextDate(1958, 13, 32));
        EXPECT_STREQ("Cannot have 1958 13 11", NextDate(1958, 13, 11));
        EXPECT_STREQ("Cannot have 1958 13 17", NextDate(1958, 13, 17));
        EXPECT_STREQ("Cannot have 1958 02 00", NextDate(1958, 2, 0));
        EXPECT_STREQ("Cannot have 1958 02 32", NextDate(1958, 2, 32));
        EXPECT_STREQ("Tomorrow's date is 1958 02 12", NextDate(1958, 2, 11));
        EXPECT_STREQ("Tomorrow's date is 1958 02 18", NextDate(1958, 2, 17));
        EXPECT_STREQ("Cannot have 1958 07 00", NextDate(1958, 7, 0));
        EXPECT_STREQ("Cannot have 1958 07 32", NextDate(1958, 7, 32));
        EXPECT_STREQ("Tomorrow's date is 1958 07 12", NextDate(1958, 7, 11));
        EXPECT_STREQ("Tomorrow's date is 1958 07 18", NextDate(1958, 7, 17));
        EXPECT_STREQ("Cannot have 2007 00 00", NextDate(2007, 0, 0));
        EXPECT_STREQ("Cannot have 2007 00 32", NextDate(2007, 0, 32));
        EXPECT_STREQ("Cannot have 2007 00 11", NextDate(2007, 0, 11));
        EXPECT_STREQ("Cannot have 2007 00 17", NextDate(2007, 0, 17));
        EXPECT_STREQ("Cannot have 2007 13 00", NextDate(2007, 13, 0));
        EXPECT_STREQ("Cannot have 2007 13 32", NextDate(2007, 13, 32));
        EXPECT_STREQ("Cannot have 2007 13 11", NextDate(2007, 13, 11));
        EXPECT_STREQ("Cannot have 2007 13 17", NextDate(2007, 13, 17));
        EXPECT_STREQ("Cannot have 2007 02 00", NextDate(2007, 2, 0));
        EXPECT_STREQ("Cannot have 2007 02 32", NextDate(2007, 2, 32));
        EXPECT_STREQ("Tomorrow's date is 2007 02 12", NextDate(2007, 2, 11));
        EXPECT_STREQ("Tomorrow's date is 2007 02 18", NextDate(2007, 2, 17));
        EXPECT_STREQ("Cannot have 2007 07 00", NextDate(2007, 7, 0));
        EXPECT_STREQ("Cannot have 2007 07 32", NextDate(2007, 7, 32));
        EXPECT_STREQ("Tomorrow's date is 2007 07 12", NextDate(2007, 7, 11));
        EXPECT_STREQ("Tomorrow's date is 2007 07 18", NextDate(2007, 7, 17));
    }

    TEST(NextDateTest, DecisionTable) {
        EXPECT_STREQ("Tomorrow's date is 2001 04 16", NextDate(2001, 4, 15));
        EXPECT_STREQ("Tomorrow's date is 2001 05 01", NextDate(2001, 4, 30));
        EXPECT_STREQ("Cannot have 2001 04 31", NextDate(2001, 4, 31));
        EXPECT_STREQ("Tomorrow's date is 2001 01 16", NextDate(2001, 1, 15));
        EXPECT_STREQ("Tomorrow's date is 2001 02 01", NextDate(2001, 1, 31));
        EXPECT_STREQ("Tomorrow's date is 2001 12 16", NextDate(2001, 12, 15));
        EXPECT_STREQ("Tomorrow's date is 2002 01 01", NextDate(2001, 12, 31));
        EXPECT_STREQ("Tomorrow's date is 2001 02 16", NextDate(2001, 2, 15));
        EXPECT_STREQ("Tomorrow's date is 2004 02 29", NextDate(2004, 2, 28));
        EXPECT_STREQ("Tomorrow's date is 2001 03 01", NextDate(2001, 2, 28));
        EXPECT_STREQ("Tomorrow's date is 2004 03 01", NextDate(2004, 2, 29));
        EXPECT_STREQ("Cannot have 2001 02 29", NextDate(2001, 2, 29));
        EXPECT_STREQ("Cannot have 2001 02 30", NextDate(2001, 2, 30));
    }

    TEST(NextDateTest, C0) {
        EXPECT_STREQ("2020 is over", NextDate(2020, 9, 9));
        EXPECT_STREQ("Cannot have 1968 00 15", NextDate(1968, 0, 15));
        EXPECT_STREQ("Cannot have 1999 12 35", NextDate(1999, 12, 35));
        EXPECT_STREQ("Tomorrow's date is 2001 07 14", NextDate(2001, 7, 13));
        EXPECT_STREQ("Tomorrow's date is 2000 08 01", NextDate(2000, 7, 31));
        EXPECT_STREQ("Cannot have 1997 10 32", NextDate(1997, 10, 32));
        EXPECT_STREQ("Tomorrow's date is 1996 04 03", NextDate(1996, 4, 2));
        EXPECT_STREQ("Tomorrow's date is 1993 12 01", NextDate(1993, 11, 30));
        EXPECT_STREQ("Cannot have 2015 06 31", NextDate(2015, 6, 31));
        EXPECT_STREQ("Tomorrow's date is 2016 12 30", NextDate(2016, 12, 29));
        EXPECT_STREQ("2019 is over", NextDate(2018, 12, 31));
        EXPECT_STREQ("Tomorrow's date is 2018 01 01", NextDate(2017, 12, 31));
        EXPECT_STREQ("Cannot have 1920 12 40", NextDate(1920, 12, 40));
        EXPECT_STREQ("Tomorrow's date is 1942 02 05", NextDate(1942, 2, 4));
        EXPECT_STREQ("Tomorrow's date is 2004 02 29", NextDate(2004, 2, 28));
        EXPECT_STREQ("Tomorrow's date is 2005 03 01", NextDate(2005, 2, 28));
        EXPECT_STREQ("Tomorrow's date is 2000 03 01", NextDate(2000, 2, 29));
        EXPECT_STREQ("Cannot have 1999 02 29", NextDate(1999, 2, 29));
        EXPECT_STREQ("Cannot have 2000 02 31", NextDate(2000, 2, 31));
    }

    TEST(NextDateTest, C1) {
        EXPECT_STREQ("1900 is over", NextDate(1900, 1, 1));
        EXPECT_STREQ("Cannot have 1966 15 13", NextDate(1966, 15, 13));
        EXPECT_STREQ("Cannot have 1998 12 999", NextDate(1998, 12, 999));
        EXPECT_STREQ("Tomorrow's date is 2010 08 16", NextDate(2010, 8, 15));
        EXPECT_STREQ("Tomorrow's date is 2000 11 01", NextDate(2000, 10, 31));
        EXPECT_STREQ("Cannot have 1990 01 430", NextDate(1990, 1, 430));
        EXPECT_STREQ("Tomorrow's date is 1976 09 22", NextDate(1976, 9, 21));
        EXPECT_STREQ("Tomorrow's date is 1943 07 01", NextDate(1943, 6, 30));
        EXPECT_STREQ("Cannot have 2013 11 31", NextDate(2013, 11, 31));
        EXPECT_STREQ("Tomorrow's date is 2018 12 03", NextDate(2018, 12, 2));
        EXPECT_STREQ("2019 is over", NextDate(2018, 12, 31));
        EXPECT_STREQ("Tomorrow's date is 2014 01 01", NextDate(2013, 12, 31));
        EXPECT_STREQ("Cannot have 1923 12 103", NextDate(1923, 12, 103));
        EXPECT_STREQ("Tomorrow's date is 1955 02 28", NextDate(1955, 2, 27));
        EXPECT_STREQ("Tomorrow's date is 2016 02 29", NextDate(2016, 2, 28));
        EXPECT_STREQ("Tomorrow's date is 2001 03 01", NextDate(2001, 2, 28));
        EXPECT_STREQ("Tomorrow's date is 2000 03 01", NextDate(2000, 2, 29));
        EXPECT_STREQ("Cannot have 1991 02 29", NextDate(1991, 2, 29));
        EXPECT_STREQ("Cannot have 2004 02 31", NextDate(2004, 2, 31));
    }

    TEST(NextDateTest, MCDC) {
        EXPECT_STREQ("1910 is over", NextDate(1910, 3, 8));
        EXPECT_STREQ("4000 is over", NextDate(4000, 12, 1));
        EXPECT_STREQ("Cannot have 1934 15 30", NextDate(1934, 15, 30));
        EXPECT_STREQ("Cannot have 1969 -3 01", NextDate(1969, -3, 1));
        EXPECT_STREQ("Cannot have 1948 12 00", NextDate(1948, 12, 0));
        EXPECT_STREQ("Cannot have 2011 12 123", NextDate(2011, 12, 123));
        EXPECT_STREQ("Tomorrow's date is 1925 01 26", NextDate(1925, 1, 25));
        EXPECT_STREQ("Tomorrow's date is 2001 04 01", NextDate(2001, 3, 31));
        EXPECT_STREQ("Cannot have 1980 05 220", NextDate(1980, 5, 220));
        EXPECT_STREQ("Tomorrow's date is 1976 09 30", NextDate(1976, 9, 29));
        EXPECT_STREQ("Tomorrow's date is 1944 05 01", NextDate(1944, 4, 30));
        EXPECT_STREQ("Cannot have 2015 11 330", NextDate(2015, 11, 330));
        EXPECT_STREQ("Tomorrow's date is 2017 12 09", NextDate(2017, 12, 8));
        EXPECT_STREQ("2019 is over", NextDate(2018, 12, 31));
        EXPECT_STREQ("Tomorrow's date is 2000 01 01", NextDate(1999, 12, 31));
        EXPECT_STREQ("Cannot have 1923 12 123", NextDate(1923, 12, 123));
        EXPECT_STREQ("Tomorrow's date is 1963 02 28", NextDate(1963, 2, 27));
        EXPECT_STREQ("Tomorrow's date is 2012 02 29", NextDate(2012, 2, 28));
        EXPECT_STREQ("Tomorrow's date is 2011 03 01", NextDate(2011, 2, 28));
        EXPECT_STREQ("Tomorrow's date is 2000 03 01", NextDate(2000, 2, 29));
        EXPECT_STREQ("Cannot have 1993 02 29", NextDate(1993, 2, 29));
        EXPECT_STREQ("Cannot have 2008 02 31", NextDate(2008, 2, 31));
    }

}
