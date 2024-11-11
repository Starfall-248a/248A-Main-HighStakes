#include "main.h"
#include "robodash/api.h"

rd::Selector selector({
	{"Red Solo Winpoint", &redSoloWP},
	{"Blue Solo Winpoint", &blueSoloWP},
	{"Skills", &skills},
});

rd::Console console;

void initialize() {
	console.println("Initializing robot...");
	chassis.calibrate(); // calibrate sensors
	ledManager.initialize(); // initialize the LED manager
}

void disabled() {
	while (true) {
		pros::delay(10);
		detectSide();
	}
}

void competition_initialize() {
  selector.focus();
  detectSide();
}

void autonomous() {
	console.println("Running auton...");
	if (blueSide) {
		underglow.setColor(0x0000FF);
	} else {
		underglow.setColor(0xFF0000);
	
	}
	redSoloWP();
}

void opcontrol() {
	console.clear();
	console.focus();
	console.println("Driving...");
	Time.rainbow(5);
	while (true) {
  
		// get left y and right x positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        // move the robot
        // prioritize steering slightly
        chassis.arcade(leftY, rightX, false, 0.70);

		setLifter();
		setIntakes();
		setClamp();
		updateArmState();
    	correctArmAngle();

		pros::delay(10);          // Run for 10 ms then update
	}
}