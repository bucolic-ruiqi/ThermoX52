/*
 * 蜂鸣器报警实现
 */

#include "buzzer.h"   
#include "delay.h"   

// 蜂鸣器报警（响n次）- 优化版本
void Buzzer_Warning(unsigned int n) {
    unsigned char i;
    while(n--) {
        // 产生清晰的三段式警告音：高-中-高
        
        // 第一段：高频急促音（紧急感）
        for(i=0; i<50; i++) {
            BEEP=0;         
            delay_ms(1);    // 1ms高频脉冲
            BEEP=1;         
            delay_ms(1);
        }
        delay_ms(80);       // 短暂停顿
        
        // 第二段：中频持续音（警告内容）
        for(i=0; i<40; i++) {
            BEEP=0;         
            delay_ms(3);    // 3ms中频脉冲
            BEEP=1;         
            delay_ms(3);
        }
        delay_ms(80);       // 短暂停顿
        
        // 第三段：高频急促音（强调）
        for(i=0; i<50; i++) {
            BEEP=0;         
            delay_ms(1);    // 1ms高频脉冲
            BEEP=1;         
            delay_ms(1);
        }
        
        if(n > 0) {
            delay_ms(400);  // 警告音之间的停顿
        }
    }
}

// 按键成功提示音
void Buzzer_KeyBeep(void) {
    unsigned char i;
    
    // 产生短促轻快的按键确认音
    for(i=0; i<20; i++) {
        BEEP=0;         
        delay_ms(2);    // 2ms脉冲产生清脆音
        BEEP=1;         
        delay_ms(2);
    }
}