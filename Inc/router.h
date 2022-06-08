#ifndef __ROUTER_H
#define __ROUTER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"
#include "font10x16.h"
#include "ili9486.h"
#include "global.h"
#include "tools.h"

void Error_Handler(void);

uint8_t add_elem_router(router* my_router, router* router_to_add);
void display_router(router* my_router, uint16_t x_pos, uint8_t y_pos);
void router_down(router *my_router);
void router_up(router *my_router);

#ifdef __cplusplus
}
#endif

#endif /* __ROUTER_H */
