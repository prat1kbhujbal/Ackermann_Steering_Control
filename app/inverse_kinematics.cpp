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

    if (left_angle < -robot2.getMaxSteerAngle() && right_angle < -
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

    if (left_angle > robot2.getMaxSteerAngle() && right_angle
    > robot2.getMaxSteerAngle()) {
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

  std::cout << "Current Robot Speed= " << new_speed <<std::endl;
  std::cout << "Left Wheel Speed= " << robot2.getLeftWheelVel()
  << std::endl;
  std::cout << "Right Wheel Speed= " << robot2.getRightWheelVel()
  << std::endl;
}
