#Lab Practical 12
#Understanding the connectivity of Raspberry-Pi /Beagle board circuit / Arduino with IR sensor. Write an application to detect obstacle and notify user using LEDs.


from gpiozero import LED, DigitalInputDevice
import time

ir_sensor = DigitalInputDevice(9, pull_up=False)
led = LED(4)

print("IR OBSTACLE DETECTION STARTED")


for i in range(150):  
    
    if ir_sensor.value == 0:  
        
        led.off()
        print("OBSTACLE DETECTED - LED OFF")
    else:
        # Turn on LED when no obstacle
        led.on()
        print("NO OBSTACLE - LED ON")
        
   
    time.sleep(0.2)

print("PROGRAM COMPLETE!")