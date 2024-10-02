#include "main.h"
#include "pros/adi.hpp"
#include "pros/adi.h"
#include "pros/misc.h"
#include "pros/misc.hpp"

bool wallMech = false;
bool clamp = false;
static bool toggle { false };

void setIntakes(){
	if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
		intakeR.move_velocity(-600);
		intakeL.move_velocity(600);
	}
	else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
		intakeR.move_velocity(600);
		intakeL.move_velocity(-600);
	}
	else {
		intakeR.move_velocity(0);
		intakeL.move_velocity(0);
	}
}

void setClamp(){
	if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_R1)) {
		if (!toggle) {
			Clamp.set_value(true);
			toggle = !toggle;
		}
		else {
			Clamp.set_value(false);
			toggle = !toggle;
		}
	}
}