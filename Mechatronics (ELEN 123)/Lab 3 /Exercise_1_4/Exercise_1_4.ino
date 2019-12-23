// Matt Russell, Joshua Ramayrat
// Lab 3 Exercise 1_4
// 4/25
volatile int count, sw;
void setup() {
  pinMode(2,INPUT_PULLUP);
  attachInterrupt(0,isrf,FALLING);
  count = 0, sw = 0;
  Serial.begin(9600);
}

void loop() {
  if(sw == 1){
    Serial.println(count);
    sw = 0;
  }
}

void isrf(){
  count++;
  sw = 1;
}

