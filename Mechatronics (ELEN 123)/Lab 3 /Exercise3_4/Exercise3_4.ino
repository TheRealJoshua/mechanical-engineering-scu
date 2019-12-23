  #include <TimerOne.h>
//Matt Russell, Joshua Ramayrat
//Lab 3 Exercise 3.4
//4/25/17
//This function is built off of ISRblink
//It uses an interrupt to count time and print it to the Serial Console
//pressing a switch once stops the printing but keeps the counting
//pressing the switch again resumes the printing


const int led = LED_BUILTIN;  // the pin with a LED

void setup(void)
{
  pinMode(led, OUTPUT);
  Timer1.initialize(100000);
  Timer1.attachInterrupt(blinkLED); // blinkLED to run every 0.15 seconds
  attachInterrupt(0,isrf,RISING); 
  Serial.begin(9600);
}


// The interrupt will blink the LED, and keep
// track of how many times it has blinked.
int ledState = LOW;
volatile unsigned long blinkCount = 0, t = 0; // use volatile for shared variables
volatile int inc = 0, sw = 0;
void blinkLED(void)
{
  if (ledState == LOW) {
    ledState = HIGH;
    blinkCount = blinkCount + 1;  // increase when LED turns on
  } else {
    ledState = LOW;
  }
  digitalWrite(led, ledState);
  inc++;
}

void isrf(void){
  sw = !sw; //flip switch state
}


// The main program will print the blink count
// to the Arduino Serial Monitor
void loop(void)
{
  unsigned long blinkCopy;  // holds a copy of the blinkCount
  
  // to read a variable which the interrupt code writes, we
  // must temporarily disable interrupts, to be sure it will
  // not change while we are reading.  To minimize the time
  // with interrupts off, just quickly make a copy, and then
  // use the copy while allowing the interrupt to keep working.
  noInterrupts();
  blinkCopy = blinkCount;
  interrupts();
  if(inc == 10){
    t = 200*blinkCopy; 
    if (sw == 0){
    Serial.print("elapsed time (sec) is: ");
    Serial.println(t/1000);
    }
    inc = 0;
  }
}
