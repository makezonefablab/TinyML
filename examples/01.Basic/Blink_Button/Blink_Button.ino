/*
  Blink와 버튼 

  버튼을 누르면 LED를 1초에 한번 씩 깜빡
*/

void setup() {
  // 2번 핀을 output으로 설정.
  pinMode(A6, OUTPUT);
  pinMode(3, INPUT_PULLUP); 
}

// loop 함수는 영원히 반복적으로 수행
void loop() {
  
  if(digitalRead(3) == LOW)
  {
    digitalWrite(A6, HIGH);   // 2번 핀으로 5V 보냄
    delay(1000);             // 1초 대기
    digitalWrite(A6, LOW);    // 2번 핀으로 0V
    delay(1000);             // 1기초 대기 
  }
  
}
