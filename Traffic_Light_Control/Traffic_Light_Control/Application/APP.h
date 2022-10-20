/*
 * APP.h
 *
 * Created: 10/10/2022 8:41:55 PM
 *  Author: Ahmed Mamdouh Elsayed
 */ 


#ifndef APP_H_
#define APP_H_

#include "../ECUAL/Led Driver/LED.h"
#include "../MCAL/Timer Driver/Timer.h"
#include "../ECUAL/Button Driver/Button.h"
#include "../Utilities/Interrupts.h"
#include "../Utilities/Registers.h"
#define N_Mode 1
#define P_Mode 0


void App_init();
void App(); // To Start the program


#endif /* APP_H_ */