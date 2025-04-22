// Lab Practical 6
// Create a program that illuminates the green LED if the counter is less than 100, illuminate the yellow LED if
// the counter is between 101 and 200 and illuminates the red LED if the counter is greater than 200.

//Change the pin numbers to the ones you are using on the Arduino board (Ask Mam for pin numbers)

int led1 = 7;   // Pin 7
int led2 = 22;  // Pin 22
int led3 = 23;  // Pin 23
int number = 0;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  delay(200); // delay for 0.2 seconds, increase if needed

  if (number <= 100) {
    digitalWrite(led1, LOW);   // OFF
    digitalWrite(led2, HIGH);  // ON
    digitalWrite(led3, HIGH);  // ON
  }
  else if (number > 201 && number <= 300) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
  }
  else if (number > 101 && number <= 200) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  }

  number = number + 1;
}
