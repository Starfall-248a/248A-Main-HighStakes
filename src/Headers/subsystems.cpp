#include "main.h"
#include "pros/misc.h"

bool toggleClamp = false;

void setIntake() {
  if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
    Intake.move_velocity(600);
  } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
    Intake.move_velocity(-600);
  } else {
    Intake.brake();
  }
}

void setClamp() {
  if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)) {
    if (toggleClamp) {
      do {
        Clamp.move(127);
      } while (clampRot.get_angle() != 90);
    } else {
      do {
        Clamp.move(-127);
      } while (clampRot.get_angle() != 90);
    }
    toggleClamp = !toggleClamp;
  }
}
