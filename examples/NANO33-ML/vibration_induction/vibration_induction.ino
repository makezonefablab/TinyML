#include <Arduino_LSM9DS1.h>
#include <Adafruit_NeoPixel.h>

#define PIN            12 
#define NUM      1 //灯个数
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM, PIN, NEO_GRB + NEO_KHZ800);

float accel_x, accel_y, accel_z;
float gyro_x, gyro_y, gyro_z;
float mag_x, mag_y, mag_z;


void setup() {
  Serial.begin(9600);
  if (!IMU.begin()) { //LSM9DSI센서 시작
    Serial.println("LSM9DSI센서 오류!");
    while (1);
  }

  pixels.begin(); 
  pixels.clear();
  pixels.show();
  pixels.setPixelColor(0, pixels.Color(0,0,0));
  pixels.show(); //打印
  
}
void loop() {

  Serial.print("aX:");Serial.print(accel_x);
  Serial.print("aY:");Serial.print(accel_y);
  Serial.print("aZ:");Serial.print(accel_z);
  Serial.print("gX:");Serial.print(gyro_x);
  Serial.print("gY:");Serial.print(gyro_y);
  Serial.print("gZ:");Serial.print(gyro_z);
  Serial.print("yX:");Serial.print(mag_x);
  Serial.print("yY:");Serial.print(mag_y);
  Serial.print("yZ:");Serial.print(mag_z);
  Serial.println(""); 

  int xSum = fabs(gyro_x);
  int ySum = fabs(gyro_y);
  int zSum = fabs(gyro_z);

  if(zSum>255){
    zSum=255;
  }
  if(ySum>255){
    ySum=255;
  }
  if(xSum>255){
    xSum=255;
  }

  if(xSum<10){
    xSum=0;
  }
  if(ySum<10){
    ySum=0;
  }
  if(zSum<10){
    zSum=0;
  }
  pixels.setPixelColor(0, pixels.Color(xSum,ySum,zSum));
  pixels.show();
  
  delay(200);
}
