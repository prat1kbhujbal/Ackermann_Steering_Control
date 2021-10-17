/** 
 * @file pid.cpp
 * @author Pratik Bhujbal
 * @author Maaruf Vazifdar
 * @author Maitreya Kulkarni
 * @brief Implementation file to compute PID values for a system.
 * @version 0.1
 * @date 10/05/2021
 * Copyright [2021] ENPM808X group - MT-15
 */

#include <iostream>
#include <stdexcept>
#include <pid.hpp>

/** @brief  A member function to calculate the PID values based on the current
 *          velocity and required velocity
 *  @param  cur_vel Current process value
 *  @param  req_vel Setpoint value
 *  @return pTerm + iTerm + dTerm 
 */

double PID::getKp() {
  return _Kp;
}

double PID::getKi() {
  return _Ki;
}

double PID::getKd() {
  return _Kd;
}

double PID::getDt() {
  return _dt;
}

double PID::compute(double current_value, double desired_value) {
  if (getDt() <= 0.0)
    throw std::domain_error("The delta t must be greater than zero");
  else if (getKp() <= 0 || getKi() <= 0 || getKd() <= 0)
    throw std::domain_error("Kp, Kd and Ki must be greater than zero");

  double error = desired_value - current_value;
  double derivative = (error - _prev_error) / getDt();
  _integral += error * getDt();
  double output = getKp() * error + getKi() * _integral + getKd() * derivative;

  _prev_error = error;

  if (output <= _min)
    output = _min;
  else if (output >= _max)
    output = _max;

  std::cout << "output = " << current_value +output << std::endl;
  return current_value + output;
}
