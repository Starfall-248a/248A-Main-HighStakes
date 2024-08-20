#include "main.h"
#include "pros/adi.hpp"
#include "pros/adi.h"
#include "pros/misc.h"

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
    else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) and color.get_hue() > 0 and color.get_hue() < 15){
        intake.move_velocity(200);
        hooks.move_velocity(200);
    }
}
>>>>>>> 18e9ba57c8f17be95946b6affcb30688385194e8
