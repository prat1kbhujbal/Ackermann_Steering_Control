/** 
 * @file inverse_kinematics.hpp
 * @author Pratik Bhujbal
 * @author Maaruf Vazifdar
 * @author Maitreya Kulkarni
 * @brief A class to calculate inverse kinematics of 
 *        ackermann robot.
 * @version 1.1
 * @date 10/15/2021
 * Copyright [2021] ENPM808X group - MT-15
 */

#pragma once
class InverseKinematics {
 public:
  InverseKinematics() {}
/
  ~InverseKinematics() {}

  void calculateWheelAngles(double);

  void calculateWheelSpeeds(double);
};
