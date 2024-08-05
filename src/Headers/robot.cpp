#include "main.h"
#include "pros/abstract_motor.hpp"
#include "pros/adi.h"
#include "pros/adi.hpp"
#include "pros/misc.h"
#include "pros/motors.hpp"
#include "pros/optical.hpp"

using namespace pros;
using namespace lemlib;

Controller controller(E_CONTROLLER_MASTER);

MotorGroup driveLeft({-13, -12, -11}, pros::MotorGearset::blue); // left motors on ports 13, 12, 11
<<<<<<< HEAD
MotorGroup driveRight({20, 19, 18}, pros::MotorGearset::blue); // right motors on ports 20, 19, 18

Motor liftLeft(-14);
Motor liftRight(17);

Motor intakeTop(4);
Motor intakeBottom(5);
=======
MotorGroup driveRight({17, 19, 18}, pros::MotorGearset::blue); // right motors on ports 17, 19, 18

Motor hooks(15, pros::MotorGearset::green);
Motor intake(-11, pros::MotorGearset::green);
>>>>>>> 18e9ba57c8f17be95946b6affcb30688385194e8

Imu imu(1);
Distance distance(3);
Optical color(2);

Rotation latRot(7);
Rotation angRot(8);

adi::DigitalOut PTO(1, LOW);

// drivetrain settings
Drivetrain drivetrain(&driveLeft, // left motor group
                              &driveRight, // right motor group
<<<<<<< HEAD
                              12.482, // 10 inch track width
                              lemlib::Omniwheel::NEW_275, // using new 2.75" omnis
=======
                              10.98, // 10 inch track width
                              lemlib::Omniwheel::NEW_275, // using new 4" omnis
>>>>>>> 18e9ba57c8f17be95946b6affcb30688385194e8
                              450, // drivetrain rpm is 360
                              2 // horizontal drift is 2 (for now)
);

// horizontal tracking wheel
TrackingWheel horizontal_tracking_wheel(&angRot, lemlib::Omniwheel::NEW_275, -5.75);
// vertical tracking wheel
TrackingWheel vertical_tracking_wheel(&latRot, lemlib::Omniwheel::NEW_275, -2.5);

OdomSensors sensors(nullptr, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            nullptr, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            nullptr // inertial sensor
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