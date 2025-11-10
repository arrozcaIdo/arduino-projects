
// two LEDs, led 1 on pin 12, led 2 on pin 9

void setup() {
  
  pinMode(12, OUTPUT);
  pinMode(9, OUTPUT);
}

// runs forever
void loop() {
  digitalWrite(12, HIGH);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(9, LOW);
  delay(1000);                      // wait for a second

  digitalWrite(12, LOW);   // turn the LED off by making the voltage LOW
  digitalWrite(9, HIGH);
  delay(1000);                      // wait for a second

}
