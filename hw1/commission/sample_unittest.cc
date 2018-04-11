#include <limits.h>
#include "sample.h"
#include "gtest/gtest.h"

namespace {
  TEST(CommissionTest, NormalBoundary_Normal) {
    EXPECT_STREQ("Commission is $334.000000", Commission(1, 40, 45));
    EXPECT_STREQ("Commission is $343.000000", Commission(2, 40, 45));
    EXPECT_STREQ("Commission is $640.000000", Commission(35, 40, 45));
    EXPECT_STREQ("Commission is $946.000000", Commission(69, 40, 45));
    EXPECT_STREQ("Commission is $955.000000", Commission(70, 40, 45));
    EXPECT_STREQ("Commission is $406.000000", Commission(35, 1, 45));
    EXPECT_STREQ("Commission is $412.000000", Commission(35, 2, 45));
    EXPECT_STREQ("Commission is $640.000000", Commission(35, 40, 45));
    EXPECT_STREQ("Commission is $874.000000", Commission(35, 79, 45));
    EXPECT_STREQ("Commission is $880.000000", Commission(35, 80, 45));
    EXPECT_STREQ("Commission is $420.000000", Commission(35, 40, 1));
    EXPECT_STREQ("Commission is $425.000000", Commission(35, 40, 2));
    EXPECT_STREQ("Commission is $640.000000", Commission(35, 40, 45));
    EXPECT_STREQ("Commission is $860.000000", Commission(35, 40, 89));
    EXPECT_STREQ("Commission is $865.000000", Commission(35, 40, 90));
  }
  
  TEST(CommissionTest, NormalBoundary_Worst) {
    EXPECT_STREQ("Commission is $10.000000", Commission(1, 1, 1));
    EXPECT_STREQ("Commission is $12.500000", Commission(1, 1, 2));
    EXPECT_STREQ("Commission is $130.000000", Commission(1, 1, 45));
    EXPECT_STREQ("Commission is $320.000000", Commission(1, 1, 89));
    EXPECT_STREQ("Commission is $325.000000", Commission(1, 1, 90));
    EXPECT_STREQ("Commission is $13.000000", Commission(1, 2, 1));
    EXPECT_STREQ("Commission is $15.500000", Commission(1, 2, 2));
    EXPECT_STREQ("Commission is $134.500000", Commission(1, 2, 45));
    EXPECT_STREQ("Commission is $326.000000", Commission(1, 2, 89));
    EXPECT_STREQ("Commission is $331.000000", Commission(1, 2, 90));
    EXPECT_STREQ("Commission is $140.500000", Commission(1, 40, 1));
    EXPECT_STREQ("Commission is $144.250000", Commission(1, 40, 2));
    EXPECT_STREQ("Commission is $334.000000", Commission(1, 40, 45));
    EXPECT_STREQ("Commission is $554.000000", Commission(1, 40, 89));
    EXPECT_STREQ("Commission is $559.000000", Commission(1, 40, 90));
    EXPECT_STREQ("Commission is $348.000000", Commission(1, 79, 1));
    EXPECT_STREQ("Commission is $353.000000", Commission(1, 79, 2));
    EXPECT_STREQ("Commission is $568.000000", Commission(1, 79, 45));
    EXPECT_STREQ("Commission is $788.000000", Commission(1, 79, 89));
    EXPECT_STREQ("Commission is $793.000000", Commission(1, 79, 90));
    EXPECT_STREQ("Commission is $354.000000", Commission(1, 80, 1));
    EXPECT_STREQ("Commission is $359.000000", Commission(1, 80, 2));
    EXPECT_STREQ("Commission is $574.000000", Commission(1, 80, 45));
    EXPECT_STREQ("Commission is $794.000000", Commission(1, 80, 89));
    EXPECT_STREQ("Commission is $799.000000", Commission(1, 80, 90));
    EXPECT_STREQ("Commission is $14.500000", Commission(2, 1, 1));
    EXPECT_STREQ("Commission is $802.000000", Commission(2, 79, 90));
    EXPECT_STREQ("Commission is $363.000000", Commission(2, 80, 1));
    EXPECT_STREQ("Commission is $368.000000", Commission(2, 80, 2));
    EXPECT_STREQ("Commission is $583.000000", Commission(2, 80, 45));
    EXPECT_STREQ("Commission is $803.000000", Commission(2, 80, 89));
    EXPECT_STREQ("Commission is $808.000000", Commission(2, 80, 90));
    EXPECT_STREQ("Commission is $1105.000000", Commission(35, 80, 90));
    EXPECT_STREQ("Commission is $718.000000", Commission(69, 2, 45));
    EXPECT_STREQ("Commission is $938.000000", Commission(69, 2, 89));
    EXPECT_STREQ("Commission is $943.000000", Commission(69, 2, 90));
    EXPECT_STREQ("Commission is $975.000000", Commission(70, 80, 1));
    EXPECT_STREQ("Commission is $980.000000", Commission(70, 80, 2));
    EXPECT_STREQ("Commission is $1195.000000", Commission(70, 80, 45));
    EXPECT_STREQ("Commission is $1415.000000", Commission(70, 80, 89));
    EXPECT_STREQ("Commission is $1420.000000", Commission(70, 80, 90));
  }
  
