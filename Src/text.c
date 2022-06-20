#include "text.h"

uint8_t display_text(text* t, uint16_t window_x, uint16_t window_y)
{
  set_font_pos(window_x + t->text_x, window_y + t->text_y);
  print_str_16x26(t->str[0][*p_current_lang], STRONG_GRAY, FONT_TEXT);
}
