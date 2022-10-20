/*
 * Timer.c
 *
 * Created: 10/10/2022 8:46:08 PM
 *  Author: Ahmed Mamdouh Elsayed
 */ 

#include "../Timer Driver/Timer.h"
uint32_t overflowcounter = 0;
void Timer_init()
{
	//Chose Timer Mode.
	TCCR0 = 0x00; //Normal mode
	//Set timer initial value
	TCNT0 = 0x00;
}
uint16_t Timer_delay(F_t Msec)
{
	//Set timer initial value
	TCNT0 = 0x00;
	TCCR0 |= (1<<0); //no prescaler
	uint16_t count = 1;
	//Start the timer-- Setting the clock source.
	while(overflowcounter < (Msec)/(.630))
	{
		//Stop after several overflows -- one overflow = 256 micro second
		//wait until set the overflow flag
		while((TIFR & (1<<0)) == 0); //busy wait
		//clear the overflow flag
		TIFR |=(1<<0);
		overflowcounter++;
	}
	overflowcounter=0;
	
	//Stop timer to count again from 0
	TCCR0 = 0x00;
	return count; 
}
