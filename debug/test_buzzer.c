/*
 * 文件名：test_buzzer.c
 * 功能：蜂鸣器功能测试程序
 * 描述：测试蜂鸣器是否能正常发出声音
 * 作者：[作者名]
 * 日期：2025/08/27
 * 
 * 测试方法：
 * 1. 编译并烧录到单片机
 * 2. 观察LCD显示当前测试状态
 * 3. 听取蜂鸣器是否发出不同模式的声音
 * 4. 程序会循环播放不同的音效模式
 */

#include "reg52.h"
#include "delay.h"
#include "lcd1602.h"
#include "buzzer.h"
#include <stdio.h>

// 自定义蜂鸣器控制函数，用于更灵活的测试
void Buzzer_Beep(unsigned int duration_ms) {
    BEEP = 0;           // 蜂鸣器开启
    delay_ms(duration_ms);
    BEEP = 1;           // 蜂鸣器关闭
}

void Buzzer_Pattern1(void) {
    // 短促连续鸣叫（报警音）
    LCD_PrintString(1, 0, "Pattern: Alarm ");
    Buzzer_Beep(100);
    delay_ms(100);
    Buzzer_Beep(100);
    delay_ms(100);
    Buzzer_Beep(100);
    delay_ms(500);
}

void Buzzer_Pattern2(void) {
    // 长音（启动音）
    LCD_PrintString(1, 0, "Pattern: Startup");
    Buzzer_Beep(500);
    delay_ms(500);
}

void Buzzer_Pattern3(void) {
    // 快速短音（按键音）
    LCD_PrintString(1, 0, "Pattern: Beep  ");
    Buzzer_Beep(50);
    delay_ms(200);
    Buzzer_Beep(50);
    delay_ms(500);
}

void Buzzer_Pattern4(void) {
    // 渐强音效
    LCD_PrintString(1, 0, "Pattern: Rising");
    Buzzer_Beep(100);
    delay_ms(50);
    Buzzer_Beep(150);
    delay_ms(50);
    Buzzer_Beep(200);
    delay_ms(500);
}

void main() {
    unsigned int test_cycle = 0;
    char cycle_str[16];
    
    // 系统初始化
    LCD_Init();
    BEEP = 1;           // 确保蜂鸣器初始状态为关闭
    delay_ms(100);
    
    // 显示测试标题
    LCD_PrintString(0, 0, "Buzzer Test");
    LCD_PrintString(1, 0, "Starting...");
    delay_ms(2000);
    
    // 初始测试音
    LCD_PrintString(1, 0, "Init Beep");
    Buzzer_Beep(200);
    delay_ms(1000);
    
    while(1) {
        test_cycle++;
        
        // 显示当前测试周期
        sprintf(cycle_str, "Cycle: %d", test_cycle);
        LCD_PrintString(0, 0, cycle_str);
        
        // 测试模式1：报警音
        Buzzer_Pattern1();
        delay_ms(1000);
        
        // 测试模式2：启动音
        Buzzer_Pattern2();
        delay_ms(1000);
        
        // 测试模式3：按键音
        Buzzer_Pattern3();
        delay_ms(1000);
        
        // 测试模式4：渐强音
        Buzzer_Pattern4();
        delay_ms(1000);
        
        // 使用原有的报警函数测试
        LCD_PrintString(1, 0, "Buzzer_Warning");
        Buzzer_Warning(2);
        delay_ms(1000);
        
        // 静音间隔
        LCD_PrintString(1, 0, "Silent Period ");
        delay_ms(3000);
        
        // 防止计数器溢出
        if(test_cycle > 999) test_cycle = 0;
    }
}

/*
 * 调试说明：
 * 1. 如果完全没有声音：
 *    - 检查蜂鸣器接线（BEEP接P3.0）
 *    - 检查蜂鸣器供电（通常需要5V）
 *    - 确认蜂鸣器极性是否正确
 *    - 检查蜂鸣器是否需要驱动电路（三极管放大）
 * 
 * 2. 如果声音很小：
 *    - 检查供电电压是否足够
 *    - 检查驱动电流是否足够
 *    - 可能需要添加功率放大电路
 * 
 * 3. 如果声音断断续续：
 *    - 检查接线是否牢固
 *    - 检查电源纹波是否过大
 * 
 * 4. 测试音效说明：
 *    - Alarm: 三次短促鸣叫
 *    - Startup: 一次长音
 *    - Beep: 两次短音
 *    - Rising: 渐强的三次鸣叫
 *    - Buzzer_Warning: 使用原始报警函数
 */
