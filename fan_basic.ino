//In this code you turn on

int fanPin = 10; // PWM pin

void setup() {
  pinMode(fanPin, OUTPUT);
}

void loop() {
  analogWrite(fanPin, 250); // speed control (0–255), 0 = off
  delay(2000); //wait 2 seconds

  analogWrite(fanPin, 0); // speed control (0–255), 255 = max speed
  delay(7000); //wait 7 seconds
}
