const int B_1 = 10;

//LED-y
const int LED[] = {2, 3, 4, 5};
const int nLED = sizeof(LED)/sizeof(LED[0]);

void setup() {
  // put your setup code here, to run once:
  pinMode(B_1, INPUT);
  
  for (int i = 0; i < nLED; i++) {
    pinMode(LED[i], OUTPUT);
    digitalWrite(LED[i], LOW);
  }
}



void loop() {
  // put your main code here, to run repeatedly:
  bool B_1_State = digitalRead(B_1);

  if (B_1_State == HIGH){

    for (int L = 0; L < nLED; L++){
      digitalWrite(LED[L], HIGH);
      delay(200);
    }
    delay(200);
    for (int L = nLED - 1; L >= 0; L--){
      digitalWrite(LED[L], LOW);
      delay(200);
    }

  }

}
