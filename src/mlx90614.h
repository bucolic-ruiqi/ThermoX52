/*
 * MLX90614红外温度传感器驱动
 */

#ifndef __MLX90614_H__
#define __MLX90614_H__

#include "reg52.h"

// 函数声明
void MLX90614_Init(void);
unsigned char MLX90614_CheckConnection(void);
float MLX90614_ReadTemp(void);
float MLX90614_ReadAmbientTemp(void);
float MLX90614_ReadCompensatedTemp(void);

#endif