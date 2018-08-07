#include "testOrient.h"

void Run(int a, int b){
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
}

void Stop(int a, int b){
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
}

void Mode(char mode){
  if(mode == '5'){
    Stop(wheel12,wheel11);
    Stop(wheel22,wheel21);
    Stop(wheel32,wheel31);
    Stop(wheel42,wheel41);
    }
  // di thang  
  else if(mode == '2'){
    Run(wheel11,wheel12);
    Run(wheel21,wheel22);
    Run(wheel31,wheel32);
    Run(wheel41,wheel42);
  }
  // di ngang trai
  else if(mode == '4'){
    Run(wheel11,wheel12);
    Run(wheel22,wheel21);
    Run(wheel31,wheel32);
    Run(wheel42,wheel41);
  }
  //di ngang phai
  else  if(mode == '6'){
    Run(wheel12,wheel11);
    Run(wheel21,wheel22);
    Run(wheel32,wheel31);
    Run(wheel41,wheel42);
  }
  // di lui
  else  if(mode == '8'){
    Run(wheel12,wheel11);
    Run(wheel22,wheel21);
    Run(wheel32,wheel31);
    Run(wheel42,wheel41);
  }
  //cheo phai
  else  if(mode == '1'){
    Run(wheel11,wheel12);
    Stop(wheel21,wheel22);
    Run(wheel31,wheel32);
    Stop(wheel42,wheel41);
  }
  //cheo trai
  else  if(mode == '3'){
    Stop(wheel11,wheel12);
    Run(wheel21,wheel22);
    Stop(wheel31,wheel32);
    Run(wheel41,wheel42);
  }
  // vong qua trai
  else  if(mode == '7'){
    Run(wheel11,wheel12);
    Run(wheel21,wheel22);
    Run(wheel32,wheel31);
    Run(wheel42,wheel41);
  }
  //vong qua phai
  else  if(mode == '9'){
    Run(wheel12,wheel11);
    Run(wheel22,wheel21);
    Run(wheel31,wheel32);
    Run(wheel41,wheel42);
  }
  
}

