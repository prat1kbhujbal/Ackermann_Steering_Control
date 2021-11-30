/**
 * MIT License
 *
 * Copyright (c) 2021 Maaruf Vazifdar, Maitreya Kulkarni, Pratik Bhujnbal
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to 
 * deal in the Software without restriction, including without limitation the  
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or 
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in 
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
 * DEALINGS IN THE SOFTWARE. 
 * 
 * @file controller.cpp
 * @author Maaruf Vazifdar
 * @author Maitreya Kulkarni
 * @author Pratik Bhujnbal
 * @brief Implementation file for ackermann controller goal attributes
 *        and its members.
 * @version 1.1
 * @date 10/15/2021
 * @copyright  Copyright (c) 2021
 * 
 */

#include <gtest/gtest.h>
#include <string>
#include "../include/pid.hpp"
#include "../include/controller.hpp"
#include "../include/robot.hpp"
#include "../include/sensor.hpp"
#include "../include/forward_kinematics.hpp"
#include "../include/inverse_kinematics.hpp"
#include "../include/convergence.hpp"

/**
* @brief Test for pid compute member
*/
TEST(computePidTest, gain_update_check) {
    PID pid(0.8, 0.5, 0.3, 1.0, -20, 20);
    double something = pid.compute(0, 5);
    EXPECT_NEAR(something, 8, 0.5);
    EXPECT_EQ(0.8, pid.getKp());
    EXPECT_EQ(0.5, pid.getKi());
    EXPECT_EQ(0.3, pid.getKd());
    EXPECT_EQ(1.0, pid.getDt());
}
/**
* @brief Test for invalid sampling time
*/
TEST(invaliddt, checkParameters) {
  PID pid1(1, 1, 1, 0, 0, 0);
  EXPECT_THROW(pid1.compute(1, 5), std::domain_error);
}

/**
* @brief Test for invalid PID gain parameters
*/
TEST(invalidGains, checkParameters) {
  // invalid Kp
  PID pid2(0, 1, 1, 1, 10, 10);
  EXPECT_THROW(pid2.compute(1, 5), std::domain_error);

  // invalid Ki
  PID pid3(1, 0, 1, 1, 10, 10);
  EXPECT_THROW(pid3.compute(1, 5), std::domain_error);

  // invalid Kd
  PID pid4(1, 1, 0, 1, 10, 10);
  EXPECT_THROW(pid4.compute(1, 5), std::domain_error);
}


TEST(goalsetterTest, controllerTest) {
    Controller controller;
    controller.setGoal(0.5, 10);
    EXPECT_EQ(10, controller.getGoalSpeed());
    EXPECT_EQ(0.5, controller.getGoalHeading());
}

TEST(robotTest, robotMembersTest) {
    Robot robot(2, 3, 0.2, 10, 10, 0.25, 0.26, 1, 0.785);
    robot.setLeftWheelVel(25);
    robot.setRightWheelVel(25);
    robot.setLeftWheelAng(0.7);
    robot.setRightWheelAng(0.7);
    EXPECT_EQ(2, robot.getWheelBase());
    EXPECT_EQ(3, robot.getTrackWidth());
    EXPECT_EQ(0.2, robot.getWheelRadius());
    EXPECT_EQ(25, robot.getLeftWheelVel());
    EXPECT_EQ(25, robot.getRightWheelVel());
    EXPECT_EQ(0.7, robot.getLeftWheelAng());
    EXPECT_EQ(0.7, robot.getRightWheelAng());
    EXPECT_EQ(1, robot.getComOffset());
    EXPECT_EQ(0.785, robot.getMaxSteerAngle());
}

TEST(sensorTest, sensorMemberTest) {
    Sensor sensor;
    sensor.setCurrerntHeading(0.5);
    sensor.setCurrerntSpeed(5);
    EXPECT_EQ(sensor.getCurrerntHeading(), 0.5);
    EXPECT_EQ(sensor.getCurrentSpeed(), 5);
}

TEST(InverseKinematicsTest, inverseKinematicsMembersTest) {
    Robot robot2(4, 2, 0.3, 0.01, 0.01, 0, 0, 1, 0.785);
    ForwardKinematics fk2;
    InverseKinematics ik1;
    ik1.calculateWheelAngles(0.1);
    ik1.calculateWheelSpeeds(10);
    EXPECT_NEAR(robot2.getLeftWheelAng(), 0, 1);
    EXPECT_NEAR(robot2.getRightWheelAng(), 0, 1);
    EXPECT_NEAR(robot2.getLeftWheelVel(), 0.01, 1);
    EXPECT_NEAR(robot2.getRightWheelVel(), 0.01, 1);
}

TEST(InverseKinematicsTest1, inverseKinematicsMembersTest) {
    Robot robot3(4, 2, 0.3, 0.01, 0.01, 0, 0, 1, 0.785);
    ForwardKinematics fk3;
    InverseKinematics ik2;
    ik2.calculateWheelAngles(-0.1);
    ik2.calculateWheelSpeeds(5);
    EXPECT_NEAR(robot3.getLeftWheelAng(), 0, 1);
    EXPECT_NEAR(robot3.getRightWheelAng(), 0, 1);
    EXPECT_NEAR(robot3.getLeftWheelVel(), 0.01, 1);
    EXPECT_NEAR(robot3.getRightWheelVel(), 0.01, 1);
}

TEST(InverseKinematicsTest2, inverseKinematicsMembersTest) {
    Robot robot4(4, 2, 0.3, 0.01, 0.01, 0, 0, 1, 0.785);
    ForwardKinematics fk4;
    InverseKinematics ik3;
    ik3.calculateWheelAngles(1);
    ik3.calculateWheelSpeeds(8);
    EXPECT_NEAR(robot4.getLeftWheelAng(), 0, 1);
    EXPECT_NEAR(robot4.getRightWheelAng(), 0, 1);
    EXPECT_NEAR(robot4.getLeftWheelVel(), 0.01, 1);
    EXPECT_NEAR(robot4.getRightWheelVel(), 0.01, 1);
}
