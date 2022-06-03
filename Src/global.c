#include "global.h"

TIM_HandleTypeDef htim_timer;
#ifdef USE_RAM_BUFFER
uint16_t buffer[X_SIZE][Y_SIZE] = {0, };
#endif /* USE_RAM_BUFFER */
