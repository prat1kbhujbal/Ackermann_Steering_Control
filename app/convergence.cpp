/** 
 * @file forward_kinematics.cpp
 * @author Maitreya Kulkarni
 * @author Maaruf Vazifdar
 * @author Pratik Bhujbal
 * @brief Implementation of class to calculate forward kinematics of 
 *        ackermann robot
 * @version 1.1
 * @date 10/15/2021
 * Copyright [2021] ENPM808X group - MT-15
 */
#include "../include/pbPlots/supportLib.hpp"
#include "../include/pbPlots/pbPlots.hpp"
#include "convergence.hpp"
#include <string.h>
#include <iostream>

int Convergence::plotConvergence(double goal, std::vector<double> current, std::string file_name){      
  RGBABitmapImageReference *canvasReference = CreateRGBABitmapImageReference();
  std::vector<double> y;
  y = current;
  // y.pop_back();
  std::vector<double> time;
  double j = 0;
  for (unsigned int i = 0; i < y.size(); i++)
  {
    time.push_back(j);
    j = j + 0.1;
  }

  DrawScatterPlot(canvasReference, 1260, 720, &time, &y);
  double x1 = MapXCoordinateAutoSettings(0, canvasReference->image, &time);
  double y1 = MapYCoordinateAutoSettings(goal, canvasReference->image, &y);

  double x2 = MapXCoordinateAutoSettings(time.back(), canvasReference->image, &time);
	double y2 = MapYCoordinateAutoSettings(goal, canvasReference->image, &y);
  DrawLine(canvasReference->image, x1, y1, x2, y2, 2, GetGray(0.3));
  std::vector<double> *pngdata = ConvertToPNG(canvasReference->image);
	WriteToFile(pngdata, file_name);
	DeleteImage(canvasReference->image);
  return 1;
}