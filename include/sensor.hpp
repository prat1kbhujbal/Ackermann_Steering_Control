/** 
 * @file sensor.hpp
 * @author Maaruf Vazifdar
 * @author Maitreya Kulkarni
 * @author Pratik Bhujnbal
 * @brief Class to hold current state of robot.
 * @version 1.1
 * @date 10/15/2021
 * Copyright [2021] ENPM808X group - MT-15
 */

#pragma once

class Sensor {
 public:
    Sensor() {}

    ~Sensor() {}

    double getCurrerntHeading();

    double getCurrentSpeed();

    void setCurrerntHeading(double);

    void setCurrerntSpeed(double);

 private:
    double _current_heading, _current_speed;
};
