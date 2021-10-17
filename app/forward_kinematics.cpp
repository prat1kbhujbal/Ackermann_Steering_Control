/** 
 * @file forward_kinematics.cpp
 * @author Pratik Bhujbal
 * @author Maaruf Vazifdar
 * @author Maitreya Kulkarni
 * @brief Implementation of class to calculate forward kinematics of 
 *        ackermann robot
 * @version 1.1
 * @date 10/15/2021
 * Copyright [2021] ENPM808X group - MT-15
 */

#include<iostream>
#include<cmath>
#include<forward_kinematics.hpp>
#include<pid.hpp>
#include<controller.hpp>
#include<sensor.hpp>
#include<robot.hpp>


double ForwardKinematics::getR1() {
}

void ForwardKinematics::setDTheta(double d_theta) {
}

double ForwardKinematics::calculateNewHeading(double goal_heading) {
}

double ForwardKinematics::calculateNewSpeed(double goal_speed) {
}

bool ForwardKinematics::goalReached(double goal_heading, double goal_speed) {
}
