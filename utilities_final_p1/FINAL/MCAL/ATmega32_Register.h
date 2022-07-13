/*
 * ATmega32_Register.h
 *
 * Created: 3/9/2022 8:53:39 PM
 *  Author: youss
 */ 


#ifndef ATMEGA32_REGISTER_H_
#define ATMEGA32_REGISTER_H_

#include "STD_TYPES.h"
//                 access the pointer
//                 |  part MMR in the RAM
//                 |   |       STD_type pointer
//				   |   |	    |    address from the data sheet
//define PORTA_REG(*((volatile uint8*)0X3B))

/**********************DIO REG*********************************/
//REG A
#define PORT_A	(*((volatile uint8*)0X3B))
#define DDRA_REG	(*((volatile uint8*)0X3A))
#define PIN_A	(*((volatile uint8*)0X39))
//---------------------------------------------
//REG B
#define PORT_B	(*((volatile uint8*)0X38))
#define DDRB_REG	(*((volatile uint8*)0X37))
#define PIN_B	(*((volatile uint8*)0X36))
//------------------------------------------------
//REG C
#define PORT_C	(*((volatile uint8*)0X35))
#define DDRC_REG	(*((volatile uint8*)0X34))
#define PIN_C	(*((volatile uint8*)0X33))
//REG D
#define PORT_D	(*((volatile uint8*)0X32))
#define DDRD_REG	(*((volatile uint8*)0X31))
#define PIN_D	(*((volatile uint8*)0X30))

/**********************INTERRUPT REG*********************************/
#define S_REG			(*((volatile uint8*)0X5F)) // sreg
#define I			7							  // global interrupt enable pin
#define GIC_REG			(*((volatile uint8*)0X5B))//GICR:General INT control REG
#define MCUC_REG		(*((volatile uint8*)0X55))
#define MCUCS_REG		(*((volatile uint8*)0X54))
/*******************PIN_IN_GIC_REG******************/
#define INT1_PIN    7
#define INT0_PIN    6
#define INT2_PIN    5
/*******************PIN_IN_MCUC_REG******************/
/*******************INT0******************/
#define ISC00	0
#define ISC01	1
/*******************INT1******************/
#define ISC10	2
#define ISC11	3
/*******************PIN_IN_MCUCS_REG******************/
/*******************INT2******************/
#define	ISC2	6
/**********************TIMER 1 REG*********************************/
#define TIMSK		(*((volatile uint8*)0X59))
#define TIFR		(*((volatile uint8*)0X58))
#define TCNT1		(*((volatile uint16*)0X4C))
#define TCCR1B		(*((volatile uint8*)0X4E))
#define TCCR1A		(*((volatile uint8*)0X4F))
#define ICR1		(*((volatile uint16*)0X46))
/* TIMSK */
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5	// input capture interrupt pin
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0
/* TIFR */
#define TOV1	2
#define ICF1    5	// IN CAPTURE FLAG
/* TCCR1A */
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0
/* TCCR1B */
#define CS12 2
#define CS11 1
#define	CS10 0
/****************_WDT_REGISTERS_**************/

#define UCSRA     (*((volatile uint8*)0x2B))
#define UCSRB     (*((volatile uint8*)0x2A))
#define UCSRC     (*((volatile uint8*)0x40))
#define UBRRL     (*((volatile uint8*)0x29))
#define UDR       (*((volatile uint8*)0x2C))

/***************_ADC_REGISTERS_**************/

#define ADMUX           (*(volatile uint8*)(0x27))
#define ADCSRA          (*(volatile uint8*)(0x26))
#define ADCH            (*(volatile uint8*)(0x25))
#define ADCL            (*(volatile uint8*)(0x24))
#define ADC_VALUE       (*(volatile uint16*)(0x24))




#endif /* ATMEGA32_REGISTER_H_ */