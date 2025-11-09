#define xPin A1
#define yPin A2
#define zPin A3

const int samples = 10;
const int maxVal = 20;

int xSample = 0;
int ySample = 0;
int zSample = 0;

int relay = 2;
int buzzer = 10;
unsigned long startTime;
boolean movementDetected = false;

void setup() {
  Serial.begin(115200);
  pinMode(relay, OUTPUT);
  pinMode(buzzer, OUTPUT);

  for (int i = 0; i < samples; i++) {
    xSample += analogRead(xPin);
    ySample += analogRead(yPin);
    zSample += analogRead(zPin);
  }

  xSample /= samples;
  ySample /= samples;
  zSample /= samples;

  digitalWrite(relay, HIGH);
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
      digitalWrite(relay, LOW);
      digitalWrite (buzzer,LOW);
      delay(100);
      digitalWrite(relay, HIGH);
      digitalWrite (buzzer,HIGH);
      delay(100);
      digitalWrite(relay, LOW);
      digitalWrite (buzzer, LOW);
      delay(100);
      digitalWrite(relay, HIGH);
      digitalWrite (buzzer, HIGH);
      delay(100);
      digitalWrite(relay, LOW);
      digitalWrite (buzzer, LOW);
      delay(100);
      digitalWrite(relay, HIGH);
      digitalWrite (buzzer, HIGH);
      delay(100);
      digitalWrite(relay, LOW);
      digitalWrite (buzzer, LOW);
      delay(100);
      digitalWrite(relay, HIGH);
      digitalWrite (buzzer, HIGH);
      delay(100);
      digitalWrite(relay, LOW);
      digitalWrite (buzzer, LOW);
      delay(100);
      digitalWrite(relay, HIGH);
      digitalWrite (buzzer, HIGH);
      delay(900);
      currentTime = millis();
    }

    while (currentTime - startTime >= 10000 && currentTime - startTime < 20000) {
      digitalWrite(relay, LOW);
      digitalWrite (buzzer, LOW);
      delay(700);
      digitalWrite(relay, HIGH);
      digitalWrite (buzzer, HIGH);
      delay(700);
      currentTime = millis();
    }

    digitalWrite(relay, HIGH);
    digitalWrite(buzzer, HIGH);
  } else {

    digitalWrite(relay, HIGH);
    digitalWrite(buzzer, HIGH);
  }
}
