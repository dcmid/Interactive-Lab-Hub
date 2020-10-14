#include <EEPROM.h>
#define LED 3
#define BTN 0

int addr = 0;
int state = 0; // States: 0-record, 1-playback
const int ROMLEN = EEPROM.length();
void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT);
  pinMode(A0, INPUT);

  for(int i=0; i<ROMLEN; i++) //clear the EEPROM
    EEPROM.write(i,0);
}

int a_in;
int iter;
byte data;
void loop() {
  if(state == 0){ //state 0-record
    a_in = analogRead(A0); //read analog input
    data = a_in << 2; //drop 2 bits from 10-bit ADC value to get byte for EEPROM
    EEPROM.write(addr, data); //write to EEPROM
    Serial.println(data);
    addr = (addr+1)%ROMLEN; //increment address, wrapping when out of memory
    state = read_button(); //check if button is pressed and update state
    delay(5);
  }
  else{ //state 1-playback
    for(int i=0; i<ROMLEN; i++){
      iter = (i+addr)%ROMLEN; //iterator shifted to start at oldest sample
      analogWrite(LED, EEPROM.read(iter)); //write to LED
      delay(5);
    }
    analogWrite(LED, 0);
    state = 0;
  }

}

//red button input with debounce
int read_button(){
  if(!digitalRead(BTN)){
    delay(10);
    while(!digitalRead(BTN));
    delay(10);
    return 1;
  }
  return 0;
}
