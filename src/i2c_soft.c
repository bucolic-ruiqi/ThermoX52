/*
 * 软件I2C通信实现
 */

#include "i2c_soft.h"
#include <intrins.h>

// 产生I2C启动信号
void I2C_Start(void) {
    SDA=1;
    _nop_();_nop_();_nop_();_nop_();_nop_();
    SCL=1;
    _nop_();_nop_();_nop_();_nop_();_nop_();
    SDA=0;
    _nop_();_nop_();_nop_();_nop_();_nop_();
    SCL=0;
    _nop_();_nop_();_nop_();_nop_();_nop_();
}

// 产生I2C停止信号
void I2C_Stop(void) {
    SCL=0;
    _nop_();_nop_();_nop_();_nop_();_nop_();
    SDA=0;
    _nop_();_nop_();_nop_();_nop_();_nop_();
    SCL=1;
    _nop_();_nop_();_nop_();_nop_();_nop_();
    SDA=1;
}

// 发送一个字节
bit I2C_WriteByte(unsigned char dat) {
    unsigned char i;
    unsigned char ack;
    
    for(i=0;i<8;i++) {
        if(dat&0x80)
            SDA=1;
        else
            SDA=0;
        dat<<=1;
        _nop_();
        SCL=1;
        _nop_();_nop_();_nop_();_nop_();
        _nop_();_nop_();_nop_();_nop_();
        SCL=0;
        _nop_();_nop_();_nop_();_nop_();
        _nop_();_nop_();_nop_();_nop_();
    }
    
    // 接收应答
    SDA=1;
    _nop_();
    SCL=1;
    _nop_();_nop_();_nop_();_nop_();
    _nop_();_nop_();_nop_();_nop_();
    ack=SDA;
    _nop_();
    SCL=0;
    _nop_();_nop_();_nop_();_nop_();
    _nop_();_nop_();_nop_();_nop_();
    return ack;
}

// 接收一个字节
unsigned char I2C_ReadByte(bit ack) {
    unsigned char i,dat=0;
    
    SDA=1;
    
    for(i=0;i<8;i++) {
        dat<<=1;
        SCL=1;
        _nop_();_nop_();_nop_();_nop_();
        _nop_();_nop_();_nop_();_nop_();
        if(SDA) dat|=0x01;
        _nop_();
        SCL=0;
        _nop_();_nop_();_nop_();_nop_();
        _nop_();_nop_();_nop_();_nop_();
    }
    
    // 发送应答
    if(ack==0)
        SDA=0;
    else
        SDA=1;
    _nop_();
    SCL=1;
    _nop_();_nop_();_nop_();_nop_();
    _nop_();_nop_();_nop_();_nop_();
    SCL=0;
    _nop_();_nop_();_nop_();_nop_();
    _nop_();_nop_();_nop_();_nop_();
    SDA=1;
    
    return dat;
}