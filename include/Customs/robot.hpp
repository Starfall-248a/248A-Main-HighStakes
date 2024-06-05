#include "lemlib/chassis/chassis.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/imu.hpp"
#include "pros/motor_group.hpp"
#include "pros/rotation.hpp"


using namespace pros;
using namespace lemlib;

extern Controller controller;

extern MotorGroup driveLeft;
extern MotorGroup driveRight;

extern Motor Intake;
extern Motor Clamp;

extern Imu imu;
extern Distance distance;
extern Rotation clampRot;

extern Drivetrain drivetrain;

extern Chassis chassis;