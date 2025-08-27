/*
 * 文件名：test_lcd.c
 * 功能：LCD1602显示屏测试程序
 * 描述：测试LCD1602显示屏的各项功能
 * 作者：[作者名]
 * 日期：2025/08/27
 * 
 * 测试方法：
 * 1. 编译并烧录到单片机
 * 2. 观察LCD是否正确显示各种测试内容
 * 3. 检查字符显示是否清晰
 * 4. 程序会循环显示不同的测试模式
 */

#include "reg52.h"
#include "delay.h"
#include "lcd1602.h"
#include <stdio.h>

// 显示测试字符串
void Test_BasicDisplay(void) {
    LCD_WriteCmd(0x01);     // 清屏
    delay_ms(100);
    
    LCD_PrintString(0, 0, "LCD1602 Test");
    LCD_PrintString(1, 0, "Basic Display OK");
    delay_ms(2000);
}

// 测试所有字符位置
void Test_AllPositions(void) {
    unsigned char i;
    char pos_str[17];
    
    LCD_WriteCmd(0x01);     // 清屏
    delay_ms(100);
    
    // 测试第一行所有位置
    LCD_PrintString(0, 0, "Row1:");
    for(i = 5; i < 16; i++) {
        sprintf(pos_str, "%X", i-5);
        LCD_PrintString(0, i, pos_str);
        delay_ms(200);
    }
    
    delay_ms(1000);
    
    // 测试第二行所有位置
    LCD_PrintString(1, 0, "Row2:");
    for(i = 5; i < 16; i++) {
        sprintf(pos_str, "%X", i-5);
        LCD_PrintString(1, i, pos_str);
        delay_ms(200);
    }
    
    delay_ms(2000);
}

// 测试数字显示
void Test_Numbers(void) {
    unsigned int counter;
    char num_str[16];
    
    LCD_WriteCmd(0x01);     // 清屏
    delay_ms(100);
    
    LCD_PrintString(0, 0, "Number Test:");
    
    for(counter = 0; counter <= 100; counter++) {
        sprintf(num_str, "Count: %3d", counter);
        LCD_PrintString(1, 0, num_str);
        delay_ms(100);
    }
    
    delay_ms(1000);
}

// 测试特殊字符
void Test_SpecialChars(void) {
    LCD_WriteCmd(0x01);     // 清屏
    delay_ms(100);
    
    LCD_PrintString(0, 0, "Special Chars:");
    LCD_PrintString(1, 0, "!@#$%^&*()_+-=");
    delay_ms(2000);
    
    LCD_PrintString(1, 0, "[]{}|\\:;\"'<>?/");
    delay_ms(2000);
    
    LCD_PrintString(1, 0, ",.~`           ");
    delay_ms(2000);
}

// 测试滚动显示
void Test_ScrollDisplay(void) {
    unsigned char i;
    char scroll_text[] = "  LCD1602 Scroll Test - This is a long text for scrolling display...  ";
    unsigned char text_len = sizeof(scroll_text) - 1;
    
    LCD_WriteCmd(0x01);     // 清屏
    delay_ms(100);
    
    LCD_PrintString(0, 0, "Scroll Test:");
    
    for(i = 0; i < text_len - 16; i++) {
        // 显示16个字符的窗口
        char window[17];
        unsigned char j;
        
        for(j = 0; j < 16; j++) {
            window[j] = scroll_text[i + j];
        }
        window[16] = '\0';
        
        LCD_PrintString(1, 0, window);
        delay_ms(300);
    }
    
    delay_ms(1000);
}

// 测试光标和闪烁
void Test_CursorBlink(void) {
    LCD_WriteCmd(0x01);     // 清屏
    delay_ms(100);
    
    LCD_PrintString(0, 0, "Cursor Test:");
    LCD_PrintString(1, 0, "Cursor ON");
    LCD_WriteCmd(0x0E);     // 显示光标
    delay_ms(3000);
    
    LCD_PrintString(1, 0, "Blink ON ");
    LCD_WriteCmd(0x0F);     // 显示光标并闪烁
    delay_ms(3000);
    
    LCD_PrintString(1, 0, "Normal   ");
    LCD_WriteCmd(0x0C);     // 关闭光标和闪烁
    delay_ms(2000);
}

void main() {
    unsigned int test_round = 0;
    char round_str[16];
    
    // 系统初始化
    LCD_Init();
    delay_ms(500);
    
    // 显示初始化完成
    LCD_PrintString(0, 0, "LCD Init OK!");
    LCD_PrintString(1, 0, "Test Starting...");
    delay_ms(2000);
    
    while(1) {
        test_round++;
        
        // 显示测试轮次
        sprintf(round_str, "Test Round: %d", test_round);
        LCD_WriteCmd(0x01);
        LCD_PrintString(0, 0, round_str);
        LCD_PrintString(1, 0, "Press any key...");
        delay_ms(2000);
        
        // 基本显示测试
        Test_BasicDisplay();
        
        // 位置测试
        Test_AllPositions();
        
        // 数字测试
        Test_Numbers();
        
        // 特殊字符测试
        Test_SpecialChars();
        
        // 滚动测试
        Test_ScrollDisplay();
        
        // 光标测试
        Test_CursorBlink();
        
        // 完成提示
        LCD_WriteCmd(0x01);
        LCD_PrintString(0, 0, "Test Complete!");
        sprintf(round_str, "Round %d Done", test_round);
        LCD_PrintString(1, 0, round_str);
        delay_ms(3000);
        
        // 防止计数器溢出
        if(test_round > 999) test_round = 0;
    }
}

/*
 * 调试说明：
 * 1. 如果LCD完全没有显示：
 *    - 检查LCD供电（通常需要5V）
 *    - 检查数据线连接（P0口连接LCD数据线D0-D7）
 *    - 检查控制线连接（RS-P2.0, RW-P2.1, EN-P2.2）
 *    - 调节LCD背光对比度电位器
 * 
 * 2. 如果显示模糊或字符不清：
 *    - 调节对比度电位器
 *    - 检查供电电压是否稳定
 *    - 检查接线是否牢固
 * 
 * 3. 如果显示位置错乱：
 *    - 检查数据线是否接错
 *    - 确认是否使用了正确的LCD1602初始化序列
 * 
 * 4. 如果部分字符显示异常：
 *    - 检查对应的数据线
 *    - 可能是特定位的接触不良
 * 
 * 5. 测试内容说明：
 *    - Basic Display: 基本文字显示
 *    - All Positions: 测试所有显示位置
 *    - Numbers: 数字计数显示
 *    - Special Chars: 特殊字符显示
 *    - Scroll: 滚动文字显示
 *    - Cursor: 光标和闪烁功能
 */
