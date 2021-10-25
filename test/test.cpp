#include <gtest/gtest.h>
#include <iostream>
#include<string>
#include "../include/pid.hpp"
#include "../include/controller.hpp"
#include "../include/robot.hpp"
#include "../include/sensor.hpp"
#include "../include/forward_kinematics.hpp"
#include "../include/inverse_kinematics.hpp"
#include "../include/convergence.hpp"

TEST(computePidTest, gain_update_check) {
    PID pid(0.8, 0.5, 0.3, 1.0, -20, 20);
    double something = pid.compute(0, 5);
    std::cout<<something<<std::endl;
    EXPECT_NEAR(something, 8, 0.5);
    EXPECT_EQ(0.8,pid.getKp());
    EXPECT_EQ(0.5, pid.getKi());
    EXPECT_EQ(0.3, pid.getKd());
    EXPECT_EQ(1.0,pid.getDt());
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
    EXPECT_EQ(10,controller.getGoalSpeed());
    EXPECT_EQ(0.5,controller.getGoalHeading());
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

TEST(sensorTest, sensorMemberTest){
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

TEST(forwardKinematicsTest, forwardKinematicsMemeberTest) {
    ForwardKinematics fk;
    PID pid_steer(1, 1, 1, 0.1, -0.785, 0.785);
    PID pid_speed(1, 1, 1, 0.1, 0, 1);
    Sensor sensor1;
    sensor1.setCurrerntHeading(0.1);
    sensor1.setCurrerntSpeed(10);
    Robot robot1(4, 2, 0.3, 0.1, 0.1, 0, 0, 1, 0.785);
    fk.setDTheta(0.1);
    EXPECT_EQ(0,fk.getR1());
    EXPECT_NEAR(fk.calculateNewHeading(0.1), 0.62, 0.1);
    EXPECT_NEAR(fk.calculateNewSpeed(5), 5, 0.1);
    EXPECT_TRUE(fk.goalReached(0.1, 10));
}

TEST(forwardKinematicsTest1, forwardKinematicsMemeberTest) {
    ForwardKinematics fk1;
    PID pid_steer1(1, 1, 1, 0.1, -0.785, 0.785);
    PID pid_speed1(1, 1, 1, 0.1, 0, 1);
    Sensor sensor2;
    Convergence c1;
    
    sensor2.setCurrerntHeading(0.1);
    sensor2.setCurrerntSpeed(10);
    Robot robot2(4, 2, 0.3, 0.1, 0.1, 0, 0, 1, 0.785);
    fk1.setDTheta(0.1);
    std::vector<double> my_vector{1,2,3};
    std::string my_string = "speed.png";
    EXPECT_EQ(0, fk1.getR1());
    EXPECT_NEAR(fk1.calculateNewHeading(-0.1), -0.785, 0.1);
    EXPECT_NEAR(fk1.calculateNewSpeed(5), 5, 0.1);
    EXPECT_EQ(1, c1.plotConvergence(0.1, my_vector, my_string));
}
