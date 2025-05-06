// RGB LED control with potentiometers

// LED pins
int redPin = 5;
int greenPin = 6;
int bluePin = 3;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Read and map potentiometer values directly
  int red = analogRead(A0) / 4;
  int green = analogRead(A2) / 4;
  int blue = analogRead(A3) / 4;
  
  // Set LED color (common-anode LED)
  analogWrite(redPin, 255 - red);
  analogWrite(greenPin, 255 - green);
  analogWrite(bluePin, 255 - blue);
  
  delay(100);
}
