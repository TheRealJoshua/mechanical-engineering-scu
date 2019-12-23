#define DTIME 500
// connect motor controller pins to Arduino digital pins
// motor one
int enA = 10;
int in1 = 9;
int in2 = 8;
// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Forward();
  Brake();
  Reverse();
  Brake();
  TurnLeft();
  Brake();
  TurnRight();
  Brake();
  PivotLeft();
  Brake();
  PivotRight();
}

void Forward(){

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 150);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 150);
  delay(DTIME);

}

void Reverse(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 150);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 150);
  delay(DTIME);

} 

void Brake() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 150);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 150);
  delay(DTIME);
}

void Coast() {
  analogWrite(enA, 0);
  analogWrite(enB, 0);

}
  
void TurnLeft(){
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 75);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 150);
  delay(DTIME);
  
} 
  
void TurnRight() {

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 150);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 75);
  delay(DTIME);

}
  
void PivotLeft() {
    digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 150);
  delay(DTIME);
}
  
void PivotRight(){

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 150);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);
  delay(DTIME);

}
