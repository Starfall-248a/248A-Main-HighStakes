#include "main.h"
#include "robodash/api.h"

rd::Selector selector({
	{"Red Solo Winpoint", &redSoloWP},
	{"Blue Solo Winpoint", &blueSoloWP},
	{"Red five ring", &fourRingRed},
	{"Blue five ring", &fourRingBlue},
	{"Red disrupt", &disruptRed},
	{"Blue disrupt", &disruptBlue},
	{"Skills", &skills},
});

rd::Console console;

void initialize() {
	console.println("Initializing robot...");
	chassis.calibrate(); // calibrate sensors
	ledManager.initialize(); // initialize the LED manager
}

void disabled() {
	underglow.rainbow(1);
	TimeLED.rainbow(1);
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
	selector.run_auton();
}

void opcontrol() {
	console.clear();
	console.focus();
	console.println("Driving...");
	
	ledManager.setColor(0xFF0000);
	underglow.rainbow(1);
	TimeLED.rainbow(1);
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
		ledTime();

		pros::delay(10);          // Run for 10 ms then update
	}
}