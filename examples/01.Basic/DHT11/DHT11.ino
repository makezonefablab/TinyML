
/*
  DHT11 온습도 센서 

  https://github.com/tjpetz/EnvironmentSensorTests
  
*/

 
#include "DHT.h"
#include "DHT_U.h"

#define DHTPIN 2     // DHT11센서가 연결된 핀번호 

// DHT11
DHT_Unified dht(DHTPIN, DHT11);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200); // 시리얼 통신을 위한 통신속도 설정 
  delay(1500);

  dht.begin(); // 센서 감지 시작 

}

void loop() {
  sensors_event_t event;
  float dht_temp, dht_humidity;
  char dht_out[64];

  dht.temperature().getEvent(&event);
  dht_temp = event.temperature;  // 온도값 저장 
  dht.humidity().getEvent(&event);
  dht_humidity = event.relative_humidity; // 습도값 저장 

  snprintf(dht_out, 64, "DHT: %0.2f, %0.2f", dht_temp, dht_humidity);

  // DHT11
  Serial.print("DHT temp = "); Serial.print(dht_temp);
  Serial.print(", humidity = "); Serial.println(dht_humidity);

  delay(3000);
}
