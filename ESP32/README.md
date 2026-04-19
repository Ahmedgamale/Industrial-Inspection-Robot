# 🤖 Industrial Inspection Robot

AI-based industrial robot for automated product inspection using multiple sensors and embedded systems.

---

## 🚀 Features
- Spectral analysis using AS7265x
- Gas detection (MQ135)
- Temperature & humidity monitoring (DHT11)
- Motion detection (PIR)
- Sound detection (Microphone)
- Soil/moisture sensing
- Infrared temperature measurement (MLX90614)
- Real-time clock (DS3231)
- LCD display interface
- I2C multiplexer (TCA9548A) for multi-device management

---

## 🧠 System Architecture
The system is divided into:

### 🔹 ESP32
- Handles sensor data collection
- Manages I2C devices via multiplexer
- Sends data for processing

### 🔹 Raspberry Pi (Planned)
- Computer Vision processing
- AI decision making
- Web interface

---

## Project Structure
Industrial-Inspection-Robot/
│
├── ESP32/
│ ├── as7265x_test.ino
│ └── tca_multi_device_system.ino
│
├── AI_Model/
├── RaspberryPi/
├── Sensors/


---

## 🛠️ Hardware Components
- ESP32
- AS7265x Spectral Sensor
- MLX90614 IR Sensor
- MQ135 Gas Sensor
- DHT11 Sensor
- PIR Motion Sensor
- Microphone Sensor
- Soil Sensor
- DS3231 RTC
- I2C LCD
- TCA9548A I2C Multiplexer

---

## 🎯 Project Goal
To reduce waste and improve efficiency in industrial production by automating product inspection using AI and sensor fusion.

---

## 📌 Status
🚧 In Progress
