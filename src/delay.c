/*
 * 延时函数实现
 */

#include "delay.h"     
#include <intrins.h>   

// 微秒延时（12MHz晶振）
void delay_us(unsigned int t) {
    while(t--) { 
        _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
        _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
    }
}

// 毫秒延时
void delay_ms(unsigned int t) {
    unsigned int i;
    while(t--) {
        for(i=0;i<120;i++) _nop_();
    }
}