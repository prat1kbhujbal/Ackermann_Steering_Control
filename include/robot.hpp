/** 
 * @file robot.hpp
 * @author Pratik Bhujbal
 * @author Maaruf Vazifdar
 * @author Maitreya Kulkarni
 * @brief A class to hold robot attributes and its members.
 * @version 1.1
 * @date 10/15/2021
 * Copyright [2021] ENPM808X group - MT-15
 */

#pragma once

class Robot {
 public:
  
  Robot(double wheel_base, double track_width, double wheel_radius,
    double left_wheel_vel, double right_wheel_vel,
    double left_wheel_ang, double right_wheel_ang,
    double com_offset, double max_steer_angle)
      : _wheel_base(wheel_base),
        _track_width(track_width),
        _wheel_radius(wheel_radius),
        _left_wheel_vel(left_wheel_vel),
        _right_wheel_vel(right_wheel_vel),
        _left_wheel_ang(left_wheel_ang),
        _right_wheel_ang(right_wheel_ang),
        _com_offset(com_offset),
        _max_steer_angle(max_steer_angle) {}

  ~Robot() {}

  double getWheelBase();

  double getTrackWidth();

  double getWheelRadius();

  double getLeftWheelVel();

  double getRightWheelVel();

  double getLeftWheelAng();

  double getRightWheelAng();

  double getComOffset();

  double getMaxSteerAngle();

  void setLeftWheelVel(double);

  void setRightWheelVel(double);

  void setLeftWheelAng(double);

  void setRightWheelAng(double);

 private:
  double _wheel_base, _track_width, _wheel_radius,
    _left_wheel_vel, _right_wheel_vel, _left_wheel_ang,
    _right_wheel_ang, _com_offset, _max_steer_angle;
};
