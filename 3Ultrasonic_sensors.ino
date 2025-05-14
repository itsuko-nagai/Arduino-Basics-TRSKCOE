#include <NewPing.h>   // liblary for ultrasonic sensor 
//-----------------------------------------------------------------------\

// defining pins for  ultrasonic sensors 
#define TRIG_PIN1 A0   // 1st sensor trigger pin
#define ECHO_PIN1 A1   // 1st sensor echo pin
#define TRIG_PIN2 A2   // 2nd sensor trigger pin
#define ECHO_PIN2 A3   // 2nd  sensor echo pin
#define TRIG_PIN3 12   // 3rd  sensor trigger pin
#define ECHO_PIN3 A4   // 3rd sensor echo pin
#define MAX_DISTANCE 100  // Maximum sensor distance (in cm)   (maximul value can be  400 cm rated,  200-300 cm can be used)
//-------------------------------------------------------------------------------------------------------------------------
 // acessing liblaries for respective sensors 

NewPing sonar_1(TRIG_PIN1, ECHO_PIN1, MAX_DISTANCE);
NewPing sonar_2(TRIG_PIN2, ECHO_PIN2, MAX_DISTANCE);
NewPing sonar_3(TRIG_PIN3, ECHO_PIN3, MAX_DISTANCE);
// -----------------------------------------------------------------------------------------------------------------------
// code inside setup runs only once 

void setup() {
  Serial.begin(9600); // serial communication 
}
// ----------------------------------------------------------------------------------------------------------------------
void loop() {
  delay(50);  // Short delay for stability
  //-----------------------------------------------------------------------------
 // taking senor output using liblary (distance in cm)
  int Distance_1 = sonar_1.ping_cm(); 
  int Distance_2 = sonar_2.ping_cm();
  int Distance_3= sonar_3.ping_cm();

  //----------------------------------------------------------------------------------
  if(Distance_1 >0){     // precaution for acessing only valid value
  Serial.print("sensor 1Distance: ");
  Serial.print(Distance_1);   // main line to acess sensor output
  Serial.println(" cm");}

  if(Distance_2 > 0){
  Serial.print("sensor 2 Distance: ");
  Serial.print(Distance_2);
  Serial.println(" cm");}

  if(Distance_3 >0){
  Serial.print(" sensor 3Distance: ");
  Serial.print(Distance_3);
  Serial.println(" cm");}
//----------------------------------------------------------------------------------------
  Serial.println("----------------------------");
  delay(500);
}
