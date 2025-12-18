#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#define  echoPin 16       // HC SR04 Trig <——> GPIO16(D2)
#define  trigPin 5        // HC SR04 Echo <——> GPIO5 (D3)
#define  IN_2    4        // L9110S  A-1B <——> GPIO4 (D4) MOTOR A
#define  IN_1    14       // L9110S  A-1A <——> GPIO14(D5) MOTOR A
#define  IN_4    12       // L9110S  B-1B <——> GPIO12(D6) MOTOR B
#define  IN_3    13       // L9110S  B-1A <——> GPIO13(D7) MOTOR B

String command;             //String to store app command state.
int Front_Distance;
int speedCar = 255;         // 0 - 255
const char* ssid = "ESP8266 Robot Car"; //name
ESP8266WebServer server(80);

void setup() 
{
      pinMode(LED_BUILTIN, OUTPUT);
      pinMode(IN_1, OUTPUT);
      pinMode(IN_2, OUTPUT);
      pinMode(IN_3, OUTPUT);
      pinMode(IN_4, OUTPUT); 
      pinMode(trigPin, OUTPUT);  // Sets the trigPin as an Output
      pinMode(echoPin, INPUT);   // Sets the echoPin as an Input  
      Serial.begin(115200);
  
      // Starting WiFi
      WiFi.mode(WIFI_AP);
      WiFi.softAP(ssid);
      IPAddress myIP = WiFi.softAPIP();
      Serial.print("AP IP address: ");
      Serial.println(myIP);
  
      // Starting web-server 
      server.on ( "/", HTTP_handleRoot );
      server.onNotFound ( HTTP_handleRoot );
      server.begin();
      digitalWrite(LED_BUILTIN, LOW);    
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

void loop() 
{
      server.handleClient();
      command = server.arg("State");
      if (command == "F") goAhead();
      else if (command == "B") goBack();
      else if (command == "L") goLeft();
      else if (command == "R") goRight();
      else if (command == "W") Ultrasonic_Avoidance();
      else if (command == "w") stopRobot();
      else if (command == "0") speedCar = 0;
      else if (command == "1") speedCar = 50;
      else if (command == "2") speedCar = 100;
      else if (command == "3") speedCar = 120;
      else if (command == "4") speedCar = 140;
      else if (command == "5") speedCar = 160;
      else if (command == "6") speedCar = 180;
      else if (command == "7") speedCar = 200;
      else if (command == "8") speedCar = 220;
      else if (command == "9") speedCar = 240;
      else if (command == "q") speedCar = 255;      
      else if (command == "S") stopRobot();
}

void HTTP_handleRoot(void) 
{

if( server.hasArg("State") )
  {
       Serial.println(server.arg("State"));
  }
  server.send ( 200, "text/html", "" );
  delay(1);
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


void Ultrasonic_Avoidance() {
  Front_Distance = getDistance();
  Serial.println(Front_Distance);
  if (Front_Distance < 20) {
    goBack();
    delay(200);
    if (50 >= random(1, 100)) {
      goLeft();

    } else {
      goRight();

    }
    delay(150);

  } else if (Front_Distance >= 20 && Front_Distance <= 35) 
  {
    stopRobot();
    delay(200);
    if (50 >= random(1, 100)) {
      goLeft();

    } else {
      goRight();

    }
    delay(150);
  } else if (Front_Distance > 35) {
    goAhead();
  }
}
