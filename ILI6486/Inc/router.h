#ifndef __ROUTER_H
#define __ROUTER_H

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
#include "font16x26.h"
#include "ili9486.h"
#include "global.h"
#include "tools.h"
#include "menu.h"

void Error_Handler(void);

void init_router(router *r);
void back_router(router *my_router);
uint8_t add_elem_router(router* my_router, router* router_to_add);
void display_router(router* my_router, uint16_t x_pos, uint16_t y_pos);
void display_router26(router* my_router, uint16_t x_pos, uint16_t y_pos);
void router_down(router *my_router);
void router_up(router *my_router);
void into_router(router *my_router);
uint8_t add_menu_router(router* my_router, menu* menu_to_add);

#ifdef __cplusplus
}
#endif

#endif /* __ROUTER_H */
