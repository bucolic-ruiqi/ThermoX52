/*
 * 蜂鸣器报警驱动
 */

#ifndef __BUZZER_H__
#define __BUZZER_H__

#include "reg52.h"

// 蜂鸣器控制引脚（低电平有效）
sbit BEEP = P2^3;

void Buzzer_Warning(unsigned int n);
void Buzzer_KeyBeep(void);

#endif