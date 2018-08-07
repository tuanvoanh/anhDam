#include "LazerMode.h"
 void BurnMode(){
    digitalWrite(FAN1,LOW);
    digitalWrite(FAN2,LOW);
    digitalWrite(LAZER1,LOW);
    digitalWrite(LAZER2,HIGH); 
    _delay_ms(5000);
    _delay_ms(5000);
    BURN_FLAG = 0;
 }
 void BurnStart(){
    _delay_ms(1);
    if ( digitalRead(START) == 1)
    BURN_FLAG = 1;
 }

