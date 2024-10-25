// Define the states
enum ArmState {
  IDLE,
  MEDIUM,
  SCORING
};

// Declare the current state
extern ArmState currentState;

// Function to set the arm angle
void setArmAngle(int angle);

// Function to get the current arm angle
int getArmAngle();

// Function to update the arm state based on button presses
void updateArmState();

// Function to correct the arm angle if it deviates from the target
void correctArmAngle();