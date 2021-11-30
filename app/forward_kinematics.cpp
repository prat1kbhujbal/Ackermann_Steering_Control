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
 * @file forward_kinematics.cpp
 * @author Pratik Bhujnbal
 * @brief Implementation file for ackermann controller goal attributes
 *        and its members.
 * @version 1.1
 * @date 11/29/2021
 * @copyright  Copyright (c) 2021
 * 
 */

#include<iostream>
#include<cmath>
#include<forward_kinematics.hpp>
#include<pid.hpp>
#include<controller.hpp>
#include<sensor.hpp>
#include<robot.hpp>
#include<convergence.hpp>

PID pid_steer(1, 1, 1, 0.2, -0.785, 0.785);
PID pid_speed(0.1, 0.1, 0.2, 0.2, 0, 10);
Sensor sensor1;
Robot robot1(4, 2, 0.3, 0.1, 0.1, 0, 0, 1, 0.785);

double ForwardKinematics::getR1() {
  return _R1;
}

void ForwardKinematics::setDTheta(double d_theta) {
  _d_theta = d_theta;
}

double ForwardKinematics::calculateNewHeading(double goal_heading) {
  if (goal_heading > 1.57)
    goal_heading = 3.14 - goal_heading;

  _new_heading = pid_steer.compute(sensor1.getCurrerntHeading(), goal_heading);

  if (_new_heading > 0.01) {         // Left Turn
    _R =
        sqrt(
            pow(robot1.getComOffset(), 2)
                + (pow(robot1.getWheelBase(), 2)
                    * (1 / pow(tan(_new_heading), 2))));

    _R1 = sqrt(pow(_R, 2) - pow(robot1.getComOffset(), 2));

    _d_theta = (robot1.getWheelRadius() * robot1.getLeftWheelVel() * 1)
        / (_R1 + (robot1.getTrackWidth() / 2));
  setDTheta(_d_theta);
  } else if (_new_heading < 0.01) {   // Right Turn
    _R =
        sqrt(
            pow(robot1.getComOffset(), 2)
                + (pow(robot1.getWheelBase(), 2)
                    * (1 / pow(tan(-_new_heading), 2))));

    _R1 = sqrt(pow(_R, 2) - pow(robot1.getComOffset(), 2));

    _d_theta = -(robot1.getWheelRadius() * robot1.getLeftWheelVel() * 1)
        / (_R1 + (robot1.getTrackWidth() / 2));
  } else {
    _new_heading = 0;
  }

  sensor1.setCurrerntHeading(sensor1.getCurrerntHeading() + _d_theta);
  heading_vector.push_back(sensor1.getCurrerntHeading());

  std::cout << "Current Robot heading= " << sensor1.getCurrerntHeading()
      << std::endl;
  return _new_heading;
}

double ForwardKinematics::calculateNewSpeed(double goal_speed) {
  _new_speed = pid_speed.compute(sensor1.getCurrentSpeed(), goal_speed);
  if (_new_speed > goal_speed)
    _new_speed = goal_speed;
  sensor1.setCurrerntSpeed(_new_speed);
  speed_vector.push_back(sensor1.getCurrentSpeed());
  return _new_speed;
}

bool ForwardKinematics::goalStatus(FkGoal fkgoal) {
  if (fkgoal.status == true) {
    std::cout << "Goal Received" << std::endl;
    return true;
  } else {
    return false;
  }
}
