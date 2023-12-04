#include "LED.h"

void ClearLED() {
	HAL_GPIO_WritePin(Main_Red_GPIO_Port, Main_Red_Pin, RESET);
	HAL_GPIO_WritePin(Main_Yellow_GPIO_Port, Main_Yellow_Pin, RESET);
	HAL_GPIO_WritePin(Main_Green_GPIO_Port, Main_Green_Pin, RESET);
	HAL_GPIO_WritePin(Sub_Red_GPIO_Port, Sub_Red_Pin, RESET);
	HAL_GPIO_WritePin(Sub_Yellow_GPIO_Port, Sub_Yellow_Pin, RESET);
	HAL_GPIO_WritePin(Sub_Green_GPIO_Port, Sub_Green_Pin, RESET);
}

