int buttonState=0;
int lastButtonState=0;
int state=1;
void setup() {
  pinMode(6,OUTPUT)
  pinMode(A0,INPUT);
  pinMode(8,INPUT)
  Serial.begin(9600)
}

void loop() {
 buttonState=digitalRead(8);
 Serial.println(analogRead(A0);
 a=map(analogRead(A0),0,1024,0,255);

 if(state==1){
  analogWrite(6,a)}
  else{
    analogWrite(6,0)}

  if(buttonState!=lastButtonState)&& buttonState==HIGH){
    state=-state}


   lastButtonState=buttonState;
}
