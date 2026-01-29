// ============================================================================
// LED Animation Controller - instant switch between animations (pin 12 button)
// ============================================================================

const int pins[] = {2, 3, 4, 5, 6, 7, 8, 9}; // LED pins
const int NUM_PINS = sizeof(pins) / sizeof(pins[0]);

const int ANIMATION_DELAY = 100;  // ms between LED updates
const int DELAY_BETWEEN = 1000;    // short pause between animations

// Button
const int buttonPin = 12;
const unsigned long debounceDelay = 50; // ms

// Button debounce state
int lastReading = LOW;
int buttonState = LOW;
unsigned long lastDebounceTime = 0;

// Mode index
int mode = 0;
const int NUM_MODES = 6;

// ============================================================================
// Setup
// ============================================================================
void setup() {
  initializeLEDs();
  pinMode(buttonPin, INPUT); // using external pull-down resistor
}

// ============================================================================
// Main loop
// ============================================================================
void loop() {
  switch (mode) {
    case 6: runBreathingPulse(); break;
   case 0: runLayeredFill(); break;
   // case 1: runFillTopToBottomThenBottomToTop(); break;
   // case 2: runFillAndDrain(); break;
   // case 3: runBouncingLED(); break;
   // case 4: runChaserAnimation(); break;
   // case 5: runWrappingChaser(); break;
    default: mode = 0; break;
  }

  interruptibleDelay(DELAY_BETWEEN);
  if (checkButtonPressed()) advanceMode();
}

// ============================================================================
// Button debounce
// ============================================================================
bool checkButtonPressed() {
  int reading = digitalRead(buttonPin);
  if (reading != lastReading) lastDebounceTime = millis();

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) {
        lastReading = reading;
        return true;
      }
    }
  }

  lastReading = reading;
  return false;
}

void advanceMode() {
  mode = (mode + 1) % NUM_MODES;
  clearAllLEDs();
}

// ============================================================================
// LED Initialization
// ============================================================================
void initializeLEDs() {
  for (int i = 0; i < NUM_PINS; i++) {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], LOW);
  }
}

// ============================================================================
// Utility
// ============================================================================
void setAllLEDs(int state) {
  for (int i = 0; i < NUM_PINS; i++) digitalWrite(pins[i], state);
}
void clearAllLEDs() { setAllLEDs(LOW); }

// Interruptible delay (same total time, checks button every 10 ms)
void interruptibleDelay(int totalMs) {
  int steps = totalMs / 10;
  for (int i = 0; i < steps; i++) {
    if (checkButtonPressed()) { advanceMode(); return; }
    delay(10);
  }
}

// ============================================================================
// Animations
// ============================================================================
void runChaserAnimation() {
  const int LEN = 3;
  if (LEN > NUM_PINS) return;

  for (int pos = 0; pos <= NUM_PINS - LEN; pos++) {
    if (checkButtonPressed()) { advanceMode(); return; }
    for (int o = 0; o < LEN; o++) digitalWrite(pins[pos + o], HIGH);
    interruptibleDelay(ANIMATION_DELAY);
    for (int o = 0; o < LEN; o++) digitalWrite(pins[pos + o], LOW);
    interruptibleDelay(ANIMATION_DELAY);
  }
}

void runWrappingChaser() {
  const int LEN = 3;
  if (LEN > NUM_PINS) return;

  for (int pos = 0; pos < NUM_PINS; pos++) {
    if (checkButtonPressed()) { advanceMode(); return; }
    clearAllLEDs();
    for (int o = 0; o < LEN; o++) digitalWrite(pins[(pos + o) % NUM_PINS], HIGH);
    interruptibleDelay(ANIMATION_DELAY);
  }
}

void runBouncingLED() {
  for (int i = 0; i < NUM_PINS; i++) {
    if (checkButtonPressed()) { advanceMode(); return; }
    digitalWrite(pins[i], HIGH);
    interruptibleDelay(ANIMATION_DELAY);
    digitalWrite(pins[i], LOW);
  }

  for (int i = NUM_PINS - 1; i >= 0; i--) {
    if (checkButtonPressed()) { advanceMode(); return; }
    digitalWrite(pins[i], HIGH);
    interruptibleDelay(ANIMATION_DELAY);
    digitalWrite(pins[i], LOW);
  }
}

