#ifndef __DRAW_H
#define __DRAW_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"
#include "para_16.h"
#include "ili9486.h"
#include "global.h"

void Error_Handler(void);

uint8_t draw_rectangle(uint16_t x, uint16_t y, uint16_t x_size, uint16_t y_size, uint16_t color);
void DrawCircle(uint16_t x, uint16_t y, uint16_t r, uint16_t color);
void DrawCircle2(uint16_t x, uint16_t y, uint16_t r, uint16_t color);

#ifdef __cplusplus
}
#endif


#endif /* __DRAW_H */