// Lab Practical 9
// Problem Statement:
// Write a program to control the color of the LED by turning 3 different potentiometers. One will be read for the value of Red, one for the value of Green, and one for the value of Blue.

// Pin configuration
int red_light_pin = 5;
int green_light_pin = 6;
int blue_light_pin = 3;

// Variables for RGB values
unsigned int red, green, blue;

void setup() {
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
}

void loop() {
  // Read analog values from potentiometers
  red = analogRead(A0);     // Read red potentiometer
  green = analogRead(A2);   // Read green potentiometer
  blue = analogRead(A3);    // Read blue potentiometer

  // Convert range from 0–1023 to 0–255
  red = red / 4;
  green = green / 4;
  blue = blue / 4;

  // Update LED color (inverted colors for common-anode LED)
  RGB_color(255 - red, 255 - green, 255 - blue);

  delay(100); // small delay for smoother changes
}

// Function to set RGB LED color
void RGB_color(int red_light_value, int green_light_value, int blue_light_value) {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
