/*
 * led_display.c
 *
 *  Created on: Nov 23, 2022
 *      Author: trinh huy
 */

#include "led_display.h"
#include "main.h"

void reset7SEG() {
	HAL_GPIO_WritePin(SEG0_A_GPIO_Port, SEG0_A_Pin, 1);
	HAL_GPIO_WritePin(SEG1_B_GPIO_Port, SEG1_B_Pin, 1);
	HAL_GPIO_WritePin(SEG2_C_GPIO_Port, SEG2_C_Pin, 1);
	HAL_GPIO_WritePin(SEG3_D_GPIO_Port, SEG3_D_Pin, 1);
	HAL_GPIO_WritePin(SEG4_E_GPIO_Port, SEG4_E_Pin, 1);
	HAL_GPIO_WritePin(SEG5_F_GPIO_Port, SEG5_F_Pin, 1);
	HAL_GPIO_WritePin(SEG6_G_GPIO_Port, SEG6_G_Pin, 1);
}

void display7SEG(int num) {
	reset7SEG();
	switch (num) {
	case 0: {
		HAL_GPIO_WritePin(SEG0_A_GPIO_Port, SEG0_A_Pin, 0);
		HAL_GPIO_WritePin(SEG1_B_GPIO_Port, SEG1_B_Pin, 0);
		HAL_GPIO_WritePin(SEG2_C_GPIO_Port, SEG2_C_Pin, 0);
		HAL_GPIO_WritePin(SEG3_D_GPIO_Port, SEG3_D_Pin, 0);
		HAL_GPIO_WritePin(SEG4_E_GPIO_Port, SEG4_E_Pin, 0);
		HAL_GPIO_WritePin(SEG5_F_GPIO_Port, SEG5_F_Pin, 0);
		HAL_GPIO_WritePin(SEG6_G_GPIO_Port, SEG6_G_Pin, 1);
		break;
	}
	case 1: {
		HAL_GPIO_WritePin(SEG1_B_GPIO_Port, SEG1_B_Pin, 0);
		HAL_GPIO_WritePin(SEG2_C_GPIO_Port, SEG2_C_Pin, 0);
		break;
	}
	case 2: {
		HAL_GPIO_WritePin(SEG0_A_GPIO_Port, SEG0_A_Pin, 0);
		HAL_GPIO_WritePin(SEG1_B_GPIO_Port, SEG1_B_Pin, 0);
		HAL_GPIO_WritePin(SEG3_D_GPIO_Port, SEG3_D_Pin, 0);
		HAL_GPIO_WritePin(SEG4_E_GPIO_Port, SEG4_E_Pin, 0);
		HAL_GPIO_WritePin(SEG6_G_GPIO_Port, SEG6_G_Pin, 0);
		break;
	}
	case 3: {
		HAL_GPIO_WritePin(SEG0_A_GPIO_Port, SEG0_A_Pin, 0);
		HAL_GPIO_WritePin(SEG1_B_GPIO_Port, SEG1_B_Pin, 0);
		HAL_GPIO_WritePin(SEG2_C_GPIO_Port, SEG2_C_Pin, 0);
		HAL_GPIO_WritePin(SEG3_D_GPIO_Port, SEG3_D_Pin, 0);
		HAL_GPIO_WritePin(SEG6_G_GPIO_Port, SEG6_G_Pin, 0);
		break;
	}
	case 4: {
		HAL_GPIO_WritePin(SEG1_B_GPIO_Port, SEG1_B_Pin, 0);
		HAL_GPIO_WritePin(SEG2_C_GPIO_Port, SEG2_C_Pin, 0);
		HAL_GPIO_WritePin(SEG5_F_GPIO_Port, SEG5_F_Pin, 0);
		HAL_GPIO_WritePin(SEG6_G_GPIO_Port, SEG6_G_Pin, 0);
		break;
	}
	case 5: {
		HAL_GPIO_WritePin(SEG0_A_GPIO_Port, SEG0_A_Pin, 0);
		HAL_GPIO_WritePin(SEG2_C_GPIO_Port, SEG2_C_Pin, 0);
		HAL_GPIO_WritePin(SEG3_D_GPIO_Port, SEG3_D_Pin, 0);
		HAL_GPIO_WritePin(SEG5_F_GPIO_Port, SEG5_F_Pin, 0);
		HAL_GPIO_WritePin(SEG6_G_GPIO_Port, SEG6_G_Pin, 0);
		break;
	}
	case 6: {
		HAL_GPIO_WritePin(SEG0_A_GPIO_Port, SEG0_A_Pin, 0);
		HAL_GPIO_WritePin(SEG2_C_GPIO_Port, SEG2_C_Pin, 0);
		HAL_GPIO_WritePin(SEG3_D_GPIO_Port, SEG3_D_Pin, 0);
		HAL_GPIO_WritePin(SEG4_E_GPIO_Port, SEG4_E_Pin, 0);
		HAL_GPIO_WritePin(SEG5_F_GPIO_Port, SEG5_F_Pin, 0);
		HAL_GPIO_WritePin(SEG6_G_GPIO_Port, SEG6_G_Pin, 0);
		break;
	}
	case 7: {
		HAL_GPIO_WritePin(SEG0_A_GPIO_Port, SEG0_A_Pin, 0);
		HAL_GPIO_WritePin(SEG1_B_GPIO_Port, SEG1_B_Pin, 0);
		HAL_GPIO_WritePin(SEG2_C_GPIO_Port, SEG2_C_Pin, 0);
		break;
	}
	case 8: {
		HAL_GPIO_WritePin(SEG0_A_GPIO_Port, SEG0_A_Pin, 0);
		HAL_GPIO_WritePin(SEG1_B_GPIO_Port, SEG1_B_Pin, 0);
		HAL_GPIO_WritePin(SEG2_C_GPIO_Port, SEG2_C_Pin, 0);
		HAL_GPIO_WritePin(SEG3_D_GPIO_Port, SEG3_D_Pin, 0);
		HAL_GPIO_WritePin(SEG4_E_GPIO_Port, SEG4_E_Pin, 0);
		HAL_GPIO_WritePin(SEG5_F_GPIO_Port, SEG5_F_Pin, 0);
		HAL_GPIO_WritePin(SEG6_G_GPIO_Port, SEG6_G_Pin, 0);
		break;
	}
	case 9: {
		HAL_GPIO_WritePin(SEG0_A_GPIO_Port, SEG0_A_Pin, 0);
		HAL_GPIO_WritePin(SEG1_B_GPIO_Port, SEG1_B_Pin, 0);
		HAL_GPIO_WritePin(SEG2_C_GPIO_Port, SEG2_C_Pin, 0);
		HAL_GPIO_WritePin(SEG3_D_GPIO_Port, SEG3_D_Pin, 0);
		HAL_GPIO_WritePin(SEG5_F_GPIO_Port, SEG5_F_Pin, 0);
		HAL_GPIO_WritePin(SEG6_G_GPIO_Port, SEG6_G_Pin, 0);
		break;
	}
	default:
		break;
	}
}
