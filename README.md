# RPIPicoHC-SR04
Experiment projects for the RPI Pico to use HC-SR04 Ultrasound range sensor.

This repo contains a number of projects to explore the HC-SR04. I talk through these on my YouTube channel [DrJonEA](https://youtube.com/@drjonea)

## GPIOInt

Single sensor on reading value in mm.  Uses a GPIO Interrupt to read the distance. 

Sensor:
- Trigger GP14
- Echo GP15 (Use a voltage divider to drop 5V to 3.3V for input)

STDIO is set is UART over GP16 & 17



## QuadGPIOInt

Four sensors reading value in mm. Uses a GPIO Interrupt to read the distance. 

Sensor:
- Trigger GP 2, 4, 6, 8
- Echo GP3, 5, 7, 9 (Use a voltage divider to drop 5V to 3.3V for input)
Echo is always the next GPIO pad to the Trigger

STDIO is set is UART over GP16 & 17


## QuadGPIntSharedTrigger

Four sensors reading value in mm. Uses a GPIO Interrupt to read the distance. 

Sensor:
- Trigger GP 2, 3, 4, 5
- Echo GP0 (Use a voltage divider to drop 5V to 3.3V for input)
Sharing trigger across all four sensors

STDIO is set is UART over GP16 & 17

## QuadPIO

Four sensors  reading value in cm.  Using an excellent library [pico distance sensor](https://github.com/dangarbri/pico-distance-sensor)

Sensor:
- Trigger GP 2, 4, 6, 8
- Echo GP3, 5, 7, 9 (Use a voltage divider to drop 5V to 3.3V for input)
Echo is always the next GPIO pad to the Trigger

STDIO is set is UART over GP16 & 17


