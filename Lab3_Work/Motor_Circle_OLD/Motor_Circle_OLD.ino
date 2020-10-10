// This example drives the romi chassis in a circle.
// The diameter of the circle is meant to be 200mm, so the circumference of a 200mm circle
// and the diameter of a 363mm circle (the width of the chassis) and the ratio of the larger
// circle to the smaller circle is 1.815. This could be added as a calculation to the program
// so that a user could input the diameter of the circle and the correct ratio could be calculated
// and driven to each motor.

//c = 2 * pi * r
//r1 = 200mm, c1 = 1256.64 mm
//r2 = 363mm, c2 = 2280.8 mm
//c2/c1 = 1.815

#include <Romi32U4.h>

Romi32U4Motors motors;
Romi32U4ButtonA buttonA;

void setup()
{
  // Wait for the user to press button A.
  buttonA.waitForButton();

  // Delay so that the robot does not move away while the user is
  // still touching it.
  delay(1000);
}

void loop()
{
  int speed = 100;
  driveCircle(speed);  //call circle drive algorithm
  delay(500);
}

void driveCircle(int speed){
  // Run drive forward.
  ledGreen(1); //set so i can see it's running this code
  motors.setLeftSpeed(speed); //take the input speed, hardcoded at 100
  motors.setRightSpeed(speed * 1.815); //drive the outside tire at the correct gear ratio
  delay(4000);  // run long enough to go in a circle
  motors.setSpeeds(0,0); // shut off motors
  ledGreen(0); //shut off led while idle
}
