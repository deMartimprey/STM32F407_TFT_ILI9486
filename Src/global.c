#include "global.h"

TIM_HandleTypeDef htim_timer;

#ifdef USE_5X7
uint16_t x_font_pos = 0;
uint16_t y_font_pos = 0;
#endif /* USE_5X7 */

#ifdef USE_RAM_BUFFER
uint16_t buffer[X_SIZE][Y_SIZE] = {0, };
#endif /* USE_RAM_BUFFER */

uint8_t current_lang = 0;
uint8_t* p_current_lang;
router* cur_router;
menu* cur_menu;

var vars[NB_VAR];

var* var0;
var* var1;
var* var2;
var* var3;
var* var4;
var* var5;
var* var6;
var* var7;
var* var8;
var* var9;
var* var10;
