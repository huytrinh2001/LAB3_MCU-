
#include "button.h"

int keyRegButton1_1 = NORMAL_STATE;
int keyRegButton1_2 = NORMAL_STATE;
int keyRegButton1_3 = NORMAL_STATE;
int keyRegButton1_4 = NORMAL_STATE;

int keyRegButton2_1 = NORMAL_STATE;
int keyRegButton2_2 = NORMAL_STATE;
int keyRegButton2_3 = NORMAL_STATE;
int keyRegButton2_4 = NORMAL_STATE;

int keyRegButton3_1 = NORMAL_STATE;
int keyRegButton3_2 = NORMAL_STATE;
int keyRegButton3_3 = NORMAL_STATE;
int keyRegButton3_4 = NORMAL_STATE;

int timeOutForKeyPress1 = 100;
int timeOutForKeyPress2 = 100;
int timeOutForKeyPress3 = 100;

int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;

int isKey1Pressed() {
	if (button1_flag == 1) {
		button1_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess1() {
	value = 0;
	button1_flag = 1;
	switch (mode) {
	case NORMAL_MODE:
		mode = RED_MODE;
		break;
	case RED_MODE:
		mode = YELLOW_MODE;
		break;
	case YELLOW_MODE:
		mode = GREEN_MOD;
		break;
	case GREEN_MOD:
		mode = NORMAL_MODE;
		break;
	default:
		break;
	}
}

void subKeyProcess2() {
	if (value < 99) {
		value++;
	}
}

void subKeyProcess3() {
	button3_flag = 1;
	time_main = value;
	time_sub = value;
}

void getKeyInput1() {
	keyRegButton1_1 = keyRegButton1_2;
	keyRegButton1_2 = keyRegButton1_3;
	keyRegButton1_3 = HAL_GPIO_ReadPin(button1_GPIO_Port, button1_Pin);
	if ((keyRegButton1_1 == keyRegButton1_2)
			&& (keyRegButton1_2 == keyRegButton1_3)) {
		if (keyRegButton1_3 != keyRegButton1_4) {
			keyRegButton1_4 = keyRegButton1_3;
			if (keyRegButton1_4 == PRESSED_STATE) {
				timeOutForKeyPress1 = 100;
				subKeyProcess1();
			}
		} else {
			timeOutForKeyPress1--;
			if (timeOutForKeyPress1 <= 0) {
				if (keyRegButton1_4 == PRESSED_STATE) {
					timeOutForKeyPress1 = 50;
					subKeyProcess1();
				}
			}
		}
	}
}

void getKeyInput2() {
	keyRegButton2_1 = keyRegButton2_2;
	keyRegButton2_2 = keyRegButton2_3;
	keyRegButton2_3 = HAL_GPIO_ReadPin(button2_GPIO_Port, button2_Pin);
	if ((keyRegButton2_1 == keyRegButton2_2)
			&& (keyRegButton2_2 == keyRegButton2_3)) {
		if (keyRegButton2_3 != keyRegButton2_4) {
			keyRegButton2_4 = keyRegButton2_3;
			if (keyRegButton2_4 == PRESSED_STATE) {
				timeOutForKeyPress2 = 100;
				subKeyProcess2();
			}
		} else {
			timeOutForKeyPress2--;
			if (timeOutForKeyPress2 <= 0) {
				if (keyRegButton2_4 == PRESSED_STATE) {
					timeOutForKeyPress2 = 50;
					subKeyProcess2();
				}
			}
		}
	}
}

void getKeyInput3() {
	keyRegButton3_1 = keyRegButton3_2;
	keyRegButton3_2 = keyRegButton3_3;
	keyRegButton3_3 = HAL_GPIO_ReadPin(button3_GPIO_Port, button3_Pin);
	if ((keyRegButton3_1 == keyRegButton3_2)
			&& (keyRegButton3_2 == keyRegButton3_3)) {
		if (keyRegButton3_3 != keyRegButton3_4) {
			keyRegButton3_4 = keyRegButton3_3;
			if (keyRegButton3_4 == PRESSED_STATE) {
				timeOutForKeyPress3 = 100;
				subKeyProcess3();
			}
		} else {
			timeOutForKeyPress3--;
			if (timeOutForKeyPress3 <= 0) {
				if (keyRegButton3_4 == PRESSED_STATE) {
					timeOutForKeyPress3 = 50;
					subKeyProcess3();
				}
			}
		}
	}
}
