# ThermoX52 🌡️

![Version](https://img.shields.io/badge/version-v2.0-blue)
![MCU](https://img.shields.io/badge/MCU-STC89C52-green)
![License](https://img.shields.io/badge/license-MIT-orange)

**基於STC89C52單片機的MLX90614紅外溫度測量系統，支援藍牙連線**

[English](README_en.md) | [한국어](README_ko.md) | [简体中文](README_zh.md)

---

## 📋 專案簡介

ThermoX52是一個基於STC89C52單片機的非接觸式紅外溫度測量系統。該系統使用MLX90614紅外溫度感測器實現遠端溫度檢測，配備LCD1602顯示螢幕即時顯示溫度資料，支援按鍵操作調節警報門檻，並具備聲光警報功能以及**無線藍牙資料傳輸**。

## ✨ 主要特性

- 🌡️ **非接觸式測溫**：基於MLX90614紅外感測器，測量精度±0.5℃
- 📺 **即時顯示**：LCD1602液晶螢幕顯示溫度和系統狀態
- 🎮 **按鍵控制**：支援3個按鍵操作，包括測溫和門檻調節
- 🚨 **智慧警報**：超溫自動蜂鳴器警報
- 📡 **藍牙連線**：無線資料傳輸至手機或電腦
- 📊 **電路圖**：完整電路原理圖（Schematic.pdf）
- 🔧 **模組化設計**：程式碼結構清晰，便於維護和擴展
- 🐛 **偵錯支援**：提供完整的硬體測試程式

## 🎯 核心功能

- **溫度測量**：測量範圍-70℃~380℃，精度±0.5℃
- **即時顯示**：16×2字元LCD顯示溫度值和系統資訊
- **門檻設定**：可透過按鍵調節溫度警報門檻（預設38℃）
- **超溫警報**：溫度超過門檻時蜂鳴器自動警報
- **藍牙通訊**：無線資料傳輸，支援遠端監控
- **開機動畫**：系統啟動時顯示ThermoX52標識
- **電路圖**：Schematic.pdf提供完整電路原理圖

## 🎮 使用介面

- **KEY1**：執行溫度測量
- **KEY2**：提高警報門檻溫度
- **KEY3**：降低警報門檻溫度

## 🏗️ 系統架構

```
ThermoX52/
├── src/                    # 原始碼目錄
│   ├── main.c             # 主程式入口
│   ├── delay.c/h          # 延時函數模組
│   ├── lcd1602.c/h        # LCD1602顯示驅動
│   ├── mlx90614.c/h       # MLX90614溫度感測器驅動
│   ├── i2c_soft.c/h       # 軟體I2C通訊協定
│   ├── key.c/h            # 按鍵掃描模組
│   ├── buzzer.c/h         # 蜂鳴器控制模組
│   ├── bluetooth.c/h      # 藍牙通訊模組
│   └── type.h             # 型別定義
├── Schematic.pdf          # 電路原理圖
└── README.md              # 專案說明文件
```

## ⚡ 快速開始


### 🚀 編譯和燒錄

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

## 🔧 使用說明

### 基本操作

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

### 狀態指示

| 顯示內容 | 含義 |
|----------|------|
| `ThermoX52` | 系統就緒狀態 |
| `Sensor OK` | 感測器連接正常 |
| `Sensor Error!` | 感測器連接異常 |
| `T:xx.xC` | 當前溫度值 |
| `Th:xxC` | 當前門檻設定 |
| `Warning!` | 超溫警報 |
| `Read Error!` | 讀取錯誤 |

## 📁 程式碼說明

- **main.c**：主程式流程控制，使用者介面邏輯
- **delay.c/h**：精確延時函數，支援微秒和毫秒級延時
- **lcd1602.c/h**：LCD1602顯示驅動，支援字元顯示和光標控制
- **mlx90614.c/h**：MLX90614感測器驅動，實現溫度資料讀取
- **i2c_soft.c/h**：軟體I2C協定實現，支援標準I2C時序
- **key.c/h**：按鍵掃描與消抖處理
- **buzzer.c/h**：蜂鳴器控制，支援多種警報模式
- **bluetooth.c/h**：藍牙通訊模組，無線資料傳輸
- **type.h**：通用型別定義和常數

## 📄 許可證

本專案採用 MIT 許可證 - 查看 [LICENSE](LICENSE) 檔案了解詳情

## 👥 作者

- **開發者**: Bucolic77
- **專案**: 電路綜合創新實踐
- **時間**: 2025年秋冬學期

## 📞 技術支援

如有問題或建議，請透過以下方式聯絡：

- 📧 電子郵件: limerence051693@gmail.com
- 💬 問題回報: [GitHub Issues](https://github.com/bucolic-ruiqi/ThermoX52/issues)
- 📋 電路圖: 查看 `Schematic.pdf` 了解完整電路原理圖

## 🔗 相關連結

- [MLX90614數據手冊](https://www.melexis.com/en/product/MLX90614/Digital-Plug-Play-Infrared-Thermometer-TO-Can)
- [STC89C52數據手冊](http://www.stcmcudata.com/)
- [LCD1602使用指南](https://www.sparkfun.com/datasheets/LCD/HD44780.pdf)
- [HC-05藍牙模組指南](https://components101.com/wireless/hc-05-bluetooth-module)

---

<div align="center">

**⭐ 如果這個專案對您有幫助，請給它一個Star！⭐**

用❤️為學習和創新而製作

**🌡️ ThermoX52 - 智慧溫度監控，支援藍牙 🌡️**

</div>
