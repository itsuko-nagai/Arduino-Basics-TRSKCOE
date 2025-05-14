 // mq2 is a gas sensor which can detect gases like LPG, propane, methane, hydrogen, alcohol, smoke, and carbon monoxide. 
int mq2Pin = A0;   // MQ2 AO connected to A0
int gasValue;   // variable to store sensor output
int threshold = 400;

void setup() {
  Serial.begin(9600);
  pinMode(mq2Pin, INPUT);    // declering pin for its function as input to arduino 
  
}

void loop() {
  
  gasValue = analogRead(mq2Pin);  // Read analog value   by pin A0 
  Serial.print("Gas Sensor Value: ");
  Serial.println(gasValue);
  
  // Example threshold   
  if (gasValue > threshold ) { // adjust threshold accourding to normal sensor output values 
    Serial.println(" gas detected");
}

}
