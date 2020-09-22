#include<Servo.h>

Servo my_servo;
int pos = 0;
int count = 0;

void setup(){
  Serial.begin(9600);
  pinMode(A5, INPUT);
  pinMode(0, INPUT);
  my_servo.attach(9);
}

void loop(){
  if(!digitalRead(0)){ //if the button is pressed
    //button debounce
    delay(50);
    while(!digitalRead(0));
    delay(50);
    Serial.print("PRESSED: ");
    count = (count+1)%5;
    Serial.println(count);
    pos = count*180/4;
    Serial.println(pos);
    my_servo.write(pos);
  }
}
