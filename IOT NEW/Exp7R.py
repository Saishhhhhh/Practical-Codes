#Problem Statement:
#Lab Practical 7
#Create a program so that when the user enters:
#'b' - the green light blinks
#'g' - the green light is illuminated
#'y' - the yellow light is illuminated
#'r' - the red light is illuminated

import time
from gpiozero import LED

led_red = LED(7)
led_yellow = LED(22)
led_green = LED(23)

print("Enter:")
print("r - Red light ON")
print("y - Yellow light ON")
print("g - Green light ON")
print("b - Green light BLINK")

while True:
    key = input("Enter character: ").lower()
    print("Received:", key)
    
    # Turn all LEDs off first
    led_red.off()
    led_yellow.off()
    led_green.off()
    
    if key == 'r':
        led_red.on()
    elif key == 'y':
        led_yellow.on()
    elif key == 'g':
        led_green.on()
    elif key == 'b':
        print("Green LED blinking...")
        for i in range(5):
            led_green.on()
            time.sleep(0.5)
            led_green.off()
            time.sleep(0.5)
        print("Blinking finished")
    else:
        print("Try r, y, g, or b")