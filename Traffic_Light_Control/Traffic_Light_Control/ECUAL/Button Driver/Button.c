/*
 * Button.c
 *
 * Created: 10/7/2022 1:45:01 PM
 *  Author: Ahmed Mamdouh Elsayed
 */ 
#include "Button.h"

uint16_t Button_init(uint8_t buttonport , uint8_t buttonpin)
{
	DIO_init(buttonport , buttonpin , IN);
	return 1;
}
uint16_t Button_Read(uint8_t buttonport , uint8_t buttonpin ,uint8_t *value)
{
	DIO_Read(buttonport,buttonpin, value);
}