/* INSTRUCTIONS:
If (distance < THRESHOLD), then trigger the fan on
*/

int fanPin = 11;

const int trigPin = 9;
const int echoPin = 10;

long duration;
float distance;

const float THRESHOLD = 50.0;            // cm
const unsigned long MIN_TIME = 3000;      // minimum ON/OFF time (ms). Used to avoid overheating the fan 

bool fanOn = false;
unsigned long lastChangeTime = 0;

void setup() {
  Serial.begin(9600);

  pinMode(fanPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // --- Ultrasonic sensor ---
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.0343) / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  unsigned long currentTime = millis();

  // --- Fan control with minimum ON/OFF time ---
  if (!fanOn && distance < THRESHOLD &&
      currentTime - lastChangeTime >= MIN_TIME) {

    analogWrite(fanPin, 255);   // fan ON
    fanOn = true;
    lastChangeTime = currentTime;
  }

  if (fanOn && distance >= THRESHOLD &&
      currentTime - lastChangeTime >= MIN_TIME) {

    analogWrite(fanPin, 0);     // fan OFF
    fanOn = false;
    lastChangeTime = currentTime;
  }

  delay(50); // small sensor delay
}
