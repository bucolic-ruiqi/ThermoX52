/*
 * 文件名：lcd1602.c
 * 功能：LCD1602液晶显示屏驱动实现
 * 描述：实现LCD1602的初始化、命令/数据写入、字符串显示等功能
 * 作者：[作者名]
 * 日期：2025/08/27
 */

#include "lcd1602.h"    // LCD1602驱动头文件
#include "delay.h"      // 延时函数头文件

/*
 * 函数名：LCD_WriteCmd
 * 功能：向LCD1602写入命令
 * 参数：cmd - 要写入的命令字节
 * 返回值：无
 * 说明：通过控制RS、RW、EN引脚实现命令写入时序
 */
void LCD_WriteCmd(unsigned char cmd) {
    RS=0;               // RS=0，选择命令寄存器
    RW=0;               // RW=0，选择写操作
    P0=cmd;             // 将命令数据送到P0口
    EN=1;               // EN置高电平，开始数据传输
    delay_us(5);        // 保持5微秒高电平
    EN=0;               // EN置低电平，完成数据传输
}

/*
 * 函数名：LCD_WriteData
 * 功能：向LCD1602写入显示数据
 * 参数：dat - 要写入的数据字节
 * 返回值：无
 * 说明：通过控制RS、RW、EN引脚实现数据写入时序
 */
void LCD_WriteData(unsigned char dat) {
    RS=1;               // RS=1，选择数据寄存器
    RW=0;               // RW=0，选择写操作
    P0=dat;             // 将显示数据送到P0口
    EN=1;               // EN置高电平，开始数据传输
    delay_us(5);        // 保持5微秒高电平
    EN=0;               // EN置低电平，完成数据传输
}

/*
 * 函数名：LCD_Init
 * 功能：初始化LCD1602显示屏
 * 参数：无
 * 返回值：无
 * 说明：按照LCD1602时序要求进行初始化配置
 */
void LCD_Init(void) {
    delay_ms(20);       // 上电延时20毫秒，等待LCD稳定
    LCD_WriteCmd(0x38); // 功能设置：8位数据接口，2行显示，5×7点阵字符
    LCD_WriteCmd(0x0C); // 显示控制：显示开，光标关，闪烁关
    LCD_WriteCmd(0x06); // 输入模式设置：光标右移，画面不移动
    LCD_WriteCmd(0x01); // 清屏命令
}

/*
 * 函数名：LCD_PrintString
 * 功能：在LCD1602指定位置显示字符串
 * 参数：row - 行号（0=第一行，1=第二行）
 *       col - 列号（0-15，表示第几列）
 *       str - 要显示的字符串指针
 * 返回值：无
 * 说明：先设置显示位置，然后逐个字符显示
 */
void LCD_PrintString(unsigned char row, unsigned char col, char *str) {
    // 计算显示位置地址（第一行0x80起始，第二行0xC0起始）
    unsigned char addr = (row==0)?0x80:0xC0;
    LCD_WriteCmd(addr+col);     // 设置显示起始位置
    
    // 逐个字符显示，直到字符串结束
    while(*str) {
        LCD_WriteData(*str++);  // 显示当前字符，指针移向下一个字符
    }
}