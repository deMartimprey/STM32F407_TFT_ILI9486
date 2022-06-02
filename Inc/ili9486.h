#ifndef __ILI9486_H
#define __ILI9486_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"
#include "para_16.h"
#include "global.h"

void Error_Handler(void);

void Initialization();
void pos_pixel(uint16_t x, uint16_t y);
  
#ifdef __cplusplus
}
#endif


#endif /* __ILI9486_H */
