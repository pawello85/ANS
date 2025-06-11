#include <TM1637Display.h>

#define CLK 2
#define DIO 3



const int ledPin = 11; 

TM1637Display display(CLK, DIO);

void setup() {
  pinMode(ledPin, OUTPUT);
  display.setBrightness(7);
  uint8_t blank[] = { 0x00, 0x00, 0x00, 0x00 };
  
}

void loop() {
  for (int i = 0; i <= 255; i+=5) { 
    analogWrite(ledPin, i);
    float displayValue = i*500.0/255.0;
    display.showNumberDecEx(displayValue,true);
    delay(50);
  }

  for (int i = 255; i >= 0; i-=5) { 
    analogWrite(ledPin, i);
    float displayValue = i*500.0/255.0;
    display.showNumberDecEx(displayValue,true);
    
    delay(50);
  }
}