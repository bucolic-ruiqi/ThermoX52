/*
 * 软件I2C通信驱动
 */

#ifndef __I2C_SOFT_H__
#define __I2C_SOFT_H__

#include "reg52.h"
#include <intrins.h>

// I2C引脚定义
sbit SCL = P1^0;        // 时钟线
sbit SDA = P1^1;        // 数据线

// 函数声明
void I2C_Start(void);
void I2C_Stop(void);
bit I2C_WriteByte(unsigned char dat);
unsigned char I2C_ReadByte(bit ack);

#endif
