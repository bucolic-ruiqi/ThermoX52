/*
 * 蜂鸣器报警实现
 */

#include "buzzer.h"   
#include "delay.h"   

// 蜂鸣器报警（响n次）
void Buzzer_Warning(unsigned int n) {
    while(n--) {
        BEEP=0;         // 开启蜂鸣器
        delay_ms(200);
        BEEP=1;         // 关闭蜂鸣器
        delay_ms(200);
    }
}