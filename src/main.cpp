#include "main.h"
#include "robodash/api.h"
#include "stormlib/api.hpp"
#include "stormlib/led.hpp"

rd::Selector selector({
	{"Four Ring", &fourRingDeterminer},
	{"Solo Winpoint", &wpDeterminer},
	{"Skills", &skills},
});

rd::Console console;

stormlib::aRGB underglow(1, 144);
stormlib::aRGB_manager ledManager(&underglow, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);

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

	if (blueSide) {
		underglow.setColor(0x0000FF);
	} else {
		underglow.setColor(0xFF0000);
	
	}
}

void competition_initialize() {
  selector.focus();
  detectSide();
}

void autonomous() {
	console.println("Running auton...");
	selector.run_auton();
	
}

void opcontrol() {
	console.clear();
	console.focus();
	console.println("Driving... bruh");
	while (true) {
  
		// get left y and right x positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        // move the robot
        // prioritize steering slightly
        chassis.arcade(leftY, rightX, false, 0.75);

		setIntakes();
		setClamp();
		setLady();

		pros::delay(10);          // Run for 10 ms then update
	}
}