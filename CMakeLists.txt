cmake_minimum_required(VERSION 3.2.1)
project (Ackermann_Steering_Control)

# Add project cmake modules to path.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

# We probably don't want this to run on every build.
option(COVERAGE "Generate Coverage Data" OFF)

if (COVERAGE)
    include(CodeCoverage)
    set(LCOV_REMOVE_EXTRA "'vendor/*'")
    set(LCOV_REMOVE_EXTRA "app/pbPlots/*")
    set(LCOV_REMOVE_EXTRA "'include/pbPlots/*'")
    setup_target_for_coverage(code_coverage test/cpp-test coverage)
    set(COVERAGE_SRCS app/pid.cpp include/pid.hpp)
    set(COVERAGE_SRCS app/main.cpp app/controller.cpp include/controller.hpp)
    set(COVERAGE_SRCS app/robot.cpp include/robot.hpp)
    set(COVERAGE_SRCS app/sensor.cpp include/sensor.hpp)
    set(COVERAGE_SRCS app/forward_kinematics.cpp include/forward_kinematics.hpp)
    set(COVERAGE_SRCS app/inverse_kinematics.cpp include/inverse_kinematics.hpp)


    SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
    SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
    SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")
else()
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -g")
endif()

include(CMakeToolsHelpers OPTIONAL)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(app)
add_subdirectory(test)
add_subdirectory(vendor/googletest/googletest)