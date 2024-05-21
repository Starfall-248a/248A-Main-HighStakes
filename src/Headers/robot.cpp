#include "main.h"

using namespace pros;
using namespace lemlib;

MotorGroup driveLeft({1, 2, 3}, pros::MotorGearset::blue); // left motors on ports 1, 2, 3
MotorGroup driveRight({4, 5, 6}, pros::MotorGearset::blue); // right motors on ports 4, 5, 6

Imu imu(10);

Rotation latRot(7);
Rotation angRot(8);

// drivetrain settings
Drivetrain drivetrain(&driveLeft, // left motor group
                              &driveRight, // right motor group
                              12.482, // 10 inch track width
                              lemlib::Omniwheel::NEW_4, // using new 4" omnis
                              343, // drivetrain rpm is 360
                              2 // horizontal drift is 2 (for now)
);

// horizontal tracking wheel
TrackingWheel horizontal_tracking_wheel(&angRot, lemlib::Omniwheel::NEW_4, -5.75);
// vertical tracking wheel
TrackingWheel vertical_tracking_wheel(&latRot, lemlib::Omniwheel::NEW_4, -2.5);

OdomSensors sensors(&vertical_tracking_wheel, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            &horizontal_tracking_wheel, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);

// create the chassis
Chassis chassis(drivetrain, // drivetrain settings
                        lateral_controller, // lateral PID settings
                        angular_controller, // angular PID settings
                        sensors // odometry sensors
);