
#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "button.h"
#include "software_timer.h"
#include "LED.h"

#define NORMAL_MODE		1
#define RED_MODE		2
#define YELLOW_MODE		3
#define GREEN_MOD		4
#define INIT			5
#define AUTO_RED		6
#define AUTO_GREEN		7
#define AUTO_YELLOW		8
#define MAN_RED			9
#define MAN_YELLOW		10
#define MAN_GREEN		11

extern int time_main;
extern int time_sub;
extern int main_status;
extern int sub_status;
extern int mode;
extern int value;

#endif /* INC_GLOBAL_H_ */
