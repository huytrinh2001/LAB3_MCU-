/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
//#include "button.h"
#include "global.h"
#include "fsm_automatic.h"
#include "fsm_manual.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_TIM2_Init(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
void display7SEG_1(int);
void display7SEG_2(int);
void update7SEG(int);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint8_t segNumber[10] = {
		0x40,
		0x79,
		0x24,
		0x30,
		0x19,
		0x12,
		0x02,
		0x78,
		0x00,
		0x10
};
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_TIM2_Init();
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  /*Ex1*/
  main_status = INIT;
  sub_status = INIT;
  mode = NORMAL_MODE;
  setTimer3(20);
  setTimer5(100);
  int index = 0;
  while (1)
  {
	if (isKey1Pressed() == 1) {
		setTimer5(25);
		setTimer6(50);
	}

	fsm_automatic_run();
	fsm_manual_run();

	if (timer5_flag == 1) {
		setTimer5(100);
		if (time_main > 0) {
			time_main--;
		}
		if (time_sub > 0) {
			time_sub--;
		}
		if (button3_flag == 1) {
			value--;
		}
	}

	if (timer3_flag == 1) {
		setTimer3(50);
		update7SEG(index);
		index += 1;
		if (index >= 4) {
			index = 0;
		}
	}


	/* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, Main_Red_Pin|Main_Yellow_Pin|Main_Green_Pin|Sub_Red_Pin
                          |Sub_Yellow_Pin|Sub_Green_Pin|MAIN_Pin|SUB_Pin
                          |MODE_Pin|VALUE_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, a1_Pin|b1_Pin|c1_Pin|d2_Pin
                          |e2_Pin|f2_Pin|g2_Pin|d1_Pin
                          |e1_Pin|f1_Pin|g1_Pin|a2_Pin
                          |b2_Pin|c2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : Main_Red_Pin Main_Yellow_Pin Main_Green_Pin Sub_Red_Pin
                           Sub_Yellow_Pin Sub_Green_Pin MAIN_Pin SUB_Pin
                           MODE_Pin VALUE_Pin */
  GPIO_InitStruct.Pin = Main_Red_Pin|Main_Yellow_Pin|Main_Green_Pin|Sub_Red_Pin
                          |Sub_Yellow_Pin|Sub_Green_Pin|MAIN_Pin|SUB_Pin
                          |MODE_Pin|VALUE_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : a1_Pin b1_Pin c1_Pin d2_Pin
                           e2_Pin f2_Pin g2_Pin d1_Pin
                           e1_Pin f1_Pin g1_Pin a2_Pin
                           b2_Pin c2_Pin */
  GPIO_InitStruct.Pin = a1_Pin|b1_Pin|c1_Pin|d2_Pin
                          |e2_Pin|f2_Pin|g2_Pin|d1_Pin
                          |e1_Pin|f1_Pin|g1_Pin|a2_Pin
                          |b2_Pin|c2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : button1_Pin button2_Pin button3_Pin */
  GPIO_InitStruct.Pin = button1_Pin|button2_Pin|button3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void display7SEG_1(int num) {
	HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, (segNumber[num]>>0) & 0x01);
	HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, (segNumber[num]>>1) & 0x01);
	HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, (segNumber[num]>>2) & 0x01);
	HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, (segNumber[num]>>3) & 0x01);
	HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, (segNumber[num]>>4) & 0x01);
	HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, (segNumber[num]>>5) & 0x01);
	HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, (segNumber[num]>>6) & 0x01);
}

void display7SEG_2(int num) {
	HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, (segNumber[num]>>0) & 0x01);
	HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, (segNumber[num]>>1) & 0x01);
	HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, (segNumber[num]>>2) & 0x01);
	HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, (segNumber[num]>>3) & 0x01);
	HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, (segNumber[num]>>4) & 0x01);
	HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, (segNumber[num]>>5) & 0x01);
	HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, (segNumber[num]>>6) & 0x01);
}
/*
 * index 0 : display 7SEG on MAIN road
 * index 1 : display 7SEG on SUB road
 * index 2 : display Mode
 * index 3 : display value
 * */
void update7SEG(int index) {
	switch (index) {
		case 0:
			HAL_GPIO_WritePin(MAIN_GPIO_Port, MAIN_Pin, 0);
			HAL_GPIO_WritePin(SUB_GPIO_Port, SUB_Pin, 1);
			HAL_GPIO_WritePin(MODE_GPIO_Port, MODE_Pin, 1);
			HAL_GPIO_WritePin(VALUE_GPIO_Port, VALUE_Pin, 1);
			display7SEG_1(time_main / 10);
			display7SEG_2(time_main % 10);
			break;
		case 1:
			HAL_GPIO_WritePin(MAIN_GPIO_Port, MAIN_Pin, 1);
			HAL_GPIO_WritePin(SUB_GPIO_Port, SUB_Pin, 0);
			HAL_GPIO_WritePin(MODE_GPIO_Port, MODE_Pin, 1);
			HAL_GPIO_WritePin(VALUE_GPIO_Port, VALUE_Pin, 1);
			display7SEG_1(time_sub / 10);
			display7SEG_2(time_sub % 10);
			break;
		case 2:
			HAL_GPIO_WritePin(MAIN_GPIO_Port, MAIN_Pin, 1);
			HAL_GPIO_WritePin(SUB_GPIO_Port, SUB_Pin, 1);
			HAL_GPIO_WritePin(MODE_GPIO_Port, MODE_Pin, 0);
			HAL_GPIO_WritePin(VALUE_GPIO_Port, VALUE_Pin, 1);
			display7SEG_1(0);
			display7SEG_2(mode);
			break;
		case 3:
			HAL_GPIO_WritePin(MAIN_GPIO_Port, MAIN_Pin, 1);
			HAL_GPIO_WritePin(SUB_GPIO_Port, SUB_Pin, 1);
			HAL_GPIO_WritePin(MODE_GPIO_Port, MODE_Pin, 1);
			HAL_GPIO_WritePin(VALUE_GPIO_Port, VALUE_Pin, 0);
			display7SEG_1(value / 10);
			display7SEG_2(value % 10);
			break;
		default:
			break;
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	timerRun();
	getKeyInput1();
	getKeyInput2();
	getKeyInput3();
}
/* USER CODE END 4 */

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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
