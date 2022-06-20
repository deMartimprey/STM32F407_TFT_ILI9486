#ifndef __TEXT_H
#define __TEXT_H

#include "stm32f4xx_hal.h"
#include "font16x26.h"
#include "global.h"
#include "tools.h"
#include "draw.h"

uint8_t display_text(text* t, uint16_t window_x, uint16_t window_y);
uint8_t update_text(text* t, uint16_t window_x, uint16_t window_y);


#endif /* __TEXT_H */
