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
#include "DHT.h"
#include "DHT_U.h"
#include <Servo.h>

#define DHTPIN 2     // DHT11센서가 연결된 핀번호
#define LEDPIN A6
#define SERVO_PIN 4



Servo myservo;  //서보모터 변수 

// DHT11
DHT_Unified dht(DHTPIN, DHT11);

BLEService        HouseService                 ("2A5A20B9-0000-4B9C-9C69-4975713E0FF2");
BLECharacteristic DHTCharacteristic   ("2A5A20B9-0001-4B9C-9C69-4975713E0FF2", BLERead | BLENotify, sizeof(float) * 2);
BLEByteCharacteristic LEDCharacteristic     ("2A5A20B9-0002-4B9C-9C69-4975713E0FF2", BLERead | BLEWrite);
BLEByteCharacteristic ServoCharacteristic   ("2A5A20B9-0002-4B9C-9C69-4975713E0FF2", BLERead | BLEWrite);

void setup() {
  Serial.begin(115200); // 시리얼 통신을 위한 통신속도 설정 
  delay(1500);

  pinMode(LEDPIN, OUTPUT);

  dht.begin(); // 센서 감지 시작

  myservo.attach(SERVO_PIN);  // 서보모터 변수를 실제 연결된 핀과 연결  

  // BLE초기화 및 시작 
  if (!BLE.begin()) {
    Serial.println("starting BLE failed!");

    while (1);
  }


  BLE.setLocalName("ArduinoHouse");
  BLE.setAdvertisedService(HouseService);

  HouseService.addCharacteristic(DHTCharacteristic);
  HouseService.addCharacteristic(LEDCharacteristic);
  HouseService.addCharacteristic(ServoCharacteristic);
  

  BLE.addService(HouseService);

  // set the initial value for the characeristic:
  LEDCharacteristic.writeValue(0);
  ServoCharacteristic.writeValue(0);

  BLE.advertise();

  Serial.println("Bluetooth device active, waiting for connections...");

  myservo.write(0);              // pos에 저장된 값만큼 실제 서보모터 이동 
  delay(1000);                       // 1초 대기 
  myservo.write(70);              // pos에 저장된 값만큼 실제 서보모터 이동 
  delay(1000);                       // 1초 대기 
  myservo.write(0);              // pos에 저장된 값만큼 실제 서보모터 이동 
  delay(1000);                       // 1초 대기 
}

void loop() {

  // BLE로 들어오는 신호 검출 
  BLE.poll();

  float dhtvalues[2] = {0.0,0.0};
  
  sensors_event_t event;
  float dht_temp, dht_humidity;
  char dht_out[64];

  dht.temperature().getEvent(&event);
  dht_temp = event.temperature;  // 온도값 저장 
  dht.humidity().getEvent(&event);
  dht_humidity = event.relative_humidity; // 습도값 저장 

  dhtvalues[0] = dht_temp;
  dhtvalues[1] = dht_humidity;

  snprintf(dht_out, 64, "DHT: %0.2f, %0.2f", dhtvalues[0], dhtvalues[1]);
  Serial.println(dht_out);

  DHTCharacteristic.writeValue(dhtvalues, sizeof(dhtvalues));
  
  //DHTCharacteristic.writeValue(random(0,100));



  // LED상태가 바뀌었으면 
  if (LEDCharacteristic.written()) {
    char value1 = char(LEDCharacteristic.value());
    // LED 값에 따른 LED제어 
    if (value1 =='0') {
      Serial.println("LED off");
      digitalWrite(LEDPIN, LOW);
    } else {
      Serial.println("LED on");
      digitalWrite(LEDPIN, HIGH);
    }
  }

  // 서보값이 바뀌었으 
  if (ServoCharacteristic.written()) {
    
    char value2 = char(ServoCharacteristic.value());
    
    // servo 값에 따른 servo제어 
    if (value2 =='0') {
      Serial.println("Door close");
      myservo.write(0);
    }
    else
    {
      Serial.println("Door open");
      myservo.write(70);
    }
  }


}
