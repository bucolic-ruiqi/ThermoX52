/*
 * 简单时间管理模块实现
 */

#include "rtc_time.h"

// 全局时间变量
static TimeStruct current_time = {12, 0, 0};  // 默认12:00:00
static unsigned int tick_counter = 0;

// 初始化时间
void Time_Init(unsigned char hour, unsigned char minute) {
    if(hour < 24 && minute < 60) {
        current_time.hour = hour;
        current_time.minute = minute;
        current_time.second = 0;
    }
    tick_counter = 0;
}

// 更新时间（需要在主循环中定期调用，约每100ms调用一次）
void Time_Update(void) {
    tick_counter++;
    
    // 每10次调用（约1秒）更新一次秒钟
    if(tick_counter >= 10) {
        tick_counter = 0;
        current_time.second++;
        
        if(current_time.second >= 60) {
            current_time.second = 0;
            current_time.minute++;
            
            if(current_time.minute >= 60) {
                current_time.minute = 0;
                current_time.hour++;
                
                if(current_time.hour >= 24) {
                    current_time.hour = 0;
                }
            }
        }
    }
}

// 获取时间字符串（格式：HH:MM）
void Time_GetString(char* time_str) {
    // 手动构建时间字符串，避免sprintf的兼容性问题
    time_str[0] = (current_time.hour / 10) + '0';    // 小时十位
    time_str[1] = (current_time.hour % 10) + '0';    // 小时个位
    time_str[2] = ':';                               // 冒号
    time_str[3] = (current_time.minute / 10) + '0';  // 分钟十位
    time_str[4] = (current_time.minute % 10) + '0';  // 分钟个位
    time_str[5] = '\0';                              // 字符串结束符
}

// 获取当前时间结构体
TimeStruct* Time_Get(void) {
    return &current_time;
}
