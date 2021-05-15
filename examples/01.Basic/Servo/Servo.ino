/*
  Servo 

  서보모터를 0도에서 180도 왔다갔다
*/

#include <Servo.h>

Servo myservo;  //서보모터 변수 

int pos = 0;    //현재 위치값을 저장할 변수 

void setup() {
  myservo.attach(4);  // 서보모터 변수를 실제 연결된 핀과 연결  
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // 0에서 180까지 1씩 증가 
    // in steps of 1 degree
    myservo.write(pos);              // pos에 저장된 값만큼 실제 서보모터 이동 
    delay(15);                       // 15ms 대기 
  }
  for (pos = 180; pos >= 0; pos -= 1) { // 180에서 0까지 1씩 감소  
    myservo.write(pos);              // pos에 저장된 값만큼 실제 서보모터 이동 
    delay(15);                       // 15ms 대기
  }
}
