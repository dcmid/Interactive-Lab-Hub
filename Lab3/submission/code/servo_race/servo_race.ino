#include<Servo.h>

Servo my_servo;
int pos = 0;
int count = 0;
int speed = 0;
unsigned long last_press = 0;


void setup(){
  Serial.begin(9600);
  pinMode(A5, INPUT);
  pinMode(0, INPUT);
  my_servo.attach(9);
  my_servo.write(0);
}

void loop(){
  if(!digitalRead(0)){ //if the button is pressed
    //button debounce
    delay(50);
    while(!digitalRead(0));
    delay(50);
    
    unsigned long this_press = millis();//record time of this press
    unsigned long diff = this_press - last_press;//get difference from last press
    double press_per_sec = 1000.0/diff;//convert to speed (presses per second)
    Serial.println(press_per_sec);
    
    pos = round(press_per_sec*180/4)%180;//convert into usable number for servo
    my_servo.write(pos);

    last_press = this_press;
  }
}
