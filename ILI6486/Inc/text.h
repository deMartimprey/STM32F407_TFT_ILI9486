#ifndef __TEXT_H
#define __TEXT_H

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
#include "font16x26.h"
#include "global.h"
#include "tools.h"
#include "draw.h"

uint8_t display_text(text* t, uint16_t window_x, uint16_t window_y);
uint8_t update_text(text* t, uint16_t window_x, uint16_t window_y);


#endif /* __TEXT_H */
