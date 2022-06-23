#include "navigation.h"

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

void nav_up()
{
  if (cur_menu != NULL)
    {
      menu_up(cur_menu);
    }
  else if (cur_router != NULL)
    {
      router_up(cur_router);
    }
}

void nav_down()
{
  if (cur_menu != NULL)
    {
      menu_down(cur_menu);
    }
  else if (cur_router != NULL)
    {
      router_down(cur_router);
    }
}

void nav_right()
{
  if (cur_menu != NULL)
    {
      menu_var_up(cur_menu);
    }
  else if (cur_router != NULL)
    {
      return;
    }
  else if (cur_window != NULL)
    {
      if (cur_window->window_right != NULL)
	{
	  window* new_cur_window = cur_window->window_right;
	  cur_window = new_cur_window;
	  cur_view->cur_window = new_cur_window;
	}
    }
}

void nav_left()
{
  if (cur_menu != NULL)
    {
      menu_var_down(cur_menu);
    }
  else if (cur_router != NULL)
    {
      return;
    }
  else if (cur_window != NULL)
    {
      if (cur_window->window_left != NULL)
	{
	  window* new_cur_window = cur_window->window_left;
	  cur_window = new_cur_window;
	  cur_view->cur_window = new_cur_window;
	}
    }
}

void nav_valid()
{
  if (cur_menu != 0);
  if (cur_router == 0 && cur_window->router != NULL)
    {
      cur_router = cur_window->router;
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
	}
    }
}

void nav_back()
{
  if (cur_menu != 0)
    cur_menu = 0;
  else if (cur_router != NULL)
    {
      if (cur_router->up_router != NULL)
	{
	  back_router(cur_router);
	}
      else
	cur_router = NULL;
    }
  else if (cur_view != NULL)
    {
      if (cur_view->view_back != NULL)
	{
	  cur_view = cur_view->view_back;
	  cur_window = cur_view->cur_window;
	}
    }
}
