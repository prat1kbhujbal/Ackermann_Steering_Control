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
/**
 * @brief Class to apply inverse kinematics.
 */
class InverseKinematics {
 public:
  /**
   * @brief Constructor for class InverseKinematics
   */
  InverseKinematics() {}

  /**
   * @brief Destructor for class InverseKinematics
   */
  ~InverseKinematics() {}

  /**
   * @brief Calculate the left and right wheel angles based on heading output 
   *        of fk.
   * @param double - heading output from fk
   * @return void
   */
  void calculateWheelAngles(double);

  /**
   * @brief Calculate the left and right wheel speeds based on heading output 
   *        of fk.
   * @param double - speed output from fk
   * @return void
   */
  void calculateWheelSpeeds(double);
};
