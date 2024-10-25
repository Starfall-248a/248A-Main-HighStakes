#include "main.h"
#include "pros/adi.hpp"
#include "pros/motors.hpp"
#include "pros/rtos.hpp"
// #include "lemlib/pid.hpp"
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
    currentState = IDLE;
  } else if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
    currentState = MEDIUM;
  } else if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
    currentState = SCORING;
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
 
// void LiftPID(double targetAngle){
//   double kP;
//   double kI;
//   double kD;
//   lemlib::PID LiftController(
//         kP = 0.15,
//         kI = 0.0175,
//         kD = 0.75,
//         5,
//         true
//   );

//   double error;
//   double prevError = 0;
//   double revError;
//   double prevRevError = 0;
//   double integral = 0;
//   double revIntegral;
//   double revDerivative;
//   double currentAngle = armAngle.get_position();
//   while (std::abs(error) > 1) { 
//     error = currentAngle - targetAngle; 
//     integral += error;

//     if (std::abs(error) < 1) {
//         integral = 0;
//     }

//     if (std::abs(error) > 1200) {
//         integral = 0;
//     }

//     double derivative = error - prevError;
//     prevError = error;

//     double speed = (kP * error + kI * integral + kD * derivative) * 1.4;

//     arm.move_absolute(targetAngle, speed);

//     currentAngle = armAngle.get_position();
//   }
// }