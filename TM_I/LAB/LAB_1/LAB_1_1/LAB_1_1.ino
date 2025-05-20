const int D_1 = 7; //dioda stanu
const int D_2 = 8; //dioda kontrolna wejścia bramki A
const int D_3 = 9; //dioda kontrolna wejścia bramki B

const int B_1 = 2;
const int B_2 = 3;
const int B_3 = 4;

bool B_1_State = 0;  //Wejscie A
bool B_2_State = 0;  //Wejscie B
bool B_3_State = 0;  //Wybór operacji

int tryb = 0;
bool LastState = LOW;

void setup() {
  
  //inputs
  pinMode(B_1, INPUT);  
  pinMode(B_2, INPUT);
  pinMode(B_3, INPUT);

  //outputs
  pinMode(D_1, OUTPUT); 
  pinMode(D_2, OUTPUT);
  pinMode(D_3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool B_1_State = digitalRead(B_1);
  bool B_2_State = digitalRead(B_2);
  bool B_3_State = digitalRead(B_3);

  //kontrola stanu wejścia A
  if (B_1_State == HIGH){
    digitalWrite(D_2, HIGH);
  }
  else {
    digitalWrite(D_2, LOW);
  }
  
  //kontrola stanu wejścia B
    if (B_2_State == HIGH){
    digitalWrite(D_3, HIGH);
  }
  else {
    digitalWrite(D_3, LOW);
  }
  
  //wybór operacji
  if (B_3_State == LOW && LastState == HIGH){
    delay(50);
    tryb = (tryb + 1) % 3;
  }

  switch(tryb){
    
    case 0: //AND
      if (B_1_State == HIGH && B_2_State == HIGH){
        digitalWrite(D_1, HIGH);
      }
      else {
        digitalWrite(D_1, LOW);
      }
    break;

    case 1: //OR
      if (B_1_State == HIGH || B_2_State == HIGH){
        digitalWrite(D_1, HIGH);
      }
      else {
        digitalWrite(D_1, LOW);
      }
    break;
    
    case 2: //XOR
      if (B_1_State == HIGH != B_2_State == HIGH){
        digitalWrite(D_1, HIGH);
      }
      else {
        digitalWrite(D_1, LOW);
      }
    break;

  }
  LastState = B_3_State;
}

