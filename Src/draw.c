#include "draw.h"

// return 0 : OK
// return 1 : DRAW BUT TO BIG
// reuturn 2 : OUTSIDE SCREEN, DIDN'T DRAW
uint8_t draw_rectangle(uint16_t x_pos, uint16_t y_pos, uint16_t x_size, uint16_t y_size, uint16_t color)
{
  uint8_t altered = 0;

  // check position is in screen
  if (x_pos > X_SIZE || y_pos > Y_SIZE)
    return 2;
  
  // Check not go outside screen
  if (x_pos + x_size > X_SIZE)
    {
      x_size -= X_SIZE - x_pos + x_size; // Subtract to the size the part oustise the screen
      altered = 1;
    }

  if (y_pos + y_size > Y_SIZE)
    {
      y_size -= Y_SIZE - y_pos + y_size; // Subtract to the size the part oustise the screen
      altered = 1;
    }

   write_zone(x_pos, y_pos, x_size, y_size);

   Write_Command(0x2C);	// Write

   // Write the rectangle
   for(int x = 0; x < x_size; x++)
    {
      for(int y = 0; y < y_size; y++)
	{
	  Write_Data(color);
	}
    }

   if (altered)
     return 1;
   return 0;
}
