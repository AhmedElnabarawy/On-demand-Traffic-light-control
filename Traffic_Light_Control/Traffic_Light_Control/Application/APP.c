/*
 * APP.c
 *
 * Created: 10/10/2022 8:41:46 PM
 *  Author: Ahmed Mamdouh Elsayed
 */ 

#include "APP.h"


void App_init()
{
	//Pedestrian Led
	LED_init(PORT_B,Led_p_G );
	LED_init(PORT_B,Led_p_Y );
	LED_init(PORT_B,Led_p_R );
	// Car Led
	LED_init(PORT_A,Led_C_G );
	LED_init(PORT_A,Led_C_Y );
	LED_init(PORT_A,Led_C_R );
	// Button
	Button_init(PORT_D,INT0_PIN);
	//Timer
	Timer_init();
	//Enable global interrupt --> set bin 7 in the status register to be 1.
	sei();
	//Chose the external interrupt sense - sense on rising edge.
	MCUCR |=(1<<ISC00) | (1<<ISC01);
	//Enable external interrupt 0 - INT0.
	//General Interrupt Flag Register
	GICR |= (1 << INT0);
}

uint8_t Mode = N_Mode; // when 0--> Pedestrian Mode 
uint8_t C_LED = Green; 
uint8_t PRE_C_LED= Yellow;
uint16_t count=0;
uint32_t test=0;
void App()
{
	//Testing mode
	if (!Mode && test == 0)
	{
		test = LED_init(PORT_A,Led_C_G);
		test += LED_on(PORT_A,Led_C_G);
		Timer_delay(1000);
		test +=LED_off(PORT_A,Led_C_G);
		Timer_delay(1000);
		test +=LED_toggle(PORT_A,Led_C_G);
		test +=Button_init(PORT_D,INT0_PIN);
		Timer_delay(1000);
		Mode = N_Mode;
	}
	// If the car led is Red with interrupt.
	if (test == 5)
	{
	
	if (!Mode && C_LED == Red)
	{
		//turn on the ped green led and car red led
		LED_on(PORT_B,Led_p_G);
		LED_on(PORT_A,Led_C_R);
		//turn off other leds
		LED_off(PORT_B,Led_p_Y);
		LED_off(PORT_B,Led_p_R);
		LED_off(PORT_A,Led_C_G);
		LED_off(PORT_A,Led_C_Y);
		
		Timer_delay(5000);//5 sec delay
		//turn off the ped green led and car red led after 5 SEC
		LED_off(PORT_B,Led_p_G);
		LED_off(PORT_A,Led_C_R);
		//Blinking yellow leds
		LED_BlinkD(PORT_A,Led_C_Y,PORT_B,Led_p_Y,500);
		//turn of yellow leds and turn on ped red led
		LED_off(PORT_A,Led_C_Y);
		LED_off(PORT_B,Led_p_Y);
		LED_on(PORT_B,Led_p_R);
		// Set the values to start normally again
		C_LED=Green;
		PRE_C_LED=Yellow;
		Mode=N_Mode;
		
	}
	
	
	
	
	
		else
		{
			// Check the Interrupt
			if (!Mode)
			{
				C_LED = Yellow; 
			}
			// Close the pedestrian leds in normal case
			LED_off(PORT_B , Led_p_G);
			LED_off(PORT_B , Led_p_Y);
			LED_off(PORT_B , Led_p_R);
			
			switch(C_LED)
			{
				//***************************************Green case****************************************/
				case Green:
				LED_on(PORT_A , Led_C_G);
				LED_off(PORT_A , Led_C_Y);
				LED_off(PORT_A , Led_C_R);
				//delay 5000 ms 
				for (count = 0 ; count < 5 ; count++)
				{
					Timer_delay(1000);
					if (!Mode)
					{
						break;
					}
				}
				C_LED = Yellow; 
				PRE_C_LED = Green;
				break;
				//***************************************Yellow case****************************************/
				case Yellow:
				
				if (!Mode)
				{
					if (PRE_C_LED!=Red)
					{
						LED_on(PORT_B,Led_p_R);
						LED_BlinkD(PORT_A,Led_C_Y,PORT_B,Led_p_Y,500);
					}
					PRE_C_LED=Yellow;
					C_LED=Red;
					LED_on(PORT_A,Led_C_R);
				}
				else
				{
					LED_off(PORT_A , Led_C_G);
					LED_off(PORT_A , Led_C_R);
					for (count= 0 ; count < 5 ; count++)
					{
						LED_Blink(PORT_A,Led_C_Y,500);
						
						if (!Mode)
						{
							PRE_C_LED=Yellow;
							break;
						}
					}
				}
				LED_off(PORT_A,Led_C_Y);
				LED_off(PORT_B,Led_p_Y);
				
				if(PRE_C_LED==Green)
				{
					C_LED=Red;
					PRE_C_LED=Yellow;
				}
				else if(PRE_C_LED==Red)
				{
					C_LED=Green;
					PRE_C_LED=Yellow;
				}
				break;
				//***************************************Red case****************************************/
				case Red:
				LED_off(PORT_A,Led_C_G);
				LED_off(PORT_A,Led_C_Y);
				LED_on(PORT_A,Led_C_R);
				for(count= 0; count <5; count++)
				{
					Timer_delay(1000);
					if(!Mode)
					break;
				}
				PRE_C_LED=Red;
				C_LED=Yellow;
				break;
			default:
				C_LED=Red;
				PRE_C_LED=Yellow;
				break;
				}
				
			}
	}
	else
	{
		test = 0;
	}
	
}


//Interrupt
ISR(INTR_INT0)
{
	Mode=P_Mode;
}