/**********************************************
*   neck moving program w/ M5Atom Lite
*   for JPHacks2021
***********************************************
*   using FirebaseRTDB, M5Atom
**********************************************/

#include <M5Atom.h>
#include <ESP32Servo.h>

// SG-90, SG-92R params
#define MIN_PLS 500
#define MAX_PLS 2400


// servo settings
Servo servo;
ESP32PWM pwm
int servoPin = 21;

// firebase, wifi settings
#define FIREBASE_HOST "hogehoge"
#define FIREBASE_AUTH "hogehogehoge"
#define WIFI_SSID "hogehogeeee"
#define WIFI_PASSWORD "hogehogeohogeeee"
FirebaseData fbd;


// servo settings
Servo servo;
ESP32PWM pwm;
int servoPin = 21;

// initial position(deg)
int pos = 0;
float pos_fire = 0;


void setup() {
  // allow allocation of all timers
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);

  // M5 init
  M5.begin();
  delay(50);

  // wifi init
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    M5.dis.drawpix(0, 0xff0000);        // RED(not-ready)
  }

  // firebase init
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  // servo init
  servo.setPeriodHertz(50);
  servo.attach(servoPin, MIN_PLS, MAX_PLS);
  M5.dis.drawpix(0, 0x0000f0);        // BLUE(ready)
  servo.write(0);
  delay(1);

}

void loop() {
  // get pos data
  Firebase.getFloat(fbd, "/pose/");
  pos_fire = fbd.to<float>();

  if(pos_fire<=0 && pos_fire>=-45)
  {
    // cast
    pos_fire = pos_fire * (5.0 / 9.0);
    pos = -(int)pos_fire;

    // move neck
    servo.write(pos);
    delay(1);
  }else{
    // do nothing
  }

}
