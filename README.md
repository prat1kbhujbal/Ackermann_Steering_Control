# Ackermann_Steering_Control
[![Build Status](https://app.travis-ci.com/Prat33k-dev/Ackermann_Steering_Control.svg?branch=dev)](https://app.travis-ci.com/Prat33k-dev/Ackermann_Steering_Control)
[![Coverage Status](https://coveralls.io/repos/github/Prat33k-dev/Ackermann_Steering_Control/badge.svg?branch=dev)](https://coveralls.io/github/Prat33k-dev/Ackermann_Steering_Control?branch=dev)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)
-----------------------

## Overview
Ackermann steering condition arises when axes of all wheels in a vehicle intersect
at a single turning point. In the case of Ackermann steering the wheels of the vehicle do not skid while turning as opposed to parallel steering. This reduces the tyre wear and increases the energy efficiency. Ackermann steering can be used in various autonomous systems such as self-driving cars, delivery robots which can increase the efficiency of the robot.

During the development the following assumptions
are made:
- All robot parameters are known.
- Initially the robot is on the origin of the world frame facing the x axis.
- Robot’s desired heading and velocity are given by the user as input.
- Maximum steering angle is 45 degrees.
- Friction and wheel slippage are considered negligible.
--------------------
