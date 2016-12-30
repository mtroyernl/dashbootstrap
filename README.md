# dashbootstrap

Created by Mark Troyer & Fons Janssen -  30 December 2016

This respository explains how to build a DASH-link button circuit.  The highlights of this circuit are as follows:

- Ideal for battery applications triggered by momentary push button.
- ESP8266 completely turned off through Arduino ESP8266 software command
- Less than 0.5uA consumed while WeMos D1 Mini is powered off (leakage from PNP transistor)
- Bootstrap sequence allows for the startup of the ESP8266
- Open collector configuration workaround using Arduino IDE on ESP8266
- Hardware concept can be modeled around any microprocessor.

The Bill of Materials are as follows:

- Wemos D1 Mini (ESP8266)
- BC638 PHP transistor
- 100 Ohm transistor
- Momentary switch
- Blue LED

While not explicitly supported on the ESP8266 in the Arduino IDE, this circuit uses a open collector configuration with the PNP transistor base to energize the ESP8266.  The PNP Transistor will be initially boot strapped with the momentary button being pulled to ground.   Once the ESP8266 starts, the open collector configuration will persist with the "pinMode(D5, OUTPUT); digitalWrite(D5, LOW);" commands.  

When the processing on the ESP8266 is complete, the open collector will be closed with the "pinMode(D5, INPUT);" command.  The Blue LED on D2 is only used to signal that the Wemos D1 Mini is energized.

Hardware Connections:

3.3v supply--transistor emitter
transistor collector--3.3v on Wemos
GND supply--GND on Wemos
transistor base--resistor--switch--GND.
D5 pin linked to resistor--switch junction.
D2 pin--Blue LED--GND
