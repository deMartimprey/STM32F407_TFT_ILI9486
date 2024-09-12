/**
 * @file para_16.c
 * @brief Send command and data to TFT.
 * @author de Martimprey Edmond
 * @version 0.1
 * @date 28 june 2022
 *
 * Send command and data to TFT.
 *
 */

#include "para_16.h"
#define DELAY_PARA_16 1

/**
 * @fn void TFT_Send_A_2Byte_To_TFT_DataPins_register(uint32_t character)
 * @brief Most efficient way to comunicate with the driver, write directly into register, need to apply a mask only on changing PIN and not all pin on the port to not affect other functionality
 *
 * @param command Command to send to the TFT
 * @return None
 *
 * If you don't want to wast time and just try replace this function in Write_Command and Write_Data by TFT_Send_A_2Byte_To_TFT_DataPins but it will be slower
 *
 */
void TFT_Send_A_2Byte_To_TFT_DataPins_register(uint32_t command)
{
  //                        GPIO NOT AFFECTED = 1         GPIO AFFECTED
  //                              V                             v
  GPIOA->ODR = (GPIOA->ODR & 0b1111111100000000) | (0b0000000011111111 & command);

  // For B and C there is an offset of 8 between screen pin number and MCU pin number
  GPIOB->ODR = (GPIOB->ODR & 0b1111111100001111) | (0b1111000000000000 & command) >> 8;
  GPIOC->ODR = (GPIOC->ODR & 0b1111111111110000) | (0b0000111100000000 & command) >> 8;
}

/**
 * @fn void Write_Command_init(uint32_t command)
 * @brief Send commande with delay
 *
 * @param command Command to send to the TFT
 * @return None
 *
 * Same as Write_Command but with delay for init TFT, otherwise it's not working well don't have time to investigate more deosn't affect speed of the screen after the init is complete
 *
 */
void Write_Command_init(uint32_t command)
{
  /* HAL_GPIO_WritePin(TFT_DCX_GPIO_Port, TFT_DCX_Pin, 0); */
  /* HAL_GPIO_WritePin(TFT_CSX_GPIO_Port, TFT_CSX_Pin, 0); */
  /* HAL_GPIO_WritePin(TFT_WRX_GPIO_Port, TFT_WRX_Pin, 1); */
  /* GPIOE->ODR = (GPIOE->ODR & 0b1111100001111111) | (0b0000000100000000); */
  /* delay_us(DELAY_PARA_16); */
  /* HAL_GPIO_WritePin(TFT_RESX_GPIO_Port, TFT_RESX_Pin, 1); */
  /* HAL_GPIO_WritePin(TFT_WRX_GPIO_Port, TFT_WRX_Pin, 0); */
  GPIOE->ODR = (GPIOE->ODR & 0b1111100001111111) | (0b0000000010000000);
  delay_us(DELAY_PARA_16);

  TFT_Send_A_2Byte_To_TFT_DataPins/* _register */(command);
  delay_us(DELAY_PARA_16);

  /* HAL_GPIO_WritePin(TFT_WRX_GPIO_Port, TFT_WRX_Pin, 1); */
  /* HAL_GPIO_WritePin(TFT_CSX_GPIO_Port, TFT_CSX_Pin, 1); */
  GPIOE->ODR = (GPIOE->ODR & 0b1111100001111111) | (0b0000010110000000);
  delay_us(DELAY_PARA_16);
}

/**
 * @fn void Write_Command_init(uint32_t command)
 * @brief Send commande with delay
 *
 * @param command Command to send to the TFT
 * @return None
 *
 * Same as Write_Command but with delay for init TFT, otherwise it's not working well don't have time to investigate more deosn't affect speed of the screen after the init is complete
 *
 */
void Write_Command(uint32_t command)
{
  /* HAL_GPIO_WritePin(TFT_DCX_GPIO_Port, TFT_DCX_Pin, 0); */
  /* HAL_GPIO_WritePin(TFT_CSX_GPIO_Port, TFT_CSX_Pin, 0); */
  /* HAL_GPIO_WritePin(TFT_WRX_GPIO_Port, TFT_WRX_Pin, 1); */
  /* GPIOE->ODR = (GPIOE->ODR & 0b1111100001111111) | (0b0000000100000000); */
  /* delay_us(DELAY_PARA_16); */
  /* HAL_GPIO_WritePin(TFT_RESX_GPIO_Port, TFT_RESX_Pin, 1); */
  /* HAL_GPIO_WritePin(TFT_WRX_GPIO_Port, TFT_WRX_Pin, 0); */
  GPIOE->ODR = (GPIOE->ODR & 0b1111100001111111) | (0b0000000010000000);
  //delay_us(DELAY_PARA_16);
 
  TFT_Send_A_2Byte_To_TFT_DataPins/* _register */(command);

  /* HAL_GPIO_WritePin(TFT_WRX_GPIO_Port, TFT_WRX_Pin, 1); */
  /* HAL_GPIO_WritePin(TFT_CSX_GPIO_Port, TFT_CSX_Pin, 1); */
  GPIOE->ODR = (GPIOE->ODR & 0b1111100001111111) | (0b0000010110000000);
  //delay_us(DELAY_PARA_16);
}

