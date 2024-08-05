#include "main.h"
#include "robodash/api.h"
#include "robodash/views/image.hpp"

rd::Selector selector({
   {"Solo WP", &soloWP},
   {"Half WP", &halfWP},
   {"Skills", &skills},
});

rd::Console console;

void initialize() {
	console.println("Initializing robot...");
	chassis.calibrate(); // calibrate sensors
}

void disabled() {

}

void competition_initialize() {
  selector.focus();
}

void autonomous() {
	console.println("Running auton...");
	selector.run_auton();
}

void opcontrol() {
	console.clear();
	console.println("Driving...");
	while (true) {
  
		// get left y and right x positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        // move the robot
        // prioritize steering slightly
        chassis.arcade(leftY, rightX, false, 0.75);

		pros::delay(10);          // Run for 10 ms then update
	}
}