// Lab Practical 12
// Understanding the connectivity of Raspberry-Pi /Beagle board circuit / Arduino with IR sensor. Write an application to detect obstacle and notify user using LEDs.

int LED_PIN = 4;          // LED connected to pin 4
int IR_RECEIVER_PIN = 9;  // IR Receiver connected to pin 9

void setup() {
    // Setup code to run once
    pinMode(LED_PIN, OUTPUT); // Set pin 4 as an output pin
    pinMode(IR_RECEIVER_PIN, INPUT);  // Set pin 9 as an input pin
    digitalWrite(LED_PIN, HIGH); // Initialize pin 4 to HIGH (this is optional as it's overwritten in loop)
}

void loop() {
    // Loop code to run repeatedly
    if(digitalRead(IR_RECEIVER_PIN) == 1) {
        // If pin 9 is HIGH, set pin 4 to HIGH
        digitalWrite(LED_PIN, HIGH);
    } else {
        // If pin 9 is LOW, set pin 4 to LOW
        digitalWrite(LED_PIN, LOW);
    }
}