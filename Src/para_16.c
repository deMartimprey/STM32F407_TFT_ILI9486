#include "para_16.h"

void Write_Command(uint32_t Command)
{
  HAL_GPIO_WritePin(TFT_DCX_GPIO_Port, TFT_DCX_Pin, 0);
  HAL_GPIO_WritePin(TFT_CSX_GPIO_Port, TFT_CSX_Pin, 0);
  HAL_GPIO_WritePin(TFT_WRX_GPIO_Port, TFT_WRX_Pin, 1);
  HAL_GPIO_WritePin(TFT_RESX_GPIO_Port, TFT_RESX_Pin, 1);
  HAL_GPIO_WritePin(TFT_WRX_GPIO_Port, TFT_WRX_Pin, 0);
 
  TFT_Send_A_2Byte_To_TFT_DataPins(Command); 

  HAL_GPIO_WritePin(TFT_WRX_GPIO_Port, TFT_WRX_Pin, 1);
  HAL_GPIO_WritePin(TFT_CSX_GPIO_Port, TFT_CSX_Pin, 1);
}

void Write_Data(uint32_t Data)
{
  HAL_GPIO_WritePin(TFT_DCX_GPIO_Port, TFT_DCX_Pin, 1);
  HAL_GPIO_WritePin(TFT_CSX_GPIO_Port, TFT_CSX_Pin, 0);
  HAL_GPIO_WritePin(TFT_WRX_GPIO_Port, TFT_WRX_Pin, 1);
  HAL_GPIO_WritePin(TFT_RESX_GPIO_Port, TFT_RESX_Pin, 1);
  HAL_GPIO_WritePin(TFT_WRX_GPIO_Port, TFT_WRX_Pin, 0);
 
  TFT_Send_A_2Byte_To_TFT_DataPins(Data);
 
  HAL_GPIO_WritePin(TFT_WRX_GPIO_Port, TFT_WRX_Pin, 1);
  HAL_GPIO_WritePin(TFT_CSX_GPIO_Port, TFT_CSX_Pin, 1);
}

void TFT_Send_A_2Byte_To_TFT_DataPins(uint32_t character)
{
  HAL_GPIO_WritePin(TFT_D0_GPIO_Port, TFT_D0_Pin, 	(character & 0b0000000000000001) >> 0);
  HAL_GPIO_WritePin(TFT_D1_GPIO_Port, TFT_D1_Pin, 	(character & 0b0000000000000010) >> 1);
  HAL_GPIO_WritePin(TFT_D2_GPIO_Port, TFT_D2_Pin, 	(character & 0b0000000000000100) >> 2);
  HAL_GPIO_WritePin(TFT_D3_GPIO_Port, TFT_D3_Pin, 	(character & 0b0000000000001000) >> 3);
  HAL_GPIO_WritePin(TFT_D4_GPIO_Port, TFT_D4_Pin, 	(character & 0b0000000000010000) >> 4);
  HAL_GPIO_WritePin(TFT_D5_GPIO_Port, TFT_D5_Pin, 	(character & 0b0000000000100000) >> 5);
  HAL_GPIO_WritePin(TFT_D6_GPIO_Port, TFT_D6_Pin, 	(character & 0b0000000001000000) >> 6);
  HAL_GPIO_WritePin(TFT_D7_GPIO_Port, TFT_D7_Pin, 	(character & 0b0000000010000000) >> 7);
  HAL_GPIO_WritePin(TFT_D8_GPIO_Port, TFT_D8_Pin, 	(character & 0b0000000100000000) >> 8);
  HAL_GPIO_WritePin(TFT_D9_GPIO_Port, TFT_D9_Pin, 	(character & 0b0000001000000000) >> 9);
  HAL_GPIO_WritePin(TFT_D10_GPIO_Port, TFT_D10_Pin,	(character & 0b0000010000000000) >> 10);
  HAL_GPIO_WritePin(TFT_D11_GPIO_Port, TFT_D11_Pin, 	(character & 0b0000100000000000) >> 11);
  HAL_GPIO_WritePin(TFT_D12_GPIO_Port, TFT_D12_Pin, 	(character & 0b0001000000000000) >> 12);
  HAL_GPIO_WritePin(TFT_D13_GPIO_Port, TFT_D13_Pin, 	(character & 0b0010000000000000) >> 13);
  HAL_GPIO_WritePin(TFT_D14_GPIO_Port, TFT_D14_Pin, 	(character & 0b0100000000000000) >> 14);
  HAL_GPIO_WritePin(TFT_D15_GPIO_Port, TFT_D15_Pin, 	(character & 0b1000000000000000) >> 15);
}
