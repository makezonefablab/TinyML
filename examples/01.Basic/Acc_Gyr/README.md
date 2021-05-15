# Arduino LSM9DS3 library

Arduino NANO 33 BLE에 장착된 IMU센서 입니다.


This library allows you to use the Arduino Nano 33 BLE IMU sensor. The IMU is a LSM9DS1, it is a 3-axis accelerometer and 3-axis gyroscope and 3-axis magnetometer; it is connected to the microcontroller through I2C on the NANO board. The values returned are signed floats.

To use this library
#include <Arduino_LSM9DS1.h>

The library takes care of the sensor initialisation and sets its values as follows:

Accelerometer range is set at [-4,+4]g -/+0.122 mg
Gyroscope range is set at [-2000, +2000] dps +/-70 mdps
Magnetometer range is set at [-400, +400] uT +/-0.014 uT
Accelerometer Output data rate is fixed at 104 Hz
Gyroscope Output data rate is fixed at 104 Hz
Magnetometer Output data rate is fixed at 20 Hz