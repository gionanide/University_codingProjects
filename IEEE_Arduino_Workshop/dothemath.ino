#include <Servo.h>
#include <NewPing.h>

#define TRIGGER_PIN 12
#define ECHO_PIN 11
#define MAX_DISTANCE 180

NewPing sonar(TRIGGER_PIN,ECHO_PIN,MAX_DISTANCE);

Servo myServo;

void setup() {
 Serial.begin(9600)
 myServo.attach(9);
}

void loop() {
 int angle = sonar.ping_cm()
 Serial.print(angle);

 myServo.write(angle);

 delay(500);
}
