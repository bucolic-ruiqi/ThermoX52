/*
 * LCD1602液晶显示屏驱动
 */

#ifndef __LCD1602_H__
#define __LCD1602_H__

#include "reg52.h"

// LCD控制引脚
sbit RS = P2^6;         // 数据/命令选择
sbit RW = P2^5;         // 读写控制
sbit EN = P2^4;         // 使能信号

// 函数声明
void LCD_Init(void);
void LCD_WriteCmd(unsigned char cmd);
void LCD_WriteData(unsigned char dat);
void LCD_PrintString(unsigned char row, unsigned char col, char *str);

#endif