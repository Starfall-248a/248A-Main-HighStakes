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
    chassis.turnToPoint(-23.655, -47.014, 1250);
    chassis.moveToPoint(-22.267, -50.5, 2000, {}, false);
    pros::delay(1250);
    
    
}

void blueSoloWP(){
    //grab first goal
    chassis.setPose(48.912,-36.043,115);
    chassis.moveToPoint(29.665, -26.604, 2000, { .forwards = false, .maxSpeed = 80}, false);
    Clamp.set_value(HIGH);
    intake.move(127);
    //grab 1st ring
    chassis.turnToPoint(23.655, -47.014, 1250);
    chassis.moveToPoint(23.655, -47.014, 2000, {}, false);
    pros::delay(1250);
    Clamp.set_value(LOW);
    //grab 2nd goal
    chassis.turnToHeading(270, 1250);
    chassis.moveToPoint(8, -47.014, 1250, {.forwards = false}, false);
    Clamp.set_value(HIGH);
}

void fourRingRed(){
    chassis.setPose(-52,-37,245);
    chassis.moveToPoint(-29.267, -27.114, 1500, {.forwards = false});
    Clamp.toggle(); //clamped
    intake.move_velocity(600);
}

void fourRingBlue(){
    chassis.moveToPoint(10, 10, 1000);
    chassis.moveToPoint(-31, 27.5, 1500,{.forwards = false});
    chassis.waitUntilDone();
    Clamp.set_value(HIGH);
    intake.move(127);

}

void disruptRed(){
    chassis.setPose(-51,40,304);
}

void skills(){
    chassis.setPose(-60.647, 0, 90);
    intake.move(127);
    pros::delay(750);
    chassis.moveToPoint(-47, 0, 1250);
    chassis.turnToPoint(-47, -50, 1250);
    chassis.moveToPoint(-47, 16, 2000, {.maxSpeed = 90});
    chassis.turnToPoint(-24, 24, 1250);
    chassis.moveToPoint(-24, 24, 2000);
    chassis.turnToPoint(-59.372, 59.116, 1250);
    chassis.moveToPoint(-47.126, 47.126, 2500);
    chassis.turnToPoint(-59.372, 59.116, 1250, {.forwards = false});
    chassis.moveToPoint(-59.372, 59.116, 1250, {.forwards = false});
}