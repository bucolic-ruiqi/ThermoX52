/*
 * 简单时间管理模块
 * 用于显示当前时间（时:分）
 */

#ifndef __RTC_TIME_H__
#define __RTC_TIME_H__

// 时间结构体
typedef struct {
    unsigned char hour;     // 小时 (0-23)
    unsigned char minute;   // 分钟 (0-59)
    unsigned char second;   // 秒钟 (0-59)
} TimeStruct;

// 函数声明
void Time_Init(unsigned char hour, unsigned char minute);
void Time_Update(void);
void Time_GetString(char* time_str);
TimeStruct* Time_Get(void);

#endif
