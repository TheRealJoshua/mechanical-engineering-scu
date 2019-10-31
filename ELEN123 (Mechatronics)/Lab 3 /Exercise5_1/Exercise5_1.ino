//Matt Russell, Joshua Ramayrat
//Lab 3 Exercise 5.1
//4/25/17
//make LED on pin 13 blink 200 ms out of every 500 based on timer one interrupt
volatile int dt = 500;
int ledState = LOW;

#include <TimerOne.h>
void setup() {
  pinMode(13,OUTPUT);
  Timer1.initialize(200000);
  Timer1.attachInterrupt(blinkLED);
}
void blinkLED(void){
  if (ledState == LOW){
    ledState = HIGH;
  } else {
    ledState == LOW;
  }
  digitalWrite(13,ledState);
  rdelay(dt);
}

void rdelay(int dt){
  int ct, pt;
  pt = millis();
  ct = pt;
  while(ct - pt < dt){
    ct = millis();
  }
}

void loop() {
  //Joshua requested this
  noInterrupts();
  interrupts();
}


