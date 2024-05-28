#include "main.h"
#include "pros/misc.h"

bool hangToggle = false;

void setIntake(){
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
		Intake.move_velocity(600);
	}
	else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
		Intake.move_velocity(-600);
	}
	else {
	    Intake.brake();
	}
}

void setHang(){
    if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)){
        hangToggle = !hangToggle;
        Hang.set_value(hangToggle);
    }
}