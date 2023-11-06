/*
 * global.h
 *
 *  Created on: Nov 23, 2022
 *      Author: trinh huy
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
//#include "button.h"
#include "main.h"
#include "update7SEG.h"
#include "led_display.h"
#include "fsm_automatic.h"
#include "traffic_light.h"

#define INIT        0
#define MODE1		1
#define MODE2		2
#define MODE3		3
#define MODE4		4
#define AUTO_RED1_GREEN2    11
#define AUTO_RED1_YELLOW2  	12
#define AUTO_GREEN1_RED2	13
#define AUTO_YELLOW1_RED2	14

#define MAN_RED     21
#define MAN_GREEN   22
#define MAN_YELLOW  23

#define GIVEN_RED 5
#define GIVEN_YELLOW 2
#define GIVEN_GREEN 3

extern int red_time;
extern int green_time;
extern int yellow_time;

extern int status;

extern int value1;
extern int value2;
extern int value_mode;

#endif /* INC_GLOBAL_H_ */
