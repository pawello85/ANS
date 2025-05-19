//Przyciski
const int B_1 = 10;
const int B_2 = 11;
bool B_1_Last = 0;
bool B_2_Last = 0;

//LED-y
const int LED[] = {2, 3, 4, 5};
const int nLED = sizeof(LED)/sizeof(LED[0]);

//Kierunek
int kierunek = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(B_1, INPUT);
  pinMode(B_2, INPUT);

  for (int i = 0; i < nLED; i++) {
    pinMode(LED[i], OUTPUT);
    digitalWrite(LED[i], LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:'
  bool B_1_State = digitalRead(B_1);
  bool B_2_State = digitalRead(B_2);

  if (B_1_State == LOW && B_1_Last == HIGH){
    delay(50);
    kierunek = (kierunek + 1) % 2;
  }
  
  //Wybór kierunku
  switch(kierunek){

    //Rosnący
    case 0:
      for (int L = 0; L < nLED; L++){
        digitalWrite(LED[L], HIGH);
        digitalWrite(LED[L-1], LOW);
        delay(200);
      }
      digitalWrite(LED[nLED - 1], LOW);
    break;
      
    //Malejący
    case 1:
      for (int L = nLED; L < 0; L--){
        digitalWrite(LED[L], HIGH);
        digitalWrite(LED[L-1], LOW);
        delay(200);
      }
      digitalWrite(LED[nLED - 1], LOW);
    break;
  }
  B_1_Last = B_1_State;
  B_2_Last = B_2_State;
}











