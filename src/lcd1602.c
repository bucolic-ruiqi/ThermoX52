/*
 * LCD1602液晶显示屏驱动
 */

#include "lcd1602.h"
#include "delay.h"

// 写命令
void LCD_WriteCmd(unsigned char cmd) {
    RS=0;
    RW=0;
    P0=cmd;
    EN=1;
    delay_us(5);
    EN=0;
}

// 写数据
void LCD_WriteData(unsigned char dat) {
    RS=1;
    RW=0;
    P0=dat;
    EN=1;
    delay_us(5);
    EN=0;
}

// 初始化LCD
void LCD_Init(void) {
    delay_ms(20);
    LCD_WriteCmd(0x38);     // 8位接口，2行显示
    LCD_WriteCmd(0x0C);     // 显示开，光标关
    LCD_WriteCmd(0x06);     // 光标右移
    LCD_WriteCmd(0x01);     // 清屏
}

// 显示字符串
void LCD_PrintString(unsigned char row, unsigned char col, char *str) {
    unsigned char addr = (row==0)?0x80:0xC0;
    LCD_WriteCmd(addr+col);
    
    while(*str) {
        LCD_WriteData(*str++);
    }
}