#define green 9
#define blue 10
#define red 11
void setup() {
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
}

void loop() {
  analogWrite(red,153);
  analogWrite(green,255);
  analogWrite(blue,255);
  delay(1000);
  analogWrite(red,255);
  analogWrite(green,102);
  analogWrite(blue,255);
  delay(1000);
  analogWrite(red,255);
  analogWrite(green,255);
  analogWrite(blue,102);
  delay(1000);
  
}
