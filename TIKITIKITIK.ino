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

void fastBlink() {
  for (int i = 0; i < 5; ++i) {
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
  }
}

void slowBlink() {
  for (int i = 0; i < 2; ++i) {
    digitalWrite(relay, LOW);
    digitalWrite(buzzer, LOW);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    delay(700);
    digitalWrite(relay, HIGH);
    digitalWrite(buzzer, HIGH);
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    delay(700);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(relay, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  for (int i = 0; i < samples; i++) {
    xSample += analogRead(xPin);
    ySample += analogRead(yPin);
    zSample += analogRead(zPin);
  }

  xSample /= samples;
  ySample /= samples;
  zSample /= samples;

  digitalWrite(relay, HIGH); 
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
}

void loop() {
  unsigned long currentTime = millis(); 

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

  Serial.print("x=");
  Serial.print(xValue);
  Serial.print("\ty=");
  Serial.print(yValue);
  Serial.print("\tz=");
  Serial.println(zValue);

  if (abs(xValue) > maxVal || abs(yValue) > maxVal || abs(zValue) > maxVal) {
    movementDetected = true;
    startTime = currentTime;
  } else {
    movementDetected = false;
  }

  if (movementDetected) {
    while (currentTime - startTime < 10000) {
      fastBlink();
      currentTime = millis(); 
    }

    while (currentTime - startTime >= 10000 && currentTime - startTime < 30000) {
      slowBlink();
      currentTime = millis();
    }

    digitalWrite(relay, HIGH);
    digitalWrite(buzzer, HIGH);
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
  } else {

    digitalWrite(relay, HIGH);
    digitalWrite(buzzer, HIGH);
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
  }
}
