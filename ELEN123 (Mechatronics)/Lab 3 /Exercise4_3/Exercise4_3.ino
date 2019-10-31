//Matt Russell, Joshua Ramayrat
//Lab 3 Exercise 4.3
//4/24/17
//Pin 2 is channel A, Pin 3 is channel B
volatile int count = 0, sw = 0;
void setup() {
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  attachInterrupt(0,isr0,RISING);
  Serial.begin(9600);
}
//Value of B at rising edge of A tells direction of motion
//right->B = HIGH, left->B = LOW
void isr0(void){
  if(digitalRead(3)){
    count++;
  }
  else{
    count--;
  }
  sw = 1;
}

void loop() {
  if(sw == 1){
    Serial.println(count);
    sw = 0;
  }
}
