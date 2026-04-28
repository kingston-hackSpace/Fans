# Fans (5-12V only)

⚠️ Note: This tutorial is for ***low-voltage DC fans only***. DO NOT connect high-voltage AC fans devices!

---
### STEP 1: WIRING

Follow [this tutorial](https://github.com/kingston-hackSpace/12V_devices_with_Arduino/tree/main) to safety wire your fan to the Arduino using an IRLZ44N N‑channel MOSFET.

Make sure:

- The fan is powered from an external 5–12 V supply

- The Arduino and power supply share a common ground

---
### STEP 2: BASIC PROGRAMMING

Download and upload [this code to your Arduino board](https://github.com/kingston-hackSpace/Fans/blob/main/fan_basic.ino)

This example uses PWM to control the fan speed.

---
### STEP 3: TRIGGER A FAN WITH A SENSOR

The following example shows how to turn the fan on or off based on sensor input.

In this case we will use an ultrasonic sensor. 

Before continuing, follow [this ultrasonic sensor tutorial](https://github.com/kingston-hackSpace/Distance_Sensors/blob/main/Ultrasonic.md) to understand how the sensor works and how to wire it correctly.

Once completed, download and upload [this code to your Arduino board] to link the sensor to the fan control.
