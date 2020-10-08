#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels


// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Adafruit_LIS3DH lis = Adafruit_LIS3DH();

void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  
  Serial.begin(9600);
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  Serial.println("LIS3DH test!");

  if (! lis.begin(0x18)) {   // change this to 0x19 for alternative i2c address
    Serial.println("Couldnt start");
    while (1) yield();
  }
  Serial.println("LIS3DH found!");

  display.clearDisplay(); // Clear the buffer
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.cp437(true);

  display.write("Darren's\nAcceler...");
  display.display();
  delay(2000);
  display.setTextSize(1);
}

double x_a, y_a, z_a;
int r,g,b;
void loop() {
  sensors_event_t event;
  lis.getEvent(&event);
  x_a = event.acceleration.x;
  y_a = event.acceleration.y;
  z_a = event.acceleration.z;
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("X: ");
  display.println(x_a);
  display.print("Y: ");
  display.println(y_a);
  display.print("Z: ");
  display.println(z_a);
  display.display();

  r = round(abs(x_a)*20)%255;
  g = round(abs(y_a)*20)%255;
  b = round(abs(z_a)*20)%255;
  analogWrite(9,r);
  analogWrite(10,g);
  analogWrite(11,b);
  delay(50);
}
