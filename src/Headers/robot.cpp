#include "main.h"
#include "pros/abstract_motor.hpp"
#include "pros/adi.h"
#include "pros/adi.hpp"
#include "pros/misc.h"
#include "pros/motors.hpp"

using namespace pros;
using namespace lemlib;

Controller controller(E_CONTROLLER_MASTER);

MotorGroup driveLeft({-13, -12}, pros::MotorGearset::blue); // left motors on ports 13, 12, 11
MotorGroup driveRight({20, 19}, pros::MotorGearset::blue); // right motors on ports 20, 19, 18

Motor Intake(4);
Motor Clamp(5);

Imu imu(1);
Distance distance(3);
Rotation clampRot(6);

Rotation latRot(7);
Rotation angRot(8);

adi::DigitalOut Hang(6, LOW); //delete later
adi::DigitalOut PTO(1, LOW);

// drivetrain settings
Drivetrain drivetrain(&driveLeft, // left motor group
                              &driveRight, // right motor group
                              12.482, // 10 inch track width
                              lemlib::Omniwheel::NEW_4, // using new 4" omnis
                              257, // drivetrain rpm is 360
                              2 // horizontal drift is 2 (for now)
);

OdomSensors sensors(nullptr, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            nullptr, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);

// input curve for throttle input during driver control
ExpoDriveCurve throttle_curve(6.35, // joystick deadband out of 127
                                     10, // minimum output where drivetrain will move out of 127
                                     1.025 // expo curve gain
);

// input curve for steer input during driver control
ExpoDriveCurve steer_curve(6.35, // joystick deadband out of 127
                                  10, // minimum output where drivetrain will move out of 127
                                  1.025 // expo curve gain
);

// create the chassis
Chassis chassis(drivetrain,
                        lateral_controller,
                        angular_controller,
                        sensors,
                        &throttle_curve, 
                        &steer_curve
);