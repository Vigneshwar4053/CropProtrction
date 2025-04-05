# 🌧️ Rain-Sensor Based Motor Direction Control System

This Arduino project demonstrates how to control motor direction based on rain detection using a rain sensor. The system simulates an automatic mechanism that reacts to rain by rotating motors in one direction and reverses direction when the rain stops.

---

## 🛠 Features

- 🚦 **Real-time Sensor Monitoring**  
- 🔄 **Motor Rotation Based on Rain Logic**  
  - **Rain Detected (LOW)** → Clockwise Rotation (5 seconds)  
  - **No Rain (HIGH)** → Anti-Clockwise Rotation (5 seconds)  
- 🧠 **State-Based Logic** to prevent unnecessary re-triggering  
- ⏹️ **Motor Auto-Stop** after each operation

---

## 🔧 Components Used

| Component        | Quantity |
|------------------|----------|
| Arduino Uno      | 1        |
| Rain Sensor (YL-83 or similar) | 1 |
| L298N Motor Driver | 1        |
| DC Motors        | 2        |
| Power Supply     | 1        |
| Jumper Wires     | As needed |

---

## ⚡ Wiring Diagram

| Arduino Pin | Connected To                  |
|-------------|-------------------------------|
| D2          | Rain Sensor OUT               |
| D3          | L298N IN1                     |
| D4          | L298N IN2                     |
| D5          | L298N IN3                     |
| D6          | L298N IN4                     |
| D9          | L298N ENA (Enable Motor A)    |
| D10         | L298N ENB (Enable Motor B)    |

*Ensure both ENA and ENB pins are also connected to +5V through PWM pins.*

---

## 🧠 Logic Flow

1. System initializes and waits for sensor input.
2. If rain is detected (`LOW` from sensor), motors rotate clockwise for 5 seconds and stop.
3. If rain stops (`HIGH` from sensor), motors rotate anti-clockwise for 5 seconds and stop.
4. Motors only react if the sensor state changes from the previous state.

---


---

## 📺 Serial Monitor Output

```text
System Ready...
Rain Sensor State Changed: 0
🌧 Rain Detected! Rotating Clockwise...
⏹ Stopping motors...
Rain Sensor State Changed: 1
☀️ No Rain! Rotating Anti-Clockwise...
⏹ Stopping motors...

Watch the video demo here:https://youtu.be/rlASbONKGTk?si=oKATH1VUojZu6ArC


