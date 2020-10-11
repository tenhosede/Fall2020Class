//c = 2 * pi * r
//r1 = 200mm, c1 = 1256.64 mm
//r2 = 363mm, c2 = 2280.8 mm
//c2/c1 = 1.815

#include <Romi32U4.h>
#include <PololuRPiSlave.h>

Romi32U4Motors motors;
Romi32U4Encoders encoders;
Romi32U4ButtonA buttonA;

const int left_trim = -5;
const int right_trim = 0;
void setup() {
  Serial.begin(57600);

  // put your setup code here, to run once:
  ledYellow(false);
  ledGreen(true);
  ledRed(false);
}

float _debug_linear_ms = 0.25;
float _debug_angle_rs = 0.0;
void _DEBUG_PID_CONTROL() {
  static float _linear_ms_change = 0.1;
  set_twist_target(_debug_linear_ms, _debug_angle_rs);
}

void loop() {

  _DEBUG_PID_CONTROL();
  // put your main code here, to run repeatedly:
  int speed = 100;
  driveCircle(100);
  delay(500);
  if (everyNmillisec(10)) {
    // ODOMETRY
    calculateOdom();
    doPID();
  }

}

void driveCircle(int speed){
  // Run drive forward.
  ledGreen(1); //set so i can see it's running this code
  motors.setLeftSpeed(speed+left_trim); //take the input speed, hardcoded at 100
  motors.setRightSpeed((speed+right_trim) * 1.815); //drive the outside tire at the correct gear ratio
  delay(4000);  // run long enough to go in a circle
  motors.setSpeeds(0,0); // shut off motors
  ledGreen(0); //shut off led while idle
}
