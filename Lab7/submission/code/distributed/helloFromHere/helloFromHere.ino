String data="Hello, Pi!";
String message;
int sensorPin=A0;
int ledPin=13;
int btn = 2;


void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
pinMode(ledPin, OUTPUT);
pinMode(btn, INPUT);
}

void blink(){
digitalWrite(ledPin, HIGH);
delay(100);
digitalWrite(ledPin, LOW);
delay(100);
}

void loop() {
if(Serial.available()){         //From RPi to Arduino
    message = Serial.readString();  //conveting the value of chars to integer
   // Serial.println(r);
    blink();
  }
  sensorValue=analogRead(btn);
// put your main code here, to run repeatedly:
Serial.println(sensorValue);//data that is being Sent
delay(200);
}
