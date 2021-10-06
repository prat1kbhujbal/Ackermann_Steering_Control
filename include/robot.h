/** 
 * @file robot.h
 * @author Maaruf Vazifdar
 * @author Maitreya Kulkarni
 * @author Pratik Bhujnbal
 * @brief A class to hold robot attributes and its members.
 * @version 0.1
 * @date 10/05/2021
 * Copyright [2021] ENPM808X group - MT-15
 */

#pragma once
class Robot {
 public:
  /**
   * @brief Constructor for class Robot
   * @param robot_wheelbase double
   * @param left_steerangle double
   * @param right_steerangle double
   */
  Robot(double robot_wheelbase, double left_steerangle, double right_steerangle){
  };

  /**
   * @brief Destructor for class Robot
   */
  ~Robot();

  /**
   * @brief Set robot attributes
   * @param robot_wheelbase double
   * @param left_steerangle double
   * @param right_steerangle double
   * @return void 
   */
  void setRobotParameters(double robot_wheelbase, double left_steerangle, double right_steerangle);

  /**
   * @brief Get wheelbase of robot
   * @return double 
   */
  double getRobotWheelbase();

  /**
   * @brief Get the steering angle of left wheel
   * @return double 
   */
  double getRightSteerAngle();

  /**
   * @brief Get steering angle of left wheel
   * @return double 
   */
  double getLeftSteerAngle();

 private:
  /**
   * Class local variables.
   */
  double _robot_wheelbase, _left_steerangle, _right_steerangle;
};
