/* 蜂鸣器报警头文件 */

#ifndef __BUZZER_H__
#define __BUZZER_H__

#include "reg52.h"      // 52单片机寄存器定义

// 蜂鸣器控制引脚定义
sbit BEEP = P2^3;       // 蜂鸣器控制引脚（低电平有效）

void Buzzer_Warning(unsigned int n);

#endif