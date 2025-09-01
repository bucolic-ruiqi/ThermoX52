/*
 * 按键扫描实现
 */

#include "key.h"
#include "delay.h"

// 按键扫描（带消抖）
unsigned char Key_Scan(void) {
    if(!KEY1) { 
        delay_ms(10);
        if(!KEY1) return 1;
    }
    
    if(!KEY2) { 
        delay_ms(10);
        if(!KEY2) return 2;
    }
    
    if(!KEY3) { 
        delay_ms(10);
        if(!KEY3) return 3;
    }
    
    return 0;
}