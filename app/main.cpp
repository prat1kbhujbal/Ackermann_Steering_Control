/** 
 * @file main.cpp
 * @author Maaruf Vazifdar
 * @author Maitreya Kulkarni
 * @author Pratik Bhujnbal
 * @brief main file to implement the ackermann controller
 * @version 1.1
 * @date 10/15/2021
 * Copyright [2021] ENPM808X group - MT-15
 */

#include<pid.hpp>
#include<robot.hpp>
#include<controller.hpp>
#include<forward_kinematics.hpp>
#include <inverse_kinematics.hpp>
#include<sensor.hpp>
#include<iostream>

int main() {
  double goal_heading, goal_speed;

  std::cout << "Ackermann controller" << std::endl;
  
  std::cout << "Enter goal heading: "<< std::endl;
  std::cin >> goal_heading;
  std::cout << "Enter goal speed: " << std::endl;
  std::cin >> goal_speed;

  Controller cont1;
  cont1.setGoal(goal_heading, goal_speed);
  std::cout << "Goal heading= " << cont1.getGoalHeading() << std::endl;
  std::cout << "Goal speed= " << cont1.getGoalSpeed() << std::endl;

  ForwardKinematics fk;
  InverseKinematics ik;
  while (fk.goalReached(cont1.getGoalHeading(), cont1.getGoalSpeed())) {
    std::cout << "---------------" << std::endl;
    ik.calculateWheelAngles(fk.calculateNewHeading(cont1.getGoalHeading()));
    ik.calculateWheelSpeeds(fk.calculateNewSpeed(cont1.getGoalSpeed()));
  }
  return 0;
}
