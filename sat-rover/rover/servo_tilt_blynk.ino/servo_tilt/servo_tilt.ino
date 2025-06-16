#define BLYNK_TEMPLATE_ID "ENTER YOUR TEMPLATE ID"
#define BLYNK_TEMPLATE_NAME "ENTER YOUR TEMPLATE NAME"
#define BLYNK_AUTH_TOKEN "ENTER YOUR AUNTHENTICATION TOKEN"


#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include<Servo.h>
Servo servo1, servo2;

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "ENTER YOUR WIFI SSID";
char pass[] = "ENTER YOUR PASSWORD";

BLYNK_WRITE(V0)
{
  int s0 = param.asInt(); 
  servo1.write(s0);
  Blynk.virtualWrite(V2, s0);
} 

BLYNK_WRITE(V1)
{
  int s1 = param.asInt(); 
  servo2.write(s1);
  Blynk.virtualWrite(V3, s1);
} 


void setup()
{
  Serial.begin(9600);
  servo1.attach(D2); //Connect to Pin D2 in NodeMCU
  servo2.attach(D3); //Connect to Pin D3 in NodeMCU
  Blynk.begin(auth, ssid, pass);//Splash screen delay
  delay(2000); 
}

void loop() 
{
  Blynk.run();
}