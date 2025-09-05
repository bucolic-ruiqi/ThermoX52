# ThermoX52 🌡️

![Version](https://img.shields.io/badge/version-v2.0-blue)
![MCU](https://img.shields.io/badge/MCU-STC89C52-green)
![License](https://img.shields.io/badge/license-MIT-orange)

**Infrared Temperature Measurement System based on STC89C52 MCU with Bluetooth Connectivity**

[繁體中文](README_zh-TW.md) | [한국어](README_ko.md) | [简体中文](README_zh.md)

---

## 📋 Project Overview

ThermoX52 is a non-contact infrared temperature measurement system based on STC89C52 microcontroller. The system uses MLX90614 infrared temperature sensor for remote temperature detection, features LCD1602 display for real-time temperature data visualization, supports key operations for alarm threshold adjustment, and includes audio-visual alarm functionality with **wireless Bluetooth data transmission**.

## ✨ Key Features

- 🌡️ **Non-contact Temperature Measurement**: MLX90614 infrared sensor with ±0.5℃ accuracy
- 📺 **Real-time Display**: LCD1602 screen showing temperature and system status
- 🎮 **Key Control**: 3-key operation including temperature measurement and threshold adjustment
- 🚨 **Smart Alarm**: Automatic buzzer alarm for over-temperature conditions
- 📡 **Bluetooth Connectivity**: Wireless data transmission to mobile devices or computers
- 📊 **Circuit Diagram**: Complete schematic included (Schematic.pdf)
- 🔧 **Modular Design**: Clean code structure for easy maintenance and expansion
- 🐛 **Debug Support**: Complete hardware testing programs included

## 🎯 Core Features

- **Temperature Measurement**: Range -70℃~380℃, accuracy ±0.5℃
- **Real-time Display**: 16×2 character LCD showing temperature values and system information
- **Threshold Setting**: Adjustable temperature alarm threshold via keys (default 38℃)
- **Over-temperature Alarm**: Automatic buzzer alarm when temperature exceeds threshold
- **Bluetooth Communication**: Wireless data transmission for remote monitoring
- **Boot Animation**: ThermoX52 identification display on system startup
- **Circuit Diagram**: Complete schematic provided in Schematic.pdf

## 🎮 User Interface

- **KEY1**: Execute temperature measurement
- **KEY2**: Increase alarm threshold temperature
- **KEY3**: Decrease alarm threshold temperature

## 🏗️ System Architecture

```
ThermoX52/
├── src/                    # Source code directory
│   ├── main.c             # Main program entry
│   ├── delay.c/h          # Delay function module
│   ├── lcd1602.c/h        # LCD1602 display driver
│   ├── mlx90614.c/h       # MLX90614 temperature sensor driver
│   ├── i2c_soft.c/h       # Software I2C communication
│   ├── key.c/h            # Key scanning module
│   ├── buzzer.c/h         # Buzzer control module
│   ├── bluetooth.c/h      # Bluetooth communication module
│   └── type.h             # Type definitions
├── Schematic.pdf          # Circuit schematic diagram
└── README.md              # Project documentation
```

## ⚡ Quick Start


### � Compilation and Programming

1. **Environment Setup**
   ```bash
   # Ensure Keil C51 or SDCC compiler is installed
   # Prepare STC-ISP download software
   ```

2. **Compile Project**
   ```bash
   # Open project in Keil C51
   # Or use SDCC command line compilation
   sdcc main.c delay.c lcd1602.c mlx90614.c i2c_soft.c key.c buzzer.c bluetooth.c
   ```

3. **Program MCU**
   ```bash
   # Use STC-ISP to program hex file to STC89C52
   # Set download parameters: 12MHz crystal, 5V power supply
   ```

## 🔧 Usage Instructions
### Basic Operations

1. **System Startup**
   - Power on, LCD displays boot animation
   - System checks MLX90614 sensor connection status
   - Display "ThermoX52" main interface

2. **Temperature Measurement**
   - Press KEY1 to execute temperature measurement
   - LCD displays current measured temperature value
   - Format: `T:xx.xC`

3. **Threshold Setting**
   - Press KEY2 to increase alarm threshold
   - Press KEY3 to decrease alarm threshold
   - Display format: `Th:xxC`

4. **Alarm Function**
   - Automatic alarm when temperature exceeds set threshold
   - Buzzer sounds continuously 3 times
   - LCD displays "Warning!" warning message

5. **Bluetooth Communication**
   - Temperature data automatically transmitted via Bluetooth
   - Connect mobile device or computer to receive data
   - Real-time monitoring and data logging

### Status Indicators

| Display Content | Meaning |
|----------|------|
| `ThermoX52` | System ready |
| `Sensor OK` | Sensor connection normal |
| `Sensor Error!` | Sensor connection error |
| `T:xx.xC` | Current temperature value |
| `Th:xxC` | Current threshold setting |
| `Warning!` | Over-temperature alarm |
| `Read Error!` | Reading error |

## 📁 Code Documentation

- **main.c**: Main program flow control, user interface logic
- **delay.c/h**: Precise delay functions, supports microsecond and millisecond delays
- **lcd1602.c/h**: LCD1602 display driver, supports character display and cursor control
- **mlx90614.c/h**: MLX90614 sensor driver, implements temperature data reading
- **i2c_soft.c/h**: Software I2C protocol implementation, supports standard I2C timing
- **key.c/h**: Key scanning and debouncing processing
- **buzzer.c/h**: Buzzer control, supports multiple alarm modes
- **bluetooth.c/h**: Bluetooth communication module, wireless data transmission
- **type.h**: Common type definitions and constants

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details

## 👥 Authors

- **Developer**: Bucolic77
- **Project**: Circuit Comprehensive Innovation Practice
- **Time**: Autumn & Winter 2025

## 📞 Technical Support

If you have any questions or suggestions, please contact us through:

- 📧 Email: limerence051693@gmail.com
- 💬 Issues: [GitHub Issues](https://github.com/bucolic-ruiqi/ThermoX52/issues)
- 📋 Circuit Diagram: See `Schematic.pdf` for complete circuit schematic

## 🔗 Related Links

- [MLX90614 Datasheet](https://www.melexis.com/en/product/MLX90614/Digital-Plug-Play-Infrared-Thermometer-TO-Can)
- [STC89C52 Datasheet](http://www.stcmcudata.com/)
- [LCD1602 User Guide](https://www.sparkfun.com/datasheets/LCD/HD44780.pdf)
- [HC-05 Bluetooth Module Guide](https://components101.com/wireless/hc-05-bluetooth-module)

---

<div align="center">

**⭐ If this project helps you, please give it a Star! ⭐**

Made with ❤️ for learning and innovation

**🌡️ ThermoX52 - Smart Temperature Monitoring with Bluetooth 🌡️**

</div>

| Parameter | Specification |
|------|------|
| **Microcontroller** |
| Model | STC89C52 |
| Clock Frequency | 12MHz |
| Operating Voltage | 5V |
| **Temperature Sensor** |
| Model | MLX90614ESF-BAA |
| Measurement Range | -70℃ ~ +380℃ |
| Accuracy | ±0.5℃ @ 0℃~50℃ |
| Field of View | 90° |
| Communication Interface | I2C (SMBus compatible) |
| **Display** |
| Model | LCD1602 |
| Display Characters | 16×2 characters |
| Backlight | Blue LED backlight |
| **Bluetooth** |
| Module | HC-05/06 |
| Protocol | Bluetooth 2.0 |
| Range | 10 meters |
| Baud Rate | 9600 bps |
| **Other** |
| Key Quantity | 4 tactile switches |
| Alarm Method | Active buzzer |
| Power Consumption | < 150mA @ 5V |

## 📁 Code Documentation

### Module Functions

- **main.c**: Main program flow control, user interface logic
- **delay.c/h**: Precise delay functions, supports microsecond and millisecond delays
- **lcd1602.c/h**: LCD1602 display driver, supports character display and cursor control
- **mlx90614.c/h**: MLX90614 sensor driver, implements temperature data reading
- **i2c_soft.c/h**: Software I2C protocol implementation, supports standard I2C timing
- **key.c/h**: Key scanning and debouncing processing
- **buzzer.c/h**: Buzzer control, supports multiple alarm modes
- **bluetooth.c/h**: Bluetooth communication module, wireless data transmission
- **type.h**: Common type definitions and constants

### Code Features

- ✅ **Complete Documentation**: All code with detailed comments
- ✅ **Modular Design**: Independent functional modules for easy maintenance and expansion
- ✅ **Error Handling**: Includes sensor connection detection and read error processing
- ✅ **User Experience**: Boot animation, status prompts, operation feedback
- ✅ **Debug Support**: Complete hardware testing programs
- ✅ **Bluetooth Integration**: Seamless wireless communication capability

## 🤝 Contributing

Welcome to submit issues and improvement suggestions!

1. Fork this project
2. Create feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to branch (`git push origin feature/AmazingFeature`)
5. Open Pull Request

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details

## 👥 Authors

- **Developer**: ThermoX52 Team
- **Project**: Circuit Comprehensive Innovation Practice
- **Time**: Autumn & Winter 2025

## 📞 Technical Support

If you have any questions or suggestions, please contact us through:

- 📧 Email: [Contact via GitHub Issues]
- 💬 Issues: [GitHub Issues](https://github.com/bucolic-ruiqi/ThermoX52/issues)
- 📋 Circuit Diagram: See `Schematic.pdf` for complete circuit schematic

## 🔗 Related Links

- [MLX90614 Datasheet](https://www.melexis.com/en/product/MLX90614/Digital-Plug-Play-Infrared-Thermometer-TO-Can)
- [STC89C52 Datasheet](http://www.stcmcudata.com/)
- [LCD1602 User Guide](https://www.sparkfun.com/datasheets/LCD/HD44780.pdf)
- [HC-05 Bluetooth Module Guide](https://components101.com/wireless/hc-05-bluetooth-module)

---

<div align="center">

**⭐ If this project helps you, please give it a Star! ⭐**

Made with ❤️ for learning and innovation

**🌡️ ThermoX52 - Smart Temperature Monitoring with Bluetooth 🌡️**

</div>
