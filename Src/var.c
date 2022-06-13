#include "var.h"

void init_all_var(var* vars)
{
  for (int i = 0; i < NB_VAR; i++)
    {
      vars[i].id = i;
      vars[i].value = 0;
    }
}

void set_value_var(var* vars, int32_t value)
{
  vars->value = value;
#ifdef USE_EEPROM
  write32bitsToEEPROM(vars->link_eeprom, vars->value, vars->eeprom_addr);
  osDelay(1);
#endif /* USE_EEPROM */
}


int32_t read_value_var(var* vars)
{
#ifdef USE_EEPROM
  return read32bitsFromEEPROM(vars->link_eeprom, vars->eeprom_addr);
#else
  return 0;
#endif /* USE_EEPROM */
}

uint8_t init_var(var* vars, int32_t min, int32_t max, int32_t default_value)
{
  vars->value = read_value_var(vars);
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

void erase_var(var* vars)
{
    set_value_var(vars, 0);
}

int32_t get_var(var* vars)
{
  return vars->value;
}

int32_t set_minus_one_var(var* vars)
{
  if (vars->value == vars->min)
    vars->value = vars->max;
  else
    vars->value -= 1;
  update_var(vars);
  return vars->value;
}

int32_t set_plus_one_var(var* vars)
{
  if (vars->value == vars->max)
    vars->value = vars->min;
  else
    vars->value += 1;
  update_var(vars);
  return vars->value;
}

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
