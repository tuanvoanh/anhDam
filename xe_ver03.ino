#include "testOrient.h"
//******** 11 dan bang keo den ******
#define wheel11 3
#define wheel12 4
#define wheel21 5
#define wheel22 6
#define wheel31 7
#define wheel32 8
#define wheel41 9
#define wheel42 10
int buttonPin = 11;
int buttonStop = 12;
int mode = 1;   // tu 1-13
int buttonState = 0;         // trạng thái hiện tại của button
int lastButtonState = 0;     // trạng thái trước đó của button
char a[10] = {};
char RUN;
int i;
unsigned long TIME = 0; // reset time
unsigned long TIMERUN = 0;
boolean check(char a) {
  if (a == '1' || a == '2' || a == '3' || a == '4' || a == '5' || a == '6' || a == '7' || a == '8' || a == '9' )
    return true;
  else
    return false;
}
void setup()
{
  Serial.begin(115200);
  while (!Serial) {
  }
#ifdef DEBUG
  Serial.println("Serial completed....OK");
#endif
  pinMode(wheel11, OUTPUT);
  pinMode(wheel12, OUTPUT);
  pinMode(wheel21, OUTPUT);
  pinMode(wheel22, OUTPUT);
  pinMode(wheel31, OUTPUT);
  pinMode(wheel32, OUTPUT);
  pinMode(wheel41, OUTPUT);
  pinMode(wheel42, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonStop, INPUT_PULLUP);

}

void loop()
{
  digitalWrite(13, LOW);
  if ( (millis() - TIMERUN) > (1000 * 5)){
      TIMERUN = millis();
      RUN = '5';
      Mode(RUN);
//      Serial.println(RUN);
    }
  if (Serial.available()) {
    digitalWrite(13, HIGH);
    TIME = 0;
    for (i = 1; Serial.available(); i++) { //xóa hết bộ đệm
      a[i] = Serial.read();
      delayMicroseconds(500);
    }
    if ((i < 5) && (a[1] == 'E'))
      RUN = a[3];
    else  a[3] = RUN;
    if (a[2] == '2')  {
      if ( check(RUN) ) {
  //      Serial.println((millis() - TIMERUN));
        Mode(RUN);
 //       Serial.println(RUN);
        TIMERUN = millis();
        }
    }

    // DUNG DE RESET SAU 2 ph ko su dung
    if ((Serial.available() == 0) && (TIME == 0) ) { // TIME has not Start
      TIME = millis();
    }
    if ( (unsigned long)(millis() - TIME) > (1000 * 60)) {
      asm volatile ( "jmp 0");
    }
  }
}
