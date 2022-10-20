/*
 * Timer.h
 *
 * Created: 10/10/2022 8:44:45 PM
 *  Author: Ahmed Mamdouh Elsayed
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../Utilities/Registers.h"

void Timer_init();
uint16_t Timer_delay(F_t Msec);



#endif /* TIMER_H_ */