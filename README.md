![Arduino](https://img.shields.io/badge/Platform-Arduino-blue)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Status](https://img.shields.io/badge/Status-In%20Development-green)

<img src="https://raw.githubusercontent.com/github/explore/main/topics/arduino/arduino.png" alt="Arduino Logo" width="60"/>

# Autonomous-F1-Car 
This is the repository for the Schoolcraft Engineering Club's Autonomous RC Car.

---

## Features

  - IR line following
  - Autonomous steering
  - Pixy2 vision tracking (Traffic Light Detection)

## Setup
  
  1. Install Arduino IDE
  2. Install required libraries:
     - Pixy2
     - Servo
  3. Connect Arduino Nano
  4. Upload `IRSensorCode.ino`

## Required Arduino Libraries:

  - Pixy2
  - Servo

## Files/Structure:

  - ### Main Arduino File:
    ```text
    <Filename>.ino
    ```
  - ### Header Files (Class and function declarations): <Filename>.hpp
  - ### Source Files (Class and function definitions/implementations): <Filename>.cpp

## How to Add Features:

  1. Create .hpp header file for desired purpose.
  2. Create a corresponding .cpp source file for implementation of the previous declarations.
  3. Include the newly created header file and implement the desired logic.

## Conventions:

  - ### Naming Conventions
      - Classes use *PascalCase*.
        Ex: 
        ```cpp
        class TestClass {}
        ```
      - Functions/Variables use *camelCase*.
        Ex:
        ```cpp
        <return_type> testFunction(<parameter_type> testVar) {}
        ```
      - Constants use *UPPERCASE*.
        Ex:
        ```cpp
        #define PIN_1 1
        ```

## Hardware

| Component | Model / Description |
|---|---|
| Microcontroller | Arduino Nano |
| Vision Sensor | Pixy2 Smart Vision Sensor |
| PCB | Custom PCB |
| Motor Driver | L293 Motor Driver |
| IR Sensors | 6x TCRT5000 IR Sensors |
| Servo Motor | MG90S |
| DC Motor | 540 Brushed Motor |
| Battery | 2200mAh 7.4V LiPo Battery *(Any battery capable of powering both the DC motor and Arduino is sufficient)* |

### PCB
  <details>
    <summary>PCB Schematics</summary>
    <img width="540" height="400" alt="AutonomousDrivingDiagram" src="https://github.com/user-attachments/assets/f6952d57-76e0-4def-b580-c2eb2910e4d1" />
  </details>
  
### Connections
 <details>
    <summary>Tinkercad Design</summary>
    <img width="2560" height="1180" alt="Autonomous Driving F1 Car" src="https://github.com/user-attachments/assets/1e04c08d-e821-4c5a-ad17-0cc251e29ae1" />
  </details>

  - <a href="https://www.tinkercad.com/things/8e6ZMUtTsOs-autonomous-driving-f1-car/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2Fcircuits">Tinkercad Link</a>

---

#### *Useful Links:*
- <a href="https://www.circuit-diagram.org/">Schematics Creation Tool</a>

- <a href="https://www.tinkercad.com/">Tinkercad</a>

  