/**
 * @fn void Write_Data(uint32_t data)
 * @brief Write data to Driver, without delaying.
 *
 * @param data Data to send to the TFT
 * @return None
 *
 *
 *
 */
void Write_Data(uint32_t data)
{
  /* HAL_GPIO_WritePin(TFT_DCX_GPIO_Port, TFT_DCX_Pin, 1); */
  /* HAL_GPIO_WritePin(TFT_CSX_GPIO_Port, TFT_CSX_Pin, 0); */
  /* HAL_GPIO_WritePin(TFT_WRX_GPIO_Port, TFT_WRX_Pin, 1); */
  /* GPIOE->ODR = (GPIOE->ODR & 0b1111100001111111) | (0b0000001100000000); */
  /* delay_us(DELAY_PARA_16); */
  /* HAL_GPIO_WritePin(TFT_RESX_GPIO_Port, TFT_RESX_Pin, 1); */
  /* HAL_GPIO_WritePin(TFT_WRX_GPIO_Port, TFT_WRX_Pin, 0); */
  GPIOE->ODR = (GPIOE->ODR & 0b1111100001111111) | (0b0000001010000000);
  //delay_us(DELAY_PARA_16);
 
  TFT_Send_A_2Byte_To_TFT_DataPins_register(data);

  /* HAL_GPIO_WritePin(TFT_WRX_GPIO_Port, TFT_WRX_Pin, 1); */
  /* HAL_GPIO_WritePin(TFT_CSX_GPIO_Port, TFT_CSX_Pin, 1); */
  GPIOE->ODR = (GPIOE->ODR & 0b1111100001111111) | (0b0000011110000000);
  //delay_us(DELAY_PARA_16);
}

/**
 * @fn void TFT_Send_A_2Byte_To_TFT_DataPins(uint32_t command)
 * @brief Write data to Driver, don't need to scratch head with register but very slow.
 *
 * @param command Data to send to the TFT
 * @return None
 *
 *
 *
 */
void TFT_Send_A_2Byte_To_TFT_DataPins(uint32_t command)
{
  HAL_GPIO_WritePin(TFT_D0_GPIO_Port, TFT_D0_Pin, 	(command & 0b0000000000000001) >> 0);
  HAL_GPIO_WritePin(TFT_D1_GPIO_Port, TFT_D1_Pin, 	(command & 0b0000000000000010) >> 1);
  HAL_GPIO_WritePin(TFT_D2_GPIO_Port, TFT_D2_Pin, 	(command & 0b0000000000000100) >> 2);
  HAL_GPIO_WritePin(TFT_D3_GPIO_Port, TFT_D3_Pin, 	(command & 0b0000000000001000) >> 3);
  HAL_GPIO_WritePin(TFT_D4_GPIO_Port, TFT_D4_Pin, 	(command & 0b0000000000010000) >> 4);
  HAL_GPIO_WritePin(TFT_D5_GPIO_Port, TFT_D5_Pin, 	(command & 0b0000000000100000) >> 5);
  HAL_GPIO_WritePin(TFT_D6_GPIO_Port, TFT_D6_Pin, 	(command & 0b0000000001000000) >> 6);
  HAL_GPIO_WritePin(TFT_D7_GPIO_Port, TFT_D7_Pin, 	(command & 0b0000000010000000) >> 7);
  HAL_GPIO_WritePin(TFT_D8_GPIO_Port, TFT_D8_Pin, 	(command & 0b0000000100000000) >> 8);
  HAL_GPIO_WritePin(TFT_D9_GPIO_Port, TFT_D9_Pin, 	(command & 0b0000001000000000) >> 9);
  HAL_GPIO_WritePin(TFT_D10_GPIO_Port, TFT_D10_Pin,	(command & 0b0000010000000000) >> 10);
  HAL_GPIO_WritePin(TFT_D11_GPIO_Port, TFT_D11_Pin, 	(command & 0b0000100000000000) >> 11);
  HAL_GPIO_WritePin(TFT_D12_GPIO_Port, TFT_D12_Pin, 	(command & 0b0001000000000000) >> 12);
  HAL_GPIO_WritePin(TFT_D13_GPIO_Port, TFT_D13_Pin, 	(command & 0b0010000000000000) >> 13);
  HAL_GPIO_WritePin(TFT_D14_GPIO_Port, TFT_D14_Pin, 	(command & 0b0100000000000000) >> 14);
  HAL_GPIO_WritePin(TFT_D15_GPIO_Port, TFT_D15_Pin, 	(command & 0b1000000000000000) >> 15);
}
