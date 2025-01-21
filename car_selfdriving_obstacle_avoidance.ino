#include <Servo.h>

#define trigPin 13
#define echoPin 12

#define servoPin 10

#define Right_Motor_Move 7
#define Right_Motor_Speed 5
#define Left_Motor_Move 8
#define Left_Motor_Speed 6

#define Motor_Standby 3

int carSpeed = 255;
int rightDistance = 0;
int leftDistance = 0;
int middleDistance = 0;
int distance = 0;
long duration = 0;

Servo bob;

int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}

void forward(){
 digitalWrite(Right_Motor_Move, HIGH);
 analogWrite(Right_Motor_Speed, carSpeed);
 digitalWrite(Left_Motor_Move, HIGH);
 analogWrite(Left_Motor_Speed, carSpeed);
}

void backward(){
  digitalWrite(Right_Motor_Move,LOW);
  analogWrite(Right_Motor_Speed, carSpeed);
  digitalWrite(Left_Motor_Move,LOW);
  analogWrite(Left_Motor_Speed, carSpeed);
}

void left(){
  digitalWrite(Right_Motor_Move, HIGH);
  analogWrite(Right_Motor_Speed, carSpeed);
  digitalWrite(Left_Motor_Move, LOW);
  analogWrite(Left_Motor_Speed, carSpeed);
}

void right(){
  digitalWrite(Right_Motor_Move, LOW);
  analogWrite(Right_Motor_Speed, carSpeed);
  digitalWrite(Left_Motor_Move, HIGH);
  analogWrite(Left_Motor_Speed, carSpeed);
}

void stopCar(){
  digitalWrite(Right_Motor_Move, LOW);
  analogWrite(Right_Motor_Speed, 0);
  digitalWrite(Left_Motor_Move, LOW);
  analogWrite(Left_Motor_Speed, 0);
}

void stopLeft(){
  digitalWrite(Right_Motor_Move, HIGH);
  analogWrite(Right_Motor_Speed, carSpeed);
  digitalWrite(Left_Motor_Move, LOW);
  analogWrite(Left_Motor_Speed, 0);
}

void stopRight(){
  digitalWrite(Right_Motor_Move, LOW);
  analogWrite(Right_Motor_Speed, 0);
  digitalWrite(Left_Motor_Move, HIGH);
  analogWrite(Left_Motor_Speed, carSpeed);
}


void setup() {
  pinMode(Right_Motor_Move, OUTPUT); 
  pinMode(Right_Motor_Speed, OUTPUT); 
  pinMode(Left_Motor_Move, OUTPUT); 
  pinMode(Left_Motor_Speed, OUTPUT); 
  pinMode(Motor_Standby, OUTPUT); 

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  bob.attach(servoPin);
  bob.write(90); 

  Serial.begin(9600); 
}

void loop() {
  digitalWrite(Motor_Standby, HIGH);
 
    bob.write(90);  //setservo position according to scaled value
    delay(500);
    middleDistance = getDistance();
    Serial.println(middleDistance);

    if(middleDistance <= 40) {    
      stopCar();
      delay(500);                        
      bob.write(10);          
      delay(1000);      
      rightDistance = getDistance();
     
      delay(500);
      bob.write(90);              
      delay(1000);                                                  
      bob.write(180);              
      delay(1000);
      leftDistance = getDistance();
     
      delay(500);
      bob.write(90);              
      delay(1000);
      if(rightDistance > leftDistance) {
        right();
        delay(50);
        //delay(360);
      }
      else if(rightDistance < leftDistance) {
        left();
        delay(50);
        //delay(360);
      }
      else if((rightDistance <= 40) || (leftDistance <= 40)) {
        backward();
        delay(180);
      }
      else {
        forward();
      }
    }  
    else {
        forward();
    }                
}