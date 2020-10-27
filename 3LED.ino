 int button = 2;
int flag = 1, t=300;
const int red=11,green=12,yellow=13;

//const int led2 = 1;


int buttonState ;
//int counter = 0;

void setup(){
  Serial.begin(9600);
  pinMode(red,OUTPUT);  
  pinMode(green,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(button,INPUT); 
}

void loop(){
 
  buttonState = digitalRead(button);
  Serial.println(buttonState); 
  if(buttonState == 1){
    if(flag==1){
      digitalWrite(green,HIGH);
      digitalWrite(red,LOW);
      flag = 2;
      delay(t);
    }
    else if(flag==2){
      digitalWrite(yellow,HIGH);
      digitalWrite(green,LOW);
      flag=3;
      delay(t);
    }
    else{
      digitalWrite(red,HIGH);
      digitalWrite(yellow,LOW);
      flag = 1;
      delay(t);
    }
  }
}

 
