/**
 * MIT License
 *
 * Copyright (c) 2021 Maaruf Vazifdar, Maitreya Kulkarni, Pratik Bhujnbal
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to 
 * deal in the Software without restriction, including without limitation the  
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or 
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in 
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
 * DEALINGS IN THE SOFTWARE. 
 * 
 * @file controller.cpp
 * @author Maaruf Vazifdar
 * @author Maitreya Kulkarni
 * @author Pratik Bhujnbal
 * @brief Implementation file for ackermann controller goal attributes
 *        and its members.
 * @version 1.1
 * @date 10/15/2021
 * @copyright  Copyright (c) 2021
 * 
 */

#include<iostream>
#include<pid.hpp>
#include<robot.hpp>
#include<controller.hpp>
#include<forward_kinematics.hpp>
#include <inverse_kinematics.hpp>
#include<sensor.hpp>
#include<convergence.hpp>

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
  Convergence c1;
  std::string h1 = "heading.png";
  std::string h2 = "speed.png";
  c1.plotConvergence(goal_heading, fk.heading_vector, h1);
  c1.plotConvergence(goal_speed, fk.speed_vector, h2);
  return 0;
}
