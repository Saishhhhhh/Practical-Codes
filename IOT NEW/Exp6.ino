// Lab Practical 6
// Create a program that illuminates the green LED if the counter is less than 100, illuminate the yellow LED if
// the counter is between 101 and 200 and illuminates the red LED if the counter is greater than 200.

//Change the pin numbers to the ones you are using on the Arduino board (Ask Mam for pin numbers)

int led1 = 7;   // Red LED on Pin 7
int led2 = 22;  // Yellow LED on Pin 22
int led3 = 23;  // Green LED on Pin 23
int number = 0;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  delay(200); // delay for 0.2 seconds, increase if needed

  if (number <= 100) {
    // Green LED ON (other LEDs OFF) when counter <= 100
    digitalWrite(led1, LOW);   // Red OFF
    digitalWrite(led2, LOW);   // Yellow OFF
    digitalWrite(led3, HIGH);  // Green ON
  }
  else if (number > 100 && number <= 200) {
    // Yellow LED ON (other LEDs OFF) when counter between 101-200
    digitalWrite(led1, LOW);   // Red OFF
    digitalWrite(led2, HIGH);  // Yellow ON
    digitalWrite(led3, LOW);   // Green OFF
  }
  else if (number > 200) {
    // Red LED ON (other LEDs OFF) when counter > 200
    digitalWrite(led1, HIGH);  // Red ON
    digitalWrite(led2, LOW);   // Yellow OFF
    digitalWrite(led3, LOW);   // Green OFF
  }

  // Increment counter
  number = number + 1;
  
  // Reset counter if it exceeds a large value to prevent overflow
  if (number > 1000) {
    number = 0;
  }
}
