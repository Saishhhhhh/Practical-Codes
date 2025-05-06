// Lab Practical 10
// Problem Statement:
// Write a program read the temperature sensor and send the values to the serial monitor on the computer.

//You need to install the SimpleDHT library from the Arduino Library Manager.
// Method 1: Install via Library Manager
// Open the Arduino IDE.

// Go to Sketch > Include Library > Manage Libraries…

// In the Library Manager window:

// Type SimpleDHT into the search bar (top-right).

// Find SimpleDHT by Winlin.

// Click Install.

#include <SimpleDHT.h>

// Define the pin for the DHT11 sensor
int pinDHT11 = A1;

// Initialize the DHT11 sensor
SimpleDHT11 dht11(pinDHT11);

void setup() {
  Serial.begin(115200); // Start the serial monitor
}

void loop() {
  Serial.println("=================================");
  Serial.println("Reading from DHT11...");

  byte temperature = 0;
  byte humidity = 0;

  // Try to read data from the sensor
  int err = dht11.read(&temperature, &humidity, NULL);
  
  if (err != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err = ");
    Serial.print(SimpleDHTErrCode(err));
    Serial.print(", Duration = ");
    Serial.println(SimpleDHTErrDuration(err));
    delay(1000);
    return;
  }

  // Print temperature and humidity
  Serial.print("Temperature: ");
  Serial.print((int)temperature);
  Serial.print(" °C, Humidity: ");
  Serial.print((int)humidity);
  Serial.println(" %");

  // Wait before next reading
  delay(1500); // DHT11 reads about once per second
}
