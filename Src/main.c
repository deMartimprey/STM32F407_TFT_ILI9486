#include "main.h"

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
  
/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
  HAL_Init();

  SystemClock_Config();

  MX_GPIO_Init();
  delay_init();
  Initialization();
  HAL_Delay(1);
  Write_Command(0x2C);	// Memory Write
  fill_with_RGB();
  while (1);
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
   */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
   * in the RCC_OscInitTypeDef structure.
   */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8; // REDUCE HERE TO SPEED UP
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
      Error_Handler();
    }
  /** Initializes the CPU, AHB and APB buses clocks
   */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
    |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
    {
      Error_Handler();
    }
}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_SYSCFG_CLK_ENABLE();
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();

  GPIO_InitTypeDef GPIO_InitStructTmp = {0};

  GPIO_InitStructTmp.Pin = TFT_RESX_Pin;
  GPIO_InitStructTmp.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructTmp.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(TFT_RESX_GPIO_Port, &GPIO_InitStructTmp);
  HAL_GPIO_WritePin(TFT_RESX_GPIO_Port, TFT_RESX_Pin, GPIO_PIN_RESET);

  GPIO_InitStructTmp.Pin = TFT_WRX_Pin;
  GPIO_InitStructTmp.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructTmp.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(TFT_WRX_GPIO_Port, &GPIO_InitStructTmp);
  HAL_GPIO_WritePin(TFT_WRX_GPIO_Port, TFT_WRX_Pin, GPIO_PIN_RESET);
  
  GPIO_InitStructTmp.Pin = TFT_CSX_Pin;
  GPIO_InitStructTmp.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructTmp.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(TFT_CSX_GPIO_Port, &GPIO_InitStructTmp);
  HAL_GPIO_WritePin(TFT_CSX_GPIO_Port, TFT_CSX_Pin, GPIO_PIN_RESET);

  GPIO_InitStructTmp.Pin = TFT_DCX_Pin;
  GPIO_InitStructTmp.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructTmp.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(TFT_DCX_GPIO_Port, &GPIO_InitStructTmp);
  HAL_GPIO_WritePin(TFT_DCX_GPIO_Port, TFT_DCX_Pin, GPIO_PIN_RESET);

  GPIO_InitStructTmp.Pin = TFT_D0_Pin;
  GPIO_InitStructTmp.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructTmp.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(TFT_D0_GPIO_Port, &GPIO_InitStructTmp);
  HAL_GPIO_WritePin(TFT_D0_GPIO_Port, TFT_D0_Pin, GPIO_PIN_RESET);

  GPIO_InitStructTmp.Pin = TFT_D1_Pin;
  GPIO_InitStructTmp.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructTmp.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(TFT_D1_GPIO_Port, &GPIO_InitStructTmp);
  HAL_GPIO_WritePin(TFT_D1_GPIO_Port, TFT_D1_Pin, GPIO_PIN_RESET);

  GPIO_InitStructTmp.Pin = TFT_D2_Pin;
  GPIO_InitStructTmp.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructTmp.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(TFT_D2_GPIO_Port, &GPIO_InitStructTmp);
  HAL_GPIO_WritePin(TFT_D2_GPIO_Port, TFT_D2_Pin, GPIO_PIN_RESET);

  GPIO_InitStructTmp.Pin = TFT_D3_Pin;
  GPIO_InitStructTmp.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructTmp.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(TFT_D3_GPIO_Port, &GPIO_InitStructTmp);
  HAL_GPIO_WritePin(TFT_D3_GPIO_Port, TFT_D3_Pin, GPIO_PIN_RESET);

  GPIO_InitStructTmp.Pin = TFT_D4_Pin;
  GPIO_InitStructTmp.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructTmp.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(TFT_D4_GPIO_Port, &GPIO_InitStructTmp);
  HAL_GPIO_WritePin(TFT_D4_GPIO_Port, TFT_D4_Pin, GPIO_PIN_RESET);

  GPIO_InitStructTmp.Pin = TFT_D5_Pin;
  GPIO_InitStructTmp.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructTmp.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(TFT_D5_GPIO_Port, &GPIO_InitStructTmp);
  HAL_GPIO_WritePin(TFT_D5_GPIO_Port, TFT_D5_Pin, GPIO_PIN_RESET);

  GPIO_InitStructTmp.Pin = TFT_D6_Pin;
  GPIO_InitStructTmp.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructTmp.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(TFT_D6_GPIO_Port, &GPIO_InitStructTmp);
  HAL_GPIO_WritePin(TFT_D6_GPIO_Port, TFT_D6_Pin, GPIO_PIN_RESET);

  GPIO_InitStructTmp.Pin = TFT_D7_Pin;
  GPIO_InitStructTmp.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructTmp.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(TFT_D7_GPIO_Port, &GPIO_InitStructTmp);
  HAL_GPIO_WritePin(TFT_D7_GPIO_Port, TFT_D7_Pin, GPIO_PIN_RESET);

  GPIO_InitStructTmp.Pin = TFT_D8_Pin;
  GPIO_InitStructTmp.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructTmp.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(TFT_D8_GPIO_Port, &GPIO_InitStructTmp);
  HAL_GPIO_WritePin(TFT_D8_GPIO_Port, TFT_D8_Pin, GPIO_PIN_RESET);

  GPIO_InitStructTmp.Pin = TFT_D9_Pin;
  GPIO_InitStructTmp.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructTmp.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(TFT_D9_GPIO_Port, &GPIO_InitStructTmp);
  HAL_GPIO_WritePin(TFT_D9_GPIO_Port, TFT_D9_Pin, GPIO_PIN_RESET);

  GPIO_InitStructTmp.Pin = TFT_D10_Pin;
  GPIO_InitStructTmp.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructTmp.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(TFT_D10_GPIO_Port, &GPIO_InitStructTmp);
  HAL_GPIO_WritePin(TFT_D10_GPIO_Port, TFT_D10_Pin, GPIO_PIN_RESET);

  GPIO_InitStructTmp.Pin = TFT_D11_Pin;
  GPIO_InitStructTmp.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructTmp.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(TFT_D11_GPIO_Port, &GPIO_InitStructTmp);
  HAL_GPIO_WritePin(TFT_D11_GPIO_Port, TFT_D11_Pin, GPIO_PIN_RESET);

  GPIO_InitStructTmp.Pin = TFT_D12_Pin;
  GPIO_InitStructTmp.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructTmp.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(TFT_D12_GPIO_Port, &GPIO_InitStructTmp);
  HAL_GPIO_WritePin(TFT_D12_GPIO_Port, TFT_D12_Pin, GPIO_PIN_RESET);

  GPIO_InitStructTmp.Pin = TFT_D13_Pin;
  GPIO_InitStructTmp.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructTmp.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(TFT_D13_GPIO_Port, &GPIO_InitStructTmp);
  HAL_GPIO_WritePin(TFT_D13_GPIO_Port, TFT_D13_Pin, GPIO_PIN_RESET);

  GPIO_InitStructTmp.Pin = TFT_D14_Pin;
  GPIO_InitStructTmp.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructTmp.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(TFT_D14_GPIO_Port, &GPIO_InitStructTmp);
  HAL_GPIO_WritePin(TFT_D14_GPIO_Port, TFT_D14_Pin, GPIO_PIN_RESET);

  GPIO_InitStructTmp.Pin = TFT_D15_Pin;
  GPIO_InitStructTmp.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructTmp.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(TFT_D15_GPIO_Port, &GPIO_InitStructTmp);
  HAL_GPIO_WritePin(TFT_D15_GPIO_Port, TFT_D15_Pin, GPIO_PIN_RESET);

  GPIO_InitStructTmp.Pin = GREEN_Pin;
  GPIO_InitStructTmp.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructTmp.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GREEN_GPIO_Port, &GPIO_InitStructTmp);
  HAL_GPIO_WritePin(GREEN_GPIO_Port, GREEN_Pin, GPIO_PIN_RESET);

  GPIO_InitStructTmp.Pin = RED_Pin;
  GPIO_InitStructTmp.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructTmp.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(RED_GPIO_Port, &GPIO_InitStructTmp);
  HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, GPIO_PIN_RESET);

  GPIO_InitStructTmp.Pin = ORANGE_Pin;
  GPIO_InitStructTmp.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructTmp.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(ORANGE_GPIO_Port, &GPIO_InitStructTmp);
  HAL_GPIO_WritePin(ORANGE_GPIO_Port, ORANGE_Pin, GPIO_PIN_RESET);

  GPIO_InitStructTmp.Pin = BLUE_Pin;
  GPIO_InitStructTmp.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructTmp.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(BLUE_GPIO_Port, &GPIO_InitStructTmp);
  HAL_GPIO_WritePin(BLUE_GPIO_Port, BLUE_Pin, GPIO_PIN_RESET);
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
    {
    }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

