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

class Controller {
 public:
   Controller() {}

  ~Controller() {}

  double getGoalHeading();

  double getGoalSpeed();

  void setGoal();

 private:

  double _goal_heading, _goal_speed;
};
