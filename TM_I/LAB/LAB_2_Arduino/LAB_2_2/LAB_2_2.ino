const int B_1 = 8; 
const int L_1 = 11;
const int L_2 = 10;

bool currentButton = LOW; 
bool lastButton = LOW;
 
int L_1_lvl = 0;
int L_2_lvl = 255;

bool debounce(bool last){

  bool current = digitalRead(B_1);
  if (current != lastButton){
    delay(5);
    current = digitalRead(B_1);
  }
  return current;
}

void setup(){
  pinMode(B_1, INPUT);
  pinMode(L_1, OUTPUT);
  pinMode(L_2, OUTPUT);
}

void loop(){
  currentButton = debounce(lastButton);

  if (currentButton == HIGH && lastButton == LOW){
    L_1_lvl += 51;
    L_2_lvl -= 51;
  }
  
  lastButton = currentButton;

  if (L_1_lvl > 255){
    L_1_lvl = 0;
    L_2_lvl = 255;
  }
  analogWrite(L_1, L_1_lvl);
  analogWrite(L_2, L_2_lvl);
  
 }