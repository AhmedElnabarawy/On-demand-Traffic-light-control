/*
 * Led.h
 *
 * Created: 10/5/2022 10:19:11 PM
 *  Author: Ahmed Mamdouh Elsayed
 */ 



#ifndef LED_H_
#define LED_H_
#include "../MCAL/DIO Driver/DIO.h"

//Pedestrian Led
#define Led_p_G 0
#define Led_p_Y 1
#define Led_p_R 2
//Car Led
#define Led_C_G 0
#define Led_C_Y 1
#define Led_C_R 2
//led colors
#define Green 0 
#define Yellow 1
#define Red 2

//Initialization of the led driver
uint32_t LED_init(uint8_t ledport , uint8_t ledpin);
//Turn on the led
uint32_t LED_on(uint8_t ledport , uint8_t ledpin);
//Turn off the led
uint32_t LED_off(uint8_t ledport , uint8_t ledpin);
//Change the state of the led
uint32_t LED_toggle(uint8_t ledport , uint8_t ledpin);
//Blinking function for one pin
uint32_t LED_Blink(uint8_t ledport , uint8_t ledpin , F_t Time);
//Blinking function for two pins
uint32_t LED_BlinkD(uint8_t ledport1 , uint8_t ledpin1 ,uint8_t ledport2 , uint8_t ledpin2 , F_t Time);

#endif /* LED_H_ */