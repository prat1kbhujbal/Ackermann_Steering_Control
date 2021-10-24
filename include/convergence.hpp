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

/**
 * @brief Class to visualize convergence.
 */
class Convergence{
  public:
  
  /**
   * @brief Consructor for class Convergence
   * @param void
   * @return void
   */
  Convergence(){}
  /**
 * @brief Destructor for class Convergence
 */
  ~Convergence(){}

   /**
  * @brief Calculate new speed required to reach the goal speed.
  * @param goal double - robot's goal speed/heading 
  * @param current double - vector storing robot's current speed/heading
  * @return void
  */
  void plotConvergence(double, std::vector<double>, std::string);
};