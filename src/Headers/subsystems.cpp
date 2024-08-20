#include "main.h"
#include "pros/adi.hpp"
#include "pros/adi.h"
#include "pros/misc.h"

bool clampState = true;

void setIntakes(){
	if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
		intake.move_velocity(-200);
		hooks.move_velocity(-200);
	}
	else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
		intake.move_velocity(200);
		hooks.move_velocity(200);
	}
	else {
		intake.move_velocity(0);
		hooks.move_velocity(0);
	}
}

void setClamp(){
	if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
		Clamp.set_value(HIGH);
	} 
	else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
		Clamp.set_value(LOW);
	}
}