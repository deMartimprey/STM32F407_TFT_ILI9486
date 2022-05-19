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
  Write_Command(0xF2);	
  Write_Data(0x18);

  Write_Data(0xA3);
  Write_Data(0x12);
  Write_Data(0x02);
  Write_Data(0xB2);
  Write_Data(0x12);
  Write_Data(0xFF);
  Write_Data(0x10);
  Write_Data(0x00);

  Write_Command(0xF1);
  Write_Data(0x36);
  Write_Data(0xA4);
 
  Write_Command(0xF8);	
  Write_Data(0x21);
  Write_Data(0x04);
 
  Write_Command(0xF9);	
  Write_Data(0x00);
  Write_Data(0x08);
 
  Write_Command(0x36);	//Memory Access Control
  Write_Data(0x08);		
 
  Write_Command(0xB4);	//Display Inversion Control
  Write_Data(0x00);
 
  Write_Command(0xC1);	//Power Control 2
  Write_Data(0x41);		
  //Write_Data(0x00);	
 
  Write_Command(0xC5);	//VCOM Control
  Write_Data(0x08);		//is used to set factor to generate VCOM voltage from the reference voltage VREG2OUT.
 
  Write_Command(0xC0);	//Power Control 1
  Write_Data(0x0D);		
  Write_Data(0x0D);		
 
  Write_Command(0xC2);	//Power Control 3
  Write_Data(0x00);		
 
  Write_Command(0xE0);	// PGAMCTRL (Positive Gamma Control)
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
 
  Write_Command(0xE1);	// NGAMCTRL (Negative Gamma Control)
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
 
  Write_Command(0xE2);	// Digital Gamma Control 1
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
 
  Write_Command(0xB6);	//Display Function Control
  Write_Data(0x00);
  Write_Data(0x22);		//0x42=Rotation 180 degrees  //0x22
  Write_Data(0x3B);
 
  Write_Command(0x20);	// Display Inversion OFF
  //Write_Data(0xC8);	//C8???
 
  Write_Command(0x3A);	// Interface Pixel Format
  Write_Data(0x55);
 
  Write_Command(0x2A);	// Column Address Set
  Write_Data(0x00);
  Write_Data(0x00);
  Write_Data(0x01);
  Write_Data(0x3F);
 
  Write_Command(0x2B);	// Page Address Set
  Write_Data(0x00);
  Write_Data(0x00);
  Write_Data(0x01);
  Write_Data(0xDF);
 
  Write_Command(0x11);	//Sleep out
  HAL_Delay(120);
 
  Write_Command(0x38);	//Idle Mode Off
  Write_Command(0x13);	//Normal Mode On
 
  Write_Command(0x29);	// Display ON
}
