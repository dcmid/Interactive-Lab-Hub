void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int x = analogRead(A0); //read analog input
  double v = x/1024. * 5; //convert to voltage
  Serial.print("Input: ");
  Serial.print(x);
  Serial.print('\t');
  Serial.print("Voltage");
  Serial.println(v);
  delay(25);
}
