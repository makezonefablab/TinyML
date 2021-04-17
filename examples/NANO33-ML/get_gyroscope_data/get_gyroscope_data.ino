#include <Arduino_LSM9DS1.h>

float accel_x, accel_y, accel_z;
float gyro_x, gyro_y, gyro_z;
float mag_x, mag_y, mag_z;


void setup() {
  Serial.begin(9600);
  if (!IMU.begin()) { //LSM9DSI센서 시작
    Serial.println("LSM9DSI센서 오류!");
    while (1);
  }
  
}
void loop() {
  //가속도센서
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(accel_x, accel_y, accel_z);
    Serial.print("가속도 센서 = "); Serial.print(accel_x); Serial.print(", "); Serial.print(accel_y); Serial.print(", "); Serial.println(accel_z);
  }
  //자이로센서
  if (IMU.gyroscopeAvailable()) {
    IMU.readGyroscope(gyro_x, gyro_y, gyro_z);
    Serial.print("자이로 센서 = "); Serial.print(gyro_x); Serial.print(", "); Serial.print(gyro_y); Serial.print(", "); Serial.println(gyro_z);
  }
  //지자계센서
  if (IMU.magneticFieldAvailable()) {
    IMU.readMagneticField(mag_x, mag_y, mag_z);
    Serial.print("지자계센서 = "); Serial.print(mag_x); Serial.print(", "); Serial.print(mag_y); Serial.print(", "); Serial.println(mag_z);
  }

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
  
  delay(200);
}
