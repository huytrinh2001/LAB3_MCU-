/*
 * button.h
 *
 *  Created on: Nov 1, 2022
 *      Author: khuon
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "global.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

extern int button1_flag;
extern int button2_flag;
extern int button3_flag;

int isKey1Pressed();

void getKeyInput1();
void getKeyInput2();
void getKeyInput3();

#endif /* INC_BUTTON_H_ */
