#ifndef __ILI9486_H
#define __ILI9486_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef STM32F103xE
#include "stm32f1xx_hal.h"
#endif
#ifdef STM32F207xx
#include "stm32f2xx_hal.h"
#endif
#ifdef STM32F429xx
#include "stm32f4xx_hal.h"
#endif
#ifdef STM32F407xx
#include "stm32f4xx_hal.h"
#endif
#include "para_16.h"
#include "global.h"

void Error_Handler(void);

void Initialization();
void write_one_pixel(uint16_t x, uint16_t y, uint16_t color);
void pos_pixel(uint16_t x, uint16_t y);
void write_zone(uint16_t x, uint16_t y, uint16_t x_size, uint16_t y_size);
void write_one_pixel_buffer(uint16_t** buffer, uint16_t x, uint16_t y, uint16_t color);

#ifdef __cplusplus
}
#endif


#endif /* __ILI9486_H */
