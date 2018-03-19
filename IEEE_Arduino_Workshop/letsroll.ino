#include <Servo.h>

Servo myServo;

void setup() {
 Serial.begin(9600)
 myServo.attach(9);
}

void loop() {
  dealy(100);

  int angle=0;
  int chars = Serial.available();

  for(int i=1;i<=chars;i++){
    char incomingByte = Serial.read()
    
    if(incomingBYte < '0' || incomingByte > '0' || angle<0){
      angle=-1}
      else{
        angle = angle * 10 + (incomingByte - '0')}}

        if(chars){
          if(angle==-1){
            Serial.println("Insert natural numbers");}
            else if (angle>180){
              Serial.println("Max angle is 180 degrees")}
              else{
                myServo.write(angle);
                Serial.println(angle);
                }
            }
}
