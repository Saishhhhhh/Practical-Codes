// Lab Practical 12
// Understanding the connectivity of Raspberry-Pi /Beagle board circuit / Arduino with IR sensor. Write an application to detect obstacle and notify user using LEDs.

void setup() {
    // Setup code to run once
    pinMode(4, OUTPUT); // Set pin 4 as an output pin
    pinMode(9, INPUT);  // Set pin 9 as an input pin
    digitalWrite(4, HIGH); // Initialize pin 4 to HIGH (this is optional as it's overwritten in loop)
}

void loop() {
    // Loop code to run repeatedly
    if(digitalRead(9) == 1) {
        // If pin 9 is HIGH, set pin 4 to HIGH
        digitalWrite(4, HIGH);
    } else {
        // If pin 9 is LOW, set pin 4 to LOW
        digitalWrite(4, LOW);
    }
}
