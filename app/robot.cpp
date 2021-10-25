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

#include <robot.hpp>

double Robot::getWheelBase() {
  return _wheel_base;
}

double Robot::getTrackWidth() {
  return _track_width;
}

double Robot::getWheelRadius() {
  return _wheel_radius;
}
double Robot::getLeftWheelVel() {
  return _left_wheel_vel;
}
double Robot::getRightWheelVel() {
  return _right_wheel_vel;
}
double Robot::getLeftWheelAng() {
  return _left_wheel_ang;
}
double Robot::getRightWheelAng() {
  return _right_wheel_ang;
}
void Robot::setLeftWheelVel(double left_wheel_vel) {
  _left_wheel_vel = left_wheel_vel;
}
void Robot::setRightWheelVel(double right_wheel_vel) {
  _right_wheel_vel = right_wheel_vel;
}
void Robot::setLeftWheelAng(double left_wheel_ang) {
  _left_wheel_ang = left_wheel_ang;
}
void Robot::setRightWheelAng(double right_wheel_ang) {
  _right_wheel_ang = right_wheel_ang;
}

double Robot::getComOffset() {
  return _com_offset;
}
double Robot::getMaxSteerAngle() {
  return _max_steer_angle;
}
