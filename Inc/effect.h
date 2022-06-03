#ifndef __EFFECT_H
#define __EFFECT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"
#include "para_16.h"
#include "ili9486.h"
#include "global.h"
#include "math.h"

void Error_Handler(void);

void fill_with_RGB();
void fill_with_Color(uint16_t color);

#ifdef __cplusplus
}
#endif


#endif /* __EFFECT_H */
