/** 
 * @file ackermann_controller.h
 * @author Maaruf Vazifdar
 * @author Maitreya Kulkarni
 * @author Pratik Bhujnbal
 * @brief A class to hold ackermann_controller attributes and its members.
 * @version 0.1
 * @date 10/05/2021
 * Copyright [2021] ENPM808X group - MT-15
 */

#pragma once
class AckermannController {
 public:
  /**
   * @brief Constructor for class Robot
   * @param max_steerangle double
   * @param max_velocity double
   * @param desired_velocity double
   * @param desired_heading double 
   * @param current_heading double
   */
  AckermannController(double max_steerangle, double max_velocity, double desired_velocity, double desired_heading, double current_heading){
  };

  /**
   * @brief Set desired robot velocity
   * @param desired_velocity double
   * @return void 
   */
  void setDesiredVel(double desired_velocity);

  /**
   * @brief Set desired robot heading
   * @return double 
   */
  void setDesiredHeading(double desired_heading);

  /**
   * @brief Get desired robot velocity
   * @return double 
   */
  double getDesiredVel();

  /**
   * @brief Get desired robot heading
   * @return double 
   */
  double getDesiredHeading();

  /**
   * @brief Calculate current robot heading
   * @param robot_velocity double
   * @param steering_angle double
   * @param robot_wheelbase double
   * @return current_heading double 
   */
  double calculateCurrentHeading(double robot_velocity,double steering_angle, double robot_wheelbase);
 
 private:
  /**
   * Class local variables.
   */
  double _max_steerangle, _max_velocity, _desired_velocity, _desired_heading, _current_heading;
};
