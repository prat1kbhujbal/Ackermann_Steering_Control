/** 
 * @file forward_kinematics.hpp
 * @author Pratik Bhujbal
 * @author Maaruf Vazifdar
 * @author Maitreya Kulkarni
 * @brief A class to calculate forward kinematics of 
 *        ackermann robot
 * @version 1.1
 * @date 10/15/2021
 * Copyright [2021] ENPM808X group - MT-15
 */

#pragma once
class ForwardKinematics {
 public:
  ForwardKinematics() {
  }

  ~ForwardKinematics() {}

  double getR1();

  void setDTheta(double d_theta);

  double calculateNewHeading(double goal_heading);

  double calculateNewSpeed(double goal_speed);

  bool goalReached(double goal_heading, double goal_speed);

 private:
  double _new_heading, _new_speed, _R, _R1, _d_theta;
};
