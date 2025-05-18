/*Przykładowy program dla sterowania pojedynczej diody LED
Guzik wlacza led pin 11 (PWM) */ 
const int switchPin = 8; 
const int ledPin = 11; 
bool currentButton = LOW; 
bool lastButton = LOW;
 
int ledLevel = 0;

 bool debounce(bool last)
 {
 bool current = digitalRead(switchPin);
 if (current != lastButton)
 {
 delay(5);
 current = digitalRead(switchPin);
 }
 return current;
 }

 void setup()
 {
 pinMode(switchPin, INPUT);
 pinMode(ledPin, OUTPUT);
 }

 void loop()
 {
 currentButton = debounce(lastButton);

 if (currentButton == HIGH && lastButton == LOW) ledLevel += 51;

 lastButton = currentButton;

 if (ledLevel > 255) ledLevel = 0;
 analogWrite(ledPin, ledLevel);
 }