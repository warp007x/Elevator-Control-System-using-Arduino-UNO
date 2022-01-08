#include <LiquidCrystal.h>

unsigned const int A = 13;
unsigned const int B = 12;
unsigned const int C = 11;
unsigned const int D = 10;
unsigned const int E = 9;
unsigned const int F = 8;
unsigned const int G = 15;
unsigned const int H = 14;

String ele_status="Going UP.....";

int floor_coeff= 1;
int digit =0;
int state=-1;

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void printDigit(int);
void updateStatus(int);


void setup(void)
{
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("ATAR ER ELEVATOR");
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(H, OUTPUT);
}

//My Functions

void zero(void) {
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);
}

void one(void) {
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);
}

void two(void) {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(H, LOW);
}

void three(void) {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);
}

void four(void) {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);
}

void five(void) {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);
}

void six(void) {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);
}

void seven(void) {
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);
}

void eight(void) {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);
}

void nine(void) {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);
}

// Start
void loop(void)
{
  
  if(Serial.available()>=0)
  {
  state = Serial.read();
  int x=-1;

  switch (state){
    case '0': {x=0; break;}
    case '1': {x=1; break;}
    case '2': {x=2; break;}
    case '3': {x=3; break;}
    case '4': {x=4; break;}
    case '5': {x=5; break;}
    case '6': {x=6; break;}
    default: {x=-1; break;}
  }
  
  while(x!=-1)
  {
    if(digit == 7 ){
      digit=6;
      continue;}
    else if(digit == -1){
      digit=0;
      continue;}
    
  lcd.setCursor(0, 1);
  
  printDigit(digit);
  
  lcd.print(digit);
  Serial.println(digit);
    lcd.setCursor(1,1);
    lcd.print("->");
  
  lcd.setCursor(3, 1);
  lcd.print(ele_status);
  
  digit=digit + floor_coeff;
  delay(2000);
  if(digit == x){
    
    lcd.setCursor(0,1);
    lcd.print("Reached Floor ");
    lcd.setCursor(14,1);
    lcd.print(digit);
    printDigit(digit);
    Serial.print("Reached floor-");
    Serial.println(digit);
    
    state=-1;
    delay(6000);
    break;
  }
    
    
  
  if(digit<=0||digit>=6){
    floor_coeff = -floor_coeff;
    updateStatus(floor_coeff);
  }
  }
  }
}

void printDigit(int x){

  int dig = x;

  switch (dig){
    case 0: {zero();
             break;}
    case 1: {one();
             break;}
    case 2: {two();
             break;}
    case 3: {three();
             break;}
    case 4: {four();
             break;}
    case 5: {five();
             break;}
    case 6: {six();
             break;}
   // case 7: seven();
    //case 8: eight();
    //case 9: nine();
    default: break;
  }
}

void updateStatus(int y){

  if(y>0){
    ele_status = "Going UP....."; 
  }
  else if(y<0){
    ele_status = "Going DOWN...";
  }
  
}
