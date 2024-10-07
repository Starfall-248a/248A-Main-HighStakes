#include "lemlib/chassis/chassis.hpp"
#include "main.h"
#include "pros/adi.h"

//Assets

void redSoloWP(){
    // chassis.swingToPoint(float x, float y, DriveSide lockedSide, int timeout)
}

void blueSoloWP(){
    chassis.setPose(51,40,56);
    chassis.moveToPoint(31, 27.5, 1500,{.forwards = false});
    chassis.waitUntilDone();
    Clamp.set_value(HIGH);
    intake.move(127);
    chassis.moveToPoint(23.542, 46.871, 1100);
    chassis.moveToPose(12, 12, 180, 2000);
    chassis.waitUntilDone();
    intake.brake();
    Clamp.set_value(LOW);
    chassis.moveToPoint(10.5, -16, 1500);
    chassis.turnToHeading(300, 750);
    chassis.moveToPoint(16.5, -19.5, 500, {.forwards = false});
    chassis.waitUntilDone();
    Clamp.set_value(HIGH);
    intake.move(127);
    chassis.moveToPoint(23.5, -47, 1500);
    chassis.moveToPoint(24,-10, 2000);
    chassis.waitUntilDone();
    Clamp.set_value(LOW);
    intake.brake();
    chassis.moveToPoint(24, -6, 2000, {.maxSpeed = 50});
}

void fourRingRed(){
    chassis.setPose(-52,-37,245);
    chassis.moveToPoint(-29.267, -27.114, 1500, {.forwards = false});
    Clamp.toggle(); //clamped
    intake.move_velocity(600);
}

void fourRingBlue(){
    chassis.moveToPoint(10, 10, 1000);
}

void skills(){
    chassis.moveToPoint(10, 10, 1000);
}