#define red 9 
#define green 10
#define blue 11


void setup() {
 Serial.begin(9600)
 pinMode(red,OUTPUT);
 pinMode(green,OUTPUT);
 pinMode(blue,OUTPUT);
}

void loop() {
 delay(100);

 char text[11];

 int chars = Serial.available(),i;

 for (i=0;i<chars;i++){
  text[i]=Serial.read();}

  if(i>0){
    text[i] = '\0';

    if((String)text == "heart"){
      analogWrite(red,153);
      analogWrite(blue,255);
      analogWrite(blue,255);}
     else if ((String)text == "tree"){
       analogWrite(red,255);
      analogWrite(blue,153);
      analogWrite(blue,255);}
     else if ((String)text == "ieee"){
       analogWrite(red,255);
      analogWrite(blue,255);
      analogWrite(blue,153);}
    }
}
