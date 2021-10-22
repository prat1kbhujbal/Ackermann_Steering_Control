/** 
 * @file sensor.h
 * @author Maaruf Vazifdar
 * @author Maitreya Kulkarni
 * @author Pratik Bhujnbal
 * @brief Class for Sensor to get current state of robot.
 * @version 1.1
 * @date 10/15/2021
 * Copyright [2021] ENPM808X group - MT-15
 */

#include <sensor.hpp>

double Sensor::getCurrerntHeading() {
  return _current_heading;
}

double Sensor::getCurrentSpeed() {
  return _current_speed;
}

void Sensor::setCurrerntHeading(double current_heading) {
  _current_heading = current_heading;
}

void Sensor::setCurrerntSpeed(double current_speed) {
  _current_speed = current_speed;
}
