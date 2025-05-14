#define AIN1 3 // IN1
#define AIN2 4 // IN2
#define BIN1 5 // IN3
#define BIN2 6 // IN4
#define PWMA 9 // MAKE SURE THIS IS PWM PIN ON ARDUINO
#define PWMB 10 // MAKE SURE THIS IS PWM PIN ON ARDUINO

// THIS CODE MAY BE USED FOR BOTH L293D AND L298N MOTOR DRIVERS

void setup() {

  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
}

void loop() {

  forward();
  delay(1000);

  left();
  delay(1000);

  right();
  delay(1000);

  reverse();
  delay(1000);

  stop();
  delay(5000);

}

void forward(){
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMA, 150); //PWM RANGE (0-255)
  analogWrite(PWMB, 150); 
}

void stop(){
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMA, 150); //PWM RANGE (0-255)
  analogWrite(PWMB, 150); 
}

void reverse(){
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMA, 150); //PWM RANGE (0-255)
  analogWrite(PWMB, 150); 
}

void right(){
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMA, 150); //PWM RANGE (0-255)
  analogWrite(PWMB, 150); 
}

void left(){
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMA, 150); //PWM RANGE (0-255)
  analogWrite(PWMB, 150); 
}
