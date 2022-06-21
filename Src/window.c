#include "window.h"

void init_window(window* w)
{
  w->menu = 0;
  w->window_up = 0;
  w->window_down = 0;
  w->window_right = 0;
  w->window_left = 0;
  for (uint8_t i = 0; i < MAX_NB_TEXT_PER_WINDOWS; i++)
    {
      w->text[i] = 0;
    }
  for (uint8_t i = 0; i < MAX_NB_DRAW_PER_WINDOWS; i++)
    {
      w->draw[i] = 0;
    }
  for (uint8_t i = 0; i < MAX_NB_ROUTER_PER_WINDOWS; i++)
    {
      w->router[i] = 0;
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

// 0 OK // 1 FAIL NOT ENOUGH SPACE
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

// 0 OK // 1 FAIL NOT ENOUGH SPACE
uint8_t add_router_to_window(window* w, router* r)
{
    for (uint8_t i = 0; i < MAX_NB_ROUTER_PER_WINDOWS; i++)
    {
      if (w->router[i] == 0)
	{
	  w->router[i] = r;
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
  for (uint8_t i = 0; i < MAX_NB_DRAW_PER_WINDOWS; i++)
    {
      if (w->draw[i] != 0)
	{
	  display_draw(w->draw[i], view_x + w->window_x, view_y + w->window_y);
	}
    }
  for (uint8_t i = 0; i < MAX_NB_ROUTER_PER_WINDOWS; i++)
    {
      if (w->router[i] != 0)
	{
	  display_router26(w->router[i], view_x + w->window_x, view_y + w->window_y);
	}
    }
  return 0;
}

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
  for (uint8_t i = 0; i < MAX_NB_ROUTER_PER_WINDOWS; i++)
    {
      if (w->router[i] != 0)
	{
	  display_router26(w->router[i], view_x + w->window_x, view_y + w->window_y);
	}
    }
  return 0;
}

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
  return 0;
}
