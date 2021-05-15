/*
  ArduinoBLE IMU

  This example creates a BLE peripheral with service that contains two
  characteristics(acceleration, gyroscope)

  The circuit:
  No extra circuit setup is required. You can use -
  - Arduino Nano 33 BLE
  - or Nano 33 IoT
  - or Uno WiFi Rev 2

  This example code is made by Sandeep Mistry(@sandeepmistry)
*/
#include <ArduinoBLE.h>
#include <Arduino_LSM9DS1.h> // change to Arduino_LSM6DS3.h for Nano 33 IoT or Uno WiFi Rev 2

BLEService        imuService                 ("2A5A20B9-0000-4B9C-9C69-4975713E0FF2");
BLECharacteristic accelerationCharacteristic ("2A5A20B9-0001-4B9C-9C69-4975713E0FF2", BLENotify, sizeof(float) * 3);
BLECharacteristic gyroscopeCharacteristic    ("2A5A20B9-0002-4B9C-9C69-4975713E0FF2", BLENotify, sizeof(float) * 3);
BLECharacteristic magnetCharacteristic       ("2A5A20B9-0002-4B9C-9C69-4975713E0FF2", BLENotify, sizeof(float) * 3);

void setup() {
  Serial.begin(9600);
  //  while (!Serial); // uncomment to wait for Serial port to be opened

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  if (!BLE.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  BLE.setLocalName("ArduinoIMU");
  BLE.setDeviceName("ArduinoIMU");
  BLE.setAdvertisedService(imuService);

  imuService.addCharacteristic(accelerationCharacteristic);
  imuService.addCharacteristic(gyroscopeCharacteristic);
  imuService.addCharacteristic(magnetCharacteristic);

  BLE.addService(imuService);

  BLE.advertise();
}

void loop() {
  if (BLE.connected()) {
    if (accelerationCharacteristic.subscribed() && IMU.accelerationAvailable()) {
      float acceleration[3];

      // x, y, z
      IMU.readAcceleration(acceleration[0], acceleration[1], acceleration[2]);
      Serial.print("Acc : ");
      Serial.print(acceleration[0]);
      Serial.print(" / ");
      Serial.print(acceleration[1]);
      Serial.print(" / ");
      Serial.println(acceleration[2]);

      accelerationCharacteristic.writeValue(acceleration, sizeof(acceleration));
    }

    if (gyroscopeCharacteristic.subscribed() && IMU.gyroscopeAvailable()) {
      float gyroscope[3];

      // x, y, z
      IMU.readGyroscope(gyroscope[0], gyroscope[1], gyroscope[2]);
      Serial.print("Gyro : ");
      Serial.print(gyroscope[0]);
      Serial.print(" / ");
      Serial.print(gyroscope[1]);
      Serial.print(" / ");
      Serial.println(gyroscope[2]);


      gyroscopeCharacteristic.writeValue(gyroscope, sizeof(gyroscope));
    }

    if (magnetCharacteristic.subscribed() && IMU.magneticFieldAvailable()) {
      float magnetscope[3];

      // x, y, z
      IMU.readMagneticField(magnetscope[0], magnetscope[1], magnetscope[2]);
      Serial.print("Magnet : ");
      Serial.print(magnetscope[0]);
      Serial.print(" / ");
      Serial.print(magnetscope[1]);
      Serial.print(" / ");
      Serial.println(magnetscope[2]);

      magnetCharacteristic.writeValue(magnetscope, sizeof(magnetscope));
    }

  }
}
