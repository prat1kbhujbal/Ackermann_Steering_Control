/** 
 * @file forward_kinematics.cpp
 * @author Pratik Bhujbal
 * @author Maaruf Vazifdar
 * @author Maitreya Kulkarni
 * @brief Implementation of class to calculate forward kinematics of 
 *        ackermann robot
 * @version 1.1
 * @date 10/15/2021
 * Copyright [2021] ENPM808X group - MT-15
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
    goal_heading = 3.14 -goal_heading;

  _new_heading = pid_steer.compute(sensor1.getCurrerntHeading(), goal_heading);

  if (_new_heading > 0.01) {         // Left Turn
    _R = sqrt(pow(robot1.getComOffset(), 2) + (pow(robot1.getWheelBase(), 2)
        * (1 / pow(tan(_new_heading), 2))));

  _R1 = sqrt(pow(_R, 2) - pow(robot1.getComOffset(), 2));

  _d_theta = (robot1.getWheelRadius() * robot1.getLeftWheelVel()
      * 1) / (_R1 + (robot1.getTrackWidth() / 2));
      setDTheta(_d_theta);
  } else if (_new_heading < 0.01) {   // Right Turn
    _R = sqrt(pow(robot1.getComOffset(), 2) + (pow(robot1.getWheelBase(), 2)
        * (1 / pow(tan(-_new_heading), 2))));

  _R1 = sqrt(pow(_R, 2) - pow(robot1.getComOffset(), 2));

  _d_theta = -(robot1.getWheelRadius() * robot1.getLeftWheelVel()
             * 1) / (_R1 + (robot1.getTrackWidth() / 2));
  } else {
    _new_heading = 0;
  }

  sensor1.setCurrerntHeading(sensor1.getCurrerntHeading() + _d_theta);
  heading_vector.push_back(sensor1.getCurrerntHeading());

  std::cout << "cur heading= " << sensor1.getCurrerntHeading() << std::endl;
  std::cout << "d theta= " << _d_theta << std::endl;

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

bool ForwardKinematics::goalReached(double goal_heading, double goal_speed) {
  if (sensor1.getCurrerntHeading() <= goal_heading &&
      sensor1.getCurrerntHeading() <= (goal_heading + 0.05)
      && sensor1.getCurrentSpeed() <= goal_speed &&
      sensor1.getCurrentSpeed() <= (goal_speed + 0.05))
    return true;
  return false;
}
