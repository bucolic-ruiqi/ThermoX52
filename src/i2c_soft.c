/*
 * 文件名：i2c_soft.c
 * 功能：软件I2C总线通信实现
 * 描述：实现I2C协议的启动、停止、数据发送和接收功能
 * 作者：[作者名]
 * 日期：2025/08/27
 */

#include "i2c_soft.h"   // 软件I2C头文件
#include "delay.h"      // 延时函数头文件

/*
 * 函数名：I2C_Start
 * 功能：产生I2C总线启动信号
 * 参数：无
 * 返回值：无
 * 说明：在SCL为高电平时，SDA由高电平变为低电平产生启动信号
 */
void I2C_Start(void) {
    SDA=1;              // 确保SDA为高电平
    SCL=1;              // 确保SCL为高电平
    delay_us(5);        // 延时5微秒，保持稳定
    SDA=0;              // SDA由高变低，产生启动信号
    delay_us(5);        // 延时5微秒
    SCL=0;              // 拉低SCL，准备数据传输
}

/*
 * 函数名：I2C_Stop
 * 功能：产生I2C总线停止信号
 * 参数：无
 * 返回值：无
 * 说明：在SCL为高电平时，SDA由低电平变为高电平产生停止信号
 */
void I2C_Stop(void) {
    SDA=0;              // 确保SDA为低电平
    SCL=1;              // SCL置高电平
    delay_us(5);        // 延时5微秒，保持稳定
    SDA=1;              // SDA由低变高，产生停止信号
    delay_us(5);        // 延时5微秒
}

/*
 * 函数名：I2C_WriteByte
 * 功能：通过I2C总线发送一个字节数据
 * 参数：dat - 要发送的数据字节
 * 返回值：应答位（0=收到应答，1=未收到应答）
 * 说明：从最高位开始发送，每位数据在SCL上升沿被采样
 */
bit I2C_WriteByte(unsigned char dat) {
    unsigned char i;    // 循环计数器
    
    // 逐位发送数据（从高位到低位）
    for(i=0;i<8;i++) {
        SDA=(dat&0x80)?1:0; // 发送当前最高位数据
        dat<<=1;            // 数据左移，准备发送下一位
        SCL=1;              // SCL置高，数据有效
        delay_us(5);        // 延时5微秒
        SCL=0;              // SCL置低，准备下一位数据
        delay_us(5);        // 延时5微秒
    }
    
    // 接收应答位
    SDA=1;              // 释放SDA线，由从设备控制
    SCL=1;              // SCL置高，读取应答位
    delay_us(5);        // 延时5微秒
    bit ack=SDA;        // 读取应答位（0=应答，1=非应答）
    SCL=0;              // SCL置低，完成应答位接收
    return ack;         // 返回应答位状态
}

/*
 * 函数名：I2C_ReadByte
 * 功能：通过I2C总线接收一个字节数据
 * 参数：ack - 应答位（0=发送应答，1=发送非应答）
 * 返回值：接收到的数据字节
 * 说明：从最高位开始接收，每位数据在SCL上升沿被读取
 */
unsigned char I2C_ReadByte(bit ack) {
    unsigned char i,dat=0;  // 循环计数器和接收数据缓存
    
    SDA=1;              // 释放SDA线，由从设备控制
    
    // 逐位接收数据（从高位到低位）
    for(i=0;i<8;i++) {
        dat<<=1;        // 数据左移，为接收下一位做准备
        SCL=1;          // SCL置高，读取数据位
        delay_us(5);    // 延时5微秒
        if(SDA) dat|=0x01;  // 如果SDA为高，设置当前位为1
        SCL=0;          // SCL置低，准备接收下一位
        delay_us(5);    // 延时5微秒
    }
    
    // 发送应答位
    SDA=(ack)?1:0;      // 根据ack参数设置应答位
    SCL=1;              // SCL置高，发送应答位
    delay_us(5);        // 延时5微秒
    SCL=0;              // SCL置低，完成应答位发送
    SDA=1;              // 释放SDA线
    
    return dat;         // 返回接收到的数据
}