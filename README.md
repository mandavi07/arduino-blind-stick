# arduino-blind-stick
Arduino-based blind stick using ultrasonic sensor and buzzer

---

## 🔧 Components Used

- Arduino Uno
- Ultrasonic Sensor (HC-SR04)
- Buzzer
- LED
- Jumper Wires
- Breadboard
- Power Supply (Battery or USB)

---

## ⚙️ Working Principle

- The **ultrasonic sensor** measures the distance to an obstacle.
- If the object is **closer than 25 cm**, the **buzzer** starts buzzing and the **LED** turns on.
- Otherwise, both the buzzer and LED remain off.
- The distance is printed on the **Serial Monitor** for debugging.

---

## 📟 Arduino Code

The main code is in `blind_stick.ino`.

```cpp
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

  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");

  if (distanceCm < 25) {
    digitalWrite(5, HIGH); // Buzzer ON
    digitalWrite(6, HIGH); // LED ON
  } else {
    digitalWrite(5, LOW);  // Buzzer OFF
    digitalWrite(6, LOW);  // LED OFF
  }

  delay(100);
}

