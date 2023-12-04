/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Main_Red_Pin GPIO_PIN_3
#define Main_Red_GPIO_Port GPIOA
#define Main_Yellow_Pin GPIO_PIN_4
#define Main_Yellow_GPIO_Port GPIOA
#define Main_Green_Pin GPIO_PIN_5
#define Main_Green_GPIO_Port GPIOA
#define Sub_Red_Pin GPIO_PIN_6
#define Sub_Red_GPIO_Port GPIOA
#define Sub_Yellow_Pin GPIO_PIN_7
#define Sub_Yellow_GPIO_Port GPIOA
#define a1_Pin GPIO_PIN_0
#define a1_GPIO_Port GPIOB
#define b1_Pin GPIO_PIN_1
#define b1_GPIO_Port GPIOB
#define c1_Pin GPIO_PIN_2
#define c1_GPIO_Port GPIOB
#define d2_Pin GPIO_PIN_10
#define d2_GPIO_Port GPIOB
#define e2_Pin GPIO_PIN_11
#define e2_GPIO_Port GPIOB
#define f2_Pin GPIO_PIN_12
#define f2_GPIO_Port GPIOB
#define g2_Pin GPIO_PIN_13
#define g2_GPIO_Port GPIOB
#define Sub_Green_Pin GPIO_PIN_8
#define Sub_Green_GPIO_Port GPIOA
#define MAIN_Pin GPIO_PIN_9
#define MAIN_GPIO_Port GPIOA
#define SUB_Pin GPIO_PIN_10
#define SUB_GPIO_Port GPIOA
#define MODE_Pin GPIO_PIN_11
#define MODE_GPIO_Port GPIOA
#define VALUE_Pin GPIO_PIN_12
#define VALUE_GPIO_Port GPIOA
#define button1_Pin GPIO_PIN_13
#define button1_GPIO_Port GPIOA
#define button2_Pin GPIO_PIN_14
#define button2_GPIO_Port GPIOA
#define button3_Pin GPIO_PIN_15
#define button3_GPIO_Port GPIOA
#define d1_Pin GPIO_PIN_3
#define d1_GPIO_Port GPIOB
#define e1_Pin GPIO_PIN_4
#define e1_GPIO_Port GPIOB
#define f1_Pin GPIO_PIN_5
#define f1_GPIO_Port GPIOB
#define g1_Pin GPIO_PIN_6
#define g1_GPIO_Port GPIOB
#define a2_Pin GPIO_PIN_7
#define a2_GPIO_Port GPIOB
#define b2_Pin GPIO_PIN_8
#define b2_GPIO_Port GPIOB
#define c2_Pin GPIO_PIN_9
#define c2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
