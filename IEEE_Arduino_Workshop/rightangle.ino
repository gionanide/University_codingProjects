#include <Servo.h>

Servo myServo;
void setup() {
 pinMode(5,OUTPUT);
 myServo.attach(5);
}

void loop() {
  myServo.write(0);
  delay(1000);
  myServo.write(180);
  delay(1000);
}
