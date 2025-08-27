/*
 * 文件名：test_mlx90614.c
 * 功能：MLX90614温度传感器测试程序
 * 描述：测试MLX90614传感器是否能正常读取温度数据
 * 作者：[作者名]
 * 日期：2025/08/27
 * 
 * 测试方法：
 * 1. 编译并烧录到单片机
 * 2. 观察LCD显示屏是否显示温度值
 * 3. 用手接近传感器，观察温度是否变化
 * 4. 正常情况下应显示室温（约20-30℃）
 */

#include "reg52.h"
#include "delay.h"
#include "lcd1602.h"
#include "mlx90614.h"
#include <stdio.h>

void main() {
    float temp;
    char temp_str[16];
    unsigned int test_count = 0;
    
    // 系统初始化
    LCD_Init();
    delay_ms(100);
    
    // 显示测试标题
    LCD_PrintString(0, 0, "MLX90614 Test");
    LCD_PrintString(1, 0, "Initializing...");
    delay_ms(2000);
    
    while(1) {
        // 清空第二行
        LCD_PrintString(1, 0, "                ");
        
        // 尝试读取温度
        temp = MLX90614_ReadTemp();
        
        // 格式化温度字符串
        sprintf(temp_str, "T:%.1fC #%d", temp, test_count++);
        LCD_PrintString(1, 0, temp_str);
        
        // 温度合理性检查（-40℃到85℃是MLX90614的测量范围）
        if(temp > -40 && temp < 85) {
            // 温度读取正常，在第一行显示状态
            LCD_PrintString(0, 0, "MLX90614: OK   ");
        } else {
            // 温度读取异常，可能是传感器连接问题
            LCD_PrintString(0, 0, "MLX90614: ERROR");
        }
        
        // 每秒更新一次
        delay_ms(1000);
        
        // 防止计数器溢出
        if(test_count > 9999) test_count = 0;
    }
}

/*
 * 调试说明：
 * 1. 如果显示"MLX90614: ERROR"且温度显示异常值：
 *    - 检查I2C接线（SCL接P2.3，SDA接P2.4）
 *    - 检查传感器供电（3.3V或5V）
 *    - 检查传感器地线连接
 * 
 * 2. 如果显示"MLX90614: OK"但温度不变化：
 *    - 传感器通信正常，但可能距离目标太远
 *    - MLX90614是非接触式传感器，检测距离有限
 * 
 * 3. 如果LCD无显示：
 *    - 检查LCD供电和接线
 *    - 检查LCD对比度调节
 */