void runFillAndDrain() {
  for (int i = 0; i < NUM_PINS; i++) {
    if (checkButtonPressed()) { advanceMode(); return; }
    digitalWrite(pins[i], HIGH);
    interruptibleDelay(ANIMATION_DELAY);
  }
  for (int i = NUM_PINS - 1; i >= 0; i--) {
    if (checkButtonPressed()) { advanceMode(); return; }
    digitalWrite(pins[i], LOW);
    interruptibleDelay(ANIMATION_DELAY);
  }
}

void runFillTopToBottomThenBottomToTop() {
  for (int i = NUM_PINS - 1; i >= 0; --i) {
    if (checkButtonPressed()) { advanceMode(); return; }
    digitalWrite(pins[i], HIGH);
    interruptibleDelay(ANIMATION_DELAY);
  }
  interruptibleDelay(ANIMATION_DELAY);
  for (int i = 0; i < NUM_PINS; ++i) {
    if (checkButtonPressed()) { advanceMode(); return; }
    digitalWrite(pins[i], LOW);
    interruptibleDelay(ANIMATION_DELAY);
  }
}

void runBreathingPulse() {
  // Fade in (inhale)
  for (int b = 0; b <= 255; b += 2) {
    if (checkButtonPressed()) { advanceMode(); return; }
    for (int i = 0; i < NUM_PINS; i++) {
      safeAnalogWrite(pins[i], b);
    }
    interruptibleDelay(25);
  }

  // Optional pause at full brightness
  interruptibleDelay(300);

  // Fade out (exhale)
  for (int b = 255; b >= 0; b -= 2) {
    if (checkButtonPressed()) { advanceMode(); return; }
    for (int i = 0; i < NUM_PINS; i++) {
      safeAnalogWrite(pins[i], b);
    }
    interruptibleDelay(25);
  }

  // Optional pause at darkness
  interruptibleDelay(300);
}


void runLayeredFill() {
  const int layer1[] = {6, 7, 5};
  const int layer2[] = {4, 8};
  const int layer3[] = {9, 3};
  const int layer4[] = {2};
  const int l1s = 3, l2s = 2, l3s = 2, l4s = 1;

  if (fadeLayerWithAbort(layer1, l1s, true)) return;
  if (fadeLayerWithAbort(layer2, l2s, true)) return;
  if (fadeLayerWithAbort(layer3, l3s, true)) return;
  if (fadeLayerWithAbort(layer4, l4s, true)) return;
  interruptibleDelay(200);

  if (fadeLayerWithAbort(layer4, l4s, false)) return;
  if (fadeLayerWithAbort(layer3, l3s, false)) return;
  if (fadeLayerWithAbort(layer2, l2s, false)) return;
  if (fadeLayerWithAbort(layer1, l1s, false)) return;
  interruptibleDelay(300);

  if (fadeLayerWithAbort(layer4, l4s, true)) return;
  if (fadeLayerWithAbort(layer3, l3s, true)) return;
  if (fadeLayerWithAbort(layer2, l2s, true)) return;
  if (fadeLayerWithAbort(layer1, l1s, true)) return;
  interruptibleDelay(500);

  clearAllLEDs();
}

// Simplified "fade" — still analogWrite but interruptible
bool fadeLayerWithAbort(const int layer[], int size, bool fadeIn) {
  if (fadeIn) {
    for (int b = 0; b <= 255; b += 8) {
      if (checkButtonPressed()) { advanceMode(); return true; }
      for (int j = 0; j < size; j++) safeAnalogWrite(layer[j], b);
      interruptibleDelay(20);
    }
  } else {
    for (int b = 255; b >= 0; b -= 8) {
      if (checkButtonPressed()) { advanceMode(); return true; }
      for (int j = 0; j < size; j++) safeAnalogWrite(layer[j], b);
      interruptibleDelay(20);
    }
  }
  return false;
}

// Keep PWM compatibility
void safeAnalogWrite(int pin, int value) { analogWrite(pin, value); }
