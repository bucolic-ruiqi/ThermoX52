/*
 * MLX90614红外温度传感器驱动
 */

#include "mlx90614.h"
#include "i2c_soft.h"
#include "delay.h"

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