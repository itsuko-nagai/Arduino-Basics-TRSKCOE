#include <Wire.h>
#include <VL53L0X.h>
#define SHUTDOWN_PIN 2
VL53L0X sensor;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  pinMode(SHUTDOWN_PIN, OUTPUT);

  digitalWrite(SHUTDOWN_PIN, LOW);
  delay(10);

  digitalWrite(SHUTDOWN_PIN, HIGH);
  delay(10);
  
  if (!sensor.init()) {
    Serial.println("Failed to initialize sensor");
    while (1);
  }
  sensor.startContinuous(); //continuous measurement mode
}

void loop() {

  int distance = sensor.readRangeContinuousMillimeters();

  if (sensor.timeoutOccurred()) {
    Serial.println("Error: Sensor Timeout");
  } 
  else {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" mm");
  }
  delay(100);
}
