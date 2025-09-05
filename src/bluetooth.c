/*
 * 蓝牙通信模块实现
 */

#include "reg52.h"
#include "bluetooth.h"
#include "delay.h"

void UART_Init(void)
{
    TMOD |= 0x20;   // 定时器1工作模式2
    TH1 = 0xFD;     // 波特率9600
    SCON = 0x50;    // 串口模式1
    
    TL1=TH1;
    ES=0;           // 关闭接收中断
    EA=1;           // 开总中断
    TR1=1;          // 启动定时器1
}
 
void UART_SendByte(unsigned char dat)
{
    TI = 0;
    SBUF = dat;
    while(TI == 0);
    TI = 0;
}

void BlueTooth_Init(void)
{
    UART_Init();
}
 
void BlueTooth_SendData(unsigned char dat)
{
    UART_SendByte(dat);
}

void BlueTooth_SendTemp_Char(float temp)
{
    unsigned char tens_digit, ones_digit, decimal_digit;
    unsigned int temp_times_10;
    unsigned int temp_int;
    unsigned int temp_dec;
    
    // 检查温度值范围
    if(temp < 0 || temp > 99.9) {
        BlueTooth_SendData('E');
        BlueTooth_SendData('R');
        BlueTooth_SendData('R');
        return;
    }
    
    // 温度转换，避免精度损失
    temp_times_10 = (unsigned int)(temp * 10 + 0.5);
    temp_int = temp_times_10 / 10;
    temp_dec = temp_times_10 % 10;
    
    tens_digit = '0' + temp_int / 10;
    ones_digit = '0' + temp_int % 10;
    decimal_digit = '0' + temp_dec;
    
    // 发送格式: T:XX.XC
    BlueTooth_SendData('T');
    BlueTooth_SendData(':');
    BlueTooth_SendData(tens_digit);
    BlueTooth_SendData(ones_digit);
    BlueTooth_SendData('.');
    BlueTooth_SendData(decimal_digit);
    BlueTooth_SendData('C');
    BlueTooth_SendData('\r');
    BlueTooth_SendData('\n');
}
