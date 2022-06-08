#ifndef __TOOLS_H
#define __TOOLS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"

void Error_Handler(void);
uint16_t my_strlen(const uint8_t *s);
uint8_t* my_strncpy(uint8_t *dst, const uint8_t *src, register int n);
void fill_string_with_space(uint8_t* str, uint8_t size);

#ifdef __cplusplus
}
#endif

#endif /* __TOOLS_H */
