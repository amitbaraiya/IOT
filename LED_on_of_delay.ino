int led2=13;
void setup(){
  pinMode(13,OUTPUT);
}
void loop(){
  digitalWrite(led2,HIGH);
  delay(1000);
  digitalWrite(led2,HIGH);
}
