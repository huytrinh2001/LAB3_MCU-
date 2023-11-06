/*
 * update7SEG.h
 *
 *  Created on: 26 thg 11, 2022
 *      Author: trinh huy
 */

#ifndef INC_UPDATE7SEG_H_
#define INC_UPDATE7SEG_H_

extern const int MAX_LED;
extern int index_led;
extern int led_buffer[5];

void update7SEG(int num);
void updateClockBuffer();

#endif /* INC_UPDATE7SEG_H_ */
