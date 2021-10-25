/** 
 * @file controller.hpp
 * @author Maitreya Kulkarni
 * @author Pratik Bhujbal
 * @author Maaruf Vazifdar
 * @brief A class to hold controller  goal attributes and its members.
 * @version 1.1
 * @date 10/15/2021
 * Copyright [2021] ENPM808X group - MT-15
 */

#pragma once
/**
 * @brief Class to visualize Convergence
 */
class Convergence{
  public:
  /**
    * @brief Constructor for class Convergence
    */
  Convergence(){}
  /**
    * @brief Destructor for class Convergence
    */
  ~Convergence(){}

   /**
   * @brief plot convergence of robot's heading and speed
   * @param double - speed output from fk
   * @return void
   */
  int plotConvergence(double, std::vector<double>, std::string);
};