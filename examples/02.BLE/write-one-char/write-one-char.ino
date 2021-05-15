/*
  LED
*/

#include <ArduinoBLE.h>

BLEService ledService("19B10000-E8F2-537E-4F6C-D104768A1214"); // BLE LED Service

// BLE LED Switch Characteristic - custom 128-bit UUID, read and writable by central
BLEByteCharacteristic switchCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite);

const int ledPin = A6; // pin to use for the LED

void setup() {
  Serial.begin(9600);
  //while (!Serial);

  // set LED pin to output mode
  pinMode(ledPin, OUTPUT);

  // begin initialization
  if (!BLE.begin()) {
    Serial.println("starting BLE failed!");

    while (1);
  }

  // set advertised local name and service UUID:
  BLE.setLocalName("LED");
  BLE.setAdvertisedService(ledService);

  // add the characteristic to the service
  ledService.addCharacteristic(switchCharacteristic);

  // add service
  BLE.addService(ledService);

  // set the initial value for the characeristic:
  switchCharacteristic.writeValue(0);

  // start advertising
  BLE.advertise();

  Serial.println("BLE LED Peripheral");
}

void loop() {
  // BLE주변장치로부터 연결 대기 
  BLEDevice central = BLE.central();

  // 주변 장치와 연결이 되었다면 
  if (central) {
    Serial.print("Connected to central: ");
    // 연결된 주변 장치의 mac주소 출력 
    Serial.println(central.address());

    // 주변장치와 연결이 유지되어 있다면 
    while (central.connected()) {
      
      // 주변장치가 char에 값을 썼으면, 해당 값을 LED에 적
      if (switchCharacteristic.written()) {
        char value = char(switchCharacteristic.value());
        Serial.println(value);
        if (value == '1') { // If the value is '1'
          Serial.println("LED on");
          digitalWrite(ledPin, HIGH);         // will turn the LED on
        } else { // If the value is anything else
          Serial.println(F("LED off"));
          digitalWrite(ledPin, LOW);          // will turn the LED off
        }
      }
      
    }

    // when the central disconnects, print it out:
    Serial.print(F("Disconnected from central: "));
    Serial.println(central.address());
  }
}
