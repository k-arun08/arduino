void setup() {
  pinMode(7,OUTPUT); //rightmove
  pinMode(5,OUTPUT); //rightspeed
  pinMode(8,OUTPUT); //left move
  pinMode(6,OUTPUT); //left speed
  pinMode(3,OUTPUT); // standby
}
void jiggle() {

  digitalWrite(7,HIGH);
  analogWrite(5,255);
  digitalWrite(8,LOW);
  analogWrite(6,255);
  delay(100);
  digitalWrite(8,HIGH);
  analogWrite(6,255);
  digitalWrite(7,LOW);
  analogWrite(5,255);
  
}

void stop() {
  digitalWrite(7,LOW);
  analogWrite(5,0);
  digitalWrite(8,LOW);
  analogWrite(6,0);
}

void forward() {
  digitalWrite(7,HIGH);
  analogWrite(5,255);
  digitalWrite(8,HIGH);
  analogWrite(6,255);
}

void backward() {
  digitalWrite(7,LOW);
  analogWrite(5,255);
  digitalWrite(8,LOW);
  analogWrite(6,255);
}

void left() {
  digitalWrite(7,HIGH);
  analogWrite(5,180);
}

void right() {
  digitalWrite(8,HIGH);
  analogWrite(6,180);
}

void loop() {
  //digitalWrite(3,HIGH);
  //forward();
  //delay(1000);
  //stop();
  //delay(1000);
  //left();
  //delay(100);
  //forward();
  //delay(1000);
  //jiggle();
  //delay(100);
  //jiggle();
  //delay(100);
  //jiggle();
  //delay(100);
  //jiggle();
  //delay(100);
  //jiggle();
  //delay(100);
  //jiggle();
  //delay(100);
  //jiggle();
  //delay(100);
  //left();
  //delay(1100);
  
  
}