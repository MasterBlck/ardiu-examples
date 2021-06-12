#include <SimpleTimer.h>

SimpleTimer timer;
boolean currentLEDState;
int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  currentLEDState = false;
  pinMode(ledPin, OUTPUT);
  timer.setInterval(1200, blink);
}

void loop() {
  // put your main code here, to run repeatedly:
  timer.run();
}

void blink(){
  if(!currentLEDState) digitalWrite(ledPin, HIGH);
  else digitalWrite(ledPin, LOW);

  currentLEDState = !currentLEDState; //Invert this boolean
}
