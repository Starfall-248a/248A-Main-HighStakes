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
//grab first goal
//     chassis.setPose(-53.249,-35.788,270);
//     chassis.moveToPoint(-18.042, -35.788, 2000, {.forwards = false});
//     chassis.turnToHeading(310, 750);
//     chassis.moveToPoint(-6, -47, 2000, {.forwards = false});
//     chassis.waitUntilDone();
//     pros::delay(250);
//     Clamp.set_value(HIGH);
//     pros::delay(250);
//     //grab first ring and score preload
//     chassis.turnToHeading(255, 750);
//     intakeR.move(-127);
//     chassis.moveToPoint(-23, -47.269, 1500);
//     pros::delay(250);
//     chassis.turnToHeading(180, 750);
//     chassis.moveToPoint(-23, -57.218, 1000);
//     chassis.waitUntilDone();
//     pros::delay(500);
//     intakeR.brake();
//     chassis.turnToHeading(270, 750);
//     chassis.waitUntilDone();
//     Clamp.set_value(LOW);
//     pros::delay(250);
//     chassis.turnToHeading(180, 750);
//     chassis.moveToPoint(-23, -21, 3000, {.forwards = false});
//     chassis.waitUntilDone();
//     Clamp.set_value(HIGH);
//     pros::delay(250);
//     chassis.turnToHeading(315, 1000);
//     chassis.waitUntilDone();
//     inLift.set_value(HIGH);
//     chassis.moveToPoint(-47.126, 0, 2000);
//     intakeR.move(-127);
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
//     //grab first goal
//     chassis.setPose(-53.249,-35.788,270);
//     chassis.moveToPoint(-18.042, -35.788, 2000, {.forwards = false});
//     chassis.turnToHeading(310, 750);
//     chassis.moveToPoint(-6, -47, 2000, {.forwards = false});
//     chassis.waitUntilDone();
//     pros::delay(250);
//     Clamp.set_value(HIGH);
//     pros::delay(250);
//     //grab first ring and score preload
//     chassis.turnToHeading(255, 750);
//     intakeR.move(-127);
//     chassis.moveToPoint(-23, -47.269, 1500);
//     pros::delay(250);
//     chassis.turnToHeading(180, 750);
//     chassis.moveToPoint(-23, -57.218, 1000);
//     chassis.waitUntilDone();
//     pros::delay(500);
//     intakeR.brake();
//     chassis.turnToHeading(270, 750);
//     chassis.waitUntilDone();
//     Clamp.set_value(LOW);
//     pros::delay(250);
//     chassis.turnToHeading(180, 750);
//     chassis.moveToPoint(-23, -21, 3000, {.forwards = false});
//     chassis.waitUntilDone();
//     Clamp.set_value(HIGH);
//     pros::delay(250);
//     chassis.turnToHeading(315, 1000);
//     chassis.waitUntilDone();
//     inLift.set_value(HIGH);
//     chassis.moveToPoint(-47.126, 0, 2000);
//     intakeR.move(-127);
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