/**
 * @file font5x7.c
 * @brief Fonctions to display 5x7 font.
 * @author de Martimprey Edmond
 * @version 0.1
 * @date 28 june 2022
 *
 * Fonctions to display 5x7 font.
 *
 */

#include "font5x7.h"

#ifdef USE_5X7

/**
 * @fn void set_font_pos(uint16_t x_pos, uint16_t y_pos)
 * @brief Initalise TFT with ILI8486 Driver
 *
 * @param None
 * @return None
 */
void set_font_pos(uint16_t x_pos, uint16_t y_pos)
{
  x_font_pos = x_pos;
  y_font_pos = y_pos;
}

/**
 * @fn void print_str_5x7(uint8_t* str, uint16_t color, uint16_t font)
 * @brief Print one line in 5x7 font must not go over the screen
 * @param str line to print need to terminate by 0
 * @param color color of charactere
 * @param font color of font
 * @retval None
 */
void print_str_5x7(uint8_t* str, uint16_t color, uint16_t font)
{
  uint16_t len = my_strlen(str);
  for (uint16_t i = 0; i < len; i++)
    {
      draw_one_char_5x7(str[i], color, font);
    }
}

void draw_one_char_5x7_reverse(uint8_t num, uint16_t color, uint16_t font)
{
  write_zone(x_font_pos, y_font_pos, 5, 7);

  Write_Command(0x2C);	// Start writing
    
  for (uint8_t i = 5; i > 0; i--)
    {
      for (uint8_t y = 0; y < 7; y++)
	{
	  if (font5x7[num * 5 + i - 1] & 1 << y)
	    Write_Data(color);
	  else
	    Write_Data(font);
	}
    }
  x_font_pos += 7; // decal for the next char
}

/**
 * @fn void draw_one_char_5x7(uint8_t num, uint16_t color, uint16_t font)
 * @brief Print one char in 5x7 font must not go over the screen
 * @param num char to print
 * @param color color of charactere
 * @param font color of font
 * @return None
 */
void draw_one_char_5x7(uint8_t num, uint16_t color, uint16_t font)
{
  write_zone(x_font_pos, y_font_pos, 5, 7);

  Write_Command(0x2C);	// Start writing
    
  for (uint8_t i = 0; i < 5; i++)
    {
      for (uint8_t y = 7; y > 0; y--)
	{
	  if (font5x7[num * 5 + i] & 1 << (y - 1))
	    Write_Data(color);
	  else
	    Write_Data(font);
	}
    }
  x_font_pos += 7; // decal for the next char
}

#endif /* USE_5X7 */
