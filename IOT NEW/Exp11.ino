// Lab Practical 11
// Problem Statement:
// Write a program using piezo element and use it to play a tune after someone knocks.

int buzzer = 13; // connect buzzer to digital pin 13
int knockSensor = A1; // the piezo is connected to analog pin A1
int threshold = 400; // threshold value to detect a knock

int sensorReading = 0; // variable to store sensor reading

void setup() {
  pinMode(buzzer, OUTPUT); // set buzzer as output
  pinMode(knockSensor, INPUT); // no need to set knockSensor as input, analogRead handles it
}

void loop() {
  sensorReading = analogRead(knockSensor);

  if (sensorReading >= threshold) {
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

  delay(100); // short delay before next reading
}
