add_executable(ackerman_steering_controller main.cpp controller.cpp forward_kinematics.cpp inverse_kinematics.cpp pid.cpp robot.cpp sensor.cpp convergence.cpp pbPlots/pbPlots.cpp pbPlots/supportLib.cpp fk_goal.cpp
)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
)
