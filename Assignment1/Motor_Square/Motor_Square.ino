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
  rightAngle();
  if (everyNmillisec(10)) {
    // ODOMETRY
    calculateOdom();
    doPID();
  }

}

void rightAngle(){
  // Drive forward.
  ledGreen(1);
  for (int speed = 0; speed <= 300; speed++)
  {
    motors.setSpeeds(speed+left_trim,speed+right_trim);
    delay(2);
  }
  for (int speed = 300; speed >= 0; speed--)
  {
    motors.setSpeeds(speed+left_trim,speed+right_trim);
    delay(2);
  }
  ledGreen(0);
  
  ledRed(1);
  // Turn 90 degrees left.
  motors.setLeftSpeed(-50+left_trim);
  motors.setRightSpeed(50+right_trim);
  delay(1050);
  motors.setLeftSpeed(0);
  motors.setRightSpeed(0);
  ledRed(0);
}
