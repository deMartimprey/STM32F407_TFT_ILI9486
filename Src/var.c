/**
 * @file var.c
 * @brief var creation or modification.
 * @author de Martimprey Edmond
 * @version 0.1
 * @date 28 june 2022
 *
 * A var is a value that can be change by the user in menu and use in the app.
 *
 */

#include "var.h"

/**
  * @fn void init_all_var(var* vars)
  * @brief  Update var when value is change in another thread. Onlly one thread can be use to write on eeprom
  * @param  vars : Pointeur of the var struct to init
  * @retval None
  */
void init_all_var(var* vars)
{
  for (int i = 0; i < NB_VAR; i++)
    {
      vars[i].id = i;
      vars[i].value = 0;
    }
}

/**
  * @fn void set_value_var(var* vars, int32_t value)
  * @brief  Set value of vars in EEPROM
  * @note   Write 4 bytes
  * @param  vars : Pointeur of the var struct to write on
  * @param  value : Value to write in EEPROM memory
  * @retval None
  */
void set_value_var(var* vars, int32_t value)
{
  vars->value = value;
#ifdef USE_EEPROM
  write32bitsToEEPROM(vars->link_eeprom, vars->value, vars->eeprom_addr);
  osDelay(1);
#endif /* USE_EEPROM */
}

/**
  * @fn int32_t read_value_var(var* vars)
  * @brief  Read value of vars in EEPROM
  * @note   Read 4 bytes
  * @param  vars : Pointeur of the var struct to read
  * @retval Value read from EEPROM
  */
int32_t read_value_var(var* vars)
{
#ifdef USE_EEPROM
  return read32bitsFromEEPROM(vars->link_eeprom, vars->eeprom_addr);
#else
  return 0;
#endif /* USE_EEPROM */
}

/**
  * @fn uint8_t init_var(var* vars, int32_t min, int32_t max, int32_t default_value)
  * @brief  Initiate a new var structure
  * @note   Will give the structure an id and a address in EEPROM	      memory automatically.
	    Check if variable in EEPROM is in range and set to def	      ault_value
  * @param  vars : pointeur of the var struct to init
  * @param  min : Minimum value of the variable.
  * @param  max : Max value of the variable.
  * @param  default_value : Default value of the variable if not in range.
  * @retval 0 If variable is in range, 1 otherwise
  */
uint8_t init_var(var* vars, int32_t min, int32_t max, int32_t default_value)
{
#ifdef USE_EEPROM
  vars->value = read_value_var(vars);
#else
  vars->value = default_value;
#endif /* USE_EEPROM */
  if (vars->value == (int32_t)0b11111111111111111111111111111111 || vars->value > max)
    {
      set_value_var(vars, default_value);
      return 1;
    }
  if (vars->value < min)
    {
      set_value_var(vars, default_value);
      return 1;
    }
  return 0;
}


/**
  * @fn void erase_var(var* vars)
  * @brief  Set value of a var at 0 in EEPROM
  * @note   Write 4 byte
  * @param  vars : pointeur of the var struct to erase
  * @retval None
  */
void erase_var(var* vars)
{
    set_value_var(vars, 0);
}

/**
  * @fn int32_t get_var(var* vars)
  * @brief  Return var value in struct
  * @note   Local variable, the one in EEPROM can differ
  * @param  Vars : pointeur of the vars
  * @retval Value in vars struct
  */
int32_t get_var(var* vars)
{
  return vars->value;
}

/**
  * @fn int32_t minus_one_var(var* vars)
  * @brief  Decrement one to value and set it directly in EEPROM
  * @note   If value is under min var to the max.
  * @param  Vars : pointeur of the vars
  * @retval Updated value
  */
int32_t minus_one_var(var* vars)
{
  if (vars->value == vars->min)
    set_value_var(vars, vars->max);
  else
    set_value_var(vars, vars->value - 1);
  return vars->value;
}

/**
  * @fn int32_t plus_one_var(var* vars)
  * @brief  Increment one to local var and set update flag
  * @note   Will be updated in EEPROM in another thread, use ths function if you want to change the value of a vars and you are not in the right thread to do it. If value ecced max set var to the min.
  * @param  Vars : pointeur of the vars
  * @retval Updated value
  */
int32_t plus_one_var(var* vars)
{
  if (vars->value == vars->max)
    set_value_var(vars, vars->min);
  else
    set_value_var(vars, vars->value + 1);
  return vars->value;

}

/**
  * @fn var* new_var(var* vars, const uint8_t (*name)[NB_LANG][SIZE_NAME_VAR], const uint8_t (*menu_var)[NB_LANG][NB_NAME_VAR_MENU][SIZE_NAME_VAR_MENU], int32_t min, int32_t max, int32_t default_value)
  * @brief  Initiate a new var structure
  * @note   Will give the structure an id and a address in EEPROM	      memory automatically.
	    Check if variable in EEPROM is in range and set to def	      ault_value
  * @param  vars : Pointeur to the tab that cointain all vars
  * @param  name : Pointeur to the name of the variable
  * @param  menu_var : Pointeur to the menu name, if the variable 	      is create for store raw number just send NULL pointer		(0).
  * @param  my_eeprom : EEPRROM struct where value is store.
  * @param  min : Minimum value of the variable.
  * @param  max : Max value of the variable.
  * @param  default_value : Default value of the variable if not in range.
  * @retval Return a pointeur of the vars just init.
  */
var* new_var(var* vars, const uint8_t (*name)[NB_LANG][SIZE_NAME_VAR], const uint8_t (*menu_var)[NB_LANG][NB_NAME_VAR_MENU][SIZE_NAME_VAR_MENU],
#ifdef USE_EEPROM
	     eeprom* my_eeprom,
#endif /* USE_EEPROM */
	     int32_t min, int32_t max, int32_t default_value)
{
  var* new_created_var;
  static uint8_t var_position = 0;
  if (var_position > NB_VAR)
    // augmenter la variable NB_VAR in var.h
    // increase variable NB_VAR in var.h
    return &vars[var_position];
  new_created_var = &vars[var_position];
  if (name)
    {
      new_created_var->name = name;
    }
  if (menu_var)
    {
      new_created_var->type = NAME_TYPE;
      new_created_var->menu_var = menu_var;
    }
  new_created_var->id = var_position;
#ifdef USE_EEPROM
  new_created_var->eeprom_addr = var_position * 4;
  new_created_var->link_eeprom = my_eeprom;
#endif /* USE_EEPROM */
  new_created_var->max = max;
  new_created_var->min = min;

  var_position += 1;
  init_var(new_created_var, min, max, default_value);
  return new_created_var;
}
