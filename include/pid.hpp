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
 * @brief Class to hold PID Controller attributes and members.
 */
class PID {
 public:
  /**
   * @brief Constructor for class PID
   * @param Kp double - Proportional gain constant
   * @param Ki double - Integral gain constant
   * @param Kd double - Deravitive gain constant
   * @param dt double - Sampling time
   * @param min double - Minimum limit of output value
   * @param max double - Maximum limit of output value 
   */
  PID(double Kp, double Ki, double Kd, double dt, double min, double max) {
    _Kp = Kp;
    _Ki = Ki;
    _Kd = Kd;
    _dt = dt;
    _min = min;
    _max = max;
    _prev_error = 0;
    _integral = 0;
  }

  /**
   * @brief Destructor for class PID
   */
  ~PID() {}

  /**
   * @brief Calculate the output based on the current value and the desired value
   * @param current_value double - current value of system
   * @param desired_value double - desired value of system
   * @return void
   */
  double compute(double current_value, double desired_value);

  /**
   * @brief Get the Kp value
   * @return double - Value of Kp
   */
  double getKp();

  /**
   * @brief Get the Ki value
   * @return double - Value of Ki
   */
  double getKi();

  /**
   * @brief Get the Kd value
   * @return double - Value of Kd
   */
  double getKd();

  /**
   * @brief Get the dt
   * @return double - Sampling time
   */
  double getDt();

 private:
  /**
   * Class local variables.
   */
  double _Kp, _Ki, _Kd, _dt, _max, _min;
  double _prev_error, _integral;
};
