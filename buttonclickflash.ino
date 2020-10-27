const int button = 11;
const int led = 5;
int flag =0, t=500;
//const int led2 = 1;


int buttonState ;
//int counter = 0;

void setup(){
  Serial.begin(9600);
  pinMode(led,OUTPUT);  
  pinMode(button,INPUT);
  digitalWrite(led,HIGH);
    
  
}

/*
void loop(){
// buttonState = digitalRead(button);
 
 //digitalWrite(led,LOW);
  buttonState = digitalRead(button);
  Serial.println(buttonState); 
  if(buttonState == 1){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }
  
}*/

void loop(){
// buttonState = digitalRead(button);
 //digitalWrite(led,LOW);
  buttonState = digitalRead(button);
  Serial.println(buttonState); 
  if(buttonState == 1){
    if(flag){
      digitalWrite(led,LOW);
      delay(t);
      flag = 0;
    }
    else{
      digitalWrite(led,HIGH);
      delay(t);
      flag = 1;
    }
  }
  
  
}
 
