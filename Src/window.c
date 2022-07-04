/**
 * @file window.c
 * @brief Fonctions to fill and display a window.
 * @author de Martimprey Edmond
 * @version 0.1
 * @date 28 june 2022
 *
 * Windos is a rectangle with element in it: router, menu, draw, rectangle, triangle...
 *
 */

#include "window.h"

/**
  * @fn void init_window(window* w)
  * @brief  Reset struct elem of a window.
  * @note   Need to be executed on every window created, other function check null pointer to know if some element is present or not
  * @param  v : Pointeur to the allocated window
  * @retval 0
  */
void init_window(window* w)
{
  w->menu = 0;
  w->window_up = 0;
  w->window_down = 0;
  w->window_right = 0;
  w->window_left = 0;
  w->view_enter = NULL;
  w->update_router = 0;
  for (uint8_t i = 0; i < MAX_NB_TEXT_PER_WINDOWS; i++)
    {
      w->text[i] = 0;
    }
  for (uint8_t i = 0; i < MAX_NB_DRAW_PER_WINDOWS; i++)
    {
      w->draw[i] = 0;
    }
  w->router = NULL;
}

/**
  * @fn uint8_t add_text_to_window(window* w, text* t)
  * @brief  Add one text to the window
  * @note   none
  * @param  w : Pointeur to the allocated window where to add text struct
  * @param  t : Pointeur to the text that is added to the window
  * @retval 0 : OK 1 : Fail not enough space
  */
uint8_t add_text_to_window(window* w, text* t)
{
    for (uint8_t i = 0; i < MAX_NB_TEXT_PER_WINDOWS; i++)
    {
      if (w->text[i] == 0)
	{
	  w->text[i] = t;
	  return 0;
	}
    }
  return 1;
}

/**
  * @fn uint8_t add_draw_to_window(window* w, draw* d)
  * @brief  Add one draw to the window
  * @note   none
  * @param  w : Pointeur to the allocated window where to add draw struct
  * @param  d : Pointeur to the draw that is added to the window
  * @retval 0 : OK 1 : Fail not enough space
  */
uint8_t add_draw_to_window(window* w, draw* d)
{
    for (uint8_t i = 0; i < MAX_NB_DRAW_PER_WINDOWS; i++)
    {
      if (w->draw[i] == 0)
	{
	  w->draw[i] = d;
	  return 0;
	}
    }
  return 1;
}

/**
  * @fn uint8_t add_router_to_window(window* w, router* r)
  * @brief  Add router the window
  * @note   Only one router per window
  * @param  w : Pointeur to the allocated window where to add router struct
  * @param  d : Pointeur to the router that is added to the window
  * @retval 0
  */
uint8_t add_router_to_window(window* w, router* r)
{
  w->router = r;
  return 0;
}

/**
  * @fn uint8_t display_window(window* w, uint16_t view_x, uint16_t view_y)
  * @brief  Display a window entirely
  * @note   Prefere update when possible much faster
  * @param  w : Pointeur to the allocated window
  * @param  view_x : bottom left X axis
  * @param  view_y : bottom left Y axis
  * @retval 0
  */
uint8_t display_window(window* w, uint16_t view_x, uint16_t view_y)
{
  draw_rectangle(view_x + w->window_x, view_y + w->window_y, w->window_size_x, w->window_size_y, FONT_COLOR);
  draw_empty_rectangle(view_x + w->window_x, view_y + w->window_y, w->window_size_x, w->window_size_y, 5, STRONG_FONT);
  for (uint8_t i = 0; i < MAX_NB_TEXT_PER_WINDOWS; i++)
    {
      if (w->text[i] != 0)
	{
	  display_text(w->text[i], view_x + w->window_x, view_y + w->window_y);
	}
    }
  for (uint8_t i = 0; i < MAX_NB_DRAW_PER_WINDOWS; i++)
    {
      if (w->draw[i] != 0)
	{
	  display_draw(w->draw[i], view_x + w->window_x, view_y + w->window_y);
	}
    }
  if (w->router != NULL)
    {
      display_router26(w->router, view_x + w->window_x, view_y + w->window_y);
    }
  return 0;
}

