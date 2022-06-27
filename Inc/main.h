#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"
#include "pic.h"
#include "navigation.h"
#include "bmp_reader.h"
#include "font10x16.h"
#include "font16x26.h"
#include "para_16.h"
#include "ili9486.h"
#include "font5x7.h"
#include "window.h"
#include "effect.h"
#include "router.h"
#include "global.h"
#include "timer.h"
#include "view.h"
#include "draw.h"
#include "menu.h"
#include "text.h"
#include "var.h"

void Error_Handler(void);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
