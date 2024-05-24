#include "main.h"
#include "liblvgl/misc/lv_color.h"
#include "robodash/api.h"

rd::Selector selector({
   {"Solo WP", &soloWP},
   {"Half WP", &halfWP},
   {"Skills", &skills},
});

rd::Console console;

void initialize() {
	console.println("Initializing robot...");
	// chassis.calibrate(); // calibrate sensors
}

void disabled() {

}

void competition_initialize() {

}

void autonomous() {
	console.println("Running auton...");
	selector.run_auton();
}

void opcontrol() {
	console.clear();
	
	console.println("Drive you bozo");
	while (true) {
		
		pros::delay(10);          // Run for 10 ms then update
	}
}