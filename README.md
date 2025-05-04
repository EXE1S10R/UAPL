# Arduino People Counter

A simple project that counts people entering and exiting using two light sensors (BPW34), an Arduino Uno, and an HC-05 Bluetooth module.  
Data is printed in the Serial Monitor (in English) and sent over Bluetooth (in English).

---

## Contents

- [Description](#description)  
- [Parts](#parts)  
- [Wiring](#wiring)  
- [Setup](#setup)  
- [Usage](#usage)  
- [Code](#code)  
- [License](#license)  

---

## Description

- Two sensors are placed about 5 cm apart.  
- Arduino watches which sensor trips first to tell entry vs exit.  
- Messages go to Serial Monitor and to a Bluetooth device.

---

## Parts

- Arduino Uno  
- 2 × BPW34 light sensors  
- HC-05 Bluetooth module  
- 2 × 10 kΩ resistors (optional pull-ups)  
- Breadboard and jumper wires  
- USB cable  

---

## Wiring

