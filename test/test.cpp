#include <gtest/gtest.h>
#include <iostream>
#include "../include/pid.hpp"

TEST(computepidTest, should_pass) {
    PID pid(0.8, 0.5, 0.3, 1.0, -20, 20);
    double something = pid.compute(0, 5);
    std::cout<<something<<std::endl;
    EXPECT_NEAR(something, 8, 0.5);
    EXPECT_EQ(0.8,pid.getKp());
    EXPECT_EQ(0.5, pid.getKi());
    EXPECT_EQ(0.3, pid.getKd());
    EXPECT_EQ(1.0,pid.getDt());
}

