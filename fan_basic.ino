
int fanPin = 10; // PWM pin

void setup() {
  pinMode(fanPin, OUTPUT);
}

void loop() {
  analogWrite(fanPin, 200); // speed control (0–255)
}
