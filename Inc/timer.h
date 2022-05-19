#ifndef __TIMER_H
#define __TIMER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"
#include "global.h"

void Error_Handler(void);

void delay_init ();
void delay_us (uint16_t delay);
  
#ifdef __cplusplus
}
#endif


#endif /* __TIMER_H */
