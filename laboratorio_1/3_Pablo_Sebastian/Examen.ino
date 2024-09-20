#include <EEPROM.h>
#define LED1   13
#define LED2   12
#define LED3   11
#define B1     2
#define B2     3
#define BR  9600 
#define BT   1500
#define DB   80
#define MAX   10
#define MIN    1


bool b1,b2;
int cont;
unsigned long last=0;
void setup() {  Serial.begin(BR);
  pinMode (LED1, OUTPUT);
  pinMode (LED2, OUTPUT);
  pinMode (LED3, OUTPUT);
  pinMode (B1 , INPUT);
  pinMode (B2 , INPUT);
  attachInterrupt(digitalPinToInterrupt(B1), Maxvolum  , FALLING);
  attachInterrupt(digitalPinToInterrupt(B2), Minvolum , FALLING);
  
  if (EEPROM.read(0)!=0){
    cont=EEPROM.read(0);
  }Serial.println(EEPROM.read(0));
}

void loop() {
  
  delay(BT);
}

void Maxvolum(){
  if ((millis()-last) > DB){
    if (cont<MAX){
      cont++;//Serial.println(cont);

      EEPROM.write(0, cont);
      Serial.println(EEPROM.read(0));
    }
    last=millis();
    

  }
}
void Minvolum(){
  if ((millis()-last) > DB){
    if (cont>MIN){
      cont--;//Serial.println(cont);
      EEPROM.write(0, cont);
      Serial.println(EEPROM.read(0));
    }
    last=millis();
  }
}