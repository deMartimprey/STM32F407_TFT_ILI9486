/**
 * @file font10x16.c
 * @brief Fonctions to display 10x16 font.
 * @author de Martimprey Edmond
 * @version 0.1
 * @date 28 june 2022
 *
 * Fonctions to display 10x16 font.
 *
 */

#include "font10x16.h"

#ifdef USE_10X16

/**
 * @fn void print_str_10x16(uint8_t* str, uint16_t color, uint16_t font)
 * @brief Print one line in 10x16 font must not go over the screen
 * @param str line to print need to terminate by 0
 * @param color color of charactere
 * @param font color of font
 * @retval None
 */
void print_str_10x16(const uint8_t* str, uint16_t color, uint16_t font)
{
  uint16_t len = my_strlen(str);
  for (uint16_t i = 0; i < len; i++)
    {
      draw_one_char_10x16(str[i], color, font);
      // Fill space between char whith font color exept for the end
      if (i != len - 1)
	draw_rectangle(x_font_pos + 10, y_font_pos, 10, 16, font);
      x_font_pos += 11; // decal for the next char
    }
}

/**
 * @fn void draw_one_char_10x16(uint8_t num, uint16_t color, uint16_t font)
 * @brief Print one char in 10x16 font must not go over the screen
 * @param num char to print
 * @param color color of charactere
 * @param font color of font
 * @return None
 */
void draw_one_char_10x16(uint8_t num, uint16_t color, uint16_t font)
{
  write_zone(x_font_pos, y_font_pos, 10, 16);

  Write_Command(0x2C);	// Start writing
    
  for (uint8_t i = 0; i < 20; i += 2)
    {
      /* for (uint8_t y = 8; y > 0; y--) */
	/* { */
	/*   if (font10x16[num + 1][i] & 1 << (y)) */
	/*     Write_Data(color); */
	/*   else */
	/*     Write_Data(font); */
	/* } */
      for (uint8_t y = 8; y > 0; y--)
	{
	  if (font10x16[num][i + 1] & 1 << (y - 1))
	    Write_Data(color);
	  else
	    Write_Data(font);
	}
      for (uint8_t y = 8; y > 0; y--)
	{
	  if (font10x16[num][i] & 1 << (y - 1))
	    Write_Data(color);
	  else
	    Write_Data(font);
	}
    }
}

#endif /* USE_10x16 */
