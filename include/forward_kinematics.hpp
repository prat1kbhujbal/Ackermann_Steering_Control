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
#include<vector>
#pragma once
/**
 * @brief Class to apply forward kinematics.
 */
class ForwardKinematics {
 public:
  std::vector <double> heading_vector;
  std::vector <double> speed_vector;
  /**
   * @brief Consructor for class ForwardKinematics to initialize values 
   *        local variables to 0.
   * @param void
   * @return void
   */
  ForwardKinematics() {
    _new_heading = 0;
    _new_speed = 0;
    _d_theta = 0;
    _R = 0;
    _R1 = 0;
  }

  /**
   * @brief Destructor for class ForwardKinematics
   */
  ~ForwardKinematics() {}

  /**
  * @brief Get turning raduis from centre of rear axle. 
  * @param void
  * @return double - turning raduis from centre of rear axle
  */
  double getR1();

  /**
  * @brief Get change in robot heading. 
  * @param d_theta double - change in robot's heading.
  * @return void
  */
  void setDTheta(double d_theta);

  /**
  * @brief Calculate new heading required to reach the goal heading.
  * @param goal_heading double - robot's goal heading
  * @return double - new heading required to reach the goal heading
  */
  double calculateNewHeading(double goal_heading);

  /**
  * @brief Calculate new speed required to reach the goal speed.
  * @param goal_speed double - robot's goal speed
  * @return double - new speed required to reach the goal speed
  */
  double calculateNewSpeed(double goal_speed);

  /**
   * @brief Boolean value for goal reached
   * @param goal_heading double - robot's goal heading
   * @param goal_speed double - robot's goal speed
   * @return bool
   */ 
  bool goalReached(double goal_heading, double goal_speed);

 private:
  /**
   * Class local variables.
   */
  double _new_heading, _new_speed, _R, _R1, _d_theta;
};
