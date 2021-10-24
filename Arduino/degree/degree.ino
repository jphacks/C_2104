/**********************************************
*   pose estimation program w/ M5StickC
*   for JPHacks2021
***********************************************
*   using FirebaseRTDB, M5StickC
**********************************************/

#include <M5StickC.h>
#include <Kalman.h>
#include <FirebaseESP32.h>

#define FIREBASE_HOST "hogehoge"
#define FIREBASE_AUTH "hogehogehoge"
#define WIFI_SSID "hogehogeeeee"
#define WIFI_PASSWORD "hogehogehogeeeee"


// vals
float acc[3];
float gyro[3];

float kalAngleX;
float kalAngleY;

long lastMs = 0;
long tick = 0;


Kalman kalmanX;
Kalman kalmanY;
FirebaseData fbd;


void setup() {
  // init
  M5.begin();
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);


  // connect to WiFi
  int cursor = 0;
  M5.Lcd.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    M5.Lcd.setCursor(0 + 5 * cursor, 30);
    M5.Lcd.print(".");
    delay(300);
    cursor++;
    if (cursor > 320)
    {
      cursor = 0;
    }
  }
  M5.Lcd.print("Connected with IP:");
  M5.Lcd.print(WiFi.localIP());
  delay(500);
  M5.Lcd.fillScreen(BLACK);


  // LCD init
  M5.Lcd.setRotation(3);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextSize(1);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.println("    X       Y       Z");
  M5.MPU6886.Init();
  M5.Lcd.setCursor(0, 60);

  readGyro();
  kalmanX.setAngle(getRoll());
  kalmanY.setAngle(getPitch());
  lastMs = micros();


  // firebase init
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
}

void loop() {
  readGyro();

  float dt = (micros() - lastMs) / 1000000.0;
  lastMs = micros();
  float roll = getRoll();
  float pitch = getPitch();

  // get angle
  kalAngleX = kalmanX.getAngle(roll, gyro[0], dt);
  kalAngleY = kalmanY.getAngle(pitch, gyro[1], dt);


  // draw
  tick++;
  if(tick % 20 == 0){
    tick = 0;
    Firebase.setFloat(fbd, "/pose/", kalAngleX);
    draw();
  }

  delay(5);
}


void draw(){
  M5.Lcd.setCursor(0, 15);
  M5.Lcd.printf("%7.2f %7.2f %7.2f", gyro[0], gyro[1], gyro[2]);
  M5.Lcd.setCursor(140, 15);
  M5.Lcd.print("o/s");
  M5.Lcd.setCursor(0, 30);
  M5.Lcd.printf("%7.2f %7.2f %7.2f", acc[0] * 1000, acc[1] * 1000, acc[2] * 1000);
  M5.Lcd.setCursor(145, 30);
  M5.Lcd.print("mg");
  M5.Lcd.setCursor(0, 45);
  M5.Lcd.printf("%7.2f %7.2f", kalAngleX, kalAngleY);
  M5.Lcd.setCursor(140, 45);
  M5.Lcd.print("deg");
}


void readGyro(){
  M5.MPU6886.getGyroData(&gyro[0], &gyro[1], &gyro[2]);
  M5.MPU6886.getAccelData(&acc[0], &acc[1], &acc[2]);
}


float getRoll(){
  return atan2(acc[1], acc[2]) * RAD_TO_DEG;
}


float getPitch(){
  return atan(-acc[0] / sqrt(acc[1]*acc[1] + acc[2]*acc[2])) * RAD_TO_DEG;
}
