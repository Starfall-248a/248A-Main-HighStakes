#include "lemlib/chassis/chassis.hpp"
#include "main.h"
#include "pros/adi.h"
#include "pros/rtos.hpp"

//Assets

void redSoloWP(){
    //grab first goal
    chassis.setPose(-48.912,-36.043,245);
    chassis.moveToPoint(-29.665, -26.604, 2000, { .forwards = false, .maxSpeed = 80}, false);
    Clamp.set_value(HIGH);
    intake.move(127);
    pros::delay(100);
    //grab 1st ring
    chassis.turnToPoint(-21, -47.014, 1500);
    chassis.moveToPoint(-21, -50.5, 2000, {}, false);
    pros::delay(1750);
    //go to alliance stake 2 stack
    chassis.turnToPoint(-46, 4, 1250, {}, false);
    Clamp.set_value(LOW);
    chassis.moveToPoint(-46, 4, 2250);
    chassis.waitUntil(10);
    inLift.set_value(HIGH);
    chassis.waitUntilDone();
    inLift.set_value(LOW);
    //sort out blue ring
    pros::delay(1500);
    intake.move(50);
    chassis.turnToPoint(-29, 19.5, 1000, {.forwards = false});
    chassis.moveToPoint(-29, 19.5, 1500, {.forwards = false}, false);
    Clamp.set_value(HIGH);
    pros::delay(100);
    intake.move(127);
    chassis.turnToPoint(-19, 5.5, 1000);
    chassis.moveToPoint(-19, 5.5, 1500, {.maxSpeed = 75});
    chassis.waitUntil(3);
    pros::delay(500);
    intake.brake();
}

void blueSoloWP(){
    //grab first goal
    chassis.setPose(48.912,-36.043,115);
    chassis.moveToPoint(29.665, -26.604, 2000, { .forwards = false, .maxSpeed = 80}, false);
    Clamp.set_value(HIGH);
    intake.move(127);
    pros::delay(100);
    //grab 1st ring
    chassis.turnToPoint(21, -47.014, 1500);
    chassis.moveToPoint(21, -50.5, 2000, {}, false);
    pros::delay(1750);
    //go to alliance stake 2 stack
    chassis.turnToPoint(46, 4, 1250, {}, false);
    Clamp.set_value(LOW);
    chassis.moveToPoint(46, 4, 2250);
    chassis.waitUntil(10);
    inLift.set_value(HIGH);
    chassis.waitUntilDone();
    inLift.set_value(LOW);
    //sort out blue ring
    pros::delay(1500);
    intake.move(50);
    chassis.turnToPoint(29, 19.5, 1000, {.forwards = false});
    chassis.moveToPoint(29, 19.5, 1500, {.forwards = false}, false);
    Clamp.set_value(HIGH);
    pros::delay(100);
    intake.move(127);
    chassis.turnToPoint(19, 5.5, 1000);
    chassis.moveToPoint(19, 5.5, 1500, {.maxSpeed = 75});
    chassis.waitUntil(3);
    pros::delay(500);
    intake.brake();
}

void fourRingRed(){
    chassis.setPose(-53,40,300);
    chassis.moveToPoint(-30.5, 27.5, 1500, {.forwards = false}, false);
    Clamp.set_value(HIGH); //clamped
    intake.move(127);
    chassis.turnToPoint(-20.34, 54.894, 750);
    chassis.moveToPoint(-20.34, 54.894, 1250);
    pros::delay(250);
    chassis.turnToPoint(-9.133, 52.092, 750);
    chassis.moveToPoint(-9.133, 52.092, 750);
    pros::delay(250);
    chassis.moveToPose(-21.5, 43, 90, 1500, {.forwards = false});
    chassis.moveToPoint(-11, 43, 750);
    pros::delay(250);
    chassis.turnToPoint(-63, 63, 1000);
    chassis.moveToPose(-63, 63, 300, 2500);
}

void fourRingBlue(){
    chassis.setPose(53,40,60);
    chassis.moveToPoint(30.5, 27.5, 1500, {.forwards = false}, false);
    Clamp.set_value(HIGH); //clamped
    intake.move(127);
    chassis.turnToPoint(20.34, 54.894, 750);
    chassis.moveToPoint(20.34, 54.894, 1250);
    pros::delay(250);
    chassis.turnToPoint(9.133, 52.092, 750);
    chassis.moveToPoint(9.133, 52.092, 750);
    pros::delay(250);
    chassis.moveToPose(21.5, 43, 90, 1500, {.forwards = false});
    chassis.moveToPoint(11, 43, 750);
    pros::delay(250);
    chassis.turnToPoint(63, 63, 1000);
    chassis.moveToPose(63, 63, 300, 2500);

}

void disruptRed(){
    chassis.setPose(-51,40,304);
    chassis.moveToPoint(-10, 36, 1750);
    chassis.turnToPoint(-18.706, 25.943, 500);
    chassis.moveToPoint(-18.706, 25.943, 750, {.forwards = false}, false);
    Clamp.set_value(HIGH);
    pros::delay(50);
    chassis.turnToPoint(-24.076, 50.224, 750);
    chassis.moveToPoint(-24.076, 50.224, 1750);
    chassis.waitUntil(5);
    intake.move(127);
}

void disruptBlue(){
    chassis.setPose(51,40,56);
    chassis.moveToPoint(-10, 36, 1750);
    chassis.turnToPoint(-18.706, 25.943, 500);
    chassis.moveToPoint(-18.706, 25.943, 750, {.forwards = false}, false);
    Clamp.set_value(HIGH);
}

void skills(){
    chassis.setPose(-60.647, 0, 90);
    intake.move(127);
    pros::delay(750);
    chassis.moveToPoint(-47, 0, 1250);
    chassis.turnToPoint(-47, -50, 1250, {.forwards = false});
    chassis.moveToPoint(-47, 16, 2000, {.forwards = false, .maxSpeed = 90});
    chassis.turnToPoint(-24, 24, 1250);
    chassis.moveToPoint(-24, 24, 2000);
    chassis.turnToPoint(-59.372, 59.116, 1250);
    chassis.moveToPoint(-47.126, 47.126, 2500);
    chassis.turnToPoint(-59.372, 59.116, 1250, {.forwards = false});
    chassis.moveToPoint(-59.372, 59.116, 1250, {.forwards = false});
}