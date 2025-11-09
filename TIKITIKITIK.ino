const int led1Pin = 2; 
const int led2Pin = 3;
const int led3Pin = 4; 
const int led4Pin = 5;  

void setup() {
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(led4Pin, OUTPUT);
}

void loop() {
  
  int commonDuration = 40; 

  for (int set = 0; set < 3; set++) {
   
    int duration1 = 10;
    for (int i = 0; i < duration1 * 1000; i += 2000) {
      digitalWrite(led1Pin, HIGH);
      digitalWrite(led2Pin, HIGH);
      digitalWrite(led3Pin, HIGH);
      digitalWrite(led4Pin, HIGH);
      delay(100);
      digitalWrite(led1Pin, LOW);
      digitalWrite(led2Pin, LOW);
      digitalWrite(led3Pin, LOW);
      digitalWrite(led4Pin, LOW);
      delay(100);
      digitalWrite(led1Pin, HIGH);
      digitalWrite(led2Pin, HIGH);
      digitalWrite(led3Pin, HIGH);
      digitalWrite(led4Pin, HIGH);
    }
    delay(1000); 
    int duration2 = 10;
    for (int i = 0; i < duration2 * 1000; i += 2000) {
      digitalWrite(led1Pin, HIGH);
      digitalWrite(led2Pin, HIGH);
      digitalWrite(led3Pin, HIGH);
      digitalWrite(led4Pin, HIGH);
      delay(100);
      digitalWrite(led1Pin, LOW);
      digitalWrite(led2Pin, LOW);
      digitalWrite(led3Pin, LOW);
      digitalWrite(led4Pin, LOW);
      delay(100);
      digitalWrite(led1Pin, HIGH);
      digitalWrite(led2Pin, HIGH);
      digitalWrite(led3Pin, HIGH);
      digitalWrite(led4Pin, HIGH);
    }
    delay(1000); 
   int duration3 = 10;
    for (int i = 0; i < duration3 * 1000; i += 2000) {
      digitalWrite(led1Pin, HIGH);
      digitalWrite(led2Pin, HIGH);
      digitalWrite(led3Pin, HIGH);
      digitalWrite(led4Pin, HIGH);
      delay(100);
      digitalWrite(led1Pin, LOW);
      digitalWrite(led2Pin, LOW);
      digitalWrite(led3Pin, LOW);
      digitalWrite(led4Pin, LOW);
      delay(100);
      digitalWrite(led1Pin, HIGH);
      digitalWrite(led2Pin, HIGH);
      digitalWrite(led3Pin, HIGH);
      digitalWrite(led4Pin, HIGH);
    }
    delay(1000);
    int duration4 = 10;
    for (int i = 0; i < duration4 * 1000; i += 2000) {
      digitalWrite(led1Pin, HIGH);
      digitalWrite(led2Pin, HIGH);
      digitalWrite(led3Pin, HIGH);
      digitalWrite(led4Pin, HIGH);
      delay(100);
      digitalWrite(led1Pin, LOW);
      digitalWrite(led2Pin, LOW);
      digitalWrite(led3Pin, LOW);
      digitalWrite(led4Pin, LOW);
      delay(100);
      digitalWrite(led1Pin, HIGH);
      digitalWrite(led2Pin, HIGH);
      digitalWrite(led3Pin, HIGH);
      digitalWrite(led4Pin, HIGH);
    }
    delay(1000);

   
    int duration5 = 10;
    for (int i = 0; i < duration5 * 1000; i += 2000) {
      digitalWrite(led2Pin, HIGH);
      digitalWrite(led3Pin, HIGH);
      digitalWrite(led4Pin, HIGH);
      delay(100);
      digitalWrite(led2Pin, LOW);
      digitalWrite(led3Pin, LOW);
      digitalWrite(led4Pin, LOW);
      delay(100);
      digitalWrite(led2Pin, HIGH);
      digitalWrite(led3Pin, HIGH);
      digitalWrite(led4Pin, HIGH);
    }
    delay(1000); 

     int duration6 = 10;
    for (int i = 0; i < duration6 * 1000; i += 2000) {
      digitalWrite(led2Pin, HIGH);
      digitalWrite(led3Pin, HIGH);
      digitalWrite(led4Pin, HIGH);
      delay(100);
      digitalWrite(led2Pin, LOW);
      digitalWrite(led3Pin, LOW);
      digitalWrite(led4Pin, LOW);
      delay(100);
      digitalWrite(led2Pin, HIGH);
      digitalWrite(led3Pin, HIGH);
      digitalWrite(led4Pin, HIGH);
    }
    delay(1000); 
   
     int duration7 = 10;
    for (int i = 0; i < duration7 * 1000; i += 2000) {
      digitalWrite(led2Pin, HIGH);
      digitalWrite(led3Pin, HIGH);
      digitalWrite(led4Pin, HIGH);
      delay(100);
      digitalWrite(led2Pin, LOW);
      digitalWrite(led3Pin, LOW);
      digitalWrite(led4Pin, LOW);
      delay(100);
      digitalWrite(led2Pin, HIGH);
      digitalWrite(led3Pin, HIGH);
      digitalWrite(led4Pin, HIGH);
    }
    delay(1000);
     int duration8 = 10;
    for (int i = 0; i < duration8 * 1000; i += 2000) {
      digitalWrite(led2Pin, HIGH);
      digitalWrite(led3Pin, HIGH);
      digitalWrite(led4Pin, HIGH);
      delay(100);
      digitalWrite(led2Pin, LOW);
      digitalWrite(led3Pin, LOW);
      digitalWrite(led4Pin, LOW);
      delay(100);
      digitalWrite(led2Pin, HIGH);
      digitalWrite(led3Pin, HIGH);
      digitalWrite(led4Pin, HIGH);
    }
    delay(1000);

    
    int duration9 = 10;
    for (int i = 0; i < duration9 * 1000; i += 2000) {
      digitalWrite(led3Pin, HIGH);
      digitalWrite(led4Pin, HIGH);
      delay(100);
      digitalWrite(led3Pin, LOW);
      digitalWrite(led4Pin, LOW);
      delay(100);
      digitalWrite(led3Pin, HIGH);
      digitalWrite(led4Pin, HIGH);
    }
    delay(1000);
    int duration10 = 10;
    for (int i = 0; i < duration10 * 1000; i += 2000) {
      digitalWrite(led3Pin, HIGH);
      digitalWrite(led4Pin, HIGH);
      delay(100);
      digitalWrite(led3Pin, LOW);
      digitalWrite(led4Pin, LOW);
      delay(100);
      digitalWrite(led3Pin, HIGH);
      digitalWrite(led4Pin, HIGH);
    }
    delay(1000);
    int duration11 = 10;
    for (int i = 0; i < duration11 * 1000; i += 2000) {
      digitalWrite(led3Pin, HIGH);
      digitalWrite(led4Pin, HIGH);
      delay(100);
      digitalWrite(led3Pin, LOW);
      digitalWrite(led4Pin, LOW);
      delay(100);
      digitalWrite(led3Pin, HIGH);
      digitalWrite(led4Pin, HIGH);
    }
    delay(1000);
    int duration12 = 10;
    for (int i = 0; i < duration12 * 1000; i += 2000) {
      digitalWrite(led3Pin, HIGH);
      digitalWrite(led4Pin, HIGH);
      delay(100);
      digitalWrite(led3Pin, LOW);
      digitalWrite(led4Pin, LOW);
      delay(100);
      digitalWrite(led3Pin, HIGH);
      digitalWrite(led4Pin, HIGH);
    }
    delay(1000);

    int duration13 = 10;
    for (int i = 0; i < duration13 * 1000; i += 2000) {
      digitalWrite(led4Pin, HIGH);
      delay(100);
      digitalWrite(led4Pin, LOW);
      delay(100);
      digitalWrite(led4Pin, HIGH);
    }
    delay(1000);
    int duration14 = 10;
    for (int i = 0; i < duration14 * 1000; i += 2000) {
      digitalWrite(led4Pin, HIGH);
      delay(100);
      digitalWrite(led4Pin, LOW);
      delay(100);
      digitalWrite(led4Pin, HIGH);
    }
    delay(1000);
    int duration15 = 10;
    for (int i = 0; i < duration15 * 1000; i += 2000) {
      digitalWrite(led4Pin, HIGH);
      delay(100);
      digitalWrite(led4Pin, LOW);
      delay(100);
      digitalWrite(led4Pin, HIGH);
    }
    delay(1000);
    int duration16 = 10;
    for (int i = 0; i < duration16 * 1000; i += 2000) {
      digitalWrite(led4Pin, HIGH);
      delay(100);
      digitalWrite(led4Pin, LOW);
      delay(100);
      digitalWrite(led4Pin, HIGH);
    }
    delay(1000);
  }
}
