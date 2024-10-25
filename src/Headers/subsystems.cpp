#include "main.h"
#include "pros/adi.h"
#include "pros/adi.hpp"
#include "pros/misc.h"
#include "pros/misc.hpp"


int wallMech = 0;
bool clamp = false;
static bool toggle{false};
static bool ladyT{false};

void setIntakes() {
  if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
    intakeR.move_velocity(-600);
  } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
    intakeR.move_velocity(600);
  } else {
    intakeR.move_velocity(0);
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

void setLady() {
  if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_R2)) {
	// if (!ladyT) {
	//   lady.set_value(true);
	//   ladyT = !ladyT;
	// } else {
	//   lady.set_value(false);
	//   ladyT = !ladyT;
	// }
  }
}
