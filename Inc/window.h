#ifndef __WINDOW_H
#define __WINDOW_H

#include "stm32f4xx_hal.h"
#include "global.h"
#include "tools.h"

void init_window(window* w);
uint8_t add_text_to_window(window* w, text* t);

#endif /* __WINDOW_H */
