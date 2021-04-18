#include <Arduino_LSM9DS1.h>
#include <Adafruit_NeoPixel.h>

// https://m.blog.naver.com/PostView.nhn?blogId=alexpark0922&logNo=221651198651&proxyReferer=https:%2F%2Fwww.google.com%2F

#define PIN      12 
#define NUM      1
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM, PIN, NEO_GRB + NEO_KHZ800);

float accel_x, accel_y, accel_z;
float gyro_x, gyro_y, gyro_z;
float mag_x, mag_y, mag_z;

const float accelerationThreshold_HIGH = 3.5;
const float accelerationThreshold_LOW= 1.9;

const int record_num=70;

int record_count=0;
int data_count=0;
int n=100;

int dirty=0;

float record_aX[300];
float record_aY[300];
float record_aZ[300];

float record_gX[300];
float record_gY[300];
float record_gZ[300];


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
  pixels.show();
  
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

  float aSum = fabs(accel_x) + fabs(accel_y) + fabs(accel_z);

  if (aSum >= accelerationThreshold_HIGH&&record_count==-1)
  {
    record_count=0;

    data_count++;
    if(data_count==n){
      pixels.setPixelColor(0, pixels.Color(255,0,0));
      pixels.show();
    }else if(data_count>n){
      pixels.setPixelColor(0, pixels.Color(0,255,0));
      pixels.show();
    }
  }

  if(record_count<record_num&&record_count!=-1)
  {
    record_aX[record_count]=accel_x;
    record_aY[record_count]=accel_y;
    record_aZ[record_count]=accel_z;
    record_gX[record_count]=gyro_x;
    record_gY[record_count]=gyro_y;
    record_gZ[record_count]=gyro_z;
    record_count++;
  }

  if(record_count==record_num)
  {
      for(int k=0;k<record_count;k++){
        Serial.print(record_aX[k]);
        Serial.print(",");
        Serial.print(record_aY[k]);
        Serial.print(",");
        Serial.print(record_aZ[k]);
        Serial.print(",");
        Serial.print(record_gX[k]);
        Serial.print(",");
        Serial.print(record_gY[k]);
        Serial.print(",");
        Serial.print(record_gZ[k]);
        Serial.println("");
      }
      record_count=-1;
  }
}
