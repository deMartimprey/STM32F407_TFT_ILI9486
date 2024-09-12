#ifndef __EFFECT_H
#define __EFFECT_H

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
#include "ili9486.h"
#include "font5x7.h"
#include "font10x16.h"
#include "font16x26.h"
#include "global.h"
#include "math.h"

void Error_Handler(void);

void fill_with_RGB();
void fill_with_Color(uint16_t color);
  void sleep_screen_str2(uint8_t* str, uint16_t len_str, uint16_t color_str, uint16_t color_font);
  void sleep_screen_str(uint8_t* str, uint16_t len_str, uint16_t color_str, uint16_t color_font);

#ifdef __cplusplus
}
#endif


#endif /* __EFFECT_H */
