from gpiozero import LED
import time

# Using pin 4 which corresponds to physical pin 7 in BOARD mode
led = LED(4)

for i in range(10):
    led.on()
    print("LED IS FINALLY ON")
    
    time.sleep(1)
    
    led.off()
    print("LED IS OFF")
    
    time.sleep(1)

print("PROGRAM COMPLETE!")
# No need for cleanup - gpiozero handles this automatically