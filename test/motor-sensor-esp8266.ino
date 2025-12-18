#define  IN_2    4        // L9110S  A-1B <——> GPIO4 (D4) MOTOR A
#define  IN_1    14       // L9110S  A-1A <——> GPIO14(D5) MOTOR A
#define  IN_4    12       // L9110S  B-1B <——> GPIO12(D6) MOTOR B
#define  IN_3    13       // L9110S  B-1A <——> GPIO13(D7) MOTOR B

int speedCar = 255;       // 0 - 255

void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT);

  goLeft();
  digitalWrite(LED_BUILTIN, LOW); 
  delay(2000);
  stopRobot();
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  goRight();
  digitalWrite(LED_BUILTIN, LOW);
  delay(2000);
  stopRobot();
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);

}

void loop() 
{
  
}





void goBack()
{ 
  analogWrite(IN_1, speedCar);
  digitalWrite(IN_2, LOW);
  digitalWrite(IN_3, LOW);
  analogWrite(IN_4, speedCar);
}

void goAhead()
{ 
  digitalWrite(IN_1, LOW);
  analogWrite(IN_2, speedCar);
  analogWrite(IN_3, speedCar);
  digitalWrite(IN_4, LOW);
}

void goLeft()
{ 
  analogWrite(IN_1, speedCar);
  digitalWrite(IN_2, LOW);
  analogWrite(IN_3, speedCar);
  digitalWrite(IN_4, LOW);
}

void goRight()
{
  digitalWrite(IN_1, LOW);
  analogWrite(IN_2, speedCar);
  digitalWrite(IN_3, LOW);
  analogWrite(IN_4, speedCar);
}


void stopRobot()
{  
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, LOW);
  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, LOW);
}
