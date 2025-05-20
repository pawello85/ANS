// Przyciski
const int B_1 = 10;  // Wybór kierunku
const int B_2 = 11;  // Uruchomienie cyklu
bool B_1_Last = LOW;
bool B_2_Last = LOW;

// LED-y
const int LED[] = {2, 3, 4, 5};
const int nLED = sizeof(LED) / sizeof(LED[0]);

// Kierunek i flaga wykonania cyklu
int kierunek = 0;
bool Run = false; // Flaga do uruchomienia cyklu

void setup() {
  pinMode(B_1, INPUT);  
  pinMode(B_2, INPUT);
  
  for (int i = 0; i < nLED; i++) {
    pinMode(LED[i], OUTPUT);
    digitalWrite(LED[i], LOW);
  }
}

void loop() {
  bool B_1_State = digitalRead(B_1);
  bool B_2_State = digitalRead(B_2);

  // Zmiana kierunku przyciskiem B_1
  if (B_1_State == LOW && B_1_Last == HIGH) {
    delay(50);  // Debounce
    kierunek = (kierunek + 1) % 2;
  }

  // Uruchomienie cyklu przyciskiem B_2
  if (B_2_State == LOW && B_2_Last == HIGH) {
    delay(50);  // Debounce
    Run = true;
  }

  // Wykonanie jednego cyklu
  if (Run) {
    switch (kierunek) {
      case 0:  // Rosnący
        for (int L = 0; L < nLED; L++) {
          digitalWrite(LED[L], HIGH);
          if (L > 0) digitalWrite(LED[L - 1], LOW);
          delay(200);
        }
        digitalWrite(LED[nLED - 1], LOW);
      break;

      case 1:  // Malejący
        for (int L = nLED - 1; L >= 0; L--) {
          digitalWrite(LED[L], HIGH);
          if (L < nLED - 1) digitalWrite(LED[L + 1], LOW);
          delay(200);
        }
        digitalWrite(LED[0], LOW);
      break;
    }
    Run = false; // Zakończ cykl
  }

  B_1_Last = B_1_State;
  B_2_Last = B_2_State;
}
