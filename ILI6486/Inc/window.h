#ifndef __WINDOW_H
#define __WINDOW_H

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
#include "bmp_reader.h"
#include "global.h"
#include "router.h"
#include "tools.h"
#include "draw.h"
#include "text.h"

void init_window(window* w);
uint8_t add_text_to_window(window* w, text* t);
uint8_t add_draw_to_window(window* w, draw* d);
uint8_t add_router_to_window(window* w, router* r);
uint8_t display_window(window* w, uint16_t view_x, uint16_t view_y);
uint8_t display_select_window(window* w, uint16_t view_x, uint16_t view_y);
uint8_t update_window(window* w, uint16_t view_x, uint16_t view_y);
uint8_t update_select_window(window* w, uint16_t view_x, uint16_t view_y);
uint8_t add_bmp_to_window(window* w, bmp* b);

#endif /* __WINDOW_H */
