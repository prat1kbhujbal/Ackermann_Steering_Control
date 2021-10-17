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

class PID {
 public:
  PID(double Kp, double Ki, double Kd, double dt, double min, double max) {
  }

  ~PID() {}

  double compute(double current_value, double desired_value);

  double getKp();

  double getKi();

  double getKd();

  double getDt();

 private:
  double _Kp, _Ki, _Kd, _dt, _max, _min;
  double _prev_error, _integral;
};
