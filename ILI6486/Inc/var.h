#ifndef __VAR_H
#define __VAR_H

#define MAX_SIZE_VAR 21

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
#include "global.h"

void init_all_var(var* vars);
void set_value_var(var* vars, int32_t value);
int32_t read_value_var(var* vars);
uint8_t init_var(var* vars, int32_t min, int32_t max, int32_t default_value);
void update_var(var* vars);
void erase_var(var* vars);
int32_t get_var(var* vars);

int32_t minus_one_var(var* vars);
int32_t plus_one_var(var* vars);
int32_t set_add_var(var* vars, int32_t value);
int32_t set_minus_var(var* vars, int32_t value);
var* new_var(var* vars, const uint8_t (*name)[NB_LANG][SIZE_NAME_VAR], const uint8_t (*menu_var)[NB_LANG][NB_NAME_VAR_MENU][SIZE_NAME_VAR_MENU],
#ifdef USE_EEPROM
	     eeprom* my_eeprom,
#endif /* USE_EEPROM */
	     int32_t min, int32_t max, int32_t default_value);

#endif /* __VAR_H */
