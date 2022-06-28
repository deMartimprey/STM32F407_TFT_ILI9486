#include "draw.h"

// http://rosettacode.org/wiki/Bitmap/Bresenham%27s_line_algorithm#C
void draw_line(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color)
{
  int16_t dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
  int16_t dy = abs(y1-y0), sy = y0<y1 ? 1 : -1;
  int16_t err = (dx>dy ? dx : -dy)/2, e2;

  for(;;){
    write_one_pixel(x0, y0, color);
    if (x0==x1 && y0==y1)
      break;
    e2 = err;
    if (e2 >-dx)
      {
	err -= dy; x0 += sx;
      }
    if (e2 < dy)
      {
	err += dx; y0 += sy;
      }
  }
}

//https://saideepdicholkar.blogspot.com/2017/04/bresenhams-line-algorithm-thick-line.html
void draw_thick_line(float x0, float y0, float x1, float y1, uint16_t thickness, uint16_t color)
{
  uint16_t i = 0;
  float wy;
  float wx;
  draw_line(x0, y0, x1, y1, color);
  if((y1-y0)/(x1-x0)<1)
    {
      wy=(thickness-1)*sqrt(pow((x1-x0),2)+pow((y1-y0),2))/(2*fabs(x1-x0));
      for(i=0;i<wy;i++)
	{
	  draw_line(x0, y0-i, x1, y1-i, color);
	  draw_line(x0, y0+i, x1, y1+i, color);
	}
    }
  else
    {
      wx=(thickness-1)*sqrt(pow((x1-x0),2)+pow((y1-y0),2))/(2*fabs(y1-y0));
      for(i=0;i<wx;i++)
        {
	  draw_line(x0-i, y0, x1-i, y1, color);
	  draw_line(x0+i, y0, x1+i, y1, color);
        }
    }
}

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
      write_one_pixel_buffer(buffer, (uint16_t)x1, (uint16_t)y1, color);
    }
  write_buffer(buffer, x_pos, y_pos, r * 2, r * 2);
}
#endif /* USE_RAM_BUFFER */


void DrawFillCircle(uint16_t x_pos, uint16_t y_pos, uint16_t r, uint16_t color)
{
  for(int y=-r; y<=r; y++)
    for(int x=-r; x<=r; x++)
      if(x*x+y*y <= r*r)
        write_one_pixel(x_pos+x, y_pos+y, color);
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

#define SWAP(x,y) 		do { (x)=(x)^(y); (y)=(x)^(y); (x)=(x)^(y); } while(0)

/* Horizontal Line */
static void lcd_hline(int x1, int x2, int y, uint16_t color)
{
  if (x1 >= x2)
    SWAP(x1, x2);

  for (; x1 <= x2 ; x1++)
    write_one_pixel(x1, y, color); // replace this with any function in your library of choice
  // for drawing 1 pixel
}

//https://www.codegrepper.com/code-examples/c/how+to+fill+a+triangle+in+c
/* Fill Triangle Function */
void fill_triangle(int x1, int y1, int x2, int y2, int x3, int y3, uint16_t color)
{
  int t1x, t2x, y, minx, maxx, t1xp, t2xp;
  int changed1 = 0;
  int changed2 = 0;
  int signx1, signx2, dx1, dy1, dx2, dy2;
  int e1, e2;

  // Sort vertices
  if (y1 > y2) { SWAP(y1,y2); SWAP(x1,x2); }
  if (y1 > y3) { SWAP(y1,y3); SWAP(x1,x3); }
  if (y2 > y3) { SWAP(y2,y3); SWAP(x2,x3); }

  t1x = t2x = x1;
  y = y1;   // Starting points

  dx1 = (x2 - x1); if(dx1<0) { dx1=-dx1; signx1=-1; } else signx1=1;
  dy1 = (y2 - y1);

  dx2 = (x3 - x1); if(dx2<0) { dx2=-dx2; signx2=-1; } else signx2=1;
  dy2 = (y3 - y1);

  if (dy1 > dx1) {   // swap values
    SWAP(dx1,dy1);
    changed1 = 1;
  }
  if (dy2 > dx2) {   // swap values
    SWAP(dy2,dx2);
    changed2 = 1;
  }

  e2 = (dx2>>1);
  // Flat top, just process the second half
  if(y1==y2) goto next;
  e1 = (dx1>>1);

  for (int i = 0; i < dx1;) {
    t1xp=0; t2xp=0;
    if(t1x<t2x)
      { minx=t1x; maxx=t2x; }
    else
      { minx=t2x; maxx=t1x; }
    // process first line until y value is about to change
    while(i<dx1) {
      i++;
      e1 += dy1;
      while (e1 >= dx1) {
	e1 -= dx1;
	if (changed1) t1xp=signx1;//t1x += signx1;
	else          goto next1;
      }
      if (changed1) break;
      else t1x += signx1;
    }
    // Move line
  next1:
    // process second line until y value is about to change
    while (1) {
      e2 += dy2;
      while (e2 >= dx2) {
	e2 -= dx2;
	if (changed2) t2xp=signx2;//t2x += signx2;
	else          goto next2;
      }
      if (changed2)     break;
      else              t2x += signx2;
    }
  next2:
    if(minx>t1x)
      minx=t1x;
    if(minx>t2x)
      minx=t2x;
    if(maxx<t1x)
      maxx=t1x;
    if(maxx<t2x)
      maxx=t2x;
    lcd_hline(minx, maxx, y, color);    // Draw line from min to max points found on the y
    // Now increase y
    if(!changed1)
      t1x += signx1;
    t1x+=t1xp;
    if(!changed2)
      t2x += signx2;
    t2x+=t2xp;
    y += 1;
    if(y==y2)
      break;
  }
 next:
  // Second half
  dx1 = (x3 - x2); if(dx1<0) { dx1=-dx1; signx1=-1; } else signx1=1;
  dy1 = (y3 - y2);
  t1x=x2;

  if (dy1 > dx1) {   // swap values
    SWAP(dy1,dx1);
    changed1 = 1;
  } else changed1 = 0;

  e1 = (dx1>>1);

  for (int i = 0; i<=dx1; i++) {
    t1xp=0; t2xp=0;
    if(t1x<t2x) { minx=t1x; maxx=t2x; }
    else		{ minx=t2x; maxx=t1x; }
    // process first line until y value is about to change
    while(i<dx1) {
      e1 += dy1;
      while (e1 >= dx1) {
	e1 -= dx1;
	if (changed1) { t1xp=signx1; break; }//t1x += signx1;
	else          goto next3;
      }
      if (changed1) break;
      else   	   	  t1x += signx1;
      if(i<dx1) i++;
    }
  next3:
    // process second line until y value is about to change
    while (t2x!=x3) {
      e2 += dy2;
      while (e2 >= dx2) {
	e2 -= dx2;
	if(changed2) t2xp=signx2;
	else          goto next4;
      }
      if (changed2)     break;
      else              t2x += signx2;
    }
  next4:

    if(minx>t1x)
      minx=t1x;
    if(minx>t2x)
      minx=t2x;
    if(maxx<t1x)
      maxx=t1x;
    if(maxx<t2x)
      maxx=t2x;
    lcd_hline(minx, maxx, y, color);    // Draw line from min to max points found on the y
    // Now increase y
    if(!changed1) t1x += signx1;
    t1x+=t1xp;
    if(!changed2) t2x += signx2;
    t2x+=t2xp;
    y += 1;
    if(y>y3) return;
  }
}
