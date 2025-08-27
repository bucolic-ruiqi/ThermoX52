/*
 * 文件名：main.c
 * 功能：基于STC89C52单片机的MLX90614红外温度计主程序
 * 描述：使用MLX90614红外温度传感器测量温度，通过LCD1602显示，
 *       支持按键调节阈值温度，温度超标时LED和蜂鸣器报警
 * 作者：[作者名]
 * 日期：2025/08/27
 */

#include "reg52.h"      // 52单片机寄存器定义
#include "delay.h"      // 延时函数头文件
#include "lcd1602.h"    // LCD1602显示屏驱动头文件
#include "mlx90614.h"   // MLX90614温度传感器驱动头文件
#include "key.h"        // 按键扫描头文件
#include "buzzer.h"     // 蜂鸣器报警头文件
#include <stdio.h>      // 标准输入输出头文件

/*
 * 函数名：main
 * 功能：主程序入口，控制整个系统的运行逻辑
 * 参数：无
 * 返回值：无
 */
void main() {
    float temp;                     // 温度值变量
    unsigned char key;              // 按键值变量
    unsigned int threshold=38;      // 阈值温度（默认38℃）

    // 系统初始化
    LCD_Init();                     // 初始化LCD1602显示屏
    BEEP=1;                         // 蜂鸣器初始化为关闭状态

    // 显示系统标题
    LCD_PrintString(0,0,"MLX90614 Demo");

    // 主循环
    while(1) {
        key=Key_Scan();             // 扫描按键状态
        
        if(key==1) {                // 按键1：测温功能
            temp=MLX90614_ReadTemp(); // 读取MLX90614传感器温度值
            char buf[16];             // 字符串缓冲区
            sprintf(buf,"T:%.1fC",temp); // 格式化温度字符串
            LCD_PrintString(1,0,buf); // 在LCD第二行显示温度
            
            // 高温报警（超过阈值温度时蜂鸣器报警）
            if(temp>threshold)
                Buzzer_Warning(3);    // 蜂鸣器响3次报警
        }
        else if(key==2) {           // 按键2：调高阈值温度
            threshold++;            // 阈值温度加1
        }
        else if(key==3) {           // 按键3：调低阈值温度
            threshold--;            // 阈值温度减1
        }
    }
}
