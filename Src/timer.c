#include "timer.h"

// INIT TIM1 FOR us DELAY
void delay_init ()
{
  __HAL_RCC_TIM1_CLK_ENABLE();
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};
  htim_timer.Instance = TIM1;
  htim_timer.Init.Prescaler = 168-1;
  htim_timer.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim_timer.Init.Period = 0xffff-1;;
  htim_timer.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim_timer.Init.RepetitionCounter = 0;
  htim_timer.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim_timer) != HAL_OK)
    {
      return;
    }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim_timer, &sMasterConfig) != HAL_OK)
    {
      Error_Handler();
    }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim_timer, &sBreakDeadTimeConfig) != HAL_OK)
    {
      Error_Handler();
    }

  htim_timer.Instance->SR &= ~TIM_SR_UIF; // clear UIF flag
  htim_timer.Instance->CR1 |= 1;
}

// RUN delay_init() once FIRST
void delay_us (uint16_t delay)
{
  __HAL_TIM_SET_COUNTER(&htim_timer, 0);  // reset the counter
  while ((__HAL_TIM_GET_COUNTER(&htim_timer))<delay);  // wait for the delay to complete
}
