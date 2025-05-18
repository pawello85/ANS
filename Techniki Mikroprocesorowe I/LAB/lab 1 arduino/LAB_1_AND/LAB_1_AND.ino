const int D_1 = 7; //dioda stanu
const int D_2 = 8; //dioda kontrolna wejścia bramki A
const int D_3 = 9; //dioda kontrolna wejścia bramki B

const int B_1 = 2;
const int B_2 = 3;

int B_1_State = 0;  //Wejscie A
int B_2_State = 0;  //Wejscie B

void setup() {
  // put your setup code here, to run once:
  pinMode(B_1, INPUT);
  pinMode(B_2, INPUT);
  

  pinMode(D_1, OUTPUT);
  pinMode(D_2, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  B_1_State = digitalRead(B_1);
  B_2_State = digitalRead(B_2);

  if (B_1_State & B_2_State == HIGH){
    digitalWrite(D_1, HIGH);
  }
  else {
    digitalWrite(D_1, LOW);
  }

  if (B_1_State == HIGH){
    digitalWrite(D_2, HIGH);
  }
  else {
    digitalWrite(D_2, LOW);
  }

    if (B_2_State == HIGH){
    digitalWrite(D_3, HIGH);
  }
  else {
    digitalWrite(D_3, LOW);
  }
}
