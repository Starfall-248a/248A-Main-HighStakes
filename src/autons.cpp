#include "lemlib/chassis/chassis.hpp"
#include "main.h"
#include "pros/adi.h"
#include "pros/rtos.hpp"

//Assets

void redSoloWP(){
    //grab first goal
    chassis.setPose(-48.912,-36.043,245);
    chassis.moveToPoint(-29.665, -26.604, 2000, { .forwards = false, .maxSpeed = 75}, false);
    Clamp.set_value(HIGH);
    intake.move(127);
    pros::delay(100);
    //grab 1st ring
    chassis.turnToPoint(-21, -49, 1500);
    chassis.moveToPoint(-21, -49, 2000, {}, false);
    pros::delay(1750);
    //go to alliance stake 2 stack
    chassis.turnToPoint(-48, 4, 1250, {}, false);
    Clamp.set_value(LOW);
    chassis.moveToPoint(-48, 4, 2250);
    chassis.waitUntil(10);
    inLift.set_value(HIGH);
    chassis.waitUntilDone();
    inLift.set_value(LOW);
    pros::delay(500);
    //sort out blue ring
    intake.brake();
    chassis.turnToPoint(-25.187, 21.741, 1000, {.forwards = false}, false);
    chassis.moveToPoint(-25.187, 21.741, 1500, {.forwards = false, .maxSpeed = 65}, false);
    chassis.waitUntil(5);
    Clamp.set_value(HIGH);
    pros::delay(100);
    intake.move(127);
    chassis.turnToPoint(-19, 5.5, 1000);
    chassis.moveToPoint(-19, 5.5, 1500, {.maxSpeed = 50});
    chassis.waitUntil(5);
    intake.brake();
}

void blueSoloWP(){
    //grab first goal
    chassis.setPose(48.912,-36.043,115);
    chassis.moveToPoint(29.665, -26.604, 2000, { .forwards = false, .maxSpeed = 75}, false);
    Clamp.set_value(HIGH);
    intake.move(127);
    pros::delay(100);
    //grab 1st ring
    chassis.turnToPoint(21, -49, 1500);
    chassis.moveToPoint(21, -49, 2000, {}, false);
    pros::delay(1750);
    //go to alliance stake 2 stack
    chassis.turnToPoint(48, 4, 1250, {}, false);
    Clamp.set_value(LOW);
    chassis.moveToPoint(48, 4, 2250);
    chassis.waitUntil(10);
    inLift.set_value(HIGH);
    chassis.waitUntilDone();
    inLift.set_value(LOW);
    //sort out blue ring
    chassis.turnToPoint(25.187, 21.741, 1000, {.forwards = false});
    chassis.waitUntil(15);
    intake.brake();
    chassis.moveToPoint(25.187, 21.741, 1500, {.forwards = false, .maxSpeed = 65}, false);
    chassis.waitUntil(5);
    Clamp.set_value(HIGH);
    pros::delay(100);
    intake.move(127);
    chassis.turnToPoint(19, 5.5, 1000);
    chassis.moveToPoint(19, 5.5, 1500, {.maxSpeed = 50});
    chassis.waitUntil(5);
    intake.brake();
}

void fourRingRed(){
    //grab first goal
    chassis.setPose(-48.912,-36.043,245);
    chassis.moveToPoint(-29.665, -26.604, 2000, { .forwards = false, .maxSpeed = 75}, false);
    Clamp.set_value(HIGH);
    intake.move(127);
    pros::delay(100);
    //grab 1st ring
    chassis.turnToPoint(-21, -49, 1500);
    chassis.moveToPoint(-21, -49, 2000, {}, false);
    pros::delay(1750);
    //go to alliance stake 2 stack
    chassis.turnToPoint(-48, 4, 1250, {}, false);
    chassis.moveToPoint(-48, 4, 2250);
    chassis.waitUntil(10);
    inLift.set_value(HIGH);
    chassis.waitUntilDone();
    inLift.set_value(LOW);
    pros::delay(250);
    chassis.moveToPoint(-34.526, -18.939, 1250, {.forwards = false, .maxSpeed = 50});
    chassis.moveToPoint(2-3.5, 0,1500);
    intake.brake();
}

void fourRingBlue(){
    //grab first goal
    chassis.setPose(48.912,-36.043,115);
    chassis.moveToPoint(29.665, -26.604, 2000, { .forwards = false, .maxSpeed = 75}, false);
    Clamp.set_value(HIGH);
    intake.move(127);
    pros::delay(100);
    //grab 1st ring
    chassis.turnToPoint(21, -49, 1500);
    chassis.moveToPoint(21, -49, 2000, {}, false);
    pros::delay(1750);
    //go to alliance stake 2 stack
    chassis.turnToPoint(48, 4, 1250, {}, false);
    chassis.moveToPoint(48, 4, 2250);
    chassis.waitUntil(10);
    inLift.set_value(HIGH);
    chassis.waitUntilDone();
    inLift.set_value(LOW);
    pros::delay(250);
    chassis.moveToPoint(34.526, -18.939, 1250, {.forwards = false, .maxSpeed = 50});
    chassis.moveToPoint(23.5, 0,1500);
    intake.brake();

}

void disruptRed(){
    chassis.setPose(-51,40,90);
    chassis.moveToPoint(-4, 40,2100);
    chassis.turnToPoint(-18.706, 25.943, 750, {.forwards = false});
    chassis.moveToPoint(-18.706, 25.943, 1250, {.forwards = false}, false);
    Clamp.set_value(HIGH);
    pros::delay(75);
    chassis.turnToPoint(-24.076, 50.224, 750, {}, false);
    intake.move(127);
    chassis.moveToPoint(-24.076, 53, 1750);
}

void disruptBlue(){
    chassis.setPose(51,40,270);
    chassis.moveToPoint(10, 36, 1750);
    chassis.turnToPoint(18.706, 25.943, 500, {.forwards = false});
    chassis.moveToPoint(18.706, 25.943, 750, {.forwards = false}, false);
    Clamp.set_value(HIGH);
    pros::delay(75);
    chassis.turnToPoint(24.076, 50.224, 750, {}, false);
    intake.move(127);
    chassis.moveToPoint(24.076, 50.224, 1750);
}

void rushRed(){
    chassis.setPose(51, -60,90);
    chassis.moveToPoint(15, -60, 1250, {.forwards = false});
    chassis.turnToPoint(8.61, -53.904, 1000);
    chassis.moveToPoint(8.61, -53.904, 1000);
}

void rushBlue(){
    chassis.setPose(51, -60,90);
    chassis.moveToPoint(15, -60, 1100, {.forwards = false});
    chassis.turnToPoint(8.61, -55, 650, {.forwards = false});
    chassis.moveToPoint(6, -53, 1000, {.forwards = false, .maxSpeed = 80}, false);
    // Clamp.set_value(HIGH);
    // intake.move(127);
    // pros::delay(100);
    // chassis.swingToPoint(25.42, -41.763, lemlib::DriveSide::LEFT, 1000);
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