#include "effect.h"

void fill_with_Color(uint16_t color)
{
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
