/*
 * 文件名：delay.h
 * 功能：延时函数头文件
 * 描述：提供微秒级和毫秒级延时函数声明
 * 作者：[作者名]
 * 日期：2025/08/27
 */

#ifndef __DELAY_H__
#define __DELAY_H__

#include "reg52.h" 

/*
 * 函数名：delay_us
 * 功能：微秒级延时函数
 * 参数：t - 延时时间（微秒）
 * 返回值：无
 */
void delay_us(unsigned int t);

/*
 * 函数名：delay_ms
 * 功能：毫秒级延时函数
 * 参数：t - 延时时间（毫秒）
 * 返回值：无
 */
void delay_ms(unsigned int t);

#endif