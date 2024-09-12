#ifndef __TOOLS_H
#define __TOOLS_H

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

void Error_Handler(void);
uint16_t my_strlen(const uint8_t *s);
uint8_t* my_strncpy(uint8_t *dst, const uint8_t *src, register int n);
void fill_string_with_space(uint8_t* str, uint8_t size);
void num32ToString(uint8_t* str, uint32_t nb);

#ifdef __cplusplus
}
#endif

#endif /* __TOOLS_H */
