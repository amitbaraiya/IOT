int switch1 = 2;
int led = 13;
void setup(){
  Serial.begin(9600);
  pinMode(switch1,INPUT);
  pinMode(led,OUTPUT);
}
void loop(){
  Serial.println(digitalRead(switch1));
  if(digitalRead(switch1)){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }  
}
