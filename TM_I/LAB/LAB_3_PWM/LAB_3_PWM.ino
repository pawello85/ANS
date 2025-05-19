#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);
const int pwm = 9;
const int analogInPin = A7;
float val = 0;

void setup() {
  lcd.init();
  lcd.init();
  pinMode(pwm, OUTPUT);
  lcd.backlight();

}

void loop() {
 
  for (int i = 0; i <= 255; i+=51){
    analogWrite(pwm, i);
    
    val = analogRead(analogInPin);
    lcd.setCursor(3,3);
    lcd.print (val *(5.0 /1023));
    delay(500);
  }

  for (int i = 255; i >= 0; i-=51){
    analogWrite(pwm, i);
    
    val = analogRead(analogInPin);
    lcd.setCursor(3,3);
    lcd.print (val *(5.0 /1023));
    delay(500);
  }
}
