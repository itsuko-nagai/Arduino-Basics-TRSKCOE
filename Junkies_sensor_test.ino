bool isBlackLine = 1;             // keep 1 in case of black line. In case of white line change this to 0
unsigned int lineThickness = 50;  // Enter line thickness in mm. Works best for thickness between 10 & 35
unsigned int numSensors = 8;      

int sensorWeight[8] = { 8, 3, 2, 1, -1, -2, -3, -8 };
int activeSensors;

int onLine = 1;
int minValues[8], maxValues[8], threshold[8], sensorValue[8], sensorArray[8];

void setup() {
  Serial.begin(9600);
  lineThickness = constrain(lineThickness, 10, 50); // 10-50
  
  calibrate();
  
  Serial.println("Setup complete");
}

void loop() {

  readLine();

  bool allSensorsOff = true;
  for (int i = 0; i < numSensors; i++) {
    if (sensorArray[i]) {
      allSensorsOff = false;
      break;
    }
  }

  Serial.print("Sensor Array: ");
  for (int i = 0; i < numSensors; i++) {
    Serial.print(sensorArray[i]);
    Serial.print(" ");
  }
  Serial.println();
}

void calibrate() {
  for (int i = 0; i < numSensors; i++) {
    minValues[i] = analogRead(i);
    maxValues[i] = analogRead(i);
  }

  for (int i = 0; i < 10000; i++) {
    for (int j = 0; j < numSensors; j++) {
      int value = analogRead(j);
      if (value < minValues[j]) {
        minValues[j] = value;
      }
      if (value > maxValues[j]) {
        maxValues[j] = value;
      }
    }
  }

  for (int i = 0; i < numSensors; i++) {
    threshold[i] = (minValues[i] + maxValues[i]) / 2;
    Serial.print(threshold[i]);
    Serial.print(" ");
  }
  Serial.println();
}

void readLine() {
  onLine = 0;

  for (int i = 0; i < numSensors; i++) {
    if (isBlackLine) {
      sensorValue[i] = map(analogRead(i), minValues[i], maxValues[i], 0, 1000);
    } else {
      sensorValue[i] = map(analogRead(i), minValues[i], maxValues[i], 1000, 0);
    }
    sensorValue[i] = constrain(sensorValue[i], 0, 1000);
    sensorArray[i] = sensorValue[i] > 500;  // A threshold value to determine if sensor sees the line
    if (sensorArray[i]) {
      onLine = 1;
    }
  }
}
