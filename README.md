# 🏠 Smart Home Automation & Security Solutions

A collection of modular IoT and embedded systems designed to enhance home safety, security, and environmental automation using Arduino and specialized sensors.

## 🚀 Overview
This repository contains five distinct projects that solve real-world household challenges, ranging from automated weather protection to secure access control. Each project is designed with a "Plug-and-Play" mindset for modern smart home integration.

---

## 🛠️ Included Projects

### 1. 🛡️ Intelligent Intruder Detection (Motion Sensor)
* **What it does:** Uses a PIR (Passive Infrared) sensor to monitor for movement. When triggered, it activates a high-decibel alarm.
* **Key Components:** HC-SR501 PIR Sensor, Piezo Buzzer.
* **Use Case:** Entryway security and night-time monitoring.

### 2. 🌧️ Climate-Adaptive Entryway (Rain Sensor)
* **What it does:** Detects raindrops on a specialized sensor plate. Upon detection, it triggers a servo motor to automatically deploy a protective cover over a door or window.
* **Key Components:** Raindrop Sensor Module, MG995/SG90 Servo Motor.
* **Use Case:** Protecting balcony furniture or doorways from sudden tropical rain.

### 3. 🔑 Secure RFID Access Control
* **What it does:** A keyless entry system that reads UID tags. It grants access (unlocks a solenoid or motor) only to authorized IDs while logging unauthorized attempts.
* **Key Components:** RC522 RFID Module, 13.56MHz Key Fobs.
* **Use Case:** Modernizing home or office door locks without physical keys.

### 4. ⚠️ Multi-Hazard Fire & Gas Alarm
* **What it does:** A dual-layer safety system. The MQ2 sensor monitors for smoke/combustible gas, while the HW484 flame sensor detects infrared light from fire.
* **Key Components:** MQ2 Smoke Sensor, HW484 Flame Sensor, Active Buzzer.
* **Use Case:** Early warning systems for kitchens or workshop areas.

---

## 📂 Project Structure
Each project is contained within its own folder:
- `/Intruder-Motion-Sensor` -> `.ino` source code & wiring diagrams
- `/Rain-Sensing-Door` -> Logic for motor-actuated rain protection
- `/RFID-Security-Lock` -> Tag authorization database and lock control
- `/Fire-Smoke-Alarm` -> Threshold-based safety logic

## 🔧 Getting Started
1. Clone this repository: `git clone https://github.com/YourUsername/Smart-Home-Automation-Solutions.git`
2. Open the desired `.ino` file in the **Arduino IDE**.
3. Install required libraries (e.g., `MFRC522` for RFID).
4. Upload to your Arduino Uno/ESP32 and follow the circuit diagrams provided in each folder.

---
*Developed as part of a personal portfolio in Mechatronics and IoT Systems.*
