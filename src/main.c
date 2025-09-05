/*
 * ThermoX52void main() {
    float temp;
    unsigned char key;
    unsigned int threshold=32;      // 发热阈值
    char buf[16];
    char time_str[16];              // 时间显示
    unsigned char connection_ok;

    // 系统初始化
    LCD_Init();
    MLX90614_Init();
    BlueTooth_Init();
    Time_Init(12, 0);               // 初始化时间为12:00
    BEEP=1;

    // 开机显示
    LCD_WriteCmd(0x01);
    LCD_PrintString(0,2,"ThermoX52");
    LCD_PrintString(1,6,"v1.0");
    delay_ms(1000);
    
    // 清屏显示状态功能：MLX90614红外测温、LCD1602显示、按键控制、蓝牙数据传输
 * 硬件：STC89C52、MLX90614、LCD1602、HC-05蓝牙模块
 */

#include "reg52.h"
#include "delay.h"
#include "lcd1602.h"
#include "mlx90614.h"
#include "key.h"
#include "buzzer.h"
#include "rtc_time.h"
#include "bluetooth.h"
#include <stdio.h>

void main() {
    float temp;                     // 补偿后的人体温度
    unsigned char key;
    unsigned int threshold=38;      // 默认阈值38℃
    char buf[16];
    unsigned char connection_ok;

    // 系统初始化
    LCD_Init();
    MLX90614_Init();
    BlueTooth_Init();               // 初始化蓝牙
    BEEP=1;

    // 简单开机显示
    LCD_WriteCmd(0x01);
    LCD_PrintString(0,2,"ThermoX52");
    LCD_PrintString(1,6,"v1.0");
    delay_ms(1000);
    
    // 清屏显示状态
    LCD_WriteCmd(0x01);
    delay_ms(5);
    Time_GetString(time_str);
    LCD_PrintString(0,0,time_str);   // 第一行显示时间
    
    // 发送蓝牙启动信息
    delay_ms(500);  // 等待蓝牙模块稳定
    BlueTooth_SendData('S');
    BlueTooth_SendData('t');
    BlueTooth_SendData('a');
    BlueTooth_SendData('r');
    BlueTooth_SendData('t');
    BlueTooth_SendData('\r');
    BlueTooth_SendData('\n');
    
    // 检查传感器连接
    connection_ok = MLX90614_CheckConnection();
    if(connection_ok) {
        LCD_PrintString(1,0,"Sensor OK");
        BlueTooth_SendData('O');
        BlueTooth_SendData('K');
        BlueTooth_SendData('\r');
        BlueTooth_SendData('\n');
    } else {
        LCD_PrintString(1,0,"Sensor Error!");
        BlueTooth_SendData('E');
        BlueTooth_SendData('R');
        BlueTooth_SendData('R');
        BlueTooth_SendData('\r');
        BlueTooth_SendData('\n');
    }
    delay_ms(2000);

    // 主循环
    while(1) {
        // 更新时间显示
        Time_Update();
        Time_GetString(time_str);
        LCD_PrintString(0,0,time_str);   // 第一行始终显示时间
        key=Key_Scan();
        
        if(key==1) {                // 测温
            Buzzer_KeyBeep();
            temp=MLX90614_ReadCompensatedTemp();
            
            // 只清除第二行，保持时间显示
            LCD_PrintString(1,0,"                ");  // 清除第二行
            
            if(temp == -999.0) {
                LCD_PrintString(1,0,"Read Error!");
            } else {
                sprintf(buf,"T:%.1fC",temp);
                LCD_PrintString(1,0,buf);
                
                // 蓝牙发送温度数据
                delay_ms(100);
                BlueTooth_SendTemp_Char(temp);
                
                // 超温报警
                if(temp>threshold) {
                    Buzzer_Warning(3);
                    LCD_PrintString(1,0,"Warning!");
                    delay_ms(2000);
                    // 恢复温度显示
                    sprintf(buf,"T:%.1fC",temp);
                    LCD_PrintString(1,0,buf);
                }
            }
        }
        else if(key==2) {           // 调高阈值
            Buzzer_KeyBeep();
            threshold++;
            LCD_PrintString(1,0,"                ");  // 清除第二行
            sprintf(buf,"Th:%dC",threshold);
            LCD_PrintString(1,0,buf);
            delay_ms(1000);
        }
        else if(key==3) {           // 调低阈值
            Buzzer_KeyBeep();
            threshold--;
            LCD_PrintString(1,0,"                ");  // 清除第二行
            sprintf(buf,"Th:%dC",threshold);
            LCD_PrintString(1,0,buf);
            delay_ms(1000);
        }
        
        delay_ms(100);
    }
}
