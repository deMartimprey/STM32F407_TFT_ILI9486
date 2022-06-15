#ifndef __MENU_H
#define __MENU_H

#include "stm32f4xx_hal.h"
#include "font10x16.h"
#include "global.h"
#include "tools.h"
#include "var.h"

uint8_t add_elem_menu(menu* my_menu, var* my_var);
void fill_one_line_menu(uint8_t* str, var* my_var);
void display_menu(menu *my_menu, uint16_t x_pos, uint16_t y_pos);
void add_line_number(uint8_t* str, uint8_t position);
void fill_string_with_space(uint8_t* str, uint8_t size);
void menu_up(menu *my_menu);
void menu_down(menu *my_menu);
void menu_var_up(menu *my_menu);
void menu_var_down(menu *my_menu);
uint8_t get_pos(menu *my_menu);
uint32_t get_value_current_pos(menu *my_menu);

#endif /* __MENU_H */
