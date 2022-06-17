#include "view.h"

void init_view(view* v)
{
  for (uint8_t i = 0; i < MAX_WINDOW_PER_VIEW; i++)
    {
      v->windows[i] = NULL;
    }
  v->view_x = 0;
  v->view_x = 0;
}

// 0 OK // 1 FAIL NOT ENOUGH SPACE
uint8_t add_one_window(view* v, window* win)
{
  for (uint8_t i = 0; i < MAX_WINDOW_PER_VIEW; i++)
    {
      if (v->windows[i] == 0)
	{
	  v->windows[i] = win;
	  return 0;
	}
    }
  return 1;
}

uint8_t display_view(view* v)
{
  for (uint8_t i = 0; i < MAX_WINDOW_PER_VIEW; i++)
    {
      if (v->windows[i] != 0)
	{
	  draw_rectangle(v->view_x + v->windows[i]->window_x, v->view_x + v->windows[i]->window_y, v->windows[i]->window_size_x, v->windows[i]->window_size_y, FONT_COLOR);
	  draw_empty_rectangle(v->view_x + v->windows[i]->window_x, v->view_x + v->windows[i]->window_y, v->windows[i]->window_size_x, v->windows[i]->window_size_y, 5, STRONG_FONT);
	}
    }
  return 0;
}
