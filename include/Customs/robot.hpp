#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "pros/motor_group.hpp"
#include "pros/rotation.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
#include "pros/optical.hpp"
#include "pros/gps.hpp"
#include "stormlib/api.hpp"

using namespace pros;
using namespace lemlib;
using namespace stormlib;

extern Controller controller;

extern MotorGroup driveLeft;
extern MotorGroup driveRight;

extern Motor intake;
extern Motor arm1;
extern Motor arm2;

extern Imu imu;
extern Optical colorSort;
extern Gps gps;

extern adi::Pneumatics Clamp;
extern adi::Pneumatics inLift;

extern Rotation latRot;
extern Rotation angRot;
extern Rotation armAngle;

extern Drivetrain drivetrain;

extern TrackingWheel horizontal_tracking_wheel;
extern TrackingWheel vertical_tracking_wheel;

extern Chassis chassis;

extern aRGB underglow;
extern aRGB Time;
extern aRGB_manager ledManager;