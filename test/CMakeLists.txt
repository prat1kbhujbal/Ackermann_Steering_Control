set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    test.cpp
    main.cpp
    mockFk.cpp
    ../app/pid.cpp
    ../app/controller.cpp
    ../app/forward_kinematics.cpp
    ../app/inverse_kinematics.cpp
    ../app/robot.cpp
    ../app/sensor.cpp
    ../app/convergence.cpp
    ../app/pbPlots/pbPlots.cpp
    ../app/pbPlots/supportLib.cpp
)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
${CMAKE_SOURCE_DIR}/include ../vendor/googletest/googlemock/include)
target_link_libraries(cpp-test PUBLIC gtest gmock)