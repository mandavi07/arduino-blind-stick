 const int trigPin = 9;
const int echoPin = 10;
long duration;
int distanceCm, distanceInch;

void setup() { 
  Serial.begin(9600); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(6, OUTPUT); // LED
  pinMode(5, OUTPUT); // Buzzer
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.034 / 2;
  distanceInch = duration * 0.0133 / 2;

  Serial.println("Distance: ");
  Serial.println(distanceCm);
  delay(100);

  if (distanceCm < 25) {
    digitalWrite(5, HIGH);  // Buzzer ON
    digitalWrite(6, HIGH);  // LED ON 
  } else {
    digitalWrite(5, LOW);   // Buzzer OFF
    digitalWrite(6, LOW);   // LED OFF 
  }
}
