#include "view.h"

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

// 0 OK // 1 FAIL NOT ENOUGH SPACE
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
