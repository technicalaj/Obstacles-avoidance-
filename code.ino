
// open source program to use anyone

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
int sensor= 8;
int st = 0;
int cont = 0;

void Forward()

{
   display.clearDisplay();
  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 1);
  display.println("  FORWARD ");
  display.display();      // Show initial text
    digitalWrite(2, 1);
    digitalWrite (3, 0);
    digitalWrite(4,1);
    digitalWrite(5,0);
    delay(3000);
     digitalWrite(2, 0);
    digitalWrite (3, 0);
    digitalWrite(4,0);
    digitalWrite(5,0);

}

void Backward()

{    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 1);
    display.println(" BACKWARD ");
    display.display();      // Show initial text
    digitalWrite(2, 0);
    digitalWrite(3, 1);
    digitalWrite(4, 0);
    digitalWrite(5,1);
    delay(3000);
     digitalWrite(2, 0);
    digitalWrite (3, 0);
    digitalWrite(4,0);
    digitalWrite(5,0);


}
void Left()

{   display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 1);
    display.println("    LEFT ");
    display.display();      // Show initial text
    digitalWrite(2, 0);
    digitalWrite(3, 0);
    digitalWrite(4, 1);
    digitalWrite(5,0);
    delay(2000);
     digitalWrite(2, 0);
    digitalWrite (3, 0);
    digitalWrite(4,0);
    digitalWrite(5,0);

 
}

void Right()

{
    display.clearDisplay();
  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 1);
  display.println("   RIGHT ");
  display.display();      // Show initial text
   digitalWrite(2, 1);
    digitalWrite(3, 0);
    digitalWrite(4, 0);
    digitalWrite(5,0);
    delay(2000);
     digitalWrite(2, 0);
    digitalWrite (3, 0);
    digitalWrite(4,0);
    digitalWrite(5,0);

 
}

void setup()

{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode (sensor, INPUT);
 if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
 }
  display.display();
  delay(2000); // Pause for 2 seconds
  display.clearDisplay();
  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 1);
  display.println("  Clap To    MOVE");
  display.display();      // Show initial text
  delay(100);
}

void loop()

{
 
//put your main code here,to run repeatedly;

  if (digitalRead(sensor) == HIGH) {
    delay(10);
    if (cont == 0)
      st = millis();
    cont = cont + 1;
    while (digitalRead(sensor) != LOW) {
      if (millis() - st > 2000) {
        Serial.print(cont);
        Serial.println(" aplausos");

        doOrders(cont);
        cont = 0;
      }
    }
  }
  if (millis() - st > 2000 && cont != 0) {
    Serial.print(cont);
    Serial.println(" aplausos");
    doOrders(cont);
    cont = 0;
  }
}
void doOrders(int apl)
{
 if (cont==1)

{
Forward();
}

else if (cont == 2)
{
Backward();
}

else if (cont == 3)
{
Left();
}

else if (cont == 4)
{
Right();
}
}
