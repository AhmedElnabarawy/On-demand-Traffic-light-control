/*
 * Button.h
 *
 * Created: 10/7/2022 1:45:13 PM
 *  Author: Ahmed Mamdouh Elsayed
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../MCAL/DIO Driver/DIO.h"
#define INT0_PIN 2


uint16_t Button_init(uint8_t buttonport , uint8_t buttonpin);
uint16_t Button_Read(uint8_t buttonport , uint8_t buttonpin ,uint8_t *value);


#endif /* BUTTON_H_ */