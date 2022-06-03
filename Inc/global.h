#ifndef __GLOBAL_H
#define __GLOBAL_H

#define BLUE_Pin GPIO_PIN_15
#define BLUE_GPIO_Port GPIOD

#define RED_Pin GPIO_PIN_14
#define RED_GPIO_Port GPIOD

#define ORANGE_Pin GPIO_PIN_13
#define ORANGE_GPIO_Port GPIOD

#define GREEN_Pin GPIO_PIN_12
#define GREEN_GPIO_Port GPIOD

#define TFT_CSX_Pin GPIO_PIN_10 // CS ON MY SCREEN
#define TFT_CSX_GPIO_Port GPIOE

#define TFT_DCX_Pin GPIO_PIN_9 // RS ON MY SCREEN
#define TFT_DCX_GPIO_Port GPIOE

#define TFT_WRX_Pin GPIO_PIN_8 // WR ON MY SCREEN
#define TFT_WRX_GPIO_Port GPIOE

#define TFT_RESX_Pin GPIO_PIN_7 // RESET ON MY SCREEN
#define TFT_RESX_GPIO_Port GPIOE

#define TFT_D0_Pin GPIO_PIN_0
#define TFT_D0_GPIO_Port GPIOA

#define TFT_D1_Pin GPIO_PIN_1
#define TFT_D1_GPIO_Port GPIOA

#define TFT_D2_Pin GPIO_PIN_2
#define TFT_D2_GPIO_Port GPIOA

#define TFT_D3_Pin GPIO_PIN_3
#define TFT_D3_GPIO_Port GPIOA

#define TFT_D4_Pin GPIO_PIN_4
#define TFT_D4_GPIO_Port GPIOA

#define TFT_D5_Pin GPIO_PIN_5
#define TFT_D5_GPIO_Port GPIOA

#define TFT_D6_Pin GPIO_PIN_6
#define TFT_D6_GPIO_Port GPIOA

#define TFT_D7_Pin GPIO_PIN_7
#define TFT_D7_GPIO_Port GPIOA

#define TFT_D8_Pin GPIO_PIN_0
#define TFT_D8_GPIO_Port GPIOC

#define TFT_D9_Pin GPIO_PIN_1
#define TFT_D9_GPIO_Port GPIOC

#define TFT_D10_Pin GPIO_PIN_2
#define TFT_D10_GPIO_Port GPIOC

#define TFT_D11_Pin GPIO_PIN_3
#define TFT_D11_GPIO_Port GPIOC

#define TFT_D12_Pin GPIO_PIN_4
#define TFT_D12_GPIO_Port GPIOB

#define TFT_D13_Pin GPIO_PIN_5
#define TFT_D13_GPIO_Port GPIOB

#define TFT_D14_Pin GPIO_PIN_6
#define TFT_D14_GPIO_Port GPIOB

#define TFT_D15_Pin GPIO_PIN_7
#define TFT_D15_GPIO_Port GPIOB

#define USE_5X7

#define X_SIZE	480
#define Y_SIZE	320

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"

extern TIM_HandleTypeDef htim_timer;

#ifdef USE_5X7
extern uint16_t x_font_pos;
extern uint16_t y_font_pos;
#endif /* USE_5X7 */

#ifdef USE_RAM_BUFFER
extern uint16_t buffer[X_SIZE][Y_SIZE];
#endif /* USE_RAM_BUFFER */

#ifdef __cplusplus
}
#endif

#endif /* __GLOBAL_H */
