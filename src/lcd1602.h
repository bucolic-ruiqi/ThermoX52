/*
 * 文件名：lcd1602.h
 * 功能：LCD1602液晶显示屏驱动头文件
 * 描述：定义LCD1602控制引脚和函数声明
 * 作者：[作者名]
 * 日期：2025/08/27
 */

#ifndef __LCD1602_H__
#define __LCD1602_H__

#include "reg52.h"      // 52单片机寄存器定义

// LCD1602控制引脚定义
sbit RS = P2^6;         // 数据/命令选择引脚（0=命令，1=数据）
sbit RW = P2^5;         // 读写控制引脚（0=写，1=读）
sbit EN = P2^4;         // 使能引脚（高电平有效）

/*
 * 函数名：LCD_Init
 * 功能：初始化LCD1602显示屏
 * 参数：无
 * 返回值：无
 */
void LCD_Init(void);

/*
 * 函数名：LCD_WriteCmd
 * 功能：向LCD写入命令
 * 参数：cmd - 要写入的命令字节
 * 返回值：无
 */
void LCD_WriteCmd(unsigned char cmd);

/*
 * 函数名：LCD_WriteData
 * 功能：向LCD写入数据
 * 参数：dat - 要写入的数据字节
 * 返回值：无
 */
void LCD_WriteData(unsigned char dat);

/*
 * 函数名：LCD_PrintString
 * 功能：在LCD指定位置显示字符串
 * 参数：row - 行号（0或1）
 *       col - 列号（0-15）
 *       str - 要显示的字符串指针
 * 返回值：无
 */
void LCD_PrintString(unsigned char row, unsigned char col, char *str);

#endif