/*
 * Led.c
 *
 * Created: 10/5/2022 10:19:18 PM
 *  Author: Ahmed Mamdouh Elsayed
 */ 
#include "LED.h"
#include "../MCAL/Timer Driver/Timer.h"
uint32_t check;
// initialization of the led driver
uint32_t LED_init(uint8_t ledport , uint8_t ledpin)
{
	check=DIO_init(ledport,ledpin,OUT);
	if (check = 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}

}

//Turn on the led
uint32_t LED_on(uint8_t ledport , uint8_t ledpin)
{
	check=DIO_Write(ledport,ledpin,High);
	if (check = 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
	
}
//Turn off the led
uint32_t LED_off(uint8_t ledport , uint8_t ledpin)
{
	check=DIO_Write(ledport,ledpin,Low);
	if (check = 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
//Toggle the led
uint32_t LED_toggle(uint8_t ledport , uint8_t ledpin)
{
	check=DIO_Toggle(ledport,ledpin);
	if (check = 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
//Blinking function for one pin
uint32_t LED_Blink(uint8_t ledport , uint8_t ledpin , F_t Time)
{
		LED_on(ledport,ledpin);
		Timer_delay(Time);
		LED_off(ledport,ledpin);
		Timer_delay(Time);
}
//Blinking function for two pins
uint32_t LED_BlinkD(uint8_t ledport1 , uint8_t ledpin1 ,uint8_t ledport2 , uint8_t ledpin2 , F_t Time)
{
	for(uint32_t count = 0; count <5; count++)
	{
	LED_on(ledport1,ledpin1);
	LED_on(ledport2,ledpin2);
	Timer_delay(Time);
	LED_off(ledport1,ledpin1);
	LED_off(ledport2,ledpin2);
	Timer_delay(Time);
	}
}