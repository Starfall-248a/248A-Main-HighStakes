#include "main.h"
#include "pros/adi.h"
#include "pros/adi.hpp"
#include "pros/misc.h"
#include "pros/misc.hpp"

int wallMech = 0;
static bool toggle{false};
static bool inLifter{false};

void setIntakes() {
  if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
    intake.move_velocity(-600);
  } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
    intake.move_velocity(600);
  } else {
    intake.move_velocity(0);
  }
}

void setClamp() {
  if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_R1)) {
    if (!toggle) {
      Clamp.set_value(true);
      toggle = !toggle;
    } else {
      Clamp.set_value(false);
      toggle = !toggle;
    }
  }
}

void setLifter() {
  if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_R2)) {
    if(!inLifter) {
      inLift.set_value(true);
      inLifter = !inLifter;
    } else {
      inLift.set_value(false);
      inLifter = !inLifter;
    }
  }
}
