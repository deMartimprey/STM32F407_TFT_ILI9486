#ifndef __NAVIGATION_H
#define __NAVIGATION_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"
#include "global.h"
#include "router.h"
#include "menu.h"

void check_nav();
void nav_up();
void nav_down();
void nav_right();
void nav_left();
void nav_valid();
void nav_back();

#ifdef __cplusplus
}
#endif

#endif /* __NAVIGATION_H */
