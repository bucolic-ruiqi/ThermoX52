# ThermoX52 🌡️

![Version](https://img.shields.io/badge/version-v2.0-blue)
![MCU](https://img.shields.io/badge/MCU-STC89C52-green)
![License](https://img.shields.io/badge/license-MIT-orange)

[English](#english) | [繁體中文](#繁體中文)

---

## English

**Infrared Temperature Measurement System based on STC89C52 MCU with Bluetooth Connectivity**

### 📋 Project Overview

ThermoX52 is a non-contact infrared temperature measurement system based on STC89C52 microcontroller. The system uses MLX90614 infrared temperature sensor for remote temperature detection, features LCD1602 display for real-time temperature data visualization, supports key operations for alarm threshold adjustment, and includes audio-visual alarm functionality with **wireless Bluetooth data transmission**.

### ✨ Key Features

- 🌡️ **Non-contact Temperature Measurement**: MLX90614 infrared sensor with ±0.5℃ accuracy
- 📺 **Real-time Display**: LCD1602 screen showing temperature and system status
- 🎮 **Key Control**: 3-key operation including temperature measurement and threshold adjustment
- 🚨 **Smart Alarm**: Automatic buzzer alarm for over-temperature conditions
- 📡 **Bluetooth Connectivity**: Wireless data transmission to mobile devices or computers
- 📊 **Circuit Diagram**: Complete schematic included (Schematic.pdf)
- 🔧 **Modular Design**: Clean code structure for easy maintenance and expansion
- 🐛 **Debug Support**: Complete hardware testing programs included

---

## 繁體中文

**基於STC89C52單片機的MLX90614紅外溫度測量系統，支援藍牙連線**

### 📋 專案簡介

ThermoX52是一個基於STC89C52單片機的非接觸式紅外溫度測量系統。該系統使用MLX90614紅外溫度感測器實現遠端溫度檢測，配備LCD1602顯示螢幕即時顯示溫度資料，支援按鍵操作調節警報門檻，並具備聲光警報功能以及**無線藍牙資料傳輸**。

### ✨ 主要特性

- 🌡️ **非接觸式測溫**：基於MLX90614紅外感測器，測量精度±0.5℃
- 📺 **即時顯示**：LCD1602液晶螢幕顯示溫度和系統狀態
- 🎮 **按鍵控制**：支援3個按鍵操作，包括測溫和門檻調節
- 🚨 **智慧警報**：超溫自動蜂鳴器警報
- 📡 **藍牙連線**：無線資料傳輸至手機或電腦
- 📊 **電路圖**：完整電路原理圖（Schematic.pdf）
- 🔧 **模組化設計**：程式碼結構清晰，便於維護和擴展
- 🐛 **偵錯支援**：提供完整的硬體測試程式

## 🎯 Core Features / 核心功能

### English
- **Temperature Measurement**: Range -70℃~380℃, accuracy ±0.5℃
- **Real-time Display**: 16×2 character LCD showing temperature values and system information
- **Threshold Setting**: Adjustable temperature alarm threshold via keys (default 38℃)
- **Over-temperature Alarm**: Automatic buzzer alarm when temperature exceeds threshold
- **Bluetooth Communication**: Wireless data transmission for remote monitoring
- **Boot Animation**: ThermoX52 identification display on system startup
- **Circuit Diagram**: Complete schematic provided in Schematic.pdf

### 繁體中文
- **溫度測量**：測量範圍-70℃~380℃，精度±0.5℃
- **即時顯示**：16×2字元LCD顯示溫度值和系統資訊
- **門檻設定**：可透過按鍵調節溫度警報門檻（預設38℃）
- **超溫警報**：溫度超過門檻時蜂鳴器自動警報
- **藍牙通訊**：無線資料傳輸，支援遠端監控
- **開機動畫**：系統啟動時顯示ThermoX52標識
- **電路圖**：Schematic.pdf提供完整電路原理圖

## 🎮 User Interface / 使用介面

### English
- **KEY1**: Execute temperature measurement
- **KEY2**: Increase alarm threshold temperature
- **KEY3**: Decrease alarm threshold temperature


### 繁體中文
- **KEY1**：執行溫度測量
- **KEY2**：提高警報門檻溫度
- **KEY3**：降低警報門檻溫度


## 🏗️ System Architecture / 系統架構

```
ThermoX52/
├── src/                    # Source code directory / 原始碼目錄
│   ├── main.c             # Main program entry / 主程式入口
│   ├── delay.c/h          # Delay function module / 延時函數模組
│   ├── lcd1602.c/h        # LCD1602 display driver / LCD1602顯示驅動
│   ├── mlx90614.c/h       # MLX90614 temperature sensor driver / MLX90614溫度感測器驅動
│   ├── i2c_soft.c/h       # Software I2C communication / 軟體I2C通訊協定
│   ├── key.c/h            # Key scanning module / 按鍵掃描模組
│   ├── buzzer.c/h         # Buzzer control module / 蜂鳴器控制模組
│   ├── bluetooth.c/h      # Bluetooth communication module / 藍牙通訊模組
│   └── type.h             # Type definitions / 型別定義
├── Schematic.pdf          # Circuit schematic diagram / 電路原理圖
└── README.md              # Project documentation / 專案說明文件
```

## ⚡ Quick Start / 快速開始

### 📦 Hardware Requirements / 硬體需求

| Component / 組件 | Model / 型號 | Quantity / 數量 | Description / 說明 |
|------|------|------|------|
| Microcontroller / 單片機 | STC89C52 | 1 | Main controller / 主控制器 |
| Temperature Sensor / 溫度感測器 | MLX90614 | 1 | Infrared temperature sensor / 紅外溫度感測器 |
| Display / 顯示螢幕 | LCD1602 | 1 | Character LCD display / 字元液晶顯示螢幕 |
| Keys / 按鍵 | Tactile switch / 輕觸開關 | 4 | User interaction keys / 使用者互動按鍵 |
| Buzzer / 蜂鳴器 | Active buzzer / 有源蜂鳴器 | 1 | Audio alarm / 聲音警報 |
| Bluetooth Module / 藍牙模組 | HC-05/06 | 1 | Wireless communication / 無線通訊 |
| Crystal / 晶振 | 12MHz | 1 | System clock / 系統時鐘 |
| Resistor / 電阻 | 10kΩ | 4 | Key pull-up resistors / 按鍵上拉電阻 || Resistor / 電阻 | 4.7kΩ | 2 | I2C pull-up resistors / I2C上拉電阻 |


### 🚀 Compilation and Programming / 編譯和燒錄

#### English
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

#### 繁體中文
1. **環境準備**
   ```bash
   # 確保安裝了Keil C51或SDCC編譯器
   # 準備STC-ISP下載軟體
   ```

2. **編譯專案**
   ```bash
   # 在Keil C51中開啟專案
   # 或使用SDCC命令行編譯
   sdcc main.c delay.c lcd1602.c mlx90614.c i2c_soft.c key.c buzzer.c bluetooth.c
   ```

3. **燒錄程式**
   ```bash
   # 使用STC-ISP燒錄hex檔案到STC89C52
   # 設定下載參數：12MHz晶振，5V供電
   ```

## 🔧 Usage Instructions / 使用說明

### Basic Operations / 基本操作

#### English
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

#### 繁體中文
1. **系統啟動**
   - 接通電源，LCD顯示開機動畫
   - 系統自檢MLX90614感測器連接狀態
   - 顯示"ThermoX52"主介面

2. **溫度測量**
   - 按下KEY1執行溫度測量
   - LCD顯示當前測量溫度值
   - 格式：`T:xx.xC`

3. **門檻設定**
   - 按KEY2提高警報門檻
   - 按KEY3降低警報門檻
   - 顯示格式：`Th:xxC`

4. **警報功能**
   - 溫度超過設定門檻時自動警報
   - 蜂鳴器連續鳴叫3次
   - LCD顯示"Warning!"警告訊息

5. **藍牙通訊**
   - 溫度資料自動透過藍牙傳輸
   - 連接手機或電腦接收資料
   - 即時監控和資料記錄

### Status Indicators / 狀態指示

| Display Content / 顯示內容 | Meaning (English) / 含義 (繁體中文) |
|----------|------|
| `ThermoX52` | System ready / 系統就緒狀態 |
| `Sensor OK` | Sensor connection normal / 感測器連接正常 |
| `Sensor Error!` | Sensor connection error / 感測器連接異常 |
| `T:xx.xC` | Current temperature value / 當前溫度值 |
| `Th:xxC` | Current threshold setting / 當前門檻設定 |
| `Warning!` | Over-temperature alarm / 超溫警報 |
| `Read Error!` | Reading error / 讀取錯誤 |


## 📁 Code Documentation / 程式碼說明

#### English
- **main.c**: Main program flow control, user interface logic
- **delay.c/h**: Precise delay functions, supports microsecond and millisecond delays
- **lcd1602.c/h**: LCD1602 display driver, supports character display and cursor control
- **mlx90614.c/h**: MLX90614 sensor driver, implements temperature data reading
- **i2c_soft.c/h**: Software I2C protocol implementation, supports standard I2C timing
- **key.c/h**: Key scanning and debouncing processing
- **buzzer.c/h**: Buzzer control, supports multiple alarm modes
- **bluetooth.c/h**: Bluetooth communication module, wireless data transmission
- **type.h**: Common type definitions and constants

#### 繁體中文
- **main.c**：主程式流程控制，使用者介面邏輯
- **delay.c/h**：精確延時函數，支援微秒和毫秒級延時
- **lcd1602.c/h**：LCD1602顯示驅動，支援字元顯示和光標控制
- **mlx90614.c/h**：MLX90614感測器驅動，實現溫度資料讀取
- **i2c_soft.c/h**：軟體I2C協定實現，支援標準I2C時序
- **key.c/h**：按鍵掃描與消抖處理
- **buzzer.c/h**：蜂鳴器控制，支援多種警報模式
- **bluetooth.c/h**：藍牙通訊模組，無線資料傳輸
- **type.h**：通用型別定義和常數


## 📄 License / 許可證

**English**: This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details

**繁體中文**: 本專案採用 MIT 許可證 - 查看 [LICENSE](LICENSE) 檔案了解詳情

## 👥 Authors / 作者

- **Developer / 開發者**: ThermoX52 Team
- **Project / 專案**: Circuit Comprehensive Innovation Practice / 電路綜合創新實踐
- **Time / 時間**: Autumn & Winter 2025 / 2025年秋冬學期

## 📞 Technical Support / 技術支援

#### English
If you have any questions or suggestions, please contact us through:

- 📧 Email: limerence051693@gmail.com
- 💬 Issues: [GitHub Issues](https://github.com/bucolic-ruiqi/ThermoX52/issues)
- 📋 Circuit Diagram: See `Schematic.pdf` for complete circuit schematic

#### 繁體中文
如有問題或建議，請透過以下方式聯絡：

- � 電子郵件: limerence051693@gmail.com
- 💬 問題回報: [GitHub Issues](https://github.com/bucolic-ruiqi/ThermoX52/issues)
- 📋 電路圖: 查看 `Schematic.pdf` 了解完整電路原理圖

## 🔗 Related Links / 相關連結

#### English
- [MLX90614 Datasheet](https://www.melexis.com/en/product/MLX90614/Digital-Plug-Play-Infrared-Thermometer-TO-Can)
- [STC89C52 Datasheet](http://www.stcmcudata.com/)
- [LCD1602 User Guide](https://www.sparkfun.com/datasheets/LCD/HD44780.pdf)
- [HC-05 Bluetooth Module Guide](https://components101.com/wireless/hc-05-bluetooth-module)

#### 繁體中文
- [MLX90614數據手冊](https://www.melexis.com/en/product/MLX90614/Digital-Plug-Play-Infrared-Thermometer-TO-Can)
- [STC89C52數據手冊](http://www.stcmcudata.com/)
- [LCD1602使用指南](https://www.sparkfun.com/datasheets/LCD/HD44780.pdf)
- [HC-05藍牙模組指南](https://components101.com/wireless/hc-05-bluetooth-module)

---

<div align="center">

**⭐ If this project helps you, please give it a Star! / 如果這個專案對您有幫助，請給它一個Star！⭐**

Made with ❤️ for learning and innovation / 用❤️為學習和創新而製作

**🌡️ ThermoX52 - Smart Temperature Monitoring with Bluetooth / 智慧溫度監控，支援藍牙 🌡️**

</div>
