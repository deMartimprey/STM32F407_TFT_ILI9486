#include "effect.h"

void sleep_screen_str2(uint8_t* str, uint16_t len_str, uint16_t color_str, uint16_t color_font)
{
  static uint16_t xd = 1;
  static uint16_t yd = 1;

  static uint16_t x = 1;
  static uint16_t y = 1;

  if (xd == 1)
    x += 1;
  else
    x -= 1;
  if (yd == 1)
    y += 1;
  else
    y -= 1;
  if (x > X_SIZE - len_str * 18 - 1)
    {
      xd = 0;
    }
  if (y > Y_SIZE - 26 - 1)
    {
      yd = 0;
    }
  if (x < 1)
    {
      xd = 1;
    }
  if (y < 1)
    {
      yd = 1;
    }
  set_font_pos(x + 0,  y);
  print_str_16x26(str, color_str, color_font);
  /* if (xd == 1 && xd == 1) */
  /*   { */
  /*     if (x > 0 && y > 0) */
  /* 	{ */
  /* 	  /\* draw_rectangle(x - 1, y - 1, my_strlen("12345678") * 18 + 2, 1, WHITE); *\/ */
  /* 	  /\* draw_rectangle(x - 1, y - 1, 1, 26, WHITE); *\/ */
  /* 	} */
  /*   } */
  /* if (xd == 1 && yd == 0) */
  /*   { */
  /*     if (x + 16 < X_SIZE && y > 0) */
  /* 	{ */
  /* 	  /\* draw_rectangle(x - 1, y + 1 + 26, my_strlen("12345678") * 18, 1, WHITE); *\/ */
  /* 	  /\* draw_rectangle(x - 1, y + 1, 1, 26, WHITE); *\/ */
  /* 	} */
  /*   } */
  /* if (xd == 0 && yd == 1) */
  /*   { */
  /*     if ((x > 0 && y + 26 > Y_SIZE)) */
  /* 	{ */
  /* 	  /\* draw_rectangle(x, y - 1, my_strlen("12345678") * 18, 1, WHITE); *\/ */
  /* 	  /\* draw_rectangle(x  + my_strlen("12345678") * 18 - 2, y + 1, 1, 26, WHITE); *\/ */
  /* 	} */
  /*   } */
  /* if (xd == 0 && yd == 0) */
  /*   { */
  /*     if ((x > 0 && y  > 0)) */
  /* 	{ */
  /* 	  /\* draw_rectangle(x + 1, y + 26 + 1, my_strlen("12345678") * 18, 1,  WHITE); *\/ */
  /* 	  /\* draw_rectangle(x + my_strlen("12345678") * 18, y + 1, 1, 26, WHITE); *\/ */
  /* 	} */
  /*   } */
}

void sleep_screen_str(uint8_t* str, uint16_t len_str, uint16_t color_str, uint16_t color_font)
{
  static uint16_t xd = 1;
  static uint16_t yd = 1;

  static uint16_t x = 1;
  static uint16_t y = 1;

  if (xd == 1)
    x += 1;
  else
    x -= 1;
  if (yd == 1)
    y += 1;
  else
    y -= 1;
  if (x > X_SIZE - len_str * 18 - 1)
    {
      xd = 0;
    }
  if (y > Y_SIZE - 26 - 1)
    {
      yd = 0;
    }
  if (x < 1)
    {
      xd = 1;
    }
  if (y < 1)
    {
      yd = 1;
    }
  set_font_pos(x + 0,  y);
  print_str_16x26(str, color_str, color_font);
  /* draw_rectangle(0, y, x, 26, WHITE); */
  /* draw_rectangle(x + my_strlen("12345678") * 18, y, 480 - x - my_strlen("12345678") * 18, 26, WHITE); */
  /* if (xd == 1 && xd == 1) */
  /*   { */
  /*     if (x > 0 && y > 0) */
  /* 	{ */
  /* 	  /\* draw_rectangle(x - 1, y - 1, my_strlen("12345678") * 18 + 2, 1, WHITE); *\/ */
  /* 	  /\* draw_rectangle(x - 1, y - 1, 1, 26, WHITE); *\/ */
  /* 	} */
  /*   } */
  /* if (xd == 1 && yd == 0) */
  /*   { */
  /*     if (x + 16 < X_SIZE && y > 0) */
  /* 	{ */
  /* 	  /\* draw_rectangle(x - 1, y + 1 + 26, my_strlen("12345678") * 18, 1, WHITE); *\/ */
  /* 	  /\* draw_rectangle(x - 1, y + 1, 1, 26, WHITE); *\/ */
  /* 	} */
  /*   } */
  /* if (xd == 0 && yd == 1) */
  /*   { */
  /*     if ((x > 0 && y + 26 > Y_SIZE)) */
  /* 	{ */
  /* 	  /\* draw_rectangle(x, y - 1, my_strlen("12345678") * 18, 1, WHITE); *\/ */
  /* 	  /\* draw_rectangle(x  + my_strlen("12345678") * 18 - 2, y + 1, 1, 26, WHITE); *\/ */
  /* 	} */
  /*   } */
  /* if (xd == 0 && yd == 0) */
  /*   { */
  /*     if ((x > 0 && y  > 0)) */
  /* 	{ */
  /* 	  /\* draw_rectangle(x + 1, y + 26 + 1, my_strlen("12345678") * 18, 1,  WHITE); *\/ */
  /* 	  /\* draw_rectangle(x + my_strlen("12345678") * 18, y + 1, 1, 26, WHITE); *\/ */
  /* 	} */
  /*   } */
}

void fill_with_Color(uint16_t color)
{
  pos_pixel(0, 0);
  Write_Command(0x2C);

  for(int x = 0; x < X_SIZE; x++)
    {
      for(int y = 0; y < Y_SIZE; y++)
	{
	  Write_Data(color);
	}
    }
  Write_Command(0x00);
}

void fill_with_RGB()
{
  uint16_t color = 0;

  pos_pixel(0, 0);
  Write_Command(0x2C);

  for(int x = 0; x < X_SIZE; x++)
    {
      if (x < X_SIZE / 3)
	{
	  color = 0b0000000000011111;
	}
      else if (x < X_SIZE / 3 * 2)
	{
	  color = 0b0000011111100000;
	}
      else
	{
	  color = 0b1111100000000000;
	}
	
      for(int y = 0; y < Y_SIZE; y++)
	{
	  Write_Data(color);
	}
    }

  Write_Command(0x00);
}
