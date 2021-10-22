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
/**
 * @brief Class to hold current state of robot.
 */
class Sensor {
 public:
    /**
     * @brief Constructor for class Sensor to initialize robot current heading and speed to zero.
     */
    Sensor() {
      _current_heading = 0;
      _current_speed = 0;
    }

    /**
     * @brief Destructor for class Sensor
     */
    ~Sensor() {}

    /**
     * @brief Get current heading of robot.
     * @param void
     * @return double - Robot's current heading
     */
    double getCurrerntHeading();

    /**
     * @brief Get current speed of robot.
     * @return double - Robot's current speed
     */
    double getCurrentSpeed();

    /**
     * @brief Set current heading of robot.
     * @param double - Current heading of robot.
     * @return void
     */
    void setCurrerntHeading(double);

    /**
     * @brief Set current speed of robot.
     * @param double - Current speed of robot.
     * @return void
     */
    void setCurrerntSpeed(double);

 private:
    /**
     * Class local variables.
     */
    double _current_heading, _current_speed;
};
