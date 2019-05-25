# 2019_ESPledRemote

## Overview 
Wireless lighting of the LED to the color specified by the user.
## Description  
The client mobile application sends via API using axios library the HTTP request to turn on the LED to the specified color.
The WiFi ESP 8266 module receive and process this query using NodeMCU.
The LED connected to the module lights up as specified in the HTTP request parameters.
Client device is on the same network as the WiFi module.

## Tools
1. Physical compontent:
    * ESP 8266 WiFi module
    * LED ring
2. Software:
    * NodeMCU - soft for ESP module
    * Arduino IDE - IDE for NodeMCU
    * WebStorm - IDE for mobile application
3. Programming languages:
    * C++
    * HTML
    * CSS (SCSS)
    * JavaScript (Vue.js)     
    
## How to run 
You need:
   * ESP8266 with NodeMCU
   * Adafruit NeoPixel WS2812 LED Ring.
Connect LED ring DIN and power to ESP.
## How to compile 
The app is installed via the Arduino IDE. The ESP8266 boards will need to be added to the Arduino IDE which is achieved as follows.
Click File > Preferences and copy and paste the URL "http://arduino.esp8266.com/stable/package_esp8266com_index.json" into the 
Additional Boards Manager URLs field. Click OK. Click Tools > Boards: ... > Boards Manager. Find and click on ESP8266 (using the Search 
function may expedite this). Click on Install. After installation, click on Close and then select your ESP8266 board from the Tools > 
Board: ... menu.
## License  
MIT
## Credits  
Szymon Grobelny, Szymon Biskup

The project was conducted during the Microprocessor Lab course held by the Institute of Control and Information Engineering, Poznan University of Technology.
Supervisor: Marek Kraft/Michał Fularz/Tomasz Mańkowski/Adam Bondyra

