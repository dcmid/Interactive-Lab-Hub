#include<Servo.h>

Servo my_servo;
int pos = 0;

void setup(){
  Serial.begin(9600);
  pinMode(A5, INPUT);
  my_servo.attach(9);
}

void loop(){
  pos = 180*(analogRead(A5)/1023.0);
  my_servo.write(pos);
  delay(5);
}
