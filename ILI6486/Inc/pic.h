#ifndef __PIC_H
#define __PIC_H

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

extern const uint8_t engrenage_bmp[];

#endif /* __PIC_H */
