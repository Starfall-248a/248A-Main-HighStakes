#include "main.h"
#include "robodash/api.h"
#include "robodash/views/image.hpp"
#include "Planet.c"

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

lv_img_dsc_t planet_img_dsc = {
  .header.always_zero = 0,
  .header.w = Planet.header.w,
  .header.h = Planet.header.h,
  .data_size = Planet.data_size,
  .header.cf = Planet.header.cf,
  .data = Planet.data,
};

rd::Image planet(planet_img_dsc, "Planet");

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
	pros::Task Time(ledTime, "LED time");

	while (true) {

		// get left y and right x positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        // move the robot
        // prioritize steering slightly
        chassis.arcade(leftY, rightX, false, 0.45);

		setLifter();
		setIntakes();
		setClamp();
		updateArmState();
    	correctArmAngle();
		
		pros::delay(10);          // Run for 10 ms then update
	}
}