/**
  * @fn uint8_t display_select_window(window* w, uint16_t view_x, uint16_t view_y)
  * @brief  Display a window entirely with some change in color to highlight it
  * @note   None
  * @param  w : Pointeur to the allocated window
  * @param  view_x : bottom left X axis
  * @param  view_y : bottom left Y axis
  * @retval 0
  */
uint8_t display_select_window(window* w, uint16_t view_x, uint16_t view_y)
{
  draw_rectangle(view_x + w->window_x, view_y + w->window_y, w->window_size_x, w->window_size_y, STRONG_FONT);
  draw_empty_rectangle(view_x + w->window_x, view_y + w->window_y, w->window_size_x, w->window_size_y, 5, RED);
  for (uint8_t i = 0; i < MAX_NB_TEXT_PER_WINDOWS; i++)
    {
      if (w->text[i] != 0)
	{
	  display_text(w->text[i], view_x + w->window_x, view_y + w->window_y);
	}
    }
  for (uint8_t i = 0; i < MAX_NB_DRAW_PER_WINDOWS; i++)
    {
      if (w->draw[i] != 0)
	{
	  display_draw(w->draw[i], view_x + w->window_x, view_y + w->window_y);
	}
    }
  if (w->router != 0)
    {
      display_router26(w->router, view_x + w->window_x, view_y + w->window_y);
    }
  return 0;
}

/**
  * @fn uint8_t update_window(window* w, uint16_t view_x, uint16_t view_y)
  * @brief  update all element and sub element of a window
  * @note   None
  * @param  w : Pointeur to the allocated window
  * @param  view_x : bottom left X axis
  * @param  view_y : bottom left Y axis
  * @retval 0
  */
uint8_t update_window(window* w, uint16_t view_x, uint16_t view_y)
{
  if (w->update == 1)
    {
      display_window(w, view_x, view_y);
      w->update = 0;
      return 0;
    }
  for (uint8_t i = 0; i < MAX_NB_TEXT_PER_WINDOWS; i++)
    {
      if (w->text[i] != 0)
	{
	  update_text(w->text[i], view_x + w->window_x, view_y + w->window_y);
	}
    }
  for (uint8_t i = 0; i < MAX_NB_DRAW_PER_WINDOWS; i++)
    {
      if (w->draw[i] != 0)
	{
	  update_draw(w->draw[i], view_x + w->window_x, view_y + w->window_y);
	}
    }
  if (w->router != 0 && w->update_router == 1)
    {
      display_router26(w->router, view_x + w->window_x, view_y + w->window_y);
      w->update_router = 0;
    }
  return 0;
}

/**
  * @fn uint8_t update_select_window(window* w, uint16_t view_x, uint16_t view_y)
  * @brief  update all element and sub element of a window that is highlight, in case we need to uppdate the all window it wille trigger display_select_window and not just display_window otherwise same as update_window
  * @note   None
  * @param  w : Pointeur to the allocated window
  * @param  view_x : bottom left X axis
  * @param  view_y : bottom left Y axis
  * @retval 0
  */
uint8_t update_select_window(window* w, uint16_t view_x, uint16_t view_y)
{
  if (w->update == 1)
    {
      display_select_window(w, view_x, view_y);
      w->update = 0;
      return 0;
    }
  for (uint8_t i = 0; i < MAX_NB_TEXT_PER_WINDOWS; i++)
    {
      if (w->text[i] != 0)
	{
	  update_text(w->text[i], view_x + w->window_x, view_y + w->window_y);
	}
    }
  for (uint8_t i = 0; i < MAX_NB_DRAW_PER_WINDOWS; i++)
    {
      if (w->draw[i] != 0)
	{
	  update_draw(w->draw[i], view_x + w->window_x, view_y + w->window_y);
	}
    }
  if (w->router != 0 && w->update_router == 1)
    {
      display_router26(w->router, view_x + w->window_x, view_y + w->window_y);
      w->update_router = 0;
    }
  return 0;
}
