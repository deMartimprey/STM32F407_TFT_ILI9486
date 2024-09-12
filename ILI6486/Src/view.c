/**
 * @file view.c
 * @brief Fonctions to fill and display a view.
 * @author de Martimprey Edmond
 * @version 0.1
 * @date 28 june 2022
 *
 * View is a list of windows.
 *
 */

#include "view.h"

/**
  * @fn void init_view(view* v)
  * @brief  Reset struct elem of a view.
  * @note   Need to be executed on every view created, other function check null pointer to know if some element is present or not
  * @param  v : Pointeur to the allocated view
  * @retval 0
  */
void init_view(view* v)
{
  for (uint8_t i = 0; i < MAX_WINDOW_PER_VIEW; i++)
    {
      v->windows[i] = NULL;
    }
  v->view_x = 0;
  v->view_y = 0;
  v->cur_window = 0;
  v->update = 0;
}

/**
  * @fn void view_left(view* v)
  * @brief  Change highligt window to the one on the left. If no window juste do nothing.
  * @note   none
  * @param  v : Pointeur to the allocated view
  * @retval 0
  */
void view_left(view* v)
{
  if (v->cur_window != 0)
    {
      if (v->cur_window->window_left != 0)
	{
	  v->cur_window = v->cur_window->window_left;
	}
    }
}

/**
  * @fn void view_right(view* v)
  * @brief  Change highligt window to the one on the right. If no window juste do nothing.
  * @note   none
  * @param  v : Pointeur to the allocated view
  * @retval 0
  */
void view_right(view* v)
{
  if (v->cur_window != 0)
    {
      if (v->cur_window->window_right != 0)
	{
	  v->cur_window = v->cur_window->window_right;
	}
    }
}

/**
  * @fn uint8_t add_one_window(view* v, window* win)
  * @brief  Add one window to the view
  * @note   none
  * @param  v : Pointeur to the allocated view where to add window
  * @param  win : Pointeur to the window that is added to the view
  * @retval 0 : OK 1 : Fail not enough space
  */
uint8_t add_one_window(view* v, window* win)
{
  for (uint8_t i = 0; i < MAX_WINDOW_PER_VIEW; i++)
    {
      if (v->windows[i] == 0)
	{
	  if (i == 0)
	      v->cur_window = win;
	  v->windows[i] = win;
	  return 0;
	}
    }
  return 1;
}

/**
  * @fn uint8_t display_view(view* v)
  * @brief  Display all window and sub element of a view
  * @note   Only when change view, to slow, otherwise use update view
  * @param  v : Pointeur to the allocated view
  * @retval 0
  */
uint8_t display_view(view* v)
{
  fill_with_Color(WHITE);
  for (uint8_t i = 0; i < MAX_WINDOW_PER_VIEW; i++)
    {
      if (v->windows[i] != 0)
	{
	  if (v->windows[i] == v->cur_window)
	    display_select_window(v->windows[i], v->view_x, v->view_y);
	  else
	    display_window(v->windows[i], v->view_x, v->view_y);
	}
    }
  return 0;
}

/**
  * @fn uint8_t update_view(view* v)
  * @brief  update all window and sub element of a view
  * @note   Only elements with update flag at 1 will update
  * @param  v : Pointeur to the allocated view
  * @retval 0
  */
uint8_t update_view(view* v)
{
  if (v->update == 1)
    {
      display_view(v);
      v->update = 0;
      return 0;
    }
  for (uint8_t i = 0; i < MAX_WINDOW_PER_VIEW; i++)
    {
      if (v->windows[i] != 0)
	{
	  if (v->windows[i] == v->cur_window)
	    update_select_window(v->windows[i], v->view_x, v->view_y);
	  else
	    update_window(v->windows[i], v->view_x, v->view_y);
	}
    }
  return 0;
}
