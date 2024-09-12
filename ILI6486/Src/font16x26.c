/**
 * @file font16x26.c
 * @brief Fonctions to display 16x26 font.
 * @author de Martimprey Edmond
 * @version 0.1
 * @date 28 june 2022
 *
 * Fonctions to display 16x26 font.
 *
 */

#include "font16x26.h"

#ifdef USE_16X26

/**
 * @fn void print_str_16x26(const uint8_t* str, uint16_t color, uint16_t font)
 * @brief Print one line in 16x26 font must not go over the screen
 * @param str line to print need to terminate by 0
 * @param color color of charactere
 * @param font color of font
 * @retval None
 */
void print_str_16x26(const uint8_t* str, uint16_t color, uint16_t font)
{
  uint16_t len = my_strlen(str);
  for (uint16_t i = 0; i < len; i++)
    {
      draw_one_char_16x26(str[i], color, font);
      // Fill space between char whith font color exept for the end
      if (i != len - 1)
	draw_rectangle(x_font_pos + 16, y_font_pos, 16, 26, font);
      x_font_pos += 17; // decal for the next char
    }
}

void draw_one_char_16x26_2(uint8_t num, uint16_t color, uint16_t font)
{
  write_zone(x_font_pos, y_font_pos, 16, 26);

  Write_Command(0x2C);	// Start writing
  for (uint8_t i = 0; i < 52; i += 4)
      /* for (uint8_t j = 4; j > 0; j--) */
      for (uint8_t j = 0; j < 4; j++)
	for (uint8_t y = 8; y > 0; y--)
	  {
	    if (font16x26_lsb[num][i + j] & 1 << (y - 1))
	      Write_Data(color);
	    else
	      Write_Data(font);
	  }
}

/**
 * @fn int find_one_pixel_in_16x26(uint8_t charactere, uint8_t x, uint8_t y)
 * @brief Find one pixel of one charactere
 * @param charactere char to print
 * @param color color of charactere
 * @param font color of font
 * @retval None
 */
int find_one_pixel_in_16x26(uint8_t charactere, uint8_t x, uint8_t y)
{
  return font16x26_lsb[charactere][51 - y * 2 - (1 - x / 8)] & (1 << (x - (x > 7 ? 8 : 0)));
  uint8_t letter[52];
  for (uint8_t i = 0; i < 52; i++)
    letter[i] = font16x26_lsb[charactere][i];
  uint16_t horizontal_pixel[2];
  horizontal_pixel[1] = letter[51 - y * 2];
  horizontal_pixel[0] = letter[51 - y * 2 - 1];
  if (x < 8)
    return horizontal_pixel[0] & (1 << x);
  else /* if (x < 16) */
    return horizontal_pixel[1] & (1 << (x - 8));
  return 0;
}


int find_one_pixel_in_16x26_3(uint8_t charactere, uint8_t x, uint8_t y)
{
  uint8_t letter[52];
  for (uint8_t i = 0; i < 52; i++)
    letter[i] = font16x26_lsb[charactere][i];
  uint16_t y_byte[2];
  y_byte[0] = letter[52 - y * 2];
  y_byte[1] = letter[52 - y * 2 - 1];
  y_byte[3] = letter[52 - y * 2 - 2];
  y_byte[4] = letter[52 - y * 2 - 3];
  if (x < 8)
    return y_byte[0] & (1 << x);
  else if (x < 16)
    return y_byte[1] << 8 & (1 << x);
  else if (x < 24)
    return y_byte[3] << 8 & (1 << x);
  else if (x < 26)
    return y_byte[4] << 8 & (1 << x);
  return 0;
}

/**
 * @fn void draw_one_char_16x26(uint8_t num, uint16_t color, uint16_t font)
 * @brief Print one char in 16x26 font must not go over the screen
 * @param num char to print
 * @param color color of charactere
 * @param font color of font
 * @retval None
 */
void draw_one_char_16x26(uint8_t num, uint16_t color, uint16_t font)
{
  write_zone(x_font_pos, y_font_pos, 16, 26);

  Write_Command(0x2C);	// Start writing
  for (uint8_t x = 0; x < 16; x++)
    {
      for (uint8_t y = 0; y < 26; y++)
	{
	  if (x_font_pos + x < X_SIZE && y_font_pos + y < Y_SIZE)
	    {
	      if (find_one_pixel_in_16x26(num, x, y))
		Write_Data(color);
	      else
		Write_Data(font);
	    }
	}
    }
}

#endif /* USE_16X26 */
