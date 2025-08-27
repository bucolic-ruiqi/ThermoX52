# ThermoX52
## 项目简介
本实验基于 STC89C52 单片机，使用 DS18B20 数字温度传感器采集温度数据，并通过 LCD1602 显示器实时显示。

## 功能
- 初始化 DS18B20 并采集温度
- 单总线通信协议实现
- LCD1602 实时显示温度值

## 项目架构
```
Project/
│── main.c           // 主程序入口，逻辑控制
│── delay.c
│── delay.h          // 延时函数
│── lcd1602.c
│── lcd1602.h        // LCD1602 显示驱动
│── i2c_soft.c
│── i2c_soft.h       // 软件I²C总线底层函数
│── mlx90614.c
│── mlx90614.h       // 温度传感器驱动
│── key.c
│── key.h            // 按键扫描
│── led.c
│── led.h            // LED 报警逻辑
│── buzzer.c
│── buzzer.h         // 蜂鸣器报警逻辑
```
