#include <Servo.h>

Servo Servo1; // declare servo

int servoPin = 9; // servo pin
int potPin = A0; // potentiometer pin

void setup(){
  Servo1.attach(servoPin);
}

void loop(){
  int reading = analogRead(potPin);
  // Map pot to servo speed:
  // 0   → 0°   (full speed one way)
  // 512 → 90°  (stop)
  // 1023→ 180° (full speed other way)
  int angle = map(reading, 0, 1023, 0, 180);

  Servo1.write(angle);
}
