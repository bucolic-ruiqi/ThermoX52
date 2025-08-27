/* 实现蜂鸣器的报警功能，用于温度超标提醒 */


#include "buzzer.h"   
#include "delay.h"   


void Buzzer_Warning(unsigned int n) {
    while(n--) {
        BEEP=0;         // 蜂鸣器开启（低电平有效）
        delay_ms(200);  // 持续响200毫秒
        BEEP=1;         // 蜂鸣器关闭（高电平关闭）
        delay_ms(200);  // 停止200毫秒
    }
}