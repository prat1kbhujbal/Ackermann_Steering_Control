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
     * @brief Get current heading of robot. (in radians)
     * @param void
     * @return double - Robot's current heading
     */
    double getCurrerntHeading();

    /**
     * @brief Get current speed of robot. (in meters/second)
     * @return double - Robot's current speed
     */
    double getCurrentSpeed();

    /**
     * @brief Set current heading of robot. (in radians)
     * @param double - Current heading of robot.
     * @return void
     */
    void setCurrerntHeading(double);

    /**
     * @brief Set current speed of robot. (in meters/second)
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
