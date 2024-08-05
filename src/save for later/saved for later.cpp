#include "main.h"
#include "pros/abstract_motor.hpp"
#include "pros/adi.h"
#include "pros/adi.hpp"
#include "pros/misc.h"

bool togglePTO = false;

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