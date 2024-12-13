#include "lemlib/chassis/chassis.hpp"
#include "main.h"
#include "pros/adi.h"
#include "pros/rtos.hpp"

//Assets
ASSET(SkillsP1_txt)
ASSET(SkillsP2_txt)

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
    hooks.brake();
    chassis.waitUntil(10);
    preroller.move_velocity(200);
    inLift.set_value(HIGH);
    chassis.waitUntilDone();
    inLift.set_value(LOW);
    pros::delay(500);
    //sort out blue ring
    chassis.turnToPoint(-25.187, 21.741, 1000, {.forwards = false}, false);
    chassis.moveToPoint(-25.187, 21.741, 1500, {.forwards = false, .maxSpeed = 65}, false);
    chassis.waitUntil(5);
    Clamp.set_value(HIGH);
    pros::delay(100);
    hooks.move(127);
    chassis.turnToPoint(-19, 5.5, 1000);
    chassis.moveToPoint(-19, 5.5, 1500, {.maxSpeed = 50});
    chassis.waitUntil(5);
    intake.brake();
}

void blueSoloWP(){
    blueSide = true;
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
    hooks.brake();
    chassis.waitUntil(10);
    preroller.move_velocity(200);
    inLift.set_value(HIGH);
    chassis.waitUntilDone();
    inLift.set_value(LOW);
    //sort out blue ring
    chassis.turnToPoint(25.187, 21.741, 1000, {.forwards = false});
    chassis.waitUntil(15);
    chassis.moveToPoint(25.187, 21.741, 1500, {.forwards = false, .maxSpeed = 65}, false);
    chassis.waitUntil(5);
    Clamp.set_value(HIGH);
    pros::delay(100);
    hooks.move(127);
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
    blueSide = true;
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
    blueSide = true;
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
    blueSide = true;
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
    chassis.setPose(-60.5, 0, 90);
    hooks.move(127);
    pros::delay(750);
    preroller.move(127);
    chassis.moveToPoint(-47, 0, 1250);
    chassis.turnToPoint(-47, -50, 1250, {.forwards = false});
    chassis.moveToPoint(-47, 16, 2000, {.forwards = false, .maxSpeed = 90},false);
    Clamp.set_value(HIGH);
    pros::delay(100);
    chassis.follow(SkillsP1_txt, 5, 20000);
    chassis.turnToPoint(-55.828, 61.431, 750, {.forwards = false}, false);
    Clamp.set_value(LOW);
    chassis.moveToPoint(-55.828, 61.431, 750, {.forwards = false, .maxSpeed = 90}, false);
    chassis.moveToPose(-47, -15, 0, 5000);
    chassis.follow(SkillsP2_txt, 5, 20000);
    chassis.turnToPoint(-55.828, -61.431, 750, {.forwards = false}, false);
    Clamp.set_value(LOW);
    chassis.moveToPoint(-55.828, -61.431, 750, {.forwards = false, .maxSpeed = 90}, false);
    hooks.brake();
    chassis.moveToPoint(0, -59, 2000, {.earlyExitRange = 5});
    chassis.moveToPose(47.133, -6.042, 180, 3000, {.lead = .55}, false);
    Clamp.set_value(HIGH);
}

void find_tracking_center(float turnVoltage, uint32_t time) {
  chassis.setPose(0, 0, 0);
  unsigned long n = 0;
  float heading;

  std::cout << std::fixed << "\033[1mCopy this:\033[0m\n\\left[";
  driveRight.move(127);
  driveLeft.move(127);

  std::ostringstream out;

  auto end_time = time + pros::millis();

  int i = 0;
  
  while (pros::millis() < end_time && i++ < 10000) {
    std::cout << "\\left(" << chassis.getPose().x << "," << chassis.getPose().y << "\\right),";
    /*if (i % 250 == 0) {
      std::cout << "\\right]\n\\left[" ;
    } */
    if (i % 50 == 0) {
      std::cout.flush();
    }
    pros::delay(20);
  }  
  driveRight.brake();
  driveLeft.brake();
  std::cout << "\b\\right]" << std::endl;

  std::cout << "Go to https://www.desmos.com/calculator/rxdoxxil1j to solve for offsets." << std::endl;
}