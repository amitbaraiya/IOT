int light = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT);
  pinMode(13,OUTPUT);
  pinMode(3,INPUT);
  pinMode(12,OUTPUT);
}

void loop() {
  Serial.println(digitalRead(2));
  if(digitalRead(2)){
    light = !light;
    digitalWrite(13,light);
    while(digitalRead(2));
  }
  Serial.println(digitalRead(3));
  if(digitalRead(3)){
    light = !light;
    digitalWrite(13,LOW);
    digitalWrite(12,light);
    while(digitalRead(3));
  }
}
