/*
 * fsm_automatic.c
 *
 *  Created on: 6 thg 11, 2023
 *      Author: trinh huy
 */
#include "global.h"
#include "fsm_automatic.h"
#include "main.h"
#include "traffic_light.h"

void fsm_automatic_run() {
	switch (status) {
	case INIT:
		status = MODE1;
		break;
	case MODE1:
		status = AUTO_RED1_GREEN2;
		traffic_light(INIT);
		value1 = red_time;
		value2 = green_time;
		index_led = 0;

		updateClockBuffer(value1, value2);
		update7SEG(index_led);
		setTimer0(green_time * 1000);
		setTimer1(1000);
		setTimer2(1000);
		break;
	case AUTO_RED1_GREEN2:
		traffic_light(AUTO_RED1_GREEN2);
		if (timer0_flag == 1) {
			status = AUTO_RED1_YELLOW2;
			setTimer0(yellow_time * 1000);
		}
		if (timer1_flag == 1) {
			updateClockBuffer(value1, value2);
			setTimer1(1000);
		}
		if (timer2_flag == 1) {
			update7SEG(index_led);
			setTimer2(500);
		}
		break;
	case AUTO_RED1_YELLOW2:
		traffic_light(AUTO_RED1_YELLOW2);
		if (timer0_flag == 1) {
			status = AUTO_GREEN1_RED2;
			setTimer0(green_time * 1000);
		}
		if (timer1_flag == 1) {
			updateClockBuffer(value1, value2);
			setTimer1(1000);
		}
		if (timer2_flag == 1) {
			update7SEG(index_led);
			setTimer2(500);
		}
		break;
	case AUTO_GREEN1_RED2:
		traffic_light(AUTO_GREEN1_RED2);
		if (timer0_flag == 1) {
			status = AUTO_YELLOW1_RED2;
			setTimer0(yellow_time * 1000);
		}
		if (timer1_flag == 1) {
			updateClockBuffer();
			setTimer1(1000);
		}
		if (timer2_flag == 1) {
			update7SEG(index_led);
			setTimer2(500);
		}
		break;
	case AUTO_YELLOW1_RED2:
		traffic_light(AUTO_YELLOW1_RED2);
		if (timer0_flag == 1) {
			status = AUTO_RED1_GREEN2;
			setTimer0(red_time * 1000);
		}
		if (timer1_flag == 1) {
			updateClockBuffer();
			setTimer1(1000);
		}
		if (timer2_flag == 1) {
			update7SEG(index_led);
			setTimer2(500);
		}
		break;
	default:
		break;
	}
}
