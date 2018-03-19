#include <NewPing.h>

void setup() {
 Serial.begin(9600);
}

void loop() {
  dealy(500);
  Serial.print("Distance: ");
  Serial.print(sonar.ping_cm());
  Serial.println("cm");
}
