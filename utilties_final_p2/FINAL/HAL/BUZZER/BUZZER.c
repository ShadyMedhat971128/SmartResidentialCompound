/*
 * BUZZER.c
 *
 * Created: 3/9/2022 8:32:18 PM
 *  Author: youss
 */ 


#include "DIO.h"
#define F_CPU 16000000UL
#include "util/delay.h"
#include "BUZZER.h"
#include "BUZZER_CFG.h"

void BUZZER_INIT (void)          // function to initialize the buzzer
{
	PIN_MODE(BUZZER_PIN,OUTPUT); // setting the buzzer pin to be output
}

void BUZZER_ON (void)            // function to turn the buzzer ON
{
	BUZZER_INIT();
	PIN_WRITE(BUZZER_PIN,HIGH);  // turning the buzzer ON
	
}

void BUZZER_OFF (void)           // function to turn the buzzer OFF
{
	PIN_WRITE(BUZZER_PIN,LOW);   // turning the buzzer off

}

void BUZZER_ONCE (void)          // function to turn the buzzer on for 30 ms
{
	PIN_WRITE(BUZZER_PIN,HIGH);  // turning the buzzer on
	_delay_ms(30);               // setting a delay for 30 sec
	PIN_WRITE(BUZZER_PIN,LOW);   // turning the buzzer off
	_delay_ms(30);               // setting a delay for 30 sec (in case of using while loop)
}

void BUZZER_TWICE (void)         // function to turn the buzzer twice
{
	PIN_WRITE(BUZZER_PIN,HIGH);  // turning the buzzer on
	_delay_ms(70);               // setting a delay for 70 sec
	PIN_WRITE(BUZZER_PIN,LOW);   // turning the buzzer off
	_delay_ms(40);               // setting a delay for 40 sec between the two buzzes
	PIN_WRITE(BUZZER_PIN,HIGH);  // turning the buzzer on
	_delay_ms(70);				 // setting a delay for 70 sec
	PIN_WRITE(BUZZER_PIN,LOW);	 // turning the buzzer off
}

int BUZZER_CONDITION(void)
{
	switch (BUZZER_PIN)
	{
		case 0:
		return 0;
		break;
		
		case 1:
		return 1;
		break;
		
		default:
		return 2;
		break;
	}
	
}

void BUZZER_LONG (void)
{
	PIN_WRITE(BUZZER_PIN,HIGH);
	_delay_ms(1000);
	PIN_WRITE(BUZZER_PIN,LOW);
	_delay_ms(1000);
}