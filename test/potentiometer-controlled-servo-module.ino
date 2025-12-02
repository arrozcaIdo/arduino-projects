#include <Servo.h>

Servo Servo1; // declare servo

int servoPin = 9; // servo pin
int potPin = A0; // potentiometer pin

void setup(){
  Servo1.attach(servoPin);
}

void loop(){
  int reading = analogRead(potPin);
  int angle = map(reading, 0, 1023, 0, 1080);
  Servo1.write(angle);
}
