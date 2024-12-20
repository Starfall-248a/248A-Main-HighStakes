#include "lemlib/chassis/chassis.hpp"
#include "main.h"
#include "pros/adi.h"
#include "pros/rtos.hpp"

//Assets
ASSET(SkillsP1_txt)
ASSET(SkillsP2_txt)

void redSoloWP(){
    chassis.setPose(-60, -13.25, 323);
    setArmAngle(400);
    pros::delay(1250);
    chassis.moveToPoint(-43.687, -36.394, 1750);
    chassis.turnToPoint(-23.5, -23.5, 750);
    chassis.moveToPoint(-23.5, -23.5, 1500, {.forwards = false, .maxSpeed = 60}, false);
    Clamp.set_value(HIGH);
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
    chassis.moveToPoint(-29.665, -26.604, 2000, { .forwards = false, .maxSpeed = 60}, false);
    Clamp.set_value(HIGH);
    intake.move(127);
    pros::delay(100);
    //grab 1st ring
    chassis.turnToPoint(-24, -49, 1500);
    chassis.moveToPoint(-24, -49, 2000, {}, false);
    pros::delay(1750);
    //go to alliance stake 2 stack
    chassis.turnToPoint(-50, 4, 1250, {}, false);
    chassis.moveToPoint(-50, 4, 2250);
    chassis.waitUntil(5);
    inLift.set_value(HIGH);
    chassis.waitUntilDone();
    inLift.set_value(LOW);
    pros::delay(250);
    chassis.moveToPoint(-34.526, -18.939, 1250, {.forwards = false, .maxSpeed = 50});
    chassis.moveToPoint(-23.5, 0,1500);
    intake.brake();
}

void fourRingBlue(){
    blueSide = true;
    //grab first goal
    chassis.setPose(48.912,-36.043,115);
    chassis.moveToPoint(29.665, -26.604, 2000, { .forwards = false, .maxSpeed = 60}, false);
    Clamp.set_value(HIGH);
    intake.move(127);
    pros::delay(100);
    //grab 1st ring
    chassis.turnToPoint(24, -49, 1500);
    chassis.moveToPoint(24, -49, 2000, {}, false);
    pros::delay(1750);
    //go to alliance stake 2 stack
    chassis.turnToPoint(50, 4, 1250, {}, false);
    chassis.moveToPoint(50, 4, 2250);
    chassis.waitUntil(5);
    inLift.set_value(HIGH);
    chassis.waitUntilDone();
    inLift.set_value(LOW);
    pros::delay(250);
    chassis.moveToPoint(34.526, -18.939, 1250, {.forwards = false, .maxSpeed = 50});
    chassis.moveToPoint(23.5, 0,1500);
    intake.brake();

}

void disruptRed(){
    chassis.setPose(-46.489,31.313,70);
    inLift.set_value(HIGH);
    chassis.moveToPoint(-6, 46, 2000, {.maxSpeed = 100});
    chassis.moveToPoint(-23.5, 47, 1500, {.forwards = false, .maxSpeed = 60}, false);
    chassis.turnToPoint(-23.5, 23.5, 1000, {.forwards = false});
    chassis.moveToPoint(-23.5, 23.5, 1250, {.forwards = false, .maxSpeed = 60}, false);
    Clamp.set_value(HIGH);
    chassis.moveToPoint(-23.5, 23.5, 750, {.forwards = false, .maxSpeed = 70}, false);
    intake.move(127);
    inLift.set_value(LOW);
    pros::delay(200);
    chassis.moveToPoint(-19.341, 41.123, 1000);
    chassis.swingToHeading(180, lemlib::DriveSide::LEFT, 1250, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .maxSpeed = 60});
    chassis.turnToPoint(-48.191, 19.983, 1500);
    chassis.moveToPoint(-48.191, 19.983, 1500);
}

void disruptBlue(){
    chassis.setPose(46.489,31.313,290);
    inLift.set_value(HIGH);
    chassis.moveToPoint(6, 46, 2000, {.maxSpeed = 100});
    chassis.moveToPoint(23.5, 47, 1500, {.forwards = false, .maxSpeed = 60}, false);
    chassis.turnToPoint(23.5, 23.5, 1000, {.forwards = false});
    chassis.moveToPoint(23.5, 23.5, 1250, {.forwards = false, .maxSpeed = 60}, false);
    Clamp.set_value(HIGH);
    chassis.moveToPoint(23.5, 23.5, 750, {.forwards = false, .maxSpeed = 70}, false);
    intake.move(127);
    inLift.set_value(LOW);
    pros::delay(200);
    chassis.moveToPoint(19.341, 41.123, 1000);
    chassis.swingToHeading(180, lemlib::DriveSide::RIGHT, 1250, {.direction = AngularDirection::CW_CLOCKWISE, .maxSpeed = 60});
    chassis.turnToPoint(48.191, 19.983, 1500);
    chassis.moveToPoint(48.191, 19.983, 1500);
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
    chassis.moveToPoint(-49, 0, 1250);
    chassis.turnToPoint(-49, -50, 1250);
    chassis.moveToPoint(-49, 16, 1750, {.forwards = false, .maxSpeed = 70}, false);
    Clamp.set_value(HIGH);
    pros::delay(100);
    chassis.follow(SkillsP1_txt, 10, 20000);
    chassis.turnToPoint(-55.828, 61.431, 750, {.forwards = false}, false);
    Clamp.set_value(LOW);
    chassis.moveToPoint(-55.828, 61.431, 750, {.forwards = false, .maxSpeed = 70}, false);
    chassis.moveToPose(-49, -15, 0, 5000);
    chassis.follow(SkillsP2_txt, 10, 20000);
    chassis.turnToPoint(-55.828, -61.431, 750, {.forwards = false}, false);
    Clamp.set_value(LOW);
    chassis.moveToPoint(-55.828, -61.431, 750, {.forwards = false, .maxSpeed = 70}, false);
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