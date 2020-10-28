int r = 11;
int g = 10;
int b = 9;
int btn = 2;

void setup(){
  Serial.begin(9600);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(btn, INPUT);
}

void red(){
  digitalWrite(r,1);
  digitalWrite(g,0);
  digitalWrite(b,0);
}
void grn(){
  digitalWrite(r,0);
  digitalWrite(g,1);
  digitalWrite(b,0);
}
void blu(){
  digitalWrite(r,0);
  digitalWrite(g,0);
  digitalWrite(b,1);
}

byte message;
void loop(){
  if(Serial.available()){
    message = Serial.read();
    //Serial.println(message);
    if(message == byte('g'))
      grn();
    else if(message == byte('r'))
      red();
    else if(message == byte('b'))
      blu();
  }
}
