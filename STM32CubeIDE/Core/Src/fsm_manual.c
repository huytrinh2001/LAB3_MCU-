#include "fsm_manual.h"

void fsm_manual_run() {
	switch (main_status) {
		case MAN_RED:
			if (timer4_flag == 1) {
				//TODO
				setTimer4(50);
				HAL_GPIO_TogglePin(Main_Red_GPIO_Port, Main_Red_Pin);
				HAL_GPIO_TogglePin(Sub_Red_GPIO_Port, Sub_Red_Pin);
			}
			if (button3_flag == 1) {
				HAL_GPIO_WritePin(Main_Red_GPIO_Port, Main_Red_Pin, SET);
				HAL_GPIO_WritePin(Main_Yellow_GPIO_Port, Main_Yellow_Pin, RESET);
				HAL_GPIO_WritePin(Main_Green_GPIO_Port, Main_Green_Pin, RESET);
				if (value == 0) {
					main_status = AUTO_GREEN;
					sub_status = AUTO_RED;
					mode = NORMAL_MODE;
					setTimer1(300);
					setTimer2(500);
					button3_flag = 0;
					time_main = 3;
					time_sub =5;
				}
			}
			if (mode == NORMAL_MODE) {
				main_status = AUTO_GREEN;
				sub_status = AUTO_RED;
				mode = NORMAL_MODE;
				setTimer1(300);
				setTimer2(500);
				button3_flag = 0;
				time_main = 3;
				time_sub =5;
			}
			if (mode == GREEN_MOD) {
				main_status = MAN_GREEN;
				sub_status = MAN_RED;
				button3_flag = 0;
				ClearLED();
			}
			if (mode == YELLOW_MODE) {
				main_status = MAN_YELLOW;
				sub_status = MAN_RED;
				button3_flag = 0;
				ClearLED();
			}
			break;
		case MAN_GREEN:
			if (timer4_flag == 1) {
				//TODO
				setTimer4(50);
				HAL_GPIO_TogglePin(Main_Green_GPIO_Port, Main_Green_Pin);
				HAL_GPIO_TogglePin(Sub_Green_GPIO_Port, Sub_Green_Pin);
			}
			if (button3_flag == 1) {
				HAL_GPIO_WritePin(Main_Red_GPIO_Port, Main_Red_Pin, RESET);
				HAL_GPIO_WritePin(Main_Yellow_GPIO_Port, Main_Yellow_Pin, RESET);
				HAL_GPIO_WritePin(Main_Green_GPIO_Port, Main_Green_Pin, SET);
				if (value== 0) {
					main_status = AUTO_YELLOW;
					sub_status = AUTO_RED;
					mode = NORMAL_MODE;
					setTimer1(200);
					setTimer2(200);
					button3_flag = 0;
					time_main = 2;
					time_sub = 2;
				}
			}
			if (mode == NORMAL_MODE) {
				main_status = AUTO_YELLOW;
				sub_status = AUTO_RED;
				mode = NORMAL_MODE;
				setTimer1(200);
				setTimer2(200);
				button3_flag = 0;
				time_main = 2;
				time_sub = 2;
			}
			if (mode == RED_MODE) {
				main_status = MAN_RED;
				sub_status = MAN_GREEN;
				button3_flag = 0;
				ClearLED();
			}
			if (mode == YELLOW_MODE) {
				main_status = MAN_YELLOW;
				sub_status = MAN_RED;
				button3_flag = 0;
				ClearLED();
			}
			break;
		case MAN_YELLOW:
			if (timer4_flag == 1) {
				//TODO
				setTimer4(50);
				HAL_GPIO_TogglePin(Main_Yellow_GPIO_Port, Main_Yellow_Pin);
				HAL_GPIO_TogglePin(Sub_Yellow_GPIO_Port, Sub_Yellow_Pin);
			}
			if (button3_flag == 1) {
				HAL_GPIO_WritePin(Main_Red_GPIO_Port, Main_Red_Pin, RESET);
				HAL_GPIO_WritePin(Main_Yellow_GPIO_Port, Main_Yellow_Pin, SET);
				HAL_GPIO_WritePin(Main_Green_GPIO_Port, Main_Green_Pin, RESET);
				if (value == 0) {
					main_status = AUTO_RED;
					sub_status = AUTO_GREEN;
					mode = NORMAL_MODE;
					setTimer1(500);
					setTimer2(300);
					button3_flag = 0;
					time_main = 5;
					time_sub = 3;
				}
			}
			if (mode == NORMAL_MODE) {
				main_status = AUTO_RED;
				sub_status = AUTO_GREEN;
				mode = NORMAL_MODE;
				setTimer1(500);
				setTimer2(300);
				button3_flag = 0;
				time_main = 5;
				time_sub = 3;
			}
			if (mode == GREEN_MOD) {
				main_status = MAN_GREEN;
				sub_status = MAN_RED;
				button3_flag = 0;
				ClearLED();
			}
			if (mode == RED_MODE) {
				main_status = MAN_RED;
				sub_status = MAN_GREEN;
				button3_flag = 0;
				ClearLED();
			}
			break;
		default:
			break;
	}

	switch (sub_status) {
		case MAN_RED:
			if (button3_flag == 1){
				HAL_GPIO_WritePin(Sub_Red_GPIO_Port, Sub_Red_Pin, SET);
				HAL_GPIO_WritePin(Sub_Yellow_GPIO_Port, Sub_Yellow_Pin, RESET);
				HAL_GPIO_WritePin(Sub_Green_GPIO_Port, Sub_Green_Pin, RESET);
			}
			break;
		case MAN_GREEN:
			if (button3_flag == 1) {
				HAL_GPIO_WritePin(Sub_Red_GPIO_Port, Sub_Red_Pin, RESET);
				HAL_GPIO_WritePin(Sub_Yellow_GPIO_Port, Sub_Yellow_Pin, RESET);
				HAL_GPIO_WritePin(Sub_Green_GPIO_Port, Sub_Green_Pin, SET);
			}
			break;
		case MAN_YELLOW:
			if (button3_flag == 1) {
				HAL_GPIO_WritePin(Sub_Red_GPIO_Port, Sub_Red_Pin, RESET);
				HAL_GPIO_WritePin(Sub_Yellow_GPIO_Port, Sub_Yellow_Pin, SET);
				HAL_GPIO_WritePin(Sub_Green_GPIO_Port, Sub_Green_Pin, RESET);
			}
			break;
		default:
			break;
	}
}


