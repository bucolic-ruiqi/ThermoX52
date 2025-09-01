/*
 * 按键扫描驱动
 */

#ifndef __KEY_H__
#define __KEY_H__

#include "reg52.h"

// 按键引脚（低电平有效）
sbit KEY1 = P2^2;       // 测温
sbit KEY2 = P2^1;       // 调高阈值
sbit KEY3 = P2^0;       // 调低阈值

// 函数声明
unsigned char Key_Scan(void);

#endif