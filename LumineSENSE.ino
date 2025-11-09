/*  LUMINESENSE : Structured Earthquake Notification for Safer Evacuation as an 
Earthquake Alert System for Optimal Evacuation Time Based on NDRRMC Standard Procedure
A device equipped with an earthquake sensor, designed to facilitate a well-organized evacuation plan when 
installed in multi-story buildings, with multiple LumineSENSE bulbs integrated into each room.
*/

#define xPin A1
#define yPin A2
#define zPin A3
#define ledPin1 3
#define ledPin2 4
#define ledPin3 5

const int samples = 10;
const int maxVal = 20;

int xSample = 0;
int ySample = 0;
int zSample = 0;

int relay = 2;
int buzzer = 10;
unsigned long startTime;
boolean movementDetected = false;

enum State {
  IDLE,
  FAST_BLINK,
  SLOW_BLINK,
  OFF
};

State currentState = IDLE;

void setup() {
  Serial.begin(115200);
  pinMode(relay, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  // init
  for (int i = 0; i < samples; i++) {
    xSample += analogRead(xPin);
    ySample += analogRead(yPin);
    zSample += analogRead(zPin);
  }

  xSample /= samples;
  ySample /= samples;
  zSample /= samples;

  digitalWrite(relay, HIGH); // relay && LEDs off
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
}

void loop() {
  unsigned long currentTime = millis(); // current time

  // read accelerometer values
  int xRaw = 0, yRaw = 0, zRaw = 0;

  for (int i = 0; i < samples; i++) {
    xRaw += analogRead(xPin);
    yRaw += analogRead(yPin);
    zRaw += analogRead(zPin);
  }

  xRaw /= samples;
  yRaw /= samples;
  zRaw /= samples;

  int xValue = xSample - xRaw;
  int yValue = ySample - yRaw;
  int zValue = zSample - zRaw;

  // print accelerometer values to smonitor
  Serial.print("x=");
  Serial.print(xValue);
  Serial.print("\ty=");
  Serial.print(yValue);
  Serial.print("\tz=");
  Serial.println(zValue);

  // movement check
  if (abs(xValue) > maxVal || abs(yValue) > maxVal || abs(zValue) > maxVal) {
    movementDetected = true;
    startTime = currentTime; // reset the start time when movement is detected
  } else {
    movementDetected = false;
  }

  // upd state based on movement detection
  if (movementDetected) {
    currentState = FAST_BLINK;
  } else if (currentState == FAST_BLINK && currentTime - startTime >= 10000) {
    currentState = SLOW_BLINK;
    startTime = currentTime;
  } else if (currentState == SLOW_BLINK && currentTime - startTime >= 20000) {
    currentState = OFF;
  } else if (currentState == OFF && currentTime - startTime >= 5000) {
    currentState = IDLE;
  }

  // execute state-specific actions
  switch (currentState) {
    case FAST_BLINK:
      // fast blink code
      digitalWrite(relay, LOW);
      digitalWrite(buzzer, LOW);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      delay(100);
      digitalWrite(relay, HIGH);
      digitalWrite(buzzer, HIGH);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      delay(100);
      digitalWrite(relay, LOW);
      digitalWrite(buzzer, LOW);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      delay(100);
      digitalWrite(relay, HIGH);
      digitalWrite(buzzer, HIGH);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      delay(100);
      digitalWrite(relay, LOW);
      digitalWrite(buzzer, LOW);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      delay(100);
      digitalWrite(relay, HIGH);
      digitalWrite(buzzer, HIGH);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      delay(100);
      digitalWrite(relay, LOW);
      digitalWrite(buzzer, LOW);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      delay(100);
      digitalWrite(relay, HIGH);
      digitalWrite(buzzer, HIGH);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      delay(100);
      digitalWrite(relay, LOW);
      digitalWrite(buzzer, LOW);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      delay(100);
      digitalWrite(relay, HIGH);
      digitalWrite(buzzer, HIGH);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      delay(900);

      break;
    case SLOW_BLINK:
      // slow blink code
      digitalWrite(relay, LOW);
      digitalWrite(buzzer, LOW);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      delay(100);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      delay(100);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      delay(100);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      delay(100);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      delay(100);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      delay(100);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      delay(100);
      digitalWrite(relay, HIGH);
      digitalWrite(buzzer, HIGH);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
            delay(100);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      delay(100);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      delay(100);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      delay(100);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      delay(100);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      delay(100);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      delay(100);

      break;
    case OFF:
      // relay && LEDs off
      digitalWrite(relay, HIGH);
      digitalWrite(buzzer, HIGH);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      break;
    case IDLE:
      // idle
      break;
  }
}
