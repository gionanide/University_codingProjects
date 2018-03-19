void setup() {
  pinMode(8,OUTPUT);
  Serial.begin(9600)
}

void loop() {
  int buttonState;
  buttonState = digitalRead(8);
  if (buttonState==HIGH)
  {Serial.println("ON")}
  else
  {Serial.println("OFF")}
}
