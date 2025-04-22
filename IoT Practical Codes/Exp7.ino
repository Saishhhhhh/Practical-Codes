// Problem Statement:
// Lab Practical 7
// Create a program so that when the user enters ‘b’ the green light blinks, ‘g’ the green light is illuminated ‘y’
// the yellow light is illuminated and ‘r’ the red light is illuminated.

//Change the pin numbers to the ones you are using on the Arduino board (Ask Mam for pin numbers)

int led1 = 7;
int led2 = 22;
int led3 = 23;
int led4 = 25;
char key;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  // Turn all LEDs ON initially
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);

  Serial.begin(9600);
  Serial.println("Enter Character:");
}

void loop() {
  delay(200);

  if (Serial.available() > 0) {
    key = Serial.read();
    Serial.print("Received: ");
    Serial.println(key);

    if (key == 'g' || key == 'G') {
      digitalWrite(led1, LOW);   // off
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
    } 
    else if (key == 'r' || key == 'R') {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);   // off
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
    } 
    else if (key == 'y' || key == 'Y') {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);   // off
      digitalWrite(led4, HIGH);
    } 
    else {
      // Default: all ON
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
    }
  }
}


// ✅ 3. Use Serial Monitor
// Open Serial Monitor (Ctrl + Shift + M).

// Set baud rate to 9600.

// Set line ending to "No line ending" or "Newline".

// ✅ 4. Test It!
// Type g → only led1 turns off, others on.

// Type r → only led2 turns off, others on.

// Type y → only led3 turns off, others on.

// Type anything else → all LEDs turn on.