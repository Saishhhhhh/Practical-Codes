// Problem Statement:
// Lab Practical 7
// Create a program so that when the user enters:
// 'b' - the green light blinks
// 'g' - the green light is illuminated
// 'y' - the yellow light is illuminated
// 'r' - the red light is illuminated

// Define LED pins with descriptive names
int redLed = 7;     // Red LED on pin 7
int yellowLed = 22; // Yellow LED on pin 22
int greenLed = 23;  // Green LED on pin 23
char key;           // Variable to store received character

void setup() {
  // Set all LED pins as outputs
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);

  // Turn all LEDs OFF initially
  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, LOW);

  // Initialize serial communication
  Serial.begin(9600);    //baud rate
  Serial.println("Enter:");
  Serial.println("r - Red light ON");
  Serial.println("y - Yellow light ON");
  Serial.println("g - Green light ON");
  Serial.println("b - Green light BLINK");
}

void loop() {
  // Check if data is available to read
  if (Serial.available() > 0) {
    // Read the incoming byte
    key = Serial.read();
    Serial.print("Received: ");
    Serial.println(key);

    // Turn all LEDs OFF first
    allLedsOff();

    // Process the command
    if (key == 'r' || key == 'R') {
      // Red light ON
      digitalWrite(redLed, HIGH);
    } 
    else if (key == 'y' || key == 'Y') {
      // Yellow light ON
      digitalWrite(yellowLed, HIGH);
    } 
    else if (key == 'g' || key == 'G') {
      // Green light ON
      digitalWrite(greenLed, HIGH);
    }
    else if (key == 'b' || key == 'B') {
      // Blink green light (5 times)
      blinkGreen();
    } 
    else {
      // Invalid input
      Serial.println("Try r, y, g, or b");
    }
  }
}

// Function to turn all LEDs OFF
void allLedsOff() {
  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, LOW);
}

// Function to blink the green LED
void blinkGreen() {
  Serial.println("Green LED blinking...");
  
  // Blink green LED 5 times
  for(int i = 0; i < 5; i++) {
    digitalWrite(greenLed, HIGH);  // ON
    delay(500);                    // Wait 0.5 seconds
    digitalWrite(greenLed, LOW);   // OFF
    delay(500);                    // Wait 0.5 seconds
  }
  
  Serial.println("Blinking finished");
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