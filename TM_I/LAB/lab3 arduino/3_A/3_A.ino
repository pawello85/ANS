//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
const float ANALOG = A0;
float voltage = 0;
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(4,0);
  lcd.print("Paweł Zabel");
  Serial.begin(9600);
  
  }



void loop()
{
  voltage = analogRead(ANALOG);
  Serial.println(voltage/200);
  lcd.setCursor(9,2);
  lcd.print(voltage/200);
  delay(500);

}
