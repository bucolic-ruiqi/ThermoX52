/*
 * MLX90614红外温度计主程序
 * 功能：温度测量、LCD显示、按键调节阈值、超温报警
 */

#include "reg52.h"
#include "delay.h"
#include "lcd1602.h"
#include "mlx90614.h"
#include "key.h"
#include "buzzer.h"
#include <stdio.h>

void main() {
    float temp;
    unsigned char key;
    unsigned int threshold=38;      // 默认阈值38℃
    char buf[16];
    unsigned char connection_ok;

    // 系统初始化
    LCD_Init();
    MLX90614_Init();
    BEEP=1;

    // 开机动画
    LCD_WriteCmd(0x01);
    LCD_PrintString(0,3,"T");
    delay_ms(150);
    LCD_PrintString(0,3,"Th");
    delay_ms(150);
    LCD_PrintString(0,3,"The");
    delay_ms(150);
    LCD_PrintString(0,3,"Ther");
    delay_ms(150);
    LCD_PrintString(0,3,"Therm");
    delay_ms(150);
    LCD_PrintString(0,3,"Thermo");
    delay_ms(150);
    LCD_PrintString(0,3,"ThermoX");
    delay_ms(150);
    LCD_PrintString(0,3,"ThermoX5");
    delay_ms(150);
    LCD_PrintString(0,3,"ThermoX52");
    delay_ms(800);
    
    // 显示版本信息
    LCD_PrintString(1,6,"v1.0");
    delay_ms(1000);
    
    // 清屏显示最终标题
    LCD_WriteCmd(0x01);
    delay_ms(5);                // 等待清屏完成
    LCD_PrintString(0,0,"ThermoX52");
    
    // 检查传感器连接
    connection_ok = MLX90614_CheckConnection();
    if(connection_ok) {
        LCD_PrintString(1,0,"Sensor OK");
    } else {
        LCD_PrintString(1,0,"Sensor Error!");
    }
    delay_ms(2000);

    // 主循环
    while(1) {
        key=Key_Scan();
        
        if(key==1) {                // 测温
            temp=MLX90614_ReadTemp();
            
            LCD_WriteCmd(0x01);     // 清屏
            delay_ms(5);            // 等待清屏完成
            LCD_PrintString(0,0,"ThermoX52");
            
            if(temp == -999.0) {
                LCD_PrintString(1,0,"Read Error!");
            } else {
                sprintf(buf,"T:%.1fC",temp);
                LCD_PrintString(1,0,buf);
                
                // 超温报警
                if(temp>threshold) {
                    Buzzer_Warning(3);
                    // 显示警告信息
                    LCD_WriteCmd(0x01);     // 清屏
                    delay_ms(5);
                    LCD_PrintString(0,0,"ThermoX52");
                    LCD_PrintString(1,0,"Warning!");
                    delay_ms(2000);         // 显示2秒警告
                    // 恢复温度显示
                    LCD_WriteCmd(0x01);
                    delay_ms(5);
                    LCD_PrintString(0,0,"ThermoX52");
                    sprintf(buf,"T:%.1fC",temp);
                    LCD_PrintString(1,0,buf);
                }
            }
        }
        else if(key==2) {           // 调高阈值
            threshold++;
            LCD_WriteCmd(0x01);     // 清屏
            delay_ms(5);            // 等待清屏完成
            LCD_PrintString(0,0,"ThermoX52");
            sprintf(buf,"Th:%dC",threshold);
            LCD_PrintString(1,0,buf);
            delay_ms(1000);
        }
        else if(key==3) {           // 调低阈值
            threshold--;
            LCD_WriteCmd(0x01);     // 清屏
            delay_ms(5);            // 等待清屏完成
            LCD_PrintString(0,0,"ThermoX52");
            sprintf(buf,"Th:%dC",threshold);
            LCD_PrintString(1,0,buf);
            delay_ms(1000);
        }
        
        delay_ms(100);
    }
}
