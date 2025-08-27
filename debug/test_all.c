/*
 * 文件名：test_all.c
 * 功能：综合功能测试程序
 * 描述：同时测试所有硬件模块的基本功能
 * 作者：[作者名]
 * 日期：2025/08/27
 * 
 * 测试方法：
 * 1. 编译并烧录到单片机
 * 2. 程序会自动循环测试所有功能
 * 3. 通过按键可以切换不同的测试模式
 * 4. 观察所有硬件模块是否正常工作
 */

#include "reg52.h"
#include "delay.h"
#include "lcd1602.h"
#include "mlx90614.h"
#include "key.h"
#include "buzzer.h"
#include "led.h"
#include <stdio.h>

// 测试模式定义
#define MODE_ALL_TEST    0
#define MODE_LCD_TEST    1
#define MODE_TEMP_TEST   2
#define MODE_KEY_TEST    3
#define MODE_BUZZER_TEST 4
#define MODE_LED_TEST    5

unsigned char test_mode = MODE_ALL_TEST;

// LED测试函数
void Test_LED(void) {
    unsigned char i;
    
    LCD_PrintString(0, 0, "LED Test        ");
    LCD_PrintString(1, 0, "LED Blinking... ");
    
    for(i = 0; i < 5; i++) {
        LED_Warning(1);
        delay_ms(200);
    }
}

// 综合测试模式
void All_Test_Mode(void) {
    static unsigned char test_step = 0;
    float temp;
    char display_str[16];
    unsigned char key;
    
    switch(test_step) {
        case 0:
            // LCD测试
            LCD_PrintString(0, 0, "All Test Mode   ");
            LCD_PrintString(1, 0, "Step1: LCD OK   ");
            break;
            
        case 1:
            // 温度测试
            temp = MLX90614_ReadTemp();
            LCD_PrintString(0, 0, "Step2: Temp Test");
            sprintf(display_str, "T: %.1f C", temp);
            LCD_PrintString(1, 0, display_str);
            break;
            
        case 2:
            // 按键测试
            LCD_PrintString(0, 0, "Step3: Key Test ");
            key = Key_Scan();
            if(key != 0) {
                sprintf(display_str, "Key %d Pressed", key);
                LCD_PrintString(1, 0, display_str);
            } else {
                LCD_PrintString(1, 0, "Press any key...");
            }
            break;
            
        case 3:
            // 蜂鸣器测试
            LCD_PrintString(0, 0, "Step4: Buzzer   ");
            LCD_PrintString(1, 0, "Beep Test...    ");
            BEEP = 0;
            delay_ms(100);
            BEEP = 1;
            break;
            
        case 4:
            // LED测试
            LCD_PrintString(0, 0, "Step5: LED Test ");
            LCD_PrintString(1, 0, "LED Blinking... ");
            LED_Warning(1);
            break;
            
        default:
            test_step = 0;
            return;
    }
    
    delay_ms(1000);
    test_step++;
    if(test_step > 4) test_step = 0;
}

void main() {
    unsigned char key;
    char mode_str[16];
    
    // 系统初始化
    LCD_Init();
    LED_Init();
    BEEP = 1;
    delay_ms(100);
    
    // 显示启动信息
    LCD_PrintString(0, 0, "System Init OK  ");
    LCD_PrintString(1, 0, "Hardware Test   ");
    
    // 启动提示音
    BEEP = 0;
    delay_ms(200);
    BEEP = 1;
    delay_ms(2000);
    
    while(1) {
        // 扫描按键切换模式
        key = Key_Scan();
        if(key == 1) {
            test_mode++;
            if(test_mode > MODE_LED_TEST) test_mode = MODE_ALL_TEST;
            
            // 模式切换提示音
            BEEP = 0;
            delay_ms(50);
            BEEP = 1;
            delay_ms(50);
        }
        
        // 显示当前模式
        switch(test_mode) {
            case MODE_ALL_TEST:
                All_Test_Mode();
                break;
                
            case MODE_LCD_TEST:
                LCD_PrintString(0, 0, "LCD Only Test   ");
                sprintf(mode_str, "Time: %ld", (long)(delay_ms(0)/1000));
                LCD_PrintString(1, 0, mode_str);
                delay_ms(500);
                break;
                
            case MODE_TEMP_TEST:
                {
                    float temp = MLX90614_ReadTemp();
                    LCD_PrintString(0, 0, "Temp Only Test  ");
                    sprintf(mode_str, "Temp: %.1f C", temp);
                    LCD_PrintString(1, 0, mode_str);
                    delay_ms(500);
                }
                break;
                
            case MODE_KEY_TEST:
                LCD_PrintString(0, 0, "Key Only Test   ");
                key = Key_Scan();
                if(key != 0) {
                    sprintf(mode_str, "Key: %d Pressed", key);
                    LCD_PrintString(1, 0, mode_str);
                    delay_ms(300);
                } else {
                    LCD_PrintString(1, 0, "Press KEY2-4... ");
                }
                break;
                
            case MODE_BUZZER_TEST:
                LCD_PrintString(0, 0, "Buzzer Only Test");
                LCD_PrintString(1, 0, "Auto Beeping... ");
                BEEP = 0;
                delay_ms(100);
                BEEP = 1;
                delay_ms(900);
                break;
                
            case MODE_LED_TEST:
                LCD_PrintString(0, 0, "LED Only Test   ");
                LCD_PrintString(1, 0, "Auto Blinking...");
                LED_Warning(1);
                delay_ms(300);
                break;
        }
        
        delay_ms(50);
    }
}

/*
 * 使用说明：
 * 1. 按KEY1切换测试模式：
 *    - 模式0：综合测试（自动循环所有功能）
 *    - 模式1：仅测试LCD显示
 *    - 模式2：仅测试温度传感器
 *    - 模式3：仅测试按键（用KEY2-4测试）
 *    - 模式4：仅测试蜂鸣器
 *    - 模式5：仅测试LED
 * 
 * 2. 故障排除：
 *    - 如果某个模式无法正常工作，说明对应硬件有问题
 *    - 可以单独测试有问题的模块
 *    - 参考各个单独测试文件的调试说明
 * 
 * 3. 正常状态：
 *    - LCD能清晰显示文字
 *    - 温度显示合理数值（室温范围）
 *    - 按键有响应且显示正确
 *    - 蜂鸣器能发出清晰声音
 *    - LED能正常闪烁
 */
