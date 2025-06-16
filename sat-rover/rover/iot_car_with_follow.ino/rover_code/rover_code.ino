#define BLYNK_TEMPLATE_ID "ENTER YOUR TEPLATE ID"
#define BLYNK_TEMPLATE_NAME "ENTER YOUR TEMPLATE NAME"
#define BLYNK_AUTH_TOKEN "ENTER YOUR AUNTHENTICATION TOKEN"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define ENA D6
#define IN1 D1
#define IN2 D2
#define ENB D5
#define IN3 D3
#define IN4 D4

#define trigPin D7
#define echoPin D8

bool forward = 0;
bool backward = 0;
bool left = 0;
bool right = 0;
int Speed = 0;

int highSpeed = 100;
int slowSpeed = 50;

char ssid[] = "ENTER YOUR WIFI SSID";
char pass[] = "YOUR WIFI PASSWORD";

long duration;
int distance;

void setup() {
  Serial.begin(9600);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

BLYNK_WRITE(V1) { forward = param.asInt(); }
BLYNK_WRITE(V2) { backward = param.asInt(); }
BLYNK_WRITE(V3) { left = param.asInt(); }
BLYNK_WRITE(V4) { right = param.asInt(); }
BLYNK_WRITE(V5) { Speed = param.asInt(); }

int measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  return distance;
}

void controlCar() {
  if (forward) {
    moveForward(Speed);
    Serial.println("Forward");
  } else if (backward) {
    moveBackward(Speed);
    Serial.println("Backward");
  } else if (left) {
    turnLeft(Speed);
    Serial.println("Left");
  } else if (right) {
    turnRight(Speed);
    Serial.println("Right");
  } else {
    stopCar();
    Serial.println("Stop");
  }
}

void ultrasonicControl() {
  distance = measureDistance();
  if (distance <= 20 && distance > 5) {
    moveForward(highSpeed);
    Serial.println("Moving forward at full speed.");
  } else if (distance <= 5) {
    moveForward(slowSpeed);
    Serial.println("Slowing down.");
  } else {
    stopCar();
    Serial.println("Stopping.");
  }
}

void loop() {
  Blynk.run();
  if (!forward && !backward && !left && !right) {
    ultrasonicControl();
  } else {
    controlCar();
  }
}

void moveForward(int speed) {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void moveBackward(int speed) {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnLeft(int speed) {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnRight(int speed) {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stopCar() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