  TEST(CommissionTest, RobustBoundary_Normal) {
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(0, 40, 45));
    EXPECT_STREQ("Commission is $334.000000", Commission(1, 40, 45));
    EXPECT_STREQ("Commission is $343.000000", Commission(2, 40, 45));
    EXPECT_STREQ("Commission is $640.000000", Commission(35, 40, 45));
    EXPECT_STREQ("Commission is $946.000000", Commission(69, 40, 45));
    EXPECT_STREQ("Commission is $955.000000", Commission(70, 40, 45));
    EXPECT_STREQ("Exceed production limits", Commission(71, 40, 45));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(35, 0, 45));
    EXPECT_STREQ("Commission is $406.000000", Commission(35, 1, 45));
    EXPECT_STREQ("Commission is $412.000000", Commission(35, 2, 45));
    EXPECT_STREQ("Commission is $640.000000", Commission(35, 40, 45));
    EXPECT_STREQ("Commission is $874.000000", Commission(35, 79, 45));
    EXPECT_STREQ("Commission is $880.000000", Commission(35, 80, 45));
    EXPECT_STREQ("Exceed production limits", Commission(35, 81, 45));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(35, 40, 0));
    EXPECT_STREQ("Commission is $420.000000", Commission(35, 40, 1));
    EXPECT_STREQ("Commission is $425.000000", Commission(35, 40, 2));
    EXPECT_STREQ("Commission is $640.000000", Commission(35, 40, 45));
    EXPECT_STREQ("Commission is $860.000000", Commission(35, 40, 89));
    EXPECT_STREQ("Commission is $865.000000", Commission(35, 40, 90));
    EXPECT_STREQ("Exceed production limits", Commission(35, 40, 91));
  }

  TEST(CommissionTest, RobustBoundary_Worst) {
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(0, 0, 0));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(0, 0, 1));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(0, 0, 2));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(0, 1, 89));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(0, 1, 90));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(0, 1, 91));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(0, 81, 90));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(0, 81, 91));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(1, 0, 0));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(1, 1, 0));
    EXPECT_STREQ("Commission is $10.000000", Commission(1, 1, 1));
    EXPECT_STREQ("Commission is $320.000000", Commission(1, 1, 89));
    EXPECT_STREQ("Commission is $325.000000", Commission(1, 1, 90));
    EXPECT_STREQ("Exceed production limits", Commission(1, 1, 91));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(1, 2, 0));
    EXPECT_STREQ("Commission is $13.000000", Commission(1, 2, 1));
    EXPECT_STREQ("Commission is $15.500000", Commission(1, 2, 2));
    EXPECT_STREQ("Commission is $134.500000", Commission(1, 2, 45));
    EXPECT_STREQ("Commission is $326.000000", Commission(1, 2, 89));
    EXPECT_STREQ("Commission is $331.000000", Commission(1, 2, 90));
    EXPECT_STREQ("Exceed production limits", Commission(1, 2, 91));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(1, 40, 0));
    EXPECT_STREQ("Exceed production limits", Commission(1, 80, 91));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(1, 81, 0));
    EXPECT_STREQ("Exceed production limits", Commission(1, 81, 1));
    EXPECT_STREQ("Commission is $17.500000", Commission(2, 2, 1));
    EXPECT_STREQ("Commission is $20.000000", Commission(2, 2, 2));
    EXPECT_STREQ("Commission is $141.250000", Commission(2, 2, 45));
    EXPECT_STREQ("Commission is $335.000000", Commission(2, 2, 89));
    EXPECT_STREQ("Commission is $340.000000", Commission(2, 2, 90));
    EXPECT_STREQ("Exceed production limits", Commission(2, 2, 91));
    EXPECT_STREQ("Commission is $654.000000", Commission(35, 79, 1));
    EXPECT_STREQ("Commission is $659.000000", Commission(35, 79, 2));
    EXPECT_STREQ("Commission is $874.000000", Commission(35, 79, 45));
    EXPECT_STREQ("Commission is $1094.000000", Commission(35, 79, 89));
    EXPECT_STREQ("Commission is $1099.000000", Commission(35, 79, 90));
    EXPECT_STREQ("Exceed production limits", Commission(35, 79, 91));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(35, 80, 0));
    EXPECT_STREQ("Exceed production limits", Commission(70, 80, 91));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(70, 81, 0));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(71, 0, 90));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(71, 0, 91));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(71, 1, 0));
    EXPECT_STREQ("Exceed production limits", Commission(71, 1, 1));
    EXPECT_STREQ("Exceed production limits", Commission(71, 1, 2));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(71, 81, 0));
    EXPECT_STREQ("Exceed production limits", Commission(71, 81, 1));
    EXPECT_STREQ("Exceed production limits", Commission(71, 81, 2));
    EXPECT_STREQ("Exceed production limits", Commission(71, 81, 45));
    EXPECT_STREQ("Exceed production limits", Commission(71, 81, 89));
    EXPECT_STREQ("Exceed production limits", Commission(71, 81, 90));
    EXPECT_STREQ("Exceed production limits", Commission(71, 81, 91));
  }

  TEST(CommissionTest, WeakNormal) {
    EXPECT_STREQ("Commission is $303.000000", Commission(24, 32, 7));
    EXPECT_STREQ("Commission is $842.000000", Commission(55, 32, 59));
    EXPECT_STREQ("Commission is $938.000000", Commission(55, 48, 59));
  }

  TEST(CommissionTest, SrongNormal) {
    EXPECT_STREQ("Commission is $130.750000", Commission(10, 21, 5));
    EXPECT_STREQ("Commission is $311.000000", Commission(10, 21, 47));
    EXPECT_STREQ("Commission is $245.000000", Commission(10, 45, 5));
    EXPECT_STREQ("Commission is $455.000000", Commission(10, 45, 47));
    EXPECT_STREQ("Commission is $614.000000", Commission(67, 21, 5));
    EXPECT_STREQ("Commission is $824.000000", Commission(67, 21, 47));
    EXPECT_STREQ("Commission is $758.000000", Commission(67, 45, 5));
    EXPECT_STREQ("Commission is $968.000000", Commission(67, 45, 47));
  }

  TEST(CommissionTest, WeakRobust) {
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(71, 0, 91));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(55, 79, 0));
    EXPECT_STREQ("Exceed production limits", Commission(71, 81, 91));
    EXPECT_STREQ("Exceed production limits", Commission(71, 31, 33));
    EXPECT_STREQ("Commission is $1174.000000", Commission(55, 79, 69));
    EXPECT_STREQ("Commission is $310.000000", Commission(11, 31, 33));
  }

  TEST(CommissionTest, StrongRobust) {
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(0, 0, 0));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(0, 0, 91));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(0, 0, 30));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(0, 0, 71));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(0, 81, 0));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(0, 81, 91));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(0, 81, 30));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(0, 81, 71));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(0, 32, 0));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(0, 32, 91));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(0, 32, 30));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(0, 32, 71));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(0, 46, 0));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(0, 46, 91));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(0, 46, 30));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(0, 46, 71));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(71, 0, 0));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(71, 0, 91));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(71, 0, 30));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(71, 0, 71));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(71, 81, 0));
    EXPECT_STREQ("Exceed production limits", Commission(71, 81, 91));
    EXPECT_STREQ("Exceed production limits", Commission(71, 81, 30));
    EXPECT_STREQ("Exceed production limits", Commission(71, 81, 71));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(71, 32, 0));
    EXPECT_STREQ("Exceed production limits", Commission(71, 32, 91));
    EXPECT_STREQ("Exceed production limits", Commission(71, 32, 30));
    EXPECT_STREQ("Exceed production limits", Commission(71, 32, 71));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(71, 46, 0));
    EXPECT_STREQ("Exceed production limits", Commission(71, 46, 91));
    EXPECT_STREQ("Exceed production limits", Commission(71, 46, 30));
    EXPECT_STREQ("Exceed production limits", Commission(71, 46, 71));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(19, 0, 0));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(19, 0, 91));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(19, 0, 30));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(19, 0, 71));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(19, 81, 0));
    EXPECT_STREQ("Exceed production limits", Commission(19, 81, 91));
    EXPECT_STREQ("Exceed production limits", Commission(19, 81, 30));
    EXPECT_STREQ("Exceed production limits", Commission(19, 81, 71));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(19, 32, 0));
    EXPECT_STREQ("Exceed production limits", Commission(19, 32, 91));
    EXPECT_STREQ("Commission is $373.000000", Commission(19, 32, 30));
    EXPECT_STREQ("Commission is $578.000000", Commission(19, 32, 71));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(19, 46, 0));
    EXPECT_STREQ("Exceed production limits", Commission(19, 46, 91));
    EXPECT_STREQ("Commission is $457.000000", Commission(19, 46, 30));
    EXPECT_STREQ("Commission is $662.000000", Commission(19, 46, 71));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(47, 0, 0));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(47, 0, 91));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(47, 0, 30));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(47, 0, 71));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(47, 81, 0));
    EXPECT_STREQ("Exceed production limits", Commission(47, 81, 91));
    EXPECT_STREQ("Exceed production limits", Commission(47, 81, 30));
    EXPECT_STREQ("Exceed production limits", Commission(47, 81, 71));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(47, 32, 0));
    EXPECT_STREQ("Exceed production limits", Commission(47, 32, 91));
    EXPECT_STREQ("Commission is $625.000000", Commission(47, 32, 30));
    EXPECT_STREQ("Commission is $830.000000", Commission(47, 32, 71));
    EXPECT_STREQ("Have to sell at least one lock, one stock, and one barrel", Commission(47, 46, 0));
    EXPECT_STREQ("Exceed production limits", Commission(47, 46, 91));
    EXPECT_STREQ("Commission is $709.000000", Commission(47, 46, 30));
    EXPECT_STREQ("Commission is $914.000000", Commission(47, 46, 71));
  }

  TEST(CommissionTest, DecisionTable) {
    EXPECT_STREQ("Exceed production limits", Commission(75, 5, 5));
    EXPECT_STREQ("Exceed production limits", Commission(65, 85, 5));
    EXPECT_STREQ("Exceed production limits", Commission(65, 75, 95));
    EXPECT_STREQ("Commission is $50.000000", Commission(5, 5, 5));
    EXPECT_STREQ("Commission is $145.000000", Commission(5, 15, 25));
    EXPECT_STREQ("Commission is $1320.000000", Commission(65, 75, 85));
  }

}
