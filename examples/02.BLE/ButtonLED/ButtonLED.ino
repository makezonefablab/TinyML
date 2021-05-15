/*
  Button LED
*/

#include <ArduinoBLE.h>

const int ledPin = A6; // LED연결된 핀 번호 
const int buttonPin = 4; // 버튼 연결된 핀 번호 

BLEService ledService("19B10010-E8F2-537E-4F6C-D104768A1214"); // BLE 서비스 생성 

// LED의 서비스 생성 및 읽고 쓰기 허용
BLEByteCharacteristic ledCharacteristic("19B10011-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite);
// 버튼의 서비스 생성 및 읽고 알리기 허용 
BLEByteCharacteristic buttonCharacteristic("19B10012-E8F2-537E-4F6C-D104768A1214", BLERead | BLENotify);

void setup() {
  Serial.begin(9600);
  //while (!Serial);

  pinMode(ledPin, OUTPUT); // LED핀은 출력으로 설정 
  pinMode(buttonPin, INPUT_PULLUP); // 버튼핀은 입력으로 설정 

  // BLE초기화 및 시작 
  if (!BLE.begin()) {
    Serial.println("starting BLE failed!");

    while (1);
  }

  // BLE표시 이름 설정 
  BLE.setLocalName("ButtonLED");
  // 알림 (광고)를 위해 셋팅 
  BLE.setAdvertisedService(ledService);

  // 서비스 char 설정 
  ledService.addCharacteristic(ledCharacteristic);
  ledService.addCharacteristic(buttonCharacteristic);

  // 설정된 서비스를 BLE에 추가 
  BLE.addService(ledService);

  ledCharacteristic.writeValue(0);
  buttonCharacteristic.writeValue(0);

  // 알림 시작 
  BLE.advertise();

  Serial.println("Bluetooth device active, waiting for connections...");
}

void loop() {
  // BLE로 들어오는 신호 검출 
  BLE.poll();

  // 현재 버튼 상태 읽기 
  char buttonValue = digitalRead(buttonPin);

  // 이전과 현재 버튼의 상태가 달라졌는지 검사 
  boolean buttonChanged = (buttonCharacteristic.value() != buttonValue);

  if (buttonChanged) {
    // 버튼상태 변경, LED상태 변경 
    ledCharacteristic.writeValue(buttonValue);
    buttonCharacteristic.writeValue(buttonValue);
  }

  // LED상태가 바뀌었거나 버튼상태가 바뀌었으면 
  if (ledCharacteristic.written() || buttonChanged) {

    // LED 값에 따른 LED제어 
    if (ledCharacteristic.value()) {
      Serial.println("LED on");
      digitalWrite(ledPin, HIGH);
    } else {
      Serial.println("LED off");
      digitalWrite(ledPin, LOW);
    }
  }
}
