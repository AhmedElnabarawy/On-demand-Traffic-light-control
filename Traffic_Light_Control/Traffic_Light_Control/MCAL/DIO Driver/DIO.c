/*
 * dio.c
 *
 * Created: 10/5/2022 8:05:56 PM
 *  Author: Ahmed Mamdouh Elsayed
 */ 
//Include  .h
#include "DIO.h"
//Global variables.
//Function defifnitions

uint32_t DIO_init(uint8_t portnum , uint8_t pinnum , uint8_t direction)
{
	switch(portnum)
	{
		case PORT_A:
		if (direction == IN)
		{
			DDRA &= ~(1<<pinnum);
		}
		else if (direction == OUT)
		{
			DDRA |=(1<<pinnum);
		}
		else
		{
			// Error Handling.
			return 0;
		}
		break;
		case PORT_B:
		if (direction == IN)
		{
			DDRB &= ~(1<<pinnum);
		}
		else if (direction == OUT)
		{
			DDRB |=(1<<pinnum);
		}
		else
		{
			// Error Handling.
			return 0;
		}
		break;
		case PORT_C:
		if (direction == IN)
		{
			DDRC &= ~(1<<pinnum);
		}
		else if (direction == OUT)
		{
			DDRC |=(1<<pinnum);
		}
		else
		{
			// Error Handling.
			return 0;
		}
		break;
		case PORT_D:
		if (direction == IN)
		{
			DDRD &= ~(1<<pinnum);
		}
		else if (direction == OUT)
		{
			DDRD |=(1<<pinnum);
		}
		else
		{
			// Error Handling.
			return 0;
		}
		break;
	}
}
uint32_t DIO_Write(uint8_t portnum , uint8_t pinnum , uint8_t value)
{
	switch(portnum)
	{
		case PORT_A:
		if (value == Low)
		{
			PORTA &= ~(1<<pinnum);
		}
		else if (value == High)
		{
			PORTA |=(1<<pinnum);
		}
		else
		{
			// Error Handling.
			return 0;
		}
		break;
		case PORT_B:
		if (value == Low)
		{
			PORTB &= ~(1<<pinnum);
		}
		else if (value == High)
		{
			PORTB |=(1<<pinnum);
		}
		else
		{
			// Error Handling.
			return 0;
		}
		break;
		case PORT_C:
		if (value == Low)
		{
			PORTC &= ~(1<<pinnum);
		}
		else if (value == High)
		{
			PORTC |=(1<<pinnum);
		}
		else
		{
			// Error Handling.
			return 0;
		}
		break;
		case PORT_D:
		if (value == Low)
		{
			PORTD &= ~(1<<pinnum);
		}
		else if (value == High)
		{
			PORTD |=(1<<pinnum);
		}
		else
		{
			// Error Handling.
			return 0;
		}
		break;
	}
}
uint32_t DIO_Toggle(uint8_t portnum , uint8_t pinnum )
{
	switch(portnum)
	{
		case PORT_A:
		PORTA ^=(1<<pinnum);
		break;
		
		case PORT_B:
		PORTB ^=(1<<pinnum);
		break;
		
		case PORT_C:
		PORTC ^=(1<<pinnum);
		break;
		
		case PORT_D:
		PORTD ^=(1<<pinnum);
		break;
		default:
		// Error Handling.
		return 0;
	}
	
	
}
uint32_t DIO_Read(uint8_t portnum , uint8_t pinnum , uint8_t *valuee)
{
	switch (portnum)
	{
		case PORT_A:
		*valuee = (PINA & (1<<pinnum))>>pinnum;// Get state -> Read bit, The output will be 0 or 1 only
		break;
		case PORT_B:
		*valuee = (PINB & (1<<pinnum))>>pinnum;// Get state -> Read bit
		break;
		case PORT_C:
		*valuee = (PINC & (1<<pinnum))>>pinnum;// Get state -> Read bit
		break;
		case PORT_D:
		*valuee = (PIND & (1<<pinnum))>>pinnum;// Get state -> Read bit
		break;
		default:
		// Error Handling.
		return 0;
	}
	
}