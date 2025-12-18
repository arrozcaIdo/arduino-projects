#define  echoPin 16       // HC SR04 Trig <——> GPIO16(D2)
#define  trigPin 5        // HC SR04 Echo <——> GPIO5 (D3)
int Front_Distance;


void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(trigPin, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);   // Sets the echoPin as an Input  
  Serial.begin(9600);
}


void loop() 
{ 
  Front_Distance = getDistance();
  Serial.print(Front_Distance);
  Serial.println("cm");
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
}


float getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  float distance = pulseIn(echoPin, HIGH) / 58.00;
  delay(10);
  return distance;
}
