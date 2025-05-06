# IoT Practical Experiments

This repository contains a collection of IoT practical experiments implemented for both Arduino and Raspberry Pi platforms.

## Experiment 5: LED Control
- **Arduino (Exp5.ino)**: Controls LED output using digital pins on Arduino.
- **Raspberry Pi (Exp5R.py)**: Equivalent LED control implementation using GPIO pins on Raspberry Pi.

## Experiment 6: Temperature Monitoring
- **Arduino (Exp6.ino)**: Reads temperature data from sensors and displays/processes the readings.
- **Raspberry Pi (Exp6R.py)**: Temperature monitoring implementation for Raspberry Pi using Python.

## Experiment 7: Ultrasonic Distance Sensor
- **Arduino (Exp7.ino)**: Measures distance using an ultrasonic sensor (HC-SR04) with Arduino.
- **Raspberry Pi (Exp7R.py)**: Distance measurement implementation using ultrasonic sensor on Raspberry Pi.

## Experiment 8: Servo Motor Control
- **Arduino (Exp8.ino)**: Controls servo motor position using PWM on Arduino.
- **Raspberry Pi (Exp8R.py)**: Servo motor control implementation for Raspberry Pi.

## Experiment 9: RGB LED Control
- **Arduino (Exp9.ino)**: Controls RGB LED color using potentiometers, implementing PWM for color mixing.

## Experiment 10: LCD Display
- **Arduino (Exp10.ino)**: Interfaces with an LCD display to show text and data using Arduino.

## Experiment 11: Piezo Element/Knock Sensor
- **Arduino (Exp11.ino)**: Uses a piezo element to detect knocks and plays a tune through a buzzer when detected.

## Experiment 12: IR Obstacle Detection
- **Arduino (Exp12.ino)**: Uses IR sensor to detect obstacles and notifies through an LED.
- **Raspberry Pi (Exp12R.py)**: Equivalent obstacle detection implementation for Raspberry Pi using IR sensor.

## Hardware Requirements

### Arduino Setup
- Arduino board (Uno/Nano/Mega)
- Various sensors (temperature, ultrasonic, IR, etc.)
- LEDs, RGB LEDs
- Potentiometers
- Servo motors
- LCD display
- Piezo elements
- Breadboard and jumper wires

### Raspberry Pi Setup
- Raspberry Pi board
- GPIO connectivity
- Python with gpiozero library
- Equivalent sensors compatible with Raspberry Pi

## Setup Instructions

### Arduino
1. Connect components according to the pin assignments in each sketch
2. Upload the corresponding .ino file to your Arduino board using the Arduino IDE

### Raspberry Pi
1. Install required Python libraries: `pip install gpiozero`
2. Connect components to the appropriate GPIO pins
3. Run the Python script: `python Exp#R.py`

## Notes
- Files ending with .ino are Arduino sketches
- Files ending with .py are Python scripts for Raspberry Pi
- Each experiment implements similar functionality across platforms with platform-specific code 