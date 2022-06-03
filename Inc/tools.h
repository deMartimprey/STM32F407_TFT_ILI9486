#ifndef __TOOLS_H
#define __TOOLS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"

void Error_Handler(void);
uint16_t my_strlen(const uint8_t *s);


#ifdef __cplusplus
}
#endif

#endif /* __TOOLS_H */
