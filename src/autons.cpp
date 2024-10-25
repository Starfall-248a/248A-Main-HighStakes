#include "lemlib/chassis/chassis.hpp"
#include "main.h"
#include "pros/adi.h"
#include "pros/rtos.hpp"

//Assets

void redSoloWP(){
    chassis.setPose(-51,40,304);
    chassis.moveToPoint(-30, 26.5, 2000,{.forwards = false, .maxSpeed = 80});
    chassis.waitUntilDone();
    Clamp.set_value(HIGH);
    pros::delay(100);
    intakeR.move(-127);
    chassis.moveToPoint(-23.542, 46.871, 1500);
    pros::delay(500);
    // chassis.moveToPose(-12, 12, 180, 2150);
    // chassis.waitUntilDone();
    // intakeR.brake();
    // Clamp.set_value(LOW);
    // chassis.moveToPoint(-13, -16, 1750);
    // chassis.turnToHeading(60, 1250);
    // chassis.moveToPoint(-21.5, -24, 1750, {.forwards = false});
    // chassis.waitUntilDone();
    // pros::delay(100);
    // Clamp.set_value(HIGH);
    // intakeR.move(127);
    // chassis.moveToPoint(-25, -47, 2500);
    // chassis.moveToPoint(-24,-10, 2000);
    // chassis.waitUntilDone();
    // Clamp.set_value(LOW);
    // intakeR.brake();
    // chassis.moveToPoint(-24, -6, 2000, {.maxSpeed = 50});
}

void blueSoloWP(){
    chassis.setPose(51,40,56);
    chassis.moveToPoint(30, 26.5, 2000,{.forwards = false, .maxSpeed = 80});
    chassis.waitUntilDone();
    Clamp.set_value(HIGH);
    pros::delay(100);
    intakeR.move(-127);
    chassis.moveToPoint(23.542, 46.871, 1500);
    pros::delay(500);
    // chassis.moveToPose(12, 12, 180, 2150);
    // chassis.waitUntilDone();
    // intakeR.brake();
    // Clamp.set_value(LOW);
    // chassis.moveToPoint(13, -16, 1750);
    // chassis.turnToHeading(300, 1250);
    // chassis.moveToPoint(21.5, -24, 1750, {.forwards = false});
    // chassis.waitUntilDone();
    // pros::delay(100);
    // Clamp.set_value(HIGH);
    // intakeR.move(127);
    // chassis.moveToPoint(25, -47, 2500);
    // chassis.moveToPoint(24,-10, 2000);
    // chassis.waitUntilDone();
    // Clamp.set_value(LOW);
    // intakeR.brake();
    // chassis.moveToPoint(24, -6, 2000, {.maxSpeed = 50});
}

void fourRingRed(){
    chassis.setPose(-52,-37,245);
    chassis.moveToPoint(-29.267, -27.114, 1500, {.forwards = false});
    Clamp.toggle(); //clamped
    intakeR.move_velocity(600);
}

void fourRingBlue(){
    chassis.moveToPoint(10, 10, 1000);
    chassis.moveToPoint(-31, 27.5, 1500,{.forwards = false});
    chassis.waitUntilDone();
    Clamp.set_value(HIGH);
    intakeR.move(127);

}

void disruptRed(){
    chassis.setPose(-51,40,304);
}

void skills(){
    chassis.moveToPoint(10, 10, 1000);
}