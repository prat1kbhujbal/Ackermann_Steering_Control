/** 
 * @file pid.hpp
 * @author Pratik Bhujbal
 * @author Maaruf Vazifdar
 * @author Maitreya Kulkarni
 * @brief A class to compute PID values for a system.
 * @version 0.1
 * @date 10/05/2021
 * Copyright [2021] ENPM808X group - MT-15
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
