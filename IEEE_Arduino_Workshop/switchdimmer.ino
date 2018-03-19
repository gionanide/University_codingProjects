int buttonState=0;
int lastButtonState=0;
int state=1;
void setup() {
  pinMode(A1,OUTPUT)
  pinMode(A0,INPUT);
  Serial.begin(9600)
}

void loop() {
 Serial.println(analogRead(A0));
 int a=map(analogRead(A0),0,1023,0,255);
 analogWrite(11,a);
}
