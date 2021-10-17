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

/** 
 * @file robot.h
 * @author Pratik Bhujbal
 * @author Maaruf Vazifdar
 * @author Maitreya Kulkarni
 * @brief A class to hold robot attributes and its members.
 * @version 0.1
 * @date 10/05/2021
 * Copyright [2021] ENPM808X group - MT-15
 */

double Sensor::getCurrerntHeading() {
  return _current_heading;
}

double Sensor::getCurrentSpeed() {
  return _current_speed;
}
