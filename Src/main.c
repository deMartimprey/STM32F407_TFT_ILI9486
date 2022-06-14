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
  current_lang = FR;
  p_current_lang = &current_lang;
  delay_init();
  Initialization();
  fill_with_Color(WHITE);
  draw_rectangle(100, 150, 5, 7, RED);
  draw_rectangle(50, 150, 30, 20, YELLOW);
  DrawCircle(X_SIZE / 2, Y_SIZE / 2, Y_SIZE / 2, RED);
  set_font_pos(10, 10);
  draw_one_char_5x7('H', BLACK, WHITE);
  draw_one_char_5x7('E', BLACK, WHITE);
  draw_one_char_5x7('L', BLACK, WHITE);
  draw_one_char_5x7('L', BLACK, WHITE);
  draw_one_char_5x7('O', BLACK, WHITE);
  print_str_5x7((uint8_t*)"123456789", BLACK, WHITE);
  set_font_pos(30, 30);
  draw_one_char_10x16('H', BLACK, WHITE);
  draw_one_char_10x16('E', BLACK, WHITE);
  draw_one_char_10x16('L', BLACK, WHITE);
  draw_one_char_10x16('L', BLACK, WHITE);
  draw_one_char_10x16('O', BLACK, WHITE);
  print_str_10x16((uint8_t*)"123456789!", BLACK, WHITE);
  set_font_pos(0, 280);
  print_str_16x26((uint8_t*)"abcdefghijklmnopqrs12345678", BLACK, YELLOW);
  /* fill_with_Color(WHITE); */
  /* uint16_t len = my_strlen((uint8_t*)"1234"); */
  /* uint16_t len2 = my_strlen((uint8_t*)"5678"); */
  /* while (1) { */
  /*   sleep_screen_str((uint8_t*)"1234", len, RED, WHITE); */
  /*   sleep_screen_str2((uint8_t*)"5678", len2, RED, WHITE); */
  /*   sleep_screen_str2((uint8_t*)"5678", len2, RED, WHITE); */
  /*   sleep_screen_str2((uint8_t*)"5678", len2, RED, WHITE); */
  /* } */
  pos_pixel(0, 0);

  router router1;
  router1.name = &s_router_1;
  router1.pos_router = 0;
  router1.size = 0;
  router1.arrow_pos = 0;
  router1.first_elem_pos = 0;

  router router2;
  router2.name = &s_router_2;
  router2.pos_router = 0;
  router2.size = 0;
  router2.arrow_pos = 0;
  router2.first_elem_pos = 0;

  router router3;
  router3.name = &s_router_3;
  router3.pos_router = 0;
  router3.size = 0;
  router3.arrow_pos = 0;
  router3.first_elem_pos = 0;

  router router4;
  router4.name = &s_router_4;
  router4.pos_router = 0;
  router4.size = 0;
  router4.arrow_pos = 0;
  router4.first_elem_pos = 0;

  router router5;
  router5.name = &s_router_5;
  router5.pos_router = 0;
  router5.size = 0;
  router5.arrow_pos = 0;
  router5.first_elem_pos = 0;

  router router6;
  router6.name = &s_router_6;
  router6.pos_router = 0;
  router6.size = 0;
  router6.arrow_pos = 0;
  router6.first_elem_pos = 0;

  router router7;
  router7.name = &s_router_7;
  router7.pos_router = 0;
  router7.size = 0;
  router7.arrow_pos = 0;
  router7.first_elem_pos = 0;

  cur_router = &router1;
  add_elem_router(&router1, &router1);
  add_elem_router(&router1, &router2);
  add_elem_router(&router1, &router3);
  add_elem_router(&router1, &router4);
  add_elem_router(&router1, &router5);
  add_elem_router(&router1, &router6);
  add_elem_router(&router2, &router4);
  add_elem_router(&router2, &router5);
  add_elem_router(&router2, &router6);
  add_elem_router(&router2, &router7);

  var1 = new_var(vars, &s_var1, 0, 0, 99999, 11);
  var2 = new_var(vars, &s_var2, 0, 0, 99999, 12);
  var3 = new_var(vars, &s_var3, 0, 0, 99999, 13);
  var4 = new_var(vars, &s_var4, 0, 0, 99999, 14);

  display_router(cur_router, 150, 150);
  router_up(cur_router);
  display_router(cur_router, 150, 150);
  HAL_Delay(500);
  into_router(cur_router);
  display_router(cur_router, 150, 150);

  menu menu1;
  menu1.name = &s_menu1;
  menu1.pos_menu = 0;
  menu1.size = 0;
  menu1.arrow_pos = 0;
  menu1.first_elem_pos = 0;
  add_elem_menu(&menu1, var1);
  add_elem_menu(&menu1, var2);
  add_elem_menu(&menu1, var3);
  add_elem_menu(&menu1, var4);

  fill_with_Color(0xFFFF);
  menu_up(&menu1);
  display_menu(&menu1, 150, 150);
  HAL_Delay(500);
  menu_up(&menu1);
  display_menu(&menu1, 150, 150);
  HAL_Delay(500);
  display_menu(&menu1, 150, 150);
  HAL_Delay(500);
  menu_var_up(&menu1);
  display_menu(&menu1, 150, 150);
  HAL_Delay(500);
  menu_var_up(&menu1);
  display_menu(&menu1, 150, 150);
  HAL_Delay(500);
  menu_var_up(&menu1);
  display_menu(&menu1, 150, 150);
  HAL_Delay(500);
  while (1);
    {
      HAL_Delay(3000);
      router_up(cur_router);
      display_router(cur_router, 150, 150);
    }
  while (1)
  {
    fill_with_Color(0x000000);
    fill_with_RGB();
  }
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
  RCC_OscInitStruct.PLL.PLLM = 6; // REDUCE HERE TO SPEED UP
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

