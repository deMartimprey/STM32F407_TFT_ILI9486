#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"
#include "para_16.h"
#include "ili9486.h"
#include "font5x7.h"
#include "font10x16.h"
#include "global.h"
#include "effect.h"
#include "timer.h"
#include "draw.h"

void Error_Handler(void);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
