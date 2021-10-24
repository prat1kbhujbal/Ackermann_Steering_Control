/** 
 * @file convergence.hpp
 * @author Maitreya Kulkarni
 * @author Pratik Bhujbal
 * @author Maaruf Vazifdar
 * @brief A class to visualize convergence to goal.
 * @version 1.1
 * @date 10/19/2021
 * Copyright [2021] ENPM808X group - MT-15
 */

#pragma once

class Convergence{
  public:
  
  Convergence(){}

  ~Convergence(){}

  void plotConvergence(double, std::vector<double>, std::string);
};