#include "pros/imu.hpp"
#include "pros/motor_group.hpp"
#include "pros/rotation.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "lemlib/chassis/trackingWheel.hpp"

using namespace pros;
using namespace lemlib;

extern MotorGroup driveLeft;
extern MotorGroup driveRight;

extern Imu imu;

extern Rotation latRot;
extern Rotation angRot;

extern Drivetrain drivetrain;

extern TrackingWheel horizontal_tracking_wheel;
extern TrackingWheel vertical_tracking_wheel;

extern OdomSensors sensors;

extern Chassis chassis;