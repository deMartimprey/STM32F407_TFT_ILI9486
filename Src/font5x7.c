#include "font5x7.h"

#ifdef USE_5X7

void set_font_pos(uint16_t x_pos, uint8_t y_pos)
{
  x_font_pos = x_pos;
  y_font_pos = y_pos;
}

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
