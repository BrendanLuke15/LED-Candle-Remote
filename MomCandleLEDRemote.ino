/*
  By: Brendan Luke
  Date: December 25, 2022

  Scope: This sketch outputs a 38kHz signal to digital pin 8, for use with an IR LED to send signals to Mom's LED Candles
*/

#include <Arduino.h>
#include <avr/pgmspace.h>
#include "RemoteCodes.h"

void setup() {
  // put your setup code here, to run once:

  // Turn onboard LED off
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);

  // Setup Pin Outputs
  pinMode(IR_Pin,OUTPUT);
  digitalWrite(IR_Pin,LOW);

  // Serial Monitor
  Serial.begin(9600);

  // Input Trigger Pin
  pinMode(12,INPUT_PULLUP);

  delay(1000);
  remC_ON();
  delay(2000);
  remC_Purple();
  /*
  for (int k = 0; k < 5; k++) {
    delay(2000);
    remC_DimM();
  }
  for (int k = 0; k < 5; k++) {
    delay(2000);
    remC_DimP();
  }
  /**/
  delay(2000);
  remC_OFF();
}

void loop() {
  // put your main code here, to run repeatedly:
}
