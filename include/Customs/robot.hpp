#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "pros/motor_group.hpp"
#include "pros/rotation.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
#include "pros/distance.hpp"

using namespace pros;
using namespace lemlib;

extern Controller controller;

extern MotorGroup driveLeft;
extern MotorGroup driveRight;
extern MotorGroup Lift;

extern Motor liftRight;
extern Motor liftLeft;
extern Motor intakeTop;
extern Motor intakeBottom;

extern MotorGroup Intake;

extern Imu imu;
extern Distance distance;

extern adi::DigitalOut Hang;
extern adi::DigitalOut PTO;

extern Rotation latRot;
extern Rotation angRot;

extern Drivetrain drivetrain;

extern TrackingWheel horizontal_tracking_wheel;
extern TrackingWheel vertical_tracking_wheel;

extern Chassis chassis;