#include "main.h"
#include "robodash/api.h"
#include "robodash/views/image.hpp"
#include "Planet.c"
#include "goof.c"

rd::Selector selector({
	{"Red Solo Winpoint", &redSoloWP},
	{"Blue Solo Winpoint", &blueSoloWP},
	{"Red five ring", &fourRingRed},
	{"Blue five ring", &fourRingBlue},
	{"Red rush", &rushRed},
	{"Blue rush", &rushBlue},
	{"Red disrupt", &disruptRed},
	{"Blue disrupt", &disruptBlue},
	{"Skills", &skills},
});

rd::Console console;

rd::Image planet(Planet, "Planet");
rd::Image Goof(goof, "goof");

void initialize() {
	console.println("Initializing robot...");
	chassis.calibrate(); // calibrate sensors
	ledManager.initialize(); // initialize the LED manager
	ledManager.flow(0x4B0082, 0xD9AEFF);
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
	selector.run_auton();
}

void opcontrol() {
	console.clear();
	planet.focus();
	console.println("Driving...");
	underglow.rainbow(1);
	TimeLED.rainbow(1);
	pros::Task Flasher(ledTime, "LED time");
	while (true) {
		// get left y and right x positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        // move the robot
        chassis.arcade(leftY, rightX, false, 0.5);
		
		// set subsystems
		setLifter();
		setIntakes();
		setClamp();
		updateArmState();
    	correctArmAngle();
		
		pros::delay(10);          // Run for 10 ms then update
	}
}