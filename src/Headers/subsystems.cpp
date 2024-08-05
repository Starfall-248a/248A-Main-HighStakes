#include "main.h"
#include "pros/misc.h"

void setIntakes(){
	if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
		intake.move_velocity(200);
	}
	else if(controller.get_digital(E_CONTROLLER_DIGITAL_L1) and distance.get_distance() < 100){
		intake.move_velocity(200);
        hooks.move_velocity(-200);
	}
    else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) and color.get_hue() > 0 and color.get_hue() < 15){
        intake.move_velocity(200);
        hooks.move_velocity(200);
    }
}