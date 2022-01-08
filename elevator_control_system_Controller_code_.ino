int buttonState[7] = {0,0,0,0,0,0,0};

static const int button_0[7]={1,0,0,0,0,0,0};
static const int button_1[7]={0,1,0,0,0,0,0};
static const int button_2[7]={0,0,1,0,0,0,0};
static const int button_3[7]={0,0,0,1,0,0,0};
static const int button_4[7]={0,0,0,0,1,0,0};
static const int button_5[7]={0,0,0,0,0,1,0};
static const int button_6[7]={0,0,0,0,0,0,1};


void setup()
{
  for(int i=13; i<=19; i++){
  pinMode(i, INPUT);
  }
  Serial.begin(9600);

}

void loop()
{
  // read the input pin
  buttonState[0] = digitalRead(14);
  buttonState[1] = digitalRead(15);
  buttonState[2] = digitalRead(16);
  buttonState[3] = digitalRead(17);
  buttonState[4] = digitalRead(18);
  buttonState[5] = digitalRead(19);
  buttonState[6] = digitalRead(13);

  if(buttonState[0] == 1){
    Serial.write(0);
    Serial.println(0);
  }
  else if(buttonState[1] == 1){
    Serial.write(1);
    Serial.println(1);
  }
  else if(buttonState[2] == 1){
    Serial.write(2);
    Serial.println(2);
  }
  else if(buttonState[3] == 1){
    Serial.write(3);
    Serial.println(3);
  }
  else if(buttonState[4] == 1){
    Serial.write(4);
    Serial.println(4);
  }
  else if(buttonState[5] == 1){
    Serial.write(5);
    Serial.println(5);
  }
  else if(buttonState[6] == 1){
    Serial.write(6);
    Serial.println(6);
  }
  
 /* for(int i=0; i<7; i++)
  {
  
  // print out the state of the button
    Serial.println(buttonState[i]);
  }
  Serial.println("--------");*/
  delay(50); // Delay a little bit to improve simulation performance
}
