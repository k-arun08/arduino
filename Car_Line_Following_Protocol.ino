#define Right_Motor_Move 7
#define Right_Motor_Speed 5
#define Left_Motor_Move 8
#define Left_Motor_Speed 6

#define Motor_Standby 3
#define Middle A1
#define Left A2
#define Right A0

int carSpeed = 63;

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
  pinMode(Middle, INPUT);
  pinMode(Left, INPUT);
  pinMode(Right, INPUT);

  Serial.begin(9600);
}


void loop(){
  digitalWrite(Motor_Standby, HIGH);
  int M = digitalRead(Middle);
  Serial.println(M);
  int L = digitalRead(Left);
  Serial.println(L);
  int R = digitalRead(Right);
  Serial.println(R);

  Serial.println("----------");

  

  if(M == 0){
    stopLeft();
  }
  else if(M ==1){
    stopRight();
  }
}