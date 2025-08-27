/*
 * 文件名：test_keys.c
 * 功能：按键功能测试程序
 * 描述：测试所有按键是否能正常响应
 * 作者：[作者名]
 * 日期：2025/08/27
 * 
 * 测试方法：
 * 1. 编译并烧录到单片机
 * 2. 依次按下KEY1、KEY2、KEY3、KEY4
 * 3. 观察LCD显示屏是否显示对应的按键信息
 * 4. 检查按键计数是否正确递增
 */

#include "reg52.h"
#include "delay.h"
#include "lcd1602.h"
#include "key.h"
#include <stdio.h>

void main() {
    unsigned char key_value;
    unsigned int key1_count = 0;
    unsigned int key2_count = 0;
    unsigned int key3_count = 0;
    unsigned int key4_count = 0;
    char display_str[16];
    
    // 系统初始化
    LCD_Init();
    delay_ms(100);
    
    // 显示测试标题
    LCD_PrintString(0, 0, "Key Test Ready");
    LCD_PrintString(1, 0, "Press any key...");
    delay_ms(2000);
    
    while(1) {
        // 扫描按键
        key_value = Key_Scan();
        
        if(key_value != 0) {
            // 有按键按下，更新相应计数器
            switch(key_value) {
                case 1:
                    key1_count++;
                    LCD_PrintString(0, 0, "KEY1 Pressed!  ");
                    sprintf(display_str, "Count: %d", key1_count);
                    LCD_PrintString(1, 0, display_str);
                    break;
                    
                case 2:
                    key2_count++;
                    LCD_PrintString(0, 0, "KEY2 Pressed!  ");
                    sprintf(display_str, "Count: %d", key2_count);
                    LCD_PrintString(1, 0, display_str);
                    break;
                    
                case 3:
                    key3_count++;
                    LCD_PrintString(0, 0, "KEY3 Pressed!  ");
                    sprintf(display_str, "Count: %d", key3_count);
                    LCD_PrintString(1, 0, display_str);
                    break;
                    
                case 4:
                    key4_count++;
                    LCD_PrintString(0, 0, "KEY4 Pressed!  ");
                    sprintf(display_str, "Count: %d", key4_count);
                    LCD_PrintString(1, 0, display_str);
                    break;
            }
            
            // 按键响应后延时，避免连续触发
            delay_ms(300);
            
            // 显示所有按键统计
            sprintf(display_str, "1:%d 2:%d 3:%d 4:%d", 
                    key1_count % 100, key2_count % 100, 
                    key3_count % 100, key4_count % 100);
            LCD_PrintString(1, 0, display_str);
        }
        
        // 短暂延时，提高扫描效率
        delay_ms(50);
    }
}

/*
 * 调试说明：
 * 1. 如果某个按键无响应：
 *    - 检查对应按键的接线（KEY1-P3.2, KEY2-P3.3, KEY3-P3.4, KEY4-P3.5）
 *    - 检查按键是否需要上拉电阻
 *    - 检查按键的机械接触
 * 
 * 2. 如果按键有误触发：
 *    - 可能是硬件抖动，增加消抖延时
 *    - 检查按键周围是否有干扰信号
 * 
 * 3. 如果所有按键都无响应：
 *    - 检查P3口的供电
 *    - 检查单片机P3口功能是否正常
 * 
 * 4. 计数显示格式：
 *    - 第一行显示当前按键状态
 *    - 第二行显示各按键按下次数（最大显示99）
 */
