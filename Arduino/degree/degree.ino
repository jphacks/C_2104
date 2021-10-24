#include <M5StickC.h>
#include <Kalman.h>

// vals
float acc[3];
float gyro[3];

float kalAngleX;
float kalAngleY;

long lastMs = 0;
long tick = 0;


Kalman kalmanX;
Kalman kalmanY;

void setup() {
  // init
  M5.begin();

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
}

void loop() {
  readGyro();
  float dt = (micros() - lastMs) / 1000000.0;
  lastMs = micros();
  float roll = getRoll();
  float pitch = getPitch();

  kalAngleX = kalmanX.getAngle(roll, gyro[0], dt);
  kalAngleY = kalmanY.getAngle(pitch, gyro[1], dt);

  // draw
  tick++;
  if(tick % 20 == 0){
    tick = 0;
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
