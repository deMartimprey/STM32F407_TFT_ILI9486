#ifndef __WINDOW_H
#define __WINDOW_H

#include "stm32f4xx_hal.h"
#include "global.h"
#include "tools.h"
#include "draw.h"
#include "text.h"

void init_window(window* w);
uint8_t add_text_to_window(window* w, text* t);
uint8_t display_window(window* w, uint16_t view_x, uint16_t view_y);

#endif /* __WINDOW_H */
