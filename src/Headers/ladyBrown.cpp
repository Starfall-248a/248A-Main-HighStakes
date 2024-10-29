#include "main.h"
#include "pros/adi.hpp"
#include "pros/motors.hpp"
#include "pros/rtos.hpp"
#include <cmath>

// Initialize the current state
ArmState currentState = IDLE;

// Define the angles for each state
const int LOW_ANGLE = -50;
const int MEDIUM_ANGLE = 320;
const int HIGH_ANGLE = 440;

// Function to set the arm angle
void setArmAngle(int angle) {
  
  arm.move_absolute(-angle*4, 100); // Adjust the speed as necessary
}

// Function to get the current arm angle
int getArmAngle() {
  return armAngle.get_position(); // Assuming the motor has an encoder
}

// Function to update the arm state based on button presses
void updateArmState() {
  if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)) {
    if(currentState == IDLE) {
      currentState = MEDIUM;
    } else if(currentState == MEDIUM) {
      currentState = SCORING;
    } else if(currentState == SCORING) {
      currentState = IDLE;
    }
  }
}

// Function to correct the arm angle if it deviates from the target
void correctArmAngle() {
  int targetAngle;
  switch (currentState) {
    case IDLE:
      targetAngle = LOW_ANGLE;
      break;
    case MEDIUM:
      targetAngle = MEDIUM_ANGLE;
      break;
    case SCORING:
      targetAngle = HIGH_ANGLE;
      break;
  }

  int currentAngle = getArmAngle();
  if (currentAngle != targetAngle) {
    setArmAngle(targetAngle);
  }
}
 