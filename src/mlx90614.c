/*
 * 文件名：mlx90614.c
 * 功能：MLX90614红外温度传感器驱动实现
 * 描述：实现通过I2C总线读取MLX90614传感器温度数据的功能
 * 作者：[作者名]
 * 日期：2025/08/27
 */

#include "mlx90614.h"   // MLX90614传感器头文件
#include "i2c_soft.h"   // 软件I2C通信头文件

#define MLX_ADDR 0x5A   // MLX90614传感器的I2C从设备地址

/*
 * 函数名：MLX90614_ReadTemp
 * 功能：读取MLX90614传感器测量的物体温度
 * 参数：无
 * 返回值：温度值（摄氏度，浮点数）
 * 说明：通过I2C总线读取传感器的Tobj1寄存器（0x07）获取物体温度
 */
float MLX90614_ReadTemp(void) {
    unsigned char low,high,pec;     // 低字节、高字节、校验字节
    unsigned int raw;               // 原始温度数据
    float temp;                     // 转换后的温度值
    
    // 第一步：发送读取命令
    I2C_Start();                    // 产生I2C启动信号
    I2C_WriteByte((MLX_ADDR<<1)|0); // 发送写地址（设备地址+写位）
    I2C_WriteByte(0x07);            // 发送寄存器地址（Tobj1物体温度寄存器）
    
    // 第二步：读取温度数据
    I2C_Start();                    // 产生重复启动信号
    I2C_WriteByte((MLX_ADDR<<1)|1); // 发送读地址（设备地址+读位）
    low = I2C_ReadByte(0);          // 读取温度低字节（发送ACK）
    high= I2C_ReadByte(0);          // 读取温度高字节（发送ACK）
    pec = I2C_ReadByte(1);          // 读取PEC校验字节（发送NACK）
    I2C_Stop();                     // 产生I2C停止信号
    
    // 第三步：数据处理和温度转换
    raw=(high<<8)|low;              // 合并高低字节得到16位原始数据
    temp=raw*0.02-273.15;           // 按照MLX90614规格书转换为摄氏度
                                    // 温度 = 原始值 × 0.02 - 273.15
    
    return temp;                    // 返回摄氏度温度值
}