#include "main.h"
#include "liblvgl/misc/lv_color.h"
#include "robodash/api.h"

rd::Selector selector({
   {"Solo WP", &soloWP},
   {"Half WP", &halfWP},
   {"Skills", &skills},
   {"test", &test},
   {"test1", &test1}
});

lv_color_t color_primary = lv_color_hex(0xFFB6C1);

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