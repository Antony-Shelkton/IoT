import RPi.GPIO as GPIO
import time
GPIO.setwarnings(False)
GPIO.setnode(GPIO.BOARD)
GPIO.setup(11,GPIO.OUT,initial=GPIO.LOW)
while True:
    GPIO.output(11,GPIO,HIGH)
    time.sleep(1)
    GPIO.output(11,GPIO,LOW)
