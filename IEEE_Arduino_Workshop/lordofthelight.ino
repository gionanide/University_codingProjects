int buttonState=0;
int lastButtonState=0;
int state=1;
void setup() {
  pinMode(6,OUTPUT)
  pinMode(8,INPUT);
  Serial.begin(9600)
}

void loop() {
  buttonState = digitalRead(8);
  if(state==1)
  {digitalWrite(6,LOW);}
  else
  {analogWrite(6,HIGH);}

  if(buttonState!=lastButtonState && buttonState==HIGH)
  {state=-state}

  lastButtonState = buttonState;

}
}
