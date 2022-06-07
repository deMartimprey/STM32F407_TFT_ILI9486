#include "font10x16.h"

#ifdef USE_10X16

void print_str_10x16(uint8_t* str, uint16_t color, uint16_t font)
{
  uint16_t len = my_strlen(str);
  for (uint16_t i = 0; i < len; i++)
    {
      draw_one_char_10x16(str[i], color, font);
    }
}

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
  x_font_pos += 11; // decal for the next char
}

#endif /* USE_10x16 */
