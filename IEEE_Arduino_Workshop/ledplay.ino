void setup() {
  pinMode(3,OUTPUT);
  Serial.begin(9600)
}

void loop() {
  digitalWrite(3,HIGH);
  delay(1000);
  digitalWrite(3,LOW);
  delay(1000);
}
