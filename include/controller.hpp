/** 
 * @file controller.hpp
 * @author Maaruf Vazifdar
 * @author Maitreya Kulkarni
 * @author Pratik Bhujnbal
 * @brief A class to hold controller  goal attributes and its members.
 * @version 1.1
 * @date 10/15/2021
 * Copyright [2021] ENPM808X group - MT-15
 */

#pragma once
/**
 * @brief Class to hold goal attributes and members.
 */
class Controller {
 public:
  /** @brief  Constrctor of Class Controller to initialize goal values.
   */

  Controller() {
  _goal_heading = 0;
  _goal_speed = 0;
  }

  /**
   * @brief Destructor of class Controller.
   */
  ~Controller() {}

  /**
   * @brief Get goal heading value. (0 to 3.14 radians)
   * @param void
   * @return double - Robot's goal heading (in radians)
   */
  double getGoalHeading();

  /**
   * @brief Get goal speed value. (in meters/seconds)
   * @return double - Robot's goal speed (in meters/seconds)
   */
  double getGoalSpeed();

  /**
   * @brief Get set goal heading and speed values.
   * @param goal_heading (0 to 3.14 radians)
   * @param goal_speed (in meters/seconds)
   * @return void
   */
  void setGoal(double goal_heading,  double goal_speed);

 private:
  /**
   * Class local variables.
   * _goal_heading (0 to 3.14 radians)
   * _goal_speed (in meters/seconds)
   */
  double _goal_heading, _goal_speed;
};
