#Lab Practical 6
#Create a program that illuminates the green LED if the counter is less than 100, illuminate the yellow LED if
#the counter is between 101 and 200 and illuminates the red LED if the counter is greater than 200.

import time
from gpiozero import LED

# Define LED pins with descriptive names
led_red = LED(7)     # Red LED on Pin 7
led_yellow = LED(22) # Yellow LED on Pin 22
led_green = LED(23)  # Green LED on Pin 23
number = 0

print("Starting LED counter program...")

# Main loop
while True:
    time.sleep(0.2)  # delay for 0.2 seconds
    
    if number <= 100:
        # Green LED ON (other LEDs OFF) when counter <= 100
        led_red.on()      # Red OFF (with inverter, on signal turns LED off)
        led_yellow.on()   # Yellow OFF (with inverter, on signal turns LED off)
        led_green.off()   # Green ON (with inverter, off signal turns LED on)
    elif number > 100 and number <= 200:
        # Yellow LED ON (other LEDs OFF) when counter between 101-200
        led_red.on()      # Red OFF (with inverter, on signal turns LED off)
        led_yellow.off()  # Yellow ON (with inverter, off signal turns LED on)
        led_green.on()    # Green OFF (with inverter, on signal turns LED off)
    elif number > 200:
        # Red LED ON (other LEDs OFF) when counter > 200
        led_red.off()     # Red ON (with inverter, off signal turns LED on)
        led_yellow.on()   # Yellow OFF (with inverter, on signal turns LED off)
        led_green.on()    # Green OFF (with inverter, on signal turns LED off)
    
    # Increment counter
    number = number + 1
    
    # Reset counter if it exceeds a large value to prevent overflow
    if number > 300:
        number = 0
        print("Counter reset to 0")
