#include "ili9486.h"

void Initialization()
{	//******* Reset tft driver ***************
  HAL_GPIO_WritePin(TFT_RESX_GPIO_Port, TFT_RESX_Pin, 1);
  HAL_Delay(1);
  HAL_GPIO_WritePin(TFT_RESX_GPIO_Port, TFT_RESX_Pin, 0);
  HAL_Delay(10);	// Delay 10ms // This delay time is necessary
  HAL_GPIO_WritePin(TFT_RESX_GPIO_Port, TFT_RESX_Pin, 1);
  HAL_Delay(120);
 
  //************* Start Initial Sequence **********//
  Write_Command_init(0xF2);
  Write_Data(0x18);

  Write_Data(0xA3);
  Write_Data(0x12);
  Write_Data(0x02);
  Write_Data(0xB2);
  Write_Data(0x12);
  Write_Data(0xFF);
  Write_Data(0x10);
  Write_Data(0x00);

  Write_Command_init(0xF1);
  Write_Data(0x36);
  Write_Data(0xA4);
 
  Write_Command_init(0xF8);
  Write_Data(0x21);
  Write_Data(0x04);
 
  Write_Command_init(0xF9);
  Write_Data(0x00);
  Write_Data(0x08);
 
  Write_Command_init(0x36);	//Memory Access Control
  Write_Data(0x08);		
 
  Write_Command_init(0xB4);	//Display Inversion Control
  Write_Data(0x00);
 
  Write_Command_init(0xC1);	//Power Control 2
  Write_Data(0x41);		
  //Write_Data(0x00);	
 
  Write_Command_init(0xC5);	//VCOM Control
  Write_Data(0x08);		//is used to set factor to generate VCOM voltage from the reference voltage VREG2OUT.
 
  Write_Command_init(0xC0);	//Power Control 1
  Write_Data(0x0D);		
  Write_Data(0x0D);		
 
  Write_Command_init(0xC2);	//Power Control 3
  Write_Data(0x00);		
 
  Write_Command_init(0xE0);	// PGAMCTRL (Positive Gamma Control)
  Write_Data(0x0F);
  Write_Data(0x24);
  Write_Data(0x1C);
  Write_Data(0x0A);
  Write_Data(0x0F);
  Write_Data(0x08);
  Write_Data(0x43);
  Write_Data(0x88);
  Write_Data(0x32);
  Write_Data(0x0F);
  Write_Data(0x10);
  Write_Data(0x06);
  Write_Data(0x0F);
  Write_Data(0x07);
  Write_Data(0x00);
 
  Write_Command_init(0xE1);	// NGAMCTRL (Negative Gamma Control)
  Write_Data(0x0F);
  Write_Data(0x38);
  Write_Data(0x30);
  Write_Data(0x09);
  Write_Data(0x0F);
  Write_Data(0x0F);
  Write_Data(0x4E);
  Write_Data(0x77);
  Write_Data(0x3C);
  Write_Data(0x07);
  Write_Data(0x10);
  Write_Data(0x05);
  Write_Data(0x23);
  Write_Data(0x1B);
  Write_Data(0x00);
 
  Write_Command_init(0xE2);	// Digital Gamma Control 1
  Write_Data(0x0F);
  Write_Data(0x32);
  Write_Data(0x2E);
  Write_Data(0x0B);
  Write_Data(0x0D);
  Write_Data(0x05);
  Write_Data(0x47);
  Write_Data(0x75);
  Write_Data(0x37);
  Write_Data(0x06);
  Write_Data(0x10);
  Write_Data(0x03);
  Write_Data(0x24);
  Write_Data(0x20);
  Write_Data(0x00);
 
  Write_Command_init(0xB6);	//Display Function Control
  Write_Data(0x00);
  Write_Data(0x22);		//0x42=Rotation 180 degrees  //0x22
  Write_Data(0x3B);
 
  Write_Command_init(0x20);	// Display Inversion OFF
  //Write_Data(0xC8);	//C8???
 
  Write_Command_init(0x3A);	// Interface Pixel Format
  Write_Data(0x55);
 
  Write_Command_init(0x2A);	// Column Address Set
  Write_Data(0x00);
  Write_Data(0x00);
  Write_Data(0x01);
  Write_Data(0x3F);
 
  Write_Command_init(0x2B);	// Page Address Set
  Write_Data(0x00);
  Write_Data(0x00);
  Write_Data(0x01);
  Write_Data(0xDF);

  Write_Command_init(0x11);	//Sleep out
  HAL_Delay(120);
 
  Write_Command_init(0x38);	//Idle Mode Off
  Write_Command_init(0x13);	//Normal Mode On
 
  Write_Command_init(0x29);	// Display ON
}

void pos_pixel(uint16_t x, uint16_t y)
{
  Write_Command(0x2A);	// Column Address Set
  Write_Data((y & 0b1111111100000000) >> 8);
  Write_Data((y & 0b0000000011111111));
  Write_Data((Y_SIZE & 0b1111111100000000) >> 8);
  Write_Data((Y_SIZE & 0b0000000011111111));

  Write_Command(0x2B);	// Page Address Set
  Write_Data((x & 0b1111111100000000) >> 8);
  Write_Data((x & 0b0000000011111111));
  Write_Data((X_SIZE & 0b1111111100000000) >> 8);
  Write_Data((X_SIZE & 0b0000000011111111));
}

void write_zone(uint16_t x, uint16_t y, uint16_t x_size, uint16_t y_size)
{
  Write_Command(0x2A);	// Column Address Set
  Write_Data((y & 0b1111111100000000) >> 8);
  Write_Data((y & 0b0000000011111111));
  Write_Data(((y + y_size - 1) & 0b1111111100000000) >> 8);
  Write_Data(((y + y_size - 1) & 0b0000000011111111));

  Write_Command(0x2B);	// Page Address Set
  Write_Data((x & 0b1111111100000000) >> 8);
  Write_Data((x & 0b0000000011111111));
  Write_Data(((x + x_size - 1) & 0b1111111100000000) >> 8);
  Write_Data(((x + x_size - 1) & 0b0000000011111111));
}

void write_one_pixel(uint16_t x, uint16_t y, uint16_t color)
{
  pos_pixel(x, y);

  Write_Command(0x2C);	// Page Address Set
  Write_Data(color);
}

#ifdef USE_RAM_BUFFER
void write_one_pixel_buffer(uint16_t** buffer, uint16_t x, uint16_t y, uint16_t color)
{
  buffer[x][y] = color;
}
#endif /* USE_RAM_BUFFER */

#ifdef USE_RAM_BUFFER
// return 0 : OK
// return 1 : DRAW BUT TO BIG
// reuturn 2 : OUTSIDE SCREEN, DIDN'T DRAW
uint8_t write_buffer(uint16_t** buffer, uint16_t x_pos, uint16_t y_pos, uint16_t x_size, uint16_t y_size)
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

  Write_Command(0x2C);	// Start writing

  for(int x = 0; x < x_size; x++)
    {
      for(int y = 0; y < y_size; y++)
	{
	  Write_Data(buffer[x][y]);
	}
    }

  if (altered)
    return 1;
  return 0;
}

#endif /* USE_RAM_BUFFER */
