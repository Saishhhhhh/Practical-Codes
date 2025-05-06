int led1 = 0;  // LED1 connected to digital pin 0
int led2 = 1;  // LED2 connected to digital pin 1
int led3 = 2;  // LED3 connected to digital pin 2
int led4 = 4;  // LED4 connected to digital pin 4

void setup() {
  // Initialize the LED pins as outputs
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  // Pattern 1: All LEDs ON for 1 second
  allOn();
  delay(1000);
  
  // Pattern 2: All LEDs OFF for 1 second
  allOff();
  delay(1000);
  
}

// Function to turn all LEDs ON
void allOn() {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
}

// Function to turn all LEDs OFF
void allOff() {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}
