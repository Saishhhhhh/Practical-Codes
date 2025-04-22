// Lab Practical 11
// Problem Statement:
// Write a program using piezo element and use it to play a tune after someone knocks.

const int knockSensor = A1;     // Piezo sensor connected to analog pin A1
const int buzzer = 8;           // Buzzer connected to digital pin 8
const int threshold = 400;      // Threshold for detecting a knock

int sensorReading = 0;

void setup() {
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);           // For debugging (optional)
}

void loop() {
  sensorReading = analogRead(knockSensor);
  Serial.println(sensorReading); // Optional: Monitor knock intensity

  if (sensorReading >= threshold) {
    playTune(); // Call the function to play the tune
  }

  delay(100); // Short delay to reduce noise
}

void playTune() {
  tone(buzzer, 261); // C
  delay(200);
  noTone(buzzer);

  tone(buzzer, 293); // D
  delay(200);
  noTone(buzzer);

  tone(buzzer, 329); // E
  delay(200);
  noTone(buzzer);

  tone(buzzer, 349); // F
  delay(200);
  noTone(buzzer);

  tone(buzzer, 392); // G
  delay(200);
  noTone(buzzer);
}
