#include "draw.h"

uint8_t display_draw(draw* d, uint16_t window_x, uint16_t window_y)
{
  if (d->type == RECTANGLE)
    {
      draw_rectangle(d->x_pos + window_x, d->y_pos + window_y, d->x_size, d->y_size, d->color);
    }
  if (d->type == FRAME)
    {
      draw_empty_rectangle(d->x_pos + window_x, d->y_pos + window_y, d->x_size, d->y_size, d->thickness, d->color);
    }
  if (d->type == DOT)
    {
      DrawFillCircle(d->x_pos + window_x, d->y_pos + window_y, d->x_size, d->color);
    }
  if (d->type == CIRCLE)
    {
      DrawCircle(d->x_pos + window_x, d->y_pos + window_y, d->x_size, d->color);
    }
  return 0;
}

uint8_t update_draw(draw* d, uint16_t window_x, uint16_t window_y)
{
  if (d->update == 1)
    {
      display_draw(d, window_x, window_y);
      return 0;
    }
  return 0;
}

uint8_t draw_empty_rectangle(uint16_t x_pos, uint16_t y_pos, uint16_t x_size, uint16_t y_size, uint16_t thickness, uint16_t color)
{
  draw_rectangle(x_pos, y_pos, x_size, thickness, color);
  draw_rectangle(x_pos, y_pos, thickness, y_size, color);
  draw_rectangle(x_pos + thickness, y_pos + y_size - thickness, x_size, thickness, color);
  draw_rectangle(x_pos + thickness, y_pos + y_size - thickness, x_size, thickness, color);
  draw_rectangle(x_pos + x_size, y_pos, thickness, y_size, color);
  return 0;
}

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

   pos_pixel(x_pos, y_pos);
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

#ifdef USE_RAM_BUFFER
// Not enough ram for this
void DrawCircle2(uint16_t x_pos, uint16_t y_pos, uint16_t r, uint16_t color)
{
  static const double PI = 3.1415926535;

  for (uint16_t i = 0; i < r * 2; i++)
      for (uint16_t y = 0; y < r * 2; y++)
	buffer[i][y] = YELLOW;

  double i, angle, x1, y1;

  for(i = 0; i < 360; i += 0.2)
    {
      angle = i;
      x1 = r * cos(angle * PI / 180);
      y1 = r * sin(angle * PI / 180);
      write_one_pixel_buffer(buffer, (uint16_t)x1, (uint16_t)y1, GREEN);
    }
  write_buffer(buffer, x_pos, y_pos, r * 2, r * 2);
}
#endif /* USE_RAM_BUFFER */


void DrawFillCircle(uint16_t x_pos, uint16_t y_pos, uint16_t r, uint16_t color)
{
  for(int y=-r; y<=r; y++)
    for(int x=-r; x<=r; x++)
      if(x*x+y*y <= r*r)
        write_one_pixel(x_pos+x, y_pos+y, YELLOW);
}

void DrawCircle(uint16_t x, uint16_t y, uint16_t r, uint16_t color)
{
      static const double PI = 3.1415926535;
      double i, angle, x1, y1;

      for(i = 0; i < 360; i += 0.5)
      {
            angle = i;
            x1 = r * cos(angle * PI / 180);
            y1 = r * sin(angle * PI / 180);
	    write_one_pixel((uint16_t)x + x1, (uint16_t)y + y1, color);
      }
}
