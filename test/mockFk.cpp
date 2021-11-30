/**
 * MIT License
 *
 * Copyright (c) 2021 Pratik Bhujnbal
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
 * @file mockFk.cpp
 * @author Pratik Bhujnbal
 * @brief A mock for goal status
 * @version 1.1
 * @date 11/29/2021
 * @copyright  Copyright (c) 2021
 * 
 */

#include <gtest/gtest.h>
#include <string>
#include "../include/pid.hpp"
#include "../include/controller.hpp"
#include "../include/robot.hpp"
#include "../include/sensor.hpp"
#include "../include/forward_kinematics.hpp"
#include "../include/inverse_kinematics.hpp"
#include "../include/convergence.hpp"
#include "gmock/gmock.h"
#include<fk_goal.hpp>
using ::testing::Return;
using::testing::_;
/**
 * @brief A mockclass for goal status
 * 
 */
class MockFkGoal : public FkGoal {
 public:
    MOCK_METHOD1(goalReached, bool(double goal_heading));
    bool status = true;
};

TEST(FkKinematics, goalStatus) {
  MockFkGoal mockgoal;
  ForwardKinematics fk;
  ON_CALL(mockgoal, goalReached(0.1))
      .WillByDefault(Return(true));

  bool goal_status = fk.goalStatus(mockgoal);
  EXPECT_EQ(true, goal_status);
}
