#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX
char incomingByte[5]={};
int i = 0;
int LZ1 = 2;
int LZ2 = 3;
int LZ3 = 4;
int LZ4 = 5;
int LZ5 = 6;
int LZ6 = 7;
int TEXT_TRANS = 13;
unsigned long  TIME = 0;
double baudrate = 115200;
void setup() {
  pinMode(LZ1, OUTPUT);
  pinMode(LZ2, OUTPUT);
  pinMode(LZ3, OUTPUT);
  pinMode(LZ4, OUTPUT);
  pinMode(LZ5, OUTPUT);
  pinMode(LZ6, OUTPUT);
  
  Serial.begin(baudrate);
  mySerial.begin(baudrate);
  digitalWrite(LZ1, LOW);
  digitalWrite(LZ2, LOW);
  digitalWrite(LZ3, LOW);
  digitalWrite(LZ4, LOW);
  digitalWrite(LZ5, LOW);
  digitalWrite(LZ6, LOW);
}

void loop() {

   if (mySerial.available()) {
     TIME = 0;
     digitalWrite(TEXT_TRANS,HIGH);
     for (i = 1; mySerial.available(); i++) { //xóa hết bộ đệm
      incomingByte[i] = mySerial.read();
      Serial.println(incomingByte[i]);
      delayMicroseconds(200);
    }
    if ((incomingByte[1]=='l') && (incomingByte[2]=='z')){
           if (incomingByte[3]=='1'){
               Serial.println("lz1");
               digitalWrite(LZ1, HIGH); //
               delay(1);             // tao trigger
               digitalWrite(LZ1, LOW);  //
           }
           else if (incomingByte[3]=='2'){
               Serial.println("lz2");
               digitalWrite(LZ2, HIGH); //
               delay(1);           // tao trigger
               digitalWrite(LZ2, LOW);  //
           }
           else if (incomingByte[3]=='3'){
               Serial.println("lz3");
               digitalWrite(LZ3, HIGH); //
               delay(1);           // tao trigger
               digitalWrite(LZ3, LOW);  //
           }
           else if (incomingByte[3]=='4'){
               Serial.println("lz4");     
               digitalWrite(LZ4, HIGH); //
               delay(1);             // tao trigger
               digitalWrite(LZ4, LOW);  //
           }
           else if (incomingByte[3]=='5'){
               Serial.println("lz5");     
               digitalWrite(LZ4, HIGH); //
               delay(1);             // tao trigger
               digitalWrite(LZ4, LOW);  //
           }    
           else if (incomingByte[3]=='6'){
               Serial.println("lz6");     
               digitalWrite(LZ4, HIGH); //
               delay(1);             // tao trigger
               digitalWrite(LZ4, LOW);  //
           }
      }
   }
   else  digitalWrite(TEXT_TRANS,LOW);
  if((mySerial.available()==0)&& (TIME == 0) ){// TIME has not Start
    TIME = millis();
  }
  
  if( (unsigned long)(millis()-TIME)>40000){
    asm volatile ( "jmp 0"); 
  }
}
