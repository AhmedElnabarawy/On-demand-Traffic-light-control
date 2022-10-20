/*
 * DIO.h
 *
 * Created: 10/5/2022 8:06:07 PM
 *  Author: Ahmed Mamdouh Elsayed
 */ 


#ifndef DIO_H_
#define DIO_H_

// All internal driver typedefs
#include "../Utilities/Typedefs.h"
#include "../Utilities/Registers.h"
//All driver macros.
#define  PORT_A 'A'
#define  PORT_B 'B'
#define  PORT_C 'C'
#define  PORT_D 'D'
//Direction defines
#define IN 0
#define OUT 1
//Value defines
#define High 1
#define Low 0



//All driver function prototype.

uint32_t DIO_init(uint8_t portnum , uint8_t pinnum , uint8_t direction); // initialize DIO direction
uint32_t DIO_Write(uint8_t PORTnum , uint8_t pinnum , uint8_t value); // Write on DIO
uint32_t DIO_Toggle(uint8_t PORTnum , uint8_t pinnum ); // Change the state of DIO 
uint32_t DIO_Read(uint8_t PORTnum , uint8_t pinnum , uint8_t *value); // Read from DIO





#endif /* DIO_H_ */