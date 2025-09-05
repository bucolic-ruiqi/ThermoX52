# ThermoX52 🌡️

![Version](https://img.shields.io/badge/version-v2.0-blue)
![MCU](https://img.shields.io/badge/MCU-STC89C52-green)
![License](https://img.shields.io/badge/license-MIT-orange)

**基于STC89C52单片机的MLX90614红外温度测量系统，支持蓝牙连接**

[English](README_en.md) | [繁體中文](README_zh-TW.md) | [한국어](README_ko.md)

---

## 📋 项目简介

ThermoX52是一个基于STC89C52单片机的非接触式红外温度测量系统。该系统使用MLX90614红外温度传感器实现远程温度检测，配备LCD1602显示屏实时显示温度数据，支持按键操作调节报警阈值，并具备声光报警功能以及**无线蓝牙数据传输**。

## ✨ 主要特性

- 🌡️ **非接触式测温**：基于MLX90614红外传感器，测量精度±0.5℃
- 📺 **实时显示**：LCD1602液晶屏显示温度和系统状态
- 🎮 **按键控制**：支持3个按键操作，包括测温和阈值调节
- 🚨 **智能报警**：超温自动蜂鸣器报警
- 📡 **蓝牙连接**：无线数据传输至手机或电脑
- 📊 **电路图**：完整电路原理图（Schematic.pdf）
- 🔧 **模块化设计**：代码结构清晰，便于维护和扩展
- 🐛 **调试支持**：提供完整的硬件测试程序

## 🎯 核心功能

- **温度测量**：测量范围-70℃~380℃，精度±0.5℃
- **实时显示**：16×2字符LCD显示温度值和系统信息
- **阈值设置**：可通过按键调节温度报警阈值（默认38℃）
- **超温报警**：温度超过阈值时蜂鸣器自动报警
- **蓝牙通信**：无线数据传输，支持远程监控
- **开机动画**：系统启动时显示ThermoX52标识
- **电路图**：Schematic.pdf提供完整电路原理图

## 🎮 用户界面

- **KEY1**：执行温度测量
- **KEY2**：提高报警阈值温度
- **KEY3**：降低报警阈值温度

## 🏗️ 系统架构

```
ThermoX52/
├── src/                    # 源代码目录
│   ├── main.c             # 主程序入口
│   ├── delay.c/h          # 延时函数模块
│   ├── lcd1602.c/h        # LCD1602显示驱动
│   ├── mlx90614.c/h       # MLX90614温度传感器驱动
│   ├── i2c_soft.c/h       # 软件I2C通信协议
│   ├── key.c/h            # 按键扫描模块
│   ├── buzzer.c/h         # 蜂鸣器控制模块
│   ├── bluetooth.c/h      # 蓝牙通信模块
│   └── type.h             # 类型定义
├── Schematic.pdf          # 电路原理图
└── README.md              # 项目说明文档
```

## ⚡ 快速开始

### 🚀 编译和烧录

1. **环境准备**
   ```bash
   # 确保安装了Keil C51或SDCC编译器
   # 准备STC-ISP下载软件
   ```

2. **编译项目**
   ```bash
   # 在Keil C51中打开项目
   # 或使用SDCC命令行编译
   sdcc main.c delay.c lcd1602.c mlx90614.c i2c_soft.c key.c buzzer.c bluetooth.c
   ```

3. **烧录程序**
   ```bash
   # 使用STC-ISP烧录hex文件到STC89C52
   # 设置下载参数：12MHz晶振，5V供电
   ```

## 🔧 使用说明

### 基本操作

1. **系统启动**
   - 接通电源，LCD显示开机动画
   - 系统自检MLX90614传感器连接状态
   - 显示"ThermoX52"主界面

2. **温度测量**
   - 按下KEY1执行温度测量
   - LCD显示当前测量温度值
   - 格式：`T:xx.xC`

3. **阈值设置**
   - 按KEY2提高报警阈值
   - 按KEY3降低报警阈值
   - 显示格式：`Th:xxC`

4. **报警功能**
   - 温度超过设定阈值时自动报警
   - 蜂鸣器连续鸣叫3次
   - LCD显示"Warning!"警告信息

5. **蓝牙通信**
   - 温度数据自动通过蓝牙传输
   - 连接手机或电脑接收数据
   - 实时监控和数据记录

### 状态指示

| 显示内容 | 含义 |
|----------|------|
| `ThermoX52` | 系统就绪状态 |
| `Sensor OK` | 传感器连接正常 |
| `Sensor Error!` | 传感器连接异常 |
| `T:xx.xC` | 当前温度值 |
| `Th:xxC` | 当前阈值设置 |
| `Warning!` | 超温报警 |
| `Read Error!` | 读取错误 |

## 📁 代码说明

- **main.c**：主程序流程控制，用户界面逻辑
- **delay.c/h**：精确延时函数，支持微秒和毫秒级延时
- **lcd1602.c/h**：LCD1602显示驱动，支持字符显示和光标控制
- **mlx90614.c/h**：MLX90614传感器驱动，实现温度数据读取
- **i2c_soft.c/h**：软件I2C协议实现，支持标准I2C时序
- **key.c/h**：按键扫描与消抖处理
- **buzzer.c/h**：蜂鸣器控制，支持多种报警模式
- **bluetooth.c/h**：蓝牙通信模块，无线数据传输
- **type.h**：通用类型定义和常量

## 📄 许可证

本项目采用 MIT 许可证 - 查看 [LICENSE](LICENSE) 文件了解详情

## 👥 作者

- **开发者**: Bucolic77
- **项目**: 电路综合创新实践
- **时间**: 2025年秋冬学期

## 📞 技术支持

如有问题或建议，请通过以下方式联系：

- 📧 邮箱: limerence051693@gmail.com
- 💬 问题反馈: [GitHub Issues](https://github.com/bucolic-ruiqi/ThermoX52/issues)
- 📋 电路图: 查看 `Schematic.pdf` 了解完整电路原理图

## 🔗 相关链接

- [MLX90614数据手册](https://www.melexis.com/en/product/MLX90614/Digital-Plug-Play-Infrared-Thermometer-TO-Can)
- [STC89C52数据手册](http://www.stcmcudata.com/)
- [LCD1602使用指南](https://www.sparkfun.com/datasheets/LCD/HD44780.pdf)
- [HC-05蓝牙模块指南](https://components101.com/wireless/hc-05-bluetooth-module)

---

<div align="center">

**⭐ 如果这个项目对您有帮助，请给它一个Star！⭐**

用❤️为学习和创新而制作

**🌡️ ThermoX52 - 智能温度监控，支持蓝牙 🌡️**

</div>
