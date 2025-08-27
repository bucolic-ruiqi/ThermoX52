/*
 * 文件名：i2c_soft.h
 * 功能：软件I2C总线通信头文件
 * 描述：定义I2C通信引脚和函数声明，用于与MLX90614传感器通信
 * 作者：[作者名]
 * 日期：2025/08/27
 */

#ifndef __I2C_SOFT_H__
#define __I2C_SOFT_H__

#include "reg52.h"      // 52单片机寄存器定义

// I2C通信引脚定义
sbit SCL = P1^0;        // I2C时钟线（Serial Clock Line）
sbit SDA = P1^1;        // I2C数据线（Serial Data Line）

/*
 * 函数名：I2C_Start
 * 功能：产生I2C总线启动信号
 * 参数：无
 * 返回值：无
 */
void I2C_Start(void);

/*
 * 函数名：I2C_Stop
 * 功能：产生I2C总线停止信号
 * 参数：无
 * 返回值：无
 */
void I2C_Stop(void);

/*
 * 函数名：I2C_WriteByte
 * 功能：通过I2C总线发送一个字节数据
 * 参数：dat - 要发送的数据字节
 * 返回值：应答位（0=收到应答，1=未收到应答）
 */
bit I2C_WriteByte(unsigned char dat);

/*
 * 函数名：I2C_ReadByte
 * 功能：通过I2C总线接收一个字节数据
 * 参数：ack - 应答位（0=发送应答，1=发送非应答）
 * 返回值：接收到的数据字节
 */
unsigned char I2C_ReadByte(bit ack);

#endif
