/**
 * @file menu.c
 * @brief Display menus.
 * @author de Martimprey Edmond
 * @version 0.1
 * @date 28 june 2022
 *
 * Menu is a scrolable list cointaing variable that can change value
 *
 */

#include "menu.h"

/**
  * @fn uint8_t add_elem_menu(menu* my_menu, var* my_var)
  * @brief  Add a var to the menu
  * @note   None
  * @param  my_menu : Menu to add var
  * @param  my_var : var to add menu
  * @retval 0 : OK, 1 : menu is already full didn't add the element
  */
uint8_t add_elem_menu(menu* my_menu, var* my_var)
{
  if (my_menu->size >= MAX_SIZE_MENU)
    return 1;
  my_menu->vars[my_menu->size] = my_var;
  my_menu->size += 1;
  return 0;
}

/**
  * @fn void fill_one_line_menu(uint8_t* str, var* my_var)
  * @brief  Generate one line of the menu in str depending the var give in parameter
  * @note   None
  * @param  str : String to fill, need to be alocated
  * @param  my_var : var that is use to gemerate the menu line
  * @retval None
  */
void fill_one_line_menu(uint8_t* str, var* my_var)
{
  my_strncpy(str + 1, (*my_var->name)[*p_current_lang], my_strlen((*my_var->name)[*p_current_lang]));
  my_strncpy(str + 11, (uint8_t*)":", 1);
  if (my_var->type == NAME_TYPE)
    my_strncpy(str + 12, (*my_var->menu_var)[*p_current_lang][my_var->value], my_strlen((*my_var->menu_var)[*p_current_lang][my_var->value]));
  if (my_var->type == DIGIT_TYPE)
    {
      uint8_t stringInt32[11] = "          \0";

      num32ToString((uint8_t*)&stringInt32, my_var->value);
      my_strncpy((str + SIZE_NAME_VAR / 2 + 2), (const uint8_t *)stringInt32, 5);
    }
}

/**
  * @fn void add_line_number(uint8_t* str, uint8_t position)
  * @brief  Add the position of element in the menu at the start of the string
  * @note   None
  * @param  str : String to fill whith a number at the start, need to be alocated
  * @param  position : position to add at the start of the string
  * @retval None
  */
void add_line_number(uint8_t* str, uint8_t position)
{
  uint8_t posNum = 0;
  uint8_t tens = 0;
  if (position < 10)
    posNum = position + '0';
  else if (position < 20) {
    posNum = position + '0' - 10;
    tens = '1';
  }
  else if (position < 30) {
    posNum = position + '0' - 20;
    tens = '2';
  }
  if (position < 10)
    if (str[19] == ' ')
      my_strncpy((uint8_t*)str + 19, &posNum, 1);
  if (position < 20)
    if (str[19] == ' ' && str[18] == ' ') {
      my_strncpy((uint8_t*)str + 18, &tens, 1);
      my_strncpy((uint8_t*)str + 19, &posNum, 1);
    }
  if (position < 30)
    if (str[19] == ' ' && str[18] == ' ') {
      my_strncpy((uint8_t*)str + 18, &tens, 1);
      my_strncpy((uint8_t*)str + 19, &posNum, 1);
    }
}

/**
  * @fn void display_menu(menu *my_menu, uint16_t x_pos, uint16_t y_pos)
  * @brief  display a menu
  * @note   A menu is a liste of var, the name and value are display and can be change by user ,write by increasing X axis and decreasing Y axis, position is at to top left
  * @param  my_menu : Menu to display
  * @param  x : X axis to start display, left of the menu
  * @param  y : Y axis to start display, top of the menu
  * @retval None
  */
