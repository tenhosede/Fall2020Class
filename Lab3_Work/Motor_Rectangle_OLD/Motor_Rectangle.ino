// This example drives each motor on the Romi forward, then
// backward.  The yellow user LED is on when a motor should be
// running forward and off when a motor should be running
// backward.

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
  rightAngle();
  delay(500);
}

void rightAngle(){
  // Drive forward.
  ledGreen(1);
  for (int speed = 0; speed <= 400; speed++)
  {
    motors.setSpeeds(speed,speed);
    delay(2);
  }
  for (int speed = 400; speed >= 0; speed--)
  {
    motors.setSpeeds(speed,speed);
    delay(2);
  }
  ledGreen(0);
  
  ledRed(1);
  // Turn 90 degrees left.
  motors.setLeftSpeed(-50);
  motors.setRightSpeed(50);
  delay(1000);
  motors.setLeftSpeed(0);
  motors.setRightSpeed(0);
  ledRed(0);
}
