const int ledPin = 11;  // Pin PWM

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (int i = 0; i <= 255; i++) { // Zwiększ jasność
    analogWrite(ledPin, i);
    delay(5);
  }

  for (int i = 255; i >= 0; i--) { // Zmniejsz jasność
    analogWrite(ledPin, i);
    delay(5);
  }
}
