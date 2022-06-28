#ifndef __DRAW_H
#define __DRAW_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"
#include "para_16.h"
#include "ili9486.h"
#include "global.h"
#include "math.h"

void Error_Handler(void);

uint8_t display_draw(draw* d, uint16_t window_x, uint16_t window_y);
uint8_t update_draw(draw* d, uint16_t window_x, uint16_t window_y);
uint8_t draw_rectangle(uint16_t x, uint16_t y, uint16_t x_size, uint16_t y_size, uint16_t color);
void DrawCircle(uint16_t x, uint16_t y, uint16_t r, uint16_t color);
void DrawCircle2(uint16_t x, uint16_t y, uint16_t r, uint16_t color);
uint8_t draw_empty_rectangle(uint16_t x_pos, uint16_t y_pos, uint16_t x_size, uint16_t y_size, uint16_t thickness, uint16_t color);
void DrawFillCircle(uint16_t x_pos, uint16_t y_pos, uint16_t r, uint16_t color);
void draw_thick_line(float x0, float y0, float x1, float y1, uint16_t thickness, uint16_t color);
void fill_triangle(int x1, int y1, int x2, int y2, int x3, int y3, uint16_t color);

#ifdef __cplusplus
}
#endif


#endif /* __DRAW_H */
