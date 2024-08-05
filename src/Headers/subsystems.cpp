#include "main.h"
#include "pros/misc.h"

<<<<<<< HEAD
bool hangToggle = false;
bool togglePTO = false;
bool intakeEject = false;

=======
>>>>>>> 18e9ba57c8f17be95946b6affcb30688385194e8
void setIntakes(){
	if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
		intake.move_velocity(200);
	}
	else if(controller.get_digital(E_CONTROLLER_DIGITAL_L1) and distance.get_distance() < 100){
		intake.move_velocity(200);
        hooks.move_velocity(-200);
	}
<<<<<<< HEAD
}

void liftPTO() {
  if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) {
    if(togglePTO) {
        Lift.erase_port(11);
        Lift.erase_port(18);
        driveLeft.append(liftLeft);
        driveRight.append(liftRight);
        PTO.set_value(LOW);
    } else {
        driveLeft.erase_port(11);
        driveRight.erase_port(18);
        Lift.append(liftLeft);
        Lift.append(liftRight);
        PTO.set_value(HIGH);
    }
    togglePTO = !togglePTO;
  }
}

void intakeControl() {
  if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
    intakeBottom.move(127);
  } else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) && distance.get_distance() < 10){
    intakeBottom.move(127);
    intakeTop.move(127);
  } else {
    
  }
}
=======
    else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) and color.get_hue() > 0 and color.get_hue() < 15){
        intake.move_velocity(200);
        hooks.move_velocity(200);
    }
}
>>>>>>> 18e9ba57c8f17be95946b6affcb30688385194e8
