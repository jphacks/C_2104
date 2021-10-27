#include <M5Atom.h>
#include <ESP32Servo.h>


// servo settings
Servo servo;
ESP32PWM pwm
int servoPin = 21;

// initial position(deg)
int pos = 0;


void setup() {
  // allow allocation of all timers
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);

  // M5 init
  M5.begin();

  // servo init
  servo.setPeriodHertz(50);
  //servo..attach(servo1Pin, minUs, maxUs);     // TODO: chose servo motor & set the params
}

void loop() {
  // put your main code here, to run repeatedly:

}
