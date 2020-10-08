void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

int r,g,b = 0;
void loop() {
  r = (r+1)%255;
  g = (g+3)%255;
  b = (b+7)%255;

  analogWrite(9,r);
  analogWrite(10,g);
  analogWrite(11,b);
  delay(20);
}
