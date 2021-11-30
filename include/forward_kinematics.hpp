/**
 * MIT License
 *
 * Copyright (c) 2021 Pratik Bhujnbal
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
 * @file forward_kinematics.cpp
 * @author Maaruf Vazifdar
 * @author Maitreya Kulkarni
 * @author Pratik Bhujbal
 * @brief Implementation file for ackermann controller goal attributes
 *        and its members.
 * @version 1.1
 * @date 10/15/2021
 * @copyright  Copyright (c) 2021
 * 
 */
#include<vector>
#include<fk_goal.hpp>

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
  * @brief Get turning raduis from centre of rear axle. (in meters)
  * @param void
  * @return double - turning raduis from centre of rear axle (in meters)
  */
  double getR1();

  /**
  * @brief Set change in robot heading. (in radians)
  * @param d_theta double - change in robot's heading. (in radians)
  * @return void
  */
  void setDTheta(double d_theta);

  /**
  * @brief Calculate new heading required to reach the goal heading. (in radians)
  * @param goal_heading double - robot's goal heading
  * @return double - new heading required to reach the goal heading
  */
  double calculateNewHeading(double goal_heading);

  /**
  * @brief Calculate new speed required to reach the goal speed. (in meters/seconds)
  * @param goal_speed double - robot's goal speed
  * @return double - new speed required to reach the goal speed
  */
  double calculateNewSpeed(double goal_speed);

  /**
   * @brief Boolean value for goal Status (True/False)
   * @return bool
   */ 
  bool goalStatus(FkGoal fkgoal);

 private:
  /**
   * Class local variables.
   * _new_heading (in radians)
   * _new_speed (in meters/second)
   * _R (in meters)
   * _R1 (in meters)
   * _d_theta (in radians)
   */
  double _new_heading, _new_speed, _R, _R1, _d_theta;
};
