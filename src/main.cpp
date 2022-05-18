#include <Arduino.h>

int ASignal = 14;
int LEDPin = 16;
int airValue = 4095;
int waterValue = 886;

void setup()
{
  pinMode(LEDPin, OUTPUT);
  pinMode(ASignal, INPUT);
  digitalWrite(LEDPin, HIGH);
  Serial.begin(9600);
}

void loop()
{
  int sensorValue = analogRead(ASignal);
  int soilMoistureValue = map(sensorValue, airValue, waterValue, 0, 100);
  Serial.println(soilMoistureValue);

  if (soilMoistureValue > 50)
  {
    digitalWrite(LEDPin, LOW);
  }
  delay(3000);
}