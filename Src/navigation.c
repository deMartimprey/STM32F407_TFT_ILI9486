/**
 * @file navigation.c
 * @brief Action depending of input from buttons
 * @author de Martimprey Edmond
 * @version 0.1
 * @date 28 june 2022
 *
 * Navigate in views, windows and menus
 *
 */

#include "navigation.h"

/**
  * @fn void check_nav()
  * @brief  Check if any of the button have been press
  * @note   None
  * @retval None
  */
void check_nav()
{
  if (pressed_up)
    nav_up();
  if (pressed_down)
    nav_down();
  if (pressed_left)
    nav_left();
  if (pressed_right)
    nav_right();
  if (pressed_valid)
    nav_valid();
  if (pressed_back)
    nav_back();
}

/**
  * @fn void nav_up()
  * @brief  Monitoring up button behaviour
  * @note   None
  * @retval None
  */
void nav_up()
{
  if (cur_menu != NULL)
    {
      menu_up(cur_menu);
      cur_window->update_router = 1;
    }
  else if (cur_router != NULL)
    {
      router_up(cur_router);
      cur_window->update_router = 1;
    }
}

/**
  * @fn void nav_down()
  * @brief  Monitoring down button behaviour
  * @note   None
  * @retval None
  */
void nav_down()
{
  if (cur_menu != NULL)
    {
      menu_down(cur_menu);
      cur_window->update_router = 1;
    }
  else if (cur_router != NULL)
    {
      router_down(cur_router);
      cur_window->update_router = 1;
    }
}

/**
  * @fn void nav_right()
  * @brief  Monitoring right button behaviour
  * @note   None
  * @retval None
  */
void nav_right()
{
  if (cur_menu != NULL)
    {
      menu_var_up(cur_menu);
      cur_window->update_router = 1;
    }
  else if (cur_router != NULL)
    {
      return;
    }
  else if (cur_window != NULL)
    {
      if (cur_window->window_right != NULL)
	{
	  cur_window->update = 1;
	  window* new_cur_window = cur_window->window_right;
	  cur_window = new_cur_window;
	  cur_view->cur_window = new_cur_window;
	  cur_window->update = 1;
	}
    }
}

/**
  * @fn void nav_left()
  * @brief  Monitoring left button behaviour
  * @note   None
  * @retval None
  */
void nav_left()
{
  if (cur_menu != NULL)
    {
      menu_var_down(cur_menu);
      cur_window->update_router = 1;
    }
  else if (cur_router != NULL)
    {
      return;
    }
  else if (cur_window != NULL)
    {
      if (cur_window->window_left != NULL)
	{
	  cur_window->update = 1;
	  window* new_cur_window = cur_window->window_left;
	  cur_window = new_cur_window;
	  cur_view->cur_window = new_cur_window;
	  cur_window->update = 1;
	}
    }
}

/**
  * @fn void nav_valid()
  * @brief  Monitoring valid button behaviour
  * @note   None
  * @retval None
  */
void nav_valid()
{
  if (cur_menu != 0);
  if (cur_router == 0 && cur_window->router != NULL)
    {
      cur_router = cur_window->router;
      cur_window->update_router = 1;
    }
  else if (cur_router != 0)
    {
      into_router(cur_router);
    }
  else if (cur_window != NULL)
    {
      if (cur_window->view_enter != NULL)
	{
	  cur_view = cur_window->view_enter;
	  cur_window = cur_view->cur_window;
	  cur_view->update = 1;
	}
    }
}

/**
  * @fn void nav_back()
  * @brief  Monitoring back button behaviour
  * @note   None
  * @retval None
  */
void nav_back()
{
  if (cur_menu != 0)
    {
      cur_menu = 0;
      cur_window->update_router = 1;
    }
  else if (cur_router != NULL)
    {
      if (cur_router->up_router != NULL)
	{
	  back_router(cur_router);
	  cur_window->update_router = 1;
	}
      else
	{
	  cur_router = NULL;
	  cur_window->update = 1;
	}
    }
  else if (cur_view != NULL)
    {
      if (cur_view->view_back != NULL)
	{
	  cur_view = cur_view->view_back;
	  cur_window = cur_view->cur_window;
	  cur_view->update = 1;
	}
    }
}
