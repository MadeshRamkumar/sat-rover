#include <Servo.h>

Servo myServo;  // Create a servo object

int ldrLeftPin = A0;   // Left LDR module connected to analog pin A0
int ldrRightPin = A1;  // Right LDR module connected to analog pin A1
int servoPin = 9;      // Servo motor connected to digital pin 9

void setup() {
  myServo.attach(servoPin);  // Attach the servo to pin 9
  myServo.write(90);         // Start with the servo in the middle position (90 degrees)
  Serial.begin(9600);        // Start serial communication for debugging
}

void loop() {
  // Read the light intensity from both LDR modules (analog outputs)
  int ldrLeftValue = analogRead(ldrLeftPin);
  int ldrRightValue = analogRead(ldrRightPin);

  // Calculate the difference in light intensity
  int difference = ldrLeftValue - ldrRightValue;

  // Move the servo based on the difference
  if (difference > 50) {
    // If the left LDR detects more light, move the servo to the left
    int newAngle = map(difference, 50, 1023, 90, 180);  // Map the difference to servo angle
    newAngle = constrain(newAngle, 90, 180);             // Limit to 90-180 degrees
    myServo.write(newAngle);
  }
  else if (difference < -50) {
    // If the right LDR detects more light, move the servo to the right
    int newAngle = map(abs(difference), 50, 1023, 90, 0); // Map the difference to servo angle
    newAngle = constrain(newAngle, 0, 90);                 // Limit to 0-90 degrees
    myServo.write(newAngle);
  }
  else {
    // If light is balanced, keep the servo in the middle
    myServo.write(90);  // Keep it centered
  }

  // Debugging information: Print LDR values to the Serial Monitor
  Serial.print("Left LDR: ");
  Serial.print(ldrLeftValue);
  Serial.print(" | Right LDR: ");
  Serial.print(ldrRightValue);
  Serial.print(" | Difference: ");
  Serial.println(difference);

  delay(500);  // Small delay before the next loop
}