# Arduino LSM9DS1 library

Arduino NANO 33 BLE에 장착된 IMU센서 입니다.

아래 라이브러리를 Arduino IDE -> 스케치 -> 라이브러리 포함하기 ->라이브러리 관리  에서 추가하세요.

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


<img src="https://github.com/makezonefablab/TinyML/blob/main/examples/01.Basic/Acc_Gyr/imgs/LSM9DS3.png" width="750" title="아두이노 나노 33 BLE IMU" alt="아두이노 나노 33 BLE IMU"></img><br/>

<img src="https://t1.daumcdn.net/cfile/tistory/21526E465614BA7104" title="자이로 가속도" alt="자이로 가속도"></img><br/>

<img src="https://github.com/makezonefablab/TinyML/blob/main/examples/01.Basic/Acc_Gyr/imgs/chart_acc.png" width="750" title="가속도 센서" alt="가속도 센서"></img><br/>

<img src="https://github.com/makezonefablab/TinyML/blob/main/examples/01.Basic/Acc_Gyr/imgs/chart_gyr.png" width="750" title="자이로 센서" alt="자이로 센서"></img><br/>

<img src="https://github.com/makezonefablab/TinyML/blob/main/examples/01.Basic/Acc_Gyr/imgs/chart_mag.png" width="750" title="마그넷 센서" alt="마그넷 센서"></img><br/>