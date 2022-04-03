/*
아래 내용 삭제금지
Title: 아두이노 손소독제 자동 펌핑키트 Arduino Sanitizer Auto Pumping Kit
Youtube Link: https://youtu.be/fLsvbnxbabY

소스코드 공유 시 위 사항을 포함하여 공유해주세요.
When sharing the source code, please include the source as shown above.

echo = 3
trig = 4
servo = 5
*/

#include  <Servo.h>
Servo myservo;

int first_angle = 100; //you can change the value.
int second_angle = 50; //you can change the value.
int detection_distance = 20; //(cm)you can change the value.

int sw = 12; //Switch
int echoPin = 3; //ultrasonic sensor echoPIN
int trigPin = 4; //ultrasonic sensor trigPIN

void setup() {
  myservo.attach(5);
  myservo.write(first_angle);
  pinMode(sw, INPUT_PULLUP);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop(){
  digitalWrite(trigPin, LOW);
  digitalWrite(echoPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  unsigned long duration = pulseIn(echoPin, HIGH);
  float distance = duration / 29.0 / 2.0;

  if (digitalRead(sw) == LOW){
   if (distance <= detection_distance){
      myservo.write(second_angle);
      delay(400);
      myservo.write(first_angle);
      delay(800);
    }
  }
  else{
    myservo.write(first_angle);
  }
}
