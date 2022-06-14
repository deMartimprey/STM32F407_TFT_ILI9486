#include "menu.h"

uint8_t add_elem_menu(menu* my_menu, var* my_var)
{
  if (my_menu->size >= MAX_SIZE_MENU)
    return 1;
  my_menu->vars[my_menu->size] = my_var;
  my_menu->size += 1;
  return 0;
}

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
      my_strncpy((str + SIZE_NAME_VAR / 2 + 2), (const uint8_t *)stringInt32, 7);
    }
}

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

void display_menu(menu *my_menu, uint16_t x_pos, uint8_t y_pos)
{
  uint8_t str[SIZE_NAME_MENU] = {0, };

  x_font_pos = x_pos;
  y_font_pos = y_pos;
  if (my_menu  == NULL)
    return;
  print_str_10x16((uint8_t*)my_menu->name[*p_current_lang], BLACK, 0x9DDF);
  y_font_pos -= 18;
  for (uint8_t i = 0; i < MAX_SIZE_MENU; i++)
    {
      x_font_pos = x_pos;
      if (i + my_menu->first_elem_pos < my_menu->size)
	{
	  fill_string_with_space(str, SIZE_NAME_MENU - 1);
	  if (i == my_menu->arrow_pos)
	    str[0] = '>';
	  else
	    str[0] = ' ';
	  fill_one_line_menu(str, my_menu->vars[my_menu->first_elem_pos + i]);
	  /* add_line_number(str, i + my_menu->first_elem_pos); */
	  print_str_10x16(str, BLACK, WHITE);
	}
      else
	{
	  fill_string_with_space(str, MAX_SIZE_MENU - 1);
	  print_str_10x16(str, BLACK, WHITE);
	}
  y_font_pos -= 18;
    }
}

void menu_var_up(menu *my_menu)
{
  plus_one_var(my_menu->vars[my_menu->pos_menu]);
}

void menu_var_down(menu *my_menu)
{
  minus_one_var(my_menu->vars[my_menu->pos_menu]);
}

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

void fill_string_with_space(uint8_t* str, uint8_t size)
{
  for (uint8_t i = 0; i < size; i++)
    str[i] = ' ';
}
