#ifndef __VIEW_H
#define __VIEW_H

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
#include "global.h"
#include "window.h"
#include "effect.h"
#include "tools.h"
#include "draw.h"

uint8_t add_one_window(view* v, window* win);
void init_view(view* v);
void view_right(view* v);
void view_left(view* v);
uint8_t display_view();
uint8_t update_view(view* v);

#endif /* __VIEW_H */
