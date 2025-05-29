#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int startStopButtonPin = 2;
const int resetButtonPin = 3;

bool running = false;
unsigned long startTime = 0;
unsigned long elapsedTime = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Adres I2C może być 0x27 lub 0x3F

void setup() {
  pinMode(startStopButtonPin, INPUT_PULLUP);
  pinMode(resetButtonPin, INPUT_PULLUP);
  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Stoper");
}

void loop() {
  static bool lastStartStopState = HIGH;
  static bool lastResetState = HIGH;

  bool currentStartStopState = digitalRead(startStopButtonPin);
  bool currentResetState = digitalRead(resetButtonPin);

  if (lastStartStopState == HIGH && currentStartStopState == LOW) {
    if (!running) {
      startTime = millis() - elapsedTime;
      running = true;
    } else {
      elapsedTime = millis() - startTime;
      running = false;
    }
    delay(200);
  }

  if (lastResetState == HIGH && currentResetState == LOW) {
    elapsedTime = 0;
    if (running) {
      startTime = millis();
    }
    delay(200);
  }

  lastStartStopState = currentStartStopState;
  lastResetState = currentResetState;

  unsigned long displayTime = running ? millis() - startTime : elapsedTime;

  // Formatowanie czasu do mm:ss.mmm
  unsigned int minutes = displayTime / 60000;
  unsigned int seconds = (displayTime / 1000) % 60;
  unsigned int milliseconds = displayTime % 1000;



  lcd.setCursor(0, 1);
  lcd.print("Czas: ");
  if (minutes < 10) lcd.print("0");
  lcd.print(minutes);
  lcd.print(":");
  if (seconds < 10) lcd.print("0");
  lcd.print(seconds);
  lcd.print(".");
  
  if (milliseconds < 100) lcd.print("0");
  lcd.print(milliseconds);
}
