/** 
 * @file inverse_kinematics.cpp
 * @author Pratik Bhujbal
 * @author Maaruf Vazifdar
 * @author Maitreya Kulkarni
 * @brief Implementation of class to calculate inverse kinematics of 
 *        ackermann robot
 * @version 1.1
 * @date 10/15/2021
 * Copyright [2021] ENPM808X group - MT-15
 */

#include<iostream>
#include <cmath>
#include <inverse_kinematics.hpp>
#include <forward_kinematics.hpp>
#include <pid.hpp>
#include <controller.hpp>
#include<sensor.hpp>
#include<robot.hpp>

Robot robot2(4, 2, 0.3, 0.01, 0.01, 0, 0, 1, 0.785);
ForwardKinematics fk;

void InverseKinematics::calculateWheelAngles(double new_heading) {
  if (new_heading < 0) {
    double left_angle = -atan(robot2.getWheelBase() / (fk.getR1() +
    robot2.getTrackWidth() / 2));
    double right_angle = atan(robot2.getWheelBase() / (fk.getR1() -
    robot2.getTrackWidth() / 2));

    if (left_angle > -robot2.getMaxSteerAngle() && right_angle > -
    robot2.getMaxSteerAngle()) {
      robot2.setLeftWheelAng(-robot2.getMaxSteerAngle());
      robot2.setRightWheelAng(-robot2.getMaxSteerAngle());
    } else {
      robot2.setLeftWheelAng(left_angle);
      robot2.setRightWheelAng(right_angle);
    }
  } else if (new_heading > 0) {
    double left_angle = atan(robot2.getWheelBase() / (fk.getR1() +
    robot2.getTrackWidth() / 2));
    double right_angle = -atan(robot2.getWheelBase() / (fk.getR1() -
    robot2.getTrackWidth() / 2));

    if (left_angle < robot2.getMaxSteerAngle() && right_angle
    < robot2.getMaxSteerAngle()) {
      robot2.setLeftWheelAng(robot2.getMaxSteerAngle());
      robot2.setRightWheelAng(robot2.getMaxSteerAngle());
    } else {
      robot2.setLeftWheelAng(left_angle);
      robot2.setRightWheelAng(right_angle);
    }
  } else {
    robot2.setLeftWheelAng(0);
    robot2.setRightWheelAng(0);
  }

  std::cout << "Left Wheel Angle= " << robot2.getLeftWheelAng()
  << std::endl;
  std::cout << "Right Wheel Angle= " << robot2.getRightWheelAng()
  << std::endl;
}

void InverseKinematics::calculateWheelSpeeds(double new_speed) {
  robot2.setLeftWheelVel(new_speed / robot2.getWheelRadius());
  robot2.setRightWheelVel(new_speed / robot2.getWheelRadius());

  std::cout << "Robot Speed= " << new_speed <<std::endl;
  std::cout << "Left Wheel Speed= " << robot2.getLeftWheelVel()
  << std::endl;
  std::cout << "Right Wheel Speed= " << robot2.getRightWheelVel()
  << std::endl;
}
