/*
 * MLX90614红外温度传感器驱动
 */

#include "mlx90614.h"
#include "i2c_soft.h"
#include "delay.h"

// 全局补偿系数变量 - 可根据实际使用情况调整
static float g_compensation_factor = 0.06;  // 默认补偿系数0.06

// 初始化MLX90614
void MLX90614_Init(void) {
    SCL = 1;
    SDA = 1;
    delay_ms(250);      // 等待传感器稳定
}

// 检查传感器连接
unsigned char MLX90614_CheckConnection(void) {
    unsigned char ack;
    
    I2C_Start();
    ack = I2C_WriteByte(0x00);      // MLX90614写地址
    I2C_Stop();
    
    return (ack == 0) ? 1 : 0;
}

// 读取温度
float MLX90614_ReadTemp(void) {
    unsigned char low,high,pec;
    unsigned int raw;
    float temp;
    unsigned char ack1, ack2, ack3;
    unsigned char retry = 3;
    
    while(retry--) {
        // 发送读取命令
        I2C_Start();
        ack1 = I2C_WriteByte(0x00);     // 设备地址
        if(ack1 != 0) {
            I2C_Stop();
            delay_ms(10);
            continue;
        }
        
        ack2 = I2C_WriteByte(0x07);     // 温度寄存器地址
        if(ack2 != 0) {
            I2C_Stop();
            delay_ms(10);
            continue;
        }
        
        // 切换到读模式
        I2C_Start();
        ack3 = I2C_WriteByte(0x01);     // 读地址
        if(ack3 != 0) {
            I2C_Stop();
            delay_ms(10);
            continue;
        }
        
        // 读取数据
        low = I2C_ReadByte(0);          // 低字节
        high= I2C_ReadByte(0);          // 高字节
        pec = I2C_ReadByte(1);          // 校验字节
        I2C_Stop();
        
        // 数据处理
        raw=(high<<8)|low;
        
        if(raw == 0xFFFF || raw == 0x0000) {
            delay_ms(10);
            continue;
        }
        
        temp=raw*0.02-273.15;           // 转换为摄氏度
        
        if(temp < -40.0 || temp > 125.0) {
            delay_ms(10);
            continue;
        }
        
        return temp;
    }
    
    return -999.0;                      // 读取失败
}

// 读取环境温度
float MLX90614_ReadAmbientTemp(void) {
    unsigned char low,high,pec;
    unsigned int raw;
    float temp;
    unsigned char ack1, ack2, ack3;
    unsigned char retry = 3;
    
    while(retry--) {
        // 发送读取命令
        I2C_Start();
        ack1 = I2C_WriteByte(0x00);     // 设备地址
        if(ack1 != 0) {
            I2C_Stop();
            delay_ms(10);
            continue;
        }
        
        ack2 = I2C_WriteByte(0x06);     // 环境温度寄存器地址(Ta)
        if(ack2 != 0) {
            I2C_Stop();
            delay_ms(10);
            continue;
        }
        
        // 切换到读模式
        I2C_Start();
        ack3 = I2C_WriteByte(0x01);     // 读地址
        if(ack3 != 0) {
            I2C_Stop();
            delay_ms(10);
            continue;
        }
        
        // 读取数据
        low = I2C_ReadByte(0);          // 低字节
        high= I2C_ReadByte(0);          // 高字节
        pec = I2C_ReadByte(1);          // 校验字节
        I2C_Stop();
        
        // 数据处理
        raw=(high<<8)|low;
        
        if(raw == 0xFFFF || raw == 0x0000) {
            delay_ms(10);
            continue;
        }
        
        temp=raw*0.02-273.15;           // 转换为摄氏度
        
        if(temp < -40.0 || temp > 85.0) {
            delay_ms(10);
            continue;
        }
        
        return temp;
    }
    
    return -999.0;                      // 读取失败
}

// 读取补偿后的人体温度
float MLX90614_ReadCompensatedTemp(void) {
    float object_temp, ambient_temp, compensated_temp;
    
    // 读取物体温度
    object_temp = MLX90614_ReadTemp();
    if(object_temp == -999.0) {
        return -999.0;  // 物体温度读取失败
    }
    
    // 读取环境温度
    ambient_temp = MLX90614_ReadAmbientTemp();
    if(ambient_temp == -999.0) {
        return -999.0;  // 环境温度读取失败
    }
    
    // 应用简单的补偿公式
    // Compensated Temperature = Object Temperature + (Compensation Factor * Ambient Temperature)
    compensated_temp = object_temp + (g_compensation_factor * ambient_temp);
    
    // 人体温度合理性检查
    if(compensated_temp < 35.0) {
        compensated_temp = 35.0;    // 最低人体温度
    } else if(compensated_temp > 42.0) {
        compensated_temp = 42.0;    // 最高合理人体温度
    }
    
    return compensated_temp;
}