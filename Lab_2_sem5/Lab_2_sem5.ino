#include <Stepper.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
const int stepsPerRevolution = 2048;  // liczba kroków na pełny obrót 28BYJ-48

// poprawna kolejność pinów dla ULN2003:
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(1);   // 10 RPM – bezpieczna prędkość dla 28BYJ-48
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Hello, world!");
}

void loop() {
  Serial.println("Obrot w prawo");
  myStepper.step(stepsPerRevolution);   // pełen obrót zgodnie z ruchem wskazówek zegara
  delay(500);

  Serial.println("Obrot w lewo");
  myStepper.step(-stepsPerRevolution);  // pełen obrót przeciwnie do ruchu wskazówek
  delay(500);
}
