#ifndef __PARA_16_H
#define __PARA_16_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"
#include "global.h"
#include "timer.h"

void Error_Handler(void);

void TFT_Send_A_2Byte_To_TFT_DataPins(uint32_t command);
void Write_Command(uint32_t command);
void Write_Command_init(uint32_t command);
void Write_Data(uint32_t data);

#ifdef __cplusplus
}
#endif


#endif /* __PARA_16_H */
