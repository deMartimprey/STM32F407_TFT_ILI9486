#include "main.h"

#define X_MENU 0
#define Y_MENU 320
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
  delay_init();
  HAL_Delay(150);
  Initialization();
  fill_with_Color(WHITE);
  current_lang = new_var(vars, &s_lang, 0, 0, 1, 0);
  p_current_lang = &current_lang->value;
  draw_rectangle(50, 150, 30, 20, YELLOW);
  DrawFillCircle(X_SIZE / 2, Y_SIZE / 2, Y_SIZE / 2, RED);
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
  fill_with_Color(WHITE);

  view view1;
  view view2;
  view view3;

  init_view(&view1);
  init_view(&view2);
  init_view(&view3);

  view2.view_back = &view1;
  view3.view_back = &view1;

  window window1_v1;
  window window2_v1;
  window window3_v1;
  window window4_v1;
  window window5_v1;
  window window1_v2;
  window window1_v3;

  init_window(&window1_v1);
  init_window(&window2_v1);
  init_window(&window3_v1);
  init_window(&window4_v1);
  init_window(&window5_v1);
  init_window(&window1_v2);
  init_window(&window1_v3);

  window1_v1.window_x = 10;
  window1_v1.window_y = 10;
  window1_v1.window_size_x = 150;
  window1_v1.window_size_y = 150;
  window1_v1.window_right = &window5_v1;
  window1_v1.window_left = &window2_v1;
  window1_v1.view_enter = &view2;

  window2_v1.window_x = 10;
  window2_v1.window_y = 170 ;
  window2_v1.window_size_x = 150;
  window2_v1.window_size_y = 150;
  window2_v1.window_left = &window1_v1;
  window2_v1.window_right = &window5_v1;
  window2_v1.view_enter = &view3;

  window3_v1.window_x = 10;
  window3_v1.window_y = 170;
  window3_v1.window_size_x = 150;
  window3_v1.window_size_y = 150;
  window3_v1.window_left = &window4_v1;
  window3_v1.window_right = &window2_v1;

  window4_v1.window_x = 170;
  window4_v1.window_y = 170;
  window4_v1.window_size_x = 150;
  window4_v1.window_size_y = 150;
  window4_v1.window_left = &window1_v1;
  window4_v1.window_right = &window1_v1;

  window5_v1.window_x = 180;
  window5_v1.window_y = 10;
  window5_v1.window_size_x = 290;
  window5_v1.window_size_y = 310;
  window5_v1.window_left = &window1_v1;
  window5_v1.window_right = &window1_v1;

  window1_v2.window_x = 180;
  window1_v2.window_y = 100;
  window1_v2.window_size_x = 100;
  window1_v2.window_size_y = 200;
  window1_v2.window_left = &window1_v2;
  window1_v2.window_right = &window1_v2;

  window1_v3.window_x = 180;
  window1_v3.window_y = 100;
  window1_v3.window_size_x = 100;
  window1_v3.window_size_y = 200;
  window1_v3.window_left = &window1_v3;
  window1_v3.window_right = &window1_v3;
  window1_v3.view_enter = &view1;

  text text1_w1_v1;
  text1_w1_v1.text_x = 10;
  text1_w1_v1.text_y = 50;
  text1_w1_v1.str = &t_1_w1_v1;
  text1_w1_v1.update = 0;

  text text1_w1_v2;
  text1_w1_v2.text_x = 10;
  text1_w1_v2.text_y = 10;
  text1_w1_v2.str = &t_1_w1_v2;
  text1_w1_v2.update = 0;

  text text1_w1_v3;
  text1_w1_v3.text_x = 10;
  text1_w1_v3.text_y = 10;
  text1_w1_v3.str = &t_1_w1_v3;
  text1_w1_v3.update = 0;

  draw draw1;
  draw1.type = DOT;
  draw1.x_pos = 140;
  draw1.y_pos = 60;
  draw1.x_size = 10;
  draw1.y_size = 0;
  draw1.thickness = 0;
  draw1.color = GREEN;
  draw1.update = 0;

  router router1;
  router1.name = &s_router_1;
  router1.pos_router = 0;
  router1.size = 0;
  router1.arrow_pos = 0;
  router1.first_elem_pos = 0;
  router1.up_router = 0;
  router1.router_x = 5;
  router1.router_y = 295;

  add_one_window(&view1, &window1_v1);
  add_one_window(&view1, &window2_v1);
  add_one_window(&view1, &window5_v1);
  view1.cur_window = &window1_v1;
  cur_window = &window1_v1;

  add_one_window(&view2, &window1_v2);
  view2.cur_window = &window1_v2;

  add_one_window(&view3, &window1_v3);

  add_text_to_window(&window2_v1, &text1_w1_v1);
  add_text_to_window(&window1_v2, &text1_w1_v2);
  add_text_to_window(&window1_v3, &text1_w1_v3);

  add_draw_to_window(&window2_v1, &draw1);
  add_router_to_window(&window5_v1, &router1);
  cur_view = &view1;

  router router2;
  router2.name = &s_router_2;
  router2.pos_router = 0;
  router2.size = 0;
  router2.arrow_pos = 0;
  router2.first_elem_pos = 0;
  router2.up_router = &router1;

  router router3;
  router3.name = &s_router_3;
  router3.pos_router = 0;
  router3.size = 0;
  router3.arrow_pos = 0;
  router3.first_elem_pos = 0;
  router3.up_router = &router1;

  router router4;
  router4.name = &s_router_4;
  router4.pos_router = 0;
  router4.size = 0;
  router4.arrow_pos = 0;
  router4.first_elem_pos = 0;
  router4.up_router = &router1;

  router router5;
  router5.name = &s_router_5;
  router5.pos_router = 0;
  router5.size = 0;
  router5.arrow_pos = 0;
  router5.first_elem_pos = 0;
  router5.up_router = &router1;

  router router6;
  router6.name = &s_router_6;
  router6.pos_router = 0;
  router6.size = 0;
  router6.arrow_pos = 0;
  router6.first_elem_pos = 0;
  router6.up_router = &router1;

  router router7;
  router7.name = &s_router_7;
  router7.pos_router = 0;
  router7.size = 0;
  router7.arrow_pos = 0;
  router7.first_elem_pos = 0;
  router7.up_router = &router1;

  add_elem_router(&router1, &router1);
  add_elem_router(&router1, &router2);
  add_elem_router(&router1, &router3);
  add_elem_router(&router1, &router4);
  add_elem_router(&router1, &router5);
  add_elem_router(&router1, &router6);
  add_elem_router(&router2, &router3);
  add_elem_router(&router2, &router4);
  add_elem_router(&router2, &router5);
  add_elem_router(&router2, &router6);
  add_elem_router(&router2, &router7);

  var1 = new_var(vars, &s_var1, 0, 0, 99999, 11);
  var2 = new_var(vars, &s_var2, 0, 0, 99999, 12);
  var3 = new_var(vars, &s_var3, 0, 0, 99999, 13);
  var4 = new_var(vars, &s_var4, 0, 0, 99999, 14);

  menu menu1;
  menu1.name = &s_menu1;
  menu1.pos_menu = 0;
  menu1.size = 0;
  menu1.arrow_pos = 0;
  menu1.first_elem_pos = 0;
  menu1.up_router = &router3;
  add_elem_menu(&menu1, var1);
  add_elem_menu(&menu1, var2);
  add_elem_menu(&menu1, var3);
  add_elem_menu(&menu1, var4);

  add_menu_router(&router3, &menu1);

  menu menu2;
  menu2.name = &s_menu2;
  menu2.pos_menu = 0;
  menu2.size = 0;
  menu2.arrow_pos = 0;
  menu2.first_elem_pos = 0;
  menu2.up_router = &router3;
  add_elem_menu(&menu2, var1);
  add_elem_menu(&menu2, var2);
  add_elem_menu(&menu2, var3);
  add_elem_menu(&menu2, var4);
  add_elem_menu(&menu2, current_lang);

  add_menu_router(&router3, &menu2);
  display_view(cur_view);
  HAL_Delay(500);
  while (1)
    {
    nav_right();
    fill_with_Color(WHITE);
    display_view(cur_view);
    HAL_Delay(500);

    nav_valid();
    fill_with_Color(WHITE);
    display_view(cur_view);
    HAL_Delay(500);

    nav_up();
    fill_with_Color(WHITE);
    display_view(cur_view);
    HAL_Delay(500);

    nav_up();
    fill_with_Color(WHITE);
    display_view(cur_view);
    HAL_Delay(500);

    nav_down();
    fill_with_Color(WHITE);
    display_view(cur_view);
    HAL_Delay(500);

    nav_back();
    fill_with_Color(WHITE);
    display_view(cur_view);
    HAL_Delay(500);

    nav_left();
    fill_with_Color(WHITE);
    display_view(cur_view);
    HAL_Delay(500);

    nav_left();
    fill_with_Color(WHITE);
    display_view(cur_view);
    HAL_Delay(500);

    nav_valid();
    fill_with_Color(WHITE);
    display_view(cur_view);
    HAL_Delay(500);

    nav_back();
    fill_with_Color(WHITE);
    display_view(cur_view);
    HAL_Delay(500);

    nav_left();
    fill_with_Color(WHITE);
    display_view(cur_view);
    HAL_Delay(500);
/* HAL_Delay(500); */
    /* view_left(&view1); */
    /* display_view(&view1); */
    /* HAL_Delay(500); */
    /* view_right(&view1); */
    /* display_view(&view1); */
    }
  fill_with_Color(WHITE);

  display_router26(cur_router, X_MENU, Y_MENU);
  nav_up();
  display_router26(cur_router, X_MENU, Y_MENU);
  HAL_Delay(500);
  nav_up();
  display_router26(cur_router, X_MENU, Y_MENU);
  HAL_Delay(500);
  into_router(cur_router);
  display_router26(cur_router, X_MENU, Y_MENU);
  HAL_Delay(500);
  nav_up();
  display_router26(cur_router, X_MENU, Y_MENU);
  HAL_Delay(500);

  nav_valid(cur_router);
  display_router26(cur_router, X_MENU, Y_MENU);
  HAL_Delay(500);
  nav_up();
  display_router26(cur_router, X_MENU, Y_MENU);
  HAL_Delay(500);
  nav_up();
  display_router26(cur_router, X_MENU, Y_MENU);
  HAL_Delay(500);
  nav_up();
  display_router26(cur_router, X_MENU, Y_MENU);
  HAL_Delay(500);
  nav_up();
  display_router26(cur_router, X_MENU, Y_MENU);
  HAL_Delay(500);
  nav_right();
  display_router26(cur_router, X_MENU, Y_MENU);
  HAL_Delay(500);
  nav_right();
  display_router26(cur_router, X_MENU, Y_MENU);
  HAL_Delay(500);
  nav_right();
  display_router26(cur_router, X_MENU, Y_MENU);
  HAL_Delay(500);
  nav_back();
  display_router26(cur_router, X_MENU, Y_MENU);
  HAL_Delay(500);
  nav_back();
  display_router26(cur_router, X_MENU, Y_MENU);
  HAL_Delay(500);

  /* uint16_t len = my_strlen((uint8_t*)"1234"); */
  /* uint16_t len2 = my_strlen((uint8_t*)"5678"); */
  /* while (1) { */
  /*   sleep_screen_str((uint8_t*)"1234", len, RED, WHITE); */
  /*   sleep_screen_str2((uint8_t*)"5678", len2, RED, WHITE); */
  /*   sleep_screen_str2((uint8_t*)"5678", len2, RED, WHITE); */
  /*   sleep_screen_str2((uint8_t*)"5678", len2, RED, WHITE); */
  /* } */

  while (1);
    {
      HAL_Delay(3000);
      nav_up();
      display_router26(cur_router, X_MENU, Y_MENU);
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

