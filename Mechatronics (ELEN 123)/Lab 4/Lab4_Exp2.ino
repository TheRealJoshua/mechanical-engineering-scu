//Lab 4 Experiment 2
//write cmForward and cmReverse
// connect motor controller pins to Arduino digital pins
// motor one
int enA = 10;
int in1 = 9;
int in2 = 8;
// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;
//Distance to travel
int x = 10;
volatile double dist = 0.0;
//Encoder
long count = 0;
int encA = 3;
int encB = 20;
//led
#define BASESPEED 35
#define DTIME 1000
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(encA, INPUT);
  pinMode(encB, INPUT);
  attachInterrupt(digitalPinToInterrupt(encA), angle, CHANGE);
  cmForward(x);
  cmReverse(x);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(count);
}

void rdelay(int dt) {
  int ct, pt;
  pt = millis();
  ct = pt;
  while (ct - pt < dt) {
    ct = millis();
  }
}

void Forward() {

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  rdelay(DTIME/2);
  analogWrite(enA, BASESPEED);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  rdelay(DTIME/2);
  analogWrite(enB, BASESPEED);
  rdelay(DTIME);

}

void Reverse() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  rdelay(DTIME/2);
  analogWrite(enA, BASESPEED);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  rdelay(DTIME/2);
  analogWrite(enB, BASESPEED);
  rdelay(DTIME);

}

void Brake() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, BASESPEED);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, BASESPEED);
  rdelay(DTIME);
}

void Coast() {
  analogWrite(enA, 0);
  analogWrite(enB, 0);

}

void TurnLeft() {

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, .5 * BASESPEED);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, BASESPEED);
  rdelay(DTIME);

}

void TurnRight() {

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, BASESPEED);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, .5 * BASESPEED);
  rdelay(DTIME);

}

void PivotLeft() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, BASESPEED);
  rdelay(DTIME);
}

void PivotRight() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, BASESPEED);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);
  rdelay(DTIME);
}

void cmForward(int x) {
  rdelay(DTIME);
  dist = 0;
  Forward();
  while (dist < x) {
    Serial.println(dist);
  }
  Brake();
}

void cmReverse(int x) {
  rdelay(DTIME);
  dist = 0;
  Reverse();
  while (dist > x) {
    Serial.println(dist);
  }
  Brake();
}

void angle() {
  //Serial.println(digitalRead(encB));
  if (digitalRead(encB) == digitalRead(encA))
    count++;
  else
    count--;
  dist = (1.65)*(3/2)*count*(PI/180);
}

