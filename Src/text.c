/**
 * @file text.c
 * @brief Display text zone.
 * @author de Martimprey Edmond
 * @version 0.1
 * @date 28 june 2022
 *
 * Display text zone.
 *
 */

#include "text.h"

/**
  * @fn uint8_t display_text(text* t, uint16_t window_x, uint16_t window_y)
  * @brief  Display text zone with offset of the window
  * @note   None
  * @param  t : text struct with all info
  * @param  window_x : window X axis offset
  * @param  window_y : window Y axis offset
  * @retval None
  */
uint8_t display_text(text* t, uint16_t window_x, uint16_t window_y)
{
  set_font_pos(window_x + t->text_x, window_y + t->text_y);
  print_str_16x26(t->str[0][*p_current_lang], STRONG_GRAY, FONT_TEXT);
  return 0;
}

/**
  * @fn uint8_t update_text(text* t, uint16_t window_x, uint16_t window_y)
  * @brief  Update text zone with offset of the window
  * @note   None
  * @param  t : text struct with all info
  * @param  window_x : window X axis offset
  * @param  window_y : window Y axis offset
  * @retval None
  */
uint8_t update_text(text* t, uint16_t window_x, uint16_t window_y)
{
  if (t->update == 1)
    {
      set_font_pos(window_x + t->text_x, window_y + t->text_y);
      print_str_16x26(t->str[0][*p_current_lang], STRONG_GRAY, FONT_TEXT);
      return 0;
    }
  return 0;
}
