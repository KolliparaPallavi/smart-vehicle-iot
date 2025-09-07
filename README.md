# Smart Vehicle using Internet of Things (IoT)

## Overview
This project aims to enhance vehicle safety using IoT technology. It focuses on preventing accidents caused by drunk driving, over-speeding, and emergency situations. The system allows parents to monitor and control the vehicle remotely via an app.

### Key Features
1. **Automatic Engine Locking**
   - Alcohol sensor detects intoxicated drivers.
   - Sends instant notifications to parents.
   - Prevents the vehicle from starting if alcohol is detected.

2. **SOS Emergency Button**
   - Pressing the SOS button 3 times within 10 seconds sends notifications to parents and nearby police with GPS coordinates.

3. **Speed Control**
   - Parents can set speed limits through a mobile app.
   - Cloud stores the speed settings and hardware enforces the limits using PWM and L293D motor driver.

## Hardware Used
- Arduino Uno
- NodeMCU (ESP8266)
- L293D Motor Driver
- Alcohol Sensor
- Push Buttons (SOS and directional)
- Motors for vehicle simulation

## Software Tools
- Arduino IDE
- madBlocks library for NodeMCU
- Serial communication for SMS notifications
- Cloud integration for speed control

## How It Works
1. The Arduino reads sensor inputs (alcohol, speed, SOS button).
2. NodeMCU fetches cloud data (speed limits) via WiFi.
3. SMS alerts are sent to parents and police when necessary.
4. Vehicle speed is automatically adjusted to the preset limits.

## Demo
- Alcohol Detection and Notification  
- Speed Control with Cloud Integration  
- SOS Button Emergency Alerts  

## Code
- **Arduino:** `arduino/smart_vehicle.ino`  
- **NodeMCU:** `nodemcu/nodemcu_iot.ino`

## License
This project is open-source under the MIT License.
