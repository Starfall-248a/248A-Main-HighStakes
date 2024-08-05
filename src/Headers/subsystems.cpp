#include "main.h"
#include "pros/misc.h"

bool hangToggle = false;
bool togglePTO = false;
bool intakeEject = false;

void setIntakes(){
	if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
		intakeTop.move_velocity(600);
		intakeBottom.move_velocity(600);
	}
	else if(controller.get_digital(E_CONTROLLER_DIGITAL_L1) and distance.get_distance() < 10){
		intakeBottom.move_velocity(600);
		intakeTop.brake();
	}
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
