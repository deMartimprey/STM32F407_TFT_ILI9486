#include "window.h"

void init_window(window* w)
{
  w->menu = 0;
  w->router = 0;
  w->window_up = 0;
  w->window_down = 0;
  w->window_right = 0;
  w->window_left = 0;
  for (uint8_t i = 0; i < MAX_NB_TEXT_PER_WINDOWS; i++)
    {
      w->text[i] = 0;
    }
}

// 0 OK // 1 FAIL NOT ENOUGH SPACE
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
  return 0;
}
