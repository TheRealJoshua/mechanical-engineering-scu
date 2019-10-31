//Matt Russell, Joshua Ramayrat
//Lab 3 Exercise 4.4
//4/25/17
//Pin 2 is channel A, Pin 3 is channel B
//Computes distance traveled by wheel
volatile int count = 0, sw = 0;
void setup() {
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  attachInterrupt(0,isr0,RISING);
  Serial.begin(9600);
}
//want distance traveled so just increment count on each interrupt
void isr0(void){
  count++;
  sw = 1;
}

void loop() {
  if(sw == 1){
    Serial.print(count*(PI/180)*.03); //printout distance traveled
    Serial.println("meters traveled");
    sw = 0;
  }
}
