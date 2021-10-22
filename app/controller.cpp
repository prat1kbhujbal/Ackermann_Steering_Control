/** 
 * @file controller.cpp
 * @author Maaruf Vazifdar
 * @author Maitreya Kulkarni
 * @author Pratik Bhujnbal
 * @brief Implementation file for ackermann controller goal attributes
 *        and its members.
 * @version 1.1
 * @date 10/15/2021
 * Copyright [2021] ENPM808X group - MT-15
 */

#include <iostream>
#include <controller.hpp>

double Controller::getGoalHeading() {
  return _goal_heading;
}

double Controller::getGoalSpeed() {
  return _goal_speed;
}

void Controller::setGoal(double goal_heading,  double goal_speed) {
  _goal_heading = goal_heading;
  _goal_speed = goal_speed;
}
