#ifndef __VIEW_H
#define __VIEW_H

#include "stm32f4xx_hal.h"
#include "global.h"
#include "tools.h"
#include "draw.h"

uint8_t add_one_window(view* v, window* win);
void init_view(view* v);
uint8_t display_view();

#endif /* __VIEW_H */
