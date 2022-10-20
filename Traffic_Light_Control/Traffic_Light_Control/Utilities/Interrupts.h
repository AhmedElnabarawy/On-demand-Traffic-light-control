/*
 * Interrupts.h
 *
 * Created: 10/10/2022 8:47:36 PM
 *  Author: Ahmed Mamdouh Elsayed
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_
#include "../Utilities/Registers.h"
#define ISC00 0
#define ISC01 1
#define INT0 6

//Interrupt vector
#define INTR_INT0 __vector_1
//To Enable the interrupt
#define sei()  __asm__ __volatile__ ("sei" ::: "memory")
//ISR 
#define ISR(INT0_vect) \
void INT0_vect(void) __attribute__ ((signal)); \
void INT0_vect(void)

#endif /* INTERRUPTS_H_ */