
# Arduino People Counter

A versatile project that counts people entering and exiting a space using two BPW34 light sensors, an Arduino Uno, and an HC-05 Bluetooth module. Designed for integration into demonstrations, resumes, and technical showcases, this system was featured at the "Engineers of the Future" conference held at MIREA University.

---

## Contents

- [Overview](#overview)  
- [Parts List](#parts-list)  
- [Wiring](#wiring)  
- [Setup](#setup)  
- [How It Works](#how-it-works)  
- [License](#license)  

---

## Overview

- Device is designed for mounting in a door frame.  
- Two BPW34 sensors are placed approximately 5 cm apart on a breadboard.  
- The Arduino monitors the order in which sensors are triggered to determine entries and exits.  
- Results can be viewed live in the Serial Monitor and transmitted via Bluetooth to a companion device.  
- A 1.5-second timeout resets the system if the expected sensor sequence is not completed.  
- Project showcased at the **"Engineers of the Future"** conference, MIREA University.  

---

## Parts List

- **Arduino Uno**  
- **2 × BPW34 light sensors**  
- **HC-05 Bluetooth module**  
- **2 × 10 kΩ resistors** (optional for pull-ups)  
- Breadboard and jumper wires  
- USB cable  

---

## Wiring

```text
BPW34 #1 (entry)  → A1  
BPW34 #2 (exit)   → A0  
All GND           → GND (Arduino)  
HC-05 VCC         → 5 V (Arduino)  
HC-05 GND         → GND (Arduino)  
HC-05 TX          → D10 (Arduino RX)  
HC-05 RX          → D11 (Arduino TX)  
````

---

## Setup

1. Assemble components on the breadboard according to the wiring diagram above.
2. Install the device in a standard door frame for accurate detection.
3. Open Arduino IDE and select **Arduino Uno** as the target board.
4. Load the provided sketch from the GitHub repository in `mainCode/code` and upload it to the Arduino.
5. Power the system via USB or external 5 V supply.

---

## How It Works

1. **Idle**: System waits for either sensor to detect an object.
2. **Entry**: Sensor 1 triggers first, then Sensor 2 confirms the passage → increment count.
3. **Exit**: Sensor 2 triggers first, then Sensor 1 confirms the passage → decrement count.
4. **Timeout**: If confirmation does not occur within 1.5 s, the state resets to idle.

Live data can be monitored in the Arduino Serial Monitor or received by an external device via Bluetooth.

---

## License

This project is licensed under the **MIT License**.

```
```

