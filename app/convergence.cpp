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

#include <string.h>
#include <iostream>
#include "../include/pbPlots/supportLib.hpp"
#include "../include/pbPlots/pbPlots.hpp"
#include "convergence.hpp"

int Convergence::plotConvergence(double goal, std::vector<double>
  &current, std::string &file_name) {
  RGBABitmapImageReference *canvasReference = CreateRGBABitmapImageReference();
  std::vector<double> y;
  y = current;
  std::vector<double> time;
  double j = 0;
  for (unsigned int i = 0; i < y.size(); i++) {
    time.push_back(j);
    j = j + 0.1;
  }

  DrawScatterPlot(canvasReference, 1260, 720, &time, &y);
  double x1 = MapXCoordinateAutoSettings(0, canvasReference->image, &time);
  double y1 = MapYCoordinateAutoSettings(goal, canvasReference->image, &y);

  double x2 = MapXCoordinateAutoSettings(time.back(), canvasReference->image,
  &time);
  double y2 = MapYCoordinateAutoSettings(goal, canvasReference->image, &y);
  DrawLine(canvasReference->image, x1, y1, x2, y2, 2, GetGray(0.3));
  std::vector<double> *pngdata = ConvertToPNG(canvasReference->image);
  WriteToFile(pngdata, file_name);
  DeleteImage(canvasReference->image);
  return 1;
}
