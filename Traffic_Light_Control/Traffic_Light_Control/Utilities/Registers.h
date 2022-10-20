/*
 * Registers.h
 *
 * Created: 10/3/2022 10:12:24 PM
 *  Author: Ahmed Mamdouh Elsayed
 */ 

// Hardware Layer.
//Register File.


#ifndef REGISTERS_H_ //Header Guard
#define REGISTERS_H_
#include "Typedefs.h"
//***************************************************
//DIO Registers
//***************************************************
// PortA DIO Register
#define DDRA *((volatile uint8_t*) 0x3A)
#define PORTA *((volatile uint8_t*) 0x3B)
#define PINA *((volatile uint8_t*) 0x39)
//PortB DIO Register
#define DDRB *((volatile uint8_t*) 0x37)
#define PORTB *((volatile uint8_t*) 0x38)
#define PINB *((volatile uint8_t*) 0x36)
// PortC DIO Register
#define DDRC *((volatile uint8_t*) 0x34)
#define PORTC *((volatile uint8_t*) 0x35)
#define PINC *((volatile uint8_t*) 0x33)
// PortD DIO Register
#define DDRD *((volatile uint8_t*) 0x31)
#define PORTD *((volatile uint8_t*) 0x32)
#define PIND *((volatile uint8_t*) 0x30)


//***************************************************
//Timer0 Registers
//***************************************************

#define TCCR0 *((volatile uint8_t*) 0x53) //Timer/Counter Control Register.
#define TCNT0 *((volatile uint8_t*) 0x52)  //Read and Write operations.
#define TIFR *((volatile uint8_t*) 0x58)  // Timer/Counter	Interrupt Flag Register.  TOV0 is set to be 1 if overflow occurs.

//***************************************************
//Interrupt Registers
//***************************************************

#define SREG (*(volatile uint8_t*)(0x5F))  //Enable Global Interrupt
#define GICR (*(volatile uint8_t*)(0x5B))  //Enable external interrupt 0 - INT0.
#define MCUCR (*(volatile uint8_t*)(0x55)) //Chose the external interrupt sense - sense on rising edge.

#endif /* REGISTERS_H_ */