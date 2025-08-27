/* 延时函数 */
#include "delay.h"     
#include <intrins.h>   

/*
 * 函数名：delay_us
 * 功能：微秒级延时函数
 * 参数：t - 延时时间（微秒）
 * 返回值：无
 * 说明：使用_nop_()空操作指令实现精确的微秒级延时
 */
void delay_us(unsigned int t) {
    while(t--) { 
        _nop_();        // 空操作指令，消耗1个机器周期
        _nop_();        // 空操作指令，消耗1个机器周期
    }
}

/*
 * 函数名：delay_ms
 * 功能：毫秒级延时函数
 * 参数：t - 延时时间（毫秒）
 * 返回值：无
 * 说明：通过循环和空操作指令实现毫秒级延时
 */
void delay_ms(unsigned int t) {
    unsigned int i;     // 循环计数变量
    while(t--) {
        // 内层循环产生约1毫秒的延时
        for(i=0;i<120;i++) _nop_();
    }
}