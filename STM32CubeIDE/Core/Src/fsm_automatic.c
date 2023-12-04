#include "fsm_automatic.h"

void fsm_automatic_run() {
	switch (main_status) {
	case INIT:
		main_status = AUTO_RED;
		setTimer1(500);
		time_main = 5;
		break;
	case AUTO_RED:
		HAL_GPIO_WritePin(Main_Red_GPIO_Port, Main_Red_Pin, SET);
		HAL_GPIO_WritePin(Main_Yellow_GPIO_Port, Main_Yellow_Pin, RESET);
		HAL_GPIO_WritePin(Main_Green_GPIO_Port, Main_Green_Pin, RESET);
		if (timer1_flag == 1) {
			setTimer1(300);
			main_status = AUTO_GREEN;
			time_main = 3;
		}
		if (mode == RED_MODE) {
			main_status = MAN_RED;
			setTimer4(50);
			ClearLED();
		}
		if (mode == GREEN_MOD) {
			main_status = MAN_GREEN;
			setTimer4(50);
			ClearLED();
		}
		if (mode == YELLOW_MODE) {
			main_status = MAN_YELLOW;
			setTimer4(50);
			ClearLED();
		}
		break;
	case AUTO_GREEN:
		HAL_GPIO_WritePin(Main_Red_GPIO_Port, Main_Red_Pin, RESET);
		HAL_GPIO_WritePin(Main_Yellow_GPIO_Port, Main_Yellow_Pin, RESET);
		HAL_GPIO_WritePin(Main_Green_GPIO_Port, Main_Green_Pin, SET);
		if (timer1_flag == 1) {
			setTimer1(200);
			main_status = AUTO_YELLOW;
			time_main = 2;
		}
		if (mode == RED_MODE) {
			main_status = MAN_RED;
			setTimer4(50);
			ClearLED();
		}
		if (mode == GREEN_MOD) {
			main_status = MAN_GREEN;
			setTimer4(50);
			ClearLED();
		}
		if (mode == YELLOW_MODE) {
			main_status = MAN_YELLOW;
			setTimer4(50);
			ClearLED();
		}
		break;
	case AUTO_YELLOW:
		HAL_GPIO_WritePin(Main_Red_GPIO_Port, Main_Red_Pin, RESET);
		HAL_GPIO_WritePin(Main_Yellow_GPIO_Port, Main_Yellow_Pin, SET);
		HAL_GPIO_WritePin(Main_Green_GPIO_Port, Main_Green_Pin, RESET);
		if (timer1_flag == 1) {
			setTimer1(500);
			main_status = AUTO_RED;
			time_main = 5;
		}
		if (mode == RED_MODE) {
			main_status = MAN_RED;
			setTimer4(50);
			ClearLED();
		}
		if (mode == GREEN_MOD) {
			main_status = MAN_GREEN;
			setTimer4(50);
			ClearLED();
		}
		if (mode == YELLOW_MODE) {
			main_status = MAN_YELLOW;
			setTimer4(50);
			ClearLED();
		}
		break;
	default:
		break;
	}

	switch (sub_status) {
	case INIT:
		sub_status = AUTO_GREEN;
		setTimer2(300);
		time_sub = 3;
		break;
	case AUTO_RED:
		HAL_GPIO_WritePin(Sub_Red_GPIO_Port, Sub_Red_Pin, SET);
		HAL_GPIO_WritePin(Sub_Yellow_GPIO_Port, Sub_Yellow_Pin, RESET);
		HAL_GPIO_WritePin(Sub_Green_GPIO_Port, Sub_Green_Pin, RESET);
		if (timer2_flag == 1) {
			setTimer2(300);
			sub_status = AUTO_GREEN;
			time_sub = 3;
		}
		if (mode == RED_MODE) {
			sub_status = MAN_GREEN;
			ClearLED();
		}
		if (mode == GREEN_MOD) {
			sub_status = MAN_RED;
			ClearLED();
		}
		if (mode == YELLOW_MODE) {
			sub_status = MAN_YELLOW;
			ClearLED();
		}
		break;
	case AUTO_GREEN:
		HAL_GPIO_WritePin(Sub_Red_GPIO_Port, Sub_Red_Pin, RESET);
		HAL_GPIO_WritePin(Sub_Yellow_GPIO_Port, Sub_Yellow_Pin, RESET);
		HAL_GPIO_WritePin(Sub_Green_GPIO_Port, Sub_Green_Pin, SET);
		if (timer2_flag == 1) {
			setTimer2(200);
			sub_status = AUTO_YELLOW;
			time_sub = 2;
		}
		if (mode == RED_MODE) {
			sub_status = MAN_GREEN;
			ClearLED();
		}
		if (mode == GREEN_MOD) {
			sub_status = MAN_RED;
			ClearLED();
		}
		if (mode == YELLOW_MODE) {
			sub_status = MAN_YELLOW;
			ClearLED();
		}
		break;
	case AUTO_YELLOW:
		HAL_GPIO_WritePin(Sub_Red_GPIO_Port, Sub_Red_Pin, RESET);
		HAL_GPIO_WritePin(Sub_Yellow_GPIO_Port, Sub_Yellow_Pin, SET);
		HAL_GPIO_WritePin(Sub_Green_GPIO_Port, Sub_Green_Pin, RESET);
		if (timer2_flag == 1) {
			setTimer2(500);
			sub_status = AUTO_RED;
			time_sub = 5;
		}
		if (mode == RED_MODE) {
			sub_status = MAN_GREEN;
			ClearLED();
		}
		if (mode == GREEN_MOD) {
			sub_status = MAN_RED;
			ClearLED();
		}
		if (mode == YELLOW_MODE) {
			sub_status = MAN_YELLOW;
			ClearLED();
		}
		break;
	default:
		break;
	}
}

