    #include "LazerMode.h"
//control lz1 with only digial signal
int FAN1 = 3; // QUAT 1
int FAN2 = 4; // QUAT 2
int LAZER1 = 5; // LAZE PHU
int LAZER2 = 6; // LAZE CHINH
int START = 2; // CHO PHÉP ĐỐT
int ON_FAN1 = 0; // time FAN1 on
int TIME_FAN1 = 0; // time FAN1 off
int ON_FAN2 = 0; // time FAN2 on
int TIME_FAN2 = 0; // time FAN2 off
int BURN_FLAG = 0;
unsigned long x = 0; 
unsigned long y = 0;
void setup(){
  
  // set FAN1 FAN2 LAZER1 LAZER2 to output
  Serial.begin(115200);
  pinMode(FAN1, OUTPUT);
  pinMode(FAN2, OUTPUT);
  pinMode(LAZER1, OUTPUT);
  pinMode(LAZER2, OUTPUT);
  pinMode(START, INPUT);
  Serial.println(" setup completed!" );
  digitalWrite(START, LOW);
  attachInterrupt(0, BurnStart , HIGH); // interupt when START high, 0 is pin2
}

void loop(){
   // khong su dung
    digitalWrite(LAZER2,LOW);
    //LAZER PHU LUON SANG
    digitalWrite(LAZER1,HIGH);
    //FAN1
    if (ON_FAN1 == 0){  //INITIAL TIME FAN2 
      ON_FAN1= random(10,20)*1000; // set random value to time FAN2 ON = random(10,20)*1000*delayMicroseconds(1000)= 10-20(s)
      Serial.println(ON_FAN1);
      TIME_FAN1 = 2000 + ON_FAN1; //  set value to time TIME_FAN = 2000(time FAN + OFF)+ time FAN ON
      x = millis();// bat dau tinh thoi gian
    
    }
   // millis() - x is time in HIGH/LOW    
    if ((unsigned long)(millis()-x) <= ON_FAN1){ // ON FAN1
      digitalWrite(FAN1,HIGH);
    }
    else if ( (unsigned long)((millis()-x) > ON_FAN1) && (unsigned long)(millis()-x) < (TIME_FAN1)){ //OFF FAN1
      digitalWrite(FAN1,LOW); 
    }
    else ON_FAN1 = 0;
    //FAN1
    if (ON_FAN2 == 0){  //INITIAL TIME FAN2 
      ON_FAN2= random(10,20)*1000; // set random value to time FAN2 ON = random(10,20)*1000*delayMicroseconds(1000)= 10-20(s)
      TIME_FAN2 = 2000 + ON_FAN2; //  set value to time TIME_FAN = 2000(time FAN + OFF)+ time FAN ON
      y = millis();// bat dau tinh thoi gian
     
    }
    if ((unsigned long)(millis()-y) <= ON_FAN2){ // ON FAN1
      digitalWrite(FAN2,HIGH);
    }
    else if ( ((unsigned long)(millis()-y) > ON_FAN2) && ((unsigned long)(millis()-y) < TIME_FAN2)){ //OFF FAN1
      digitalWrite(FAN2,LOW); 
    }
    else ON_FAN2 = 0;
   
    if( BURN_FLAG == 1){
      BurnMode();
    }
}