void display_menu(menu *my_menu, uint16_t x_pos, uint16_t y_pos)
{
  uint8_t str[SIZE_NAME_VAR] = {0, };
  uint8_t strmenu[SIZE_NAME_MENU] = {0, };

  x_font_pos = x_pos;
  y_font_pos = y_pos;
  if (my_menu  == NULL)
    return;
  fill_string_with_space(strmenu, SIZE_NAME_MENU - 1);
  my_strncpy((uint8_t*)strmenu, (uint8_t*)my_menu->name[*p_current_lang], my_strlen((uint8_t*)my_menu->name[*p_current_lang]));
  y_font_pos -= 28;
  if (cur_menu == my_menu)
    print_str_16x26(strmenu, WHITE, RED);
  else
  print_str_16x26(strmenu, WHITE, STRONG_FONT);
  y_font_pos -= 28;
  for (uint8_t i = 0; i < MAX_SIZE_MENU; i++)
    {
      x_font_pos = x_pos;
      if (i + my_menu->first_elem_pos < my_menu->size)
	{
	  fill_string_with_space(str, SIZE_NAME_VAR - 1);
	  fill_one_line_menu(str, my_menu->vars[my_menu->first_elem_pos + i]);
	  if (i == my_menu->arrow_pos)
	    {
	      str[0] = '>';
	      print_str_16x26(str, WHITE, MENU_HIGHLIGHT_FONT_COLOR);
	    }
	  else
	    {
	      str[0] = ' ';
	      print_str_16x26(str, STRONG_GRAY, (i % 2 ? MENU_PAIR_FONT_COLOR : MENU_UNPAIR_FONT_COLOR));
	    }
	  /* add_line_number(str, i + my_menu->first_elem_pos); */
	}
      else
	{
	  fill_string_with_space(str, MAX_SIZE_VAR  - 1);
	  print_str_16x26(str, BLACK, WHITE);
	}
  y_font_pos -= 28;
    }
}

/**
  * @fn void menu_var_up(menu *my_menu)
  * @brief  Increase by one the var value highlight in the menu
  * @note   None
  * @param  my_menu : Menu to increase var value
  * @retval None
  */
void menu_var_up(menu *my_menu)
{
  plus_one_var(my_menu->vars[my_menu->pos_menu]);
}

/**
  * @fn void menu_var_down(menu *my_menu)
  * @brief  Decrease by one the var value highlight in the menu
  * @note   None
  * @param  my_menu : Menu to decrease var value
  * @retval None
  */
void menu_var_down(menu *my_menu)
{
  minus_one_var(my_menu->vars[my_menu->pos_menu]);
}

/**
  * @fn void menu_down(menu *my_menu)
  * @brief  Decrease by one the var highlight in the menu
  * @note   None
  * @param  my_menu : Menu to change highlight var
  * @retval None
  */
void menu_down(menu *my_menu)
{
  if (my_menu->pos_menu == 0)
    {
      my_menu->pos_menu = my_menu->size - 1;
      my_menu->first_elem_pos = my_menu->size - 1;
      my_menu->arrow_pos = 0;
    }
  else
    {
      my_menu->pos_menu -= 1;

      if (my_menu->arrow_pos > 0)
	my_menu->arrow_pos -= 1;
      else if (my_menu->first_elem_pos > 0)
	my_menu->first_elem_pos -= 1;
    }
}

/**
  * @fn void menu_up(menu *my_menu)
  * @brief  Increase by one the var highlight in the menu
  * @note   None
  * @param  my_menu : Menu to change highlight var
  * @retval None
  */
void menu_up(menu *my_menu)
{
  if (my_menu->pos_menu >= my_menu->size - 1)
    {
      my_menu->arrow_pos = 0;
      my_menu->first_elem_pos = 0;
      my_menu->pos_menu = 0;
      return;
    }
  else
    {
      my_menu->pos_menu += 1;
      if (my_menu->arrow_pos < NB_LINE_ROUTER - 1)
	my_menu->arrow_pos += 1;
      else
	my_menu->first_elem_pos += 1;
    }
}

/**
  * @fn void fill_string_with_space(uint8_t* str, uint8_t size)
  * @brief  Fill str pointer with space
  * @note   None
  * @param  str : Str to fill, need to be alocated
  * @param  size : Number of space to fill
  * @retval None
  */
void fill_string_with_space(uint8_t* str, uint8_t size)
{
  for (uint8_t i = 0; i < size; i++)
    str[i] = ' ';
}
