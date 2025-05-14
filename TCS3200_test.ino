// TCS3200 SENSOR

#define S0 0
#define S1 1
#define S2 5
#define S3 8
#define OUT 2

unsigned int redFrequency = 0;
unsigned int greenFrequency = 0;
unsigned int blueFrequency = 0;

void setup() {
  Serial.begin(9600);

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);

  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW); // USE SCALING FREQ AS PER NEEDS FROM TABLE BELOW

/*
|   S0   |   S1   |   S2   |   S3   |   Scaling Frequency   |   Frequency Range (Hz)   |
| ------ | ------ | ------ | ------ | --------------------- | ------------------------ |
| 0      | 0      | 0      | 0      | 2%                    | 2-4 kHz                  |
| 1      | 0      | 0      | 0      | 20%                   | 20-40 kHz                |
| 0      | 1      | 0      | 0      | 100%                  | 100-200 kHz              |
| 1      | 1      | 0      | 0      | 100%                  | 100-200 kHz              |
| 0      | 0      | 1      | 0      | 2%                    | 2-4 kHz                  |
| 1      | 0      | 1      | 0      | 20%                   | 20-40 kHz                |
| 0      | 1      | 1      | 0      | 100%                  | 100-200 kHz              |
| 1      | 1      | 1      | 0      | 100%                  | 100-200 kHz              |

HIGHER FREQ = HIGHER OUTPUT RATE
BUT CONSUMES MORE POWER

*/


}

void loop() {

  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  redFrequency = pulseIn(OUT, LOW);

  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  greenFrequency = pulseIn(OUT, LOW);

  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  blueFrequency = pulseIn(OUT, LOW);

  Serial.print("Red: ");
  Serial.print(redFrequency);
  Serial.print(" Green: ");
  Serial.print(greenFrequency);
  Serial.print(" Blue: ");
  Serial.println(blueFrequency);

  delay(500);
}




// USE THE FUNCTION BELOW IF NECESSARY (color filter)

// void setColorFilter(int s2, int s3) {
//   digitalWrite(S2, s2);
//   digitalWrite(S3, s3); // put this in place of "digitalWrite(S3, HIGH);" etc
//   if (s2 == 0 && s3 == 0) {
//     Serial.println("Color filter set to Red.");
//   } 
//   else if (s2 == 1 && s3 == 0) {
//     Serial.println("Color filter set to Green.");
//   } 
//   else if (s2 == 0 && s3 == 1) {
//     Serial.println("Color filter set to Blue.");
//   } 
//   else if (s2 == 1 && s3 == 1) {
//     Serial.println("Color filter set to Clear.");
//   } 
//   else {
//     Serial.println("Invalid color filter setting.");
//   }
// }
