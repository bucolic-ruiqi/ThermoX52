/*
 * 蓝牙通信模块
 * 支持HC-05/HC-06蓝牙模块，波特率9600
 */

#ifndef _BLUETOOTH_H
#define _BLUETOOTH_H

#define RELOAD_COUNT 0xFA   // 波特率9600

void UART_Init(void);
void UART_SendByte(unsigned char dat);
void BlueTooth_Init(void);
void BlueTooth_SendData(unsigned char dat);
void BlueTooth_SendTemp_Char(float temp);

#endif
