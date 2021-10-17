/** 
 * @file robot.h
 * @author Pratik Bhujbal
 * @author Maaruf Vazifdar
 * @author Maitreya Kulkarni
 * @brief Implementation file for robot attributes and its members.
 * @version 1.1
 * @date 10/15/2021
 * Copyright [2021] ENPM808X group - MT-15
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
