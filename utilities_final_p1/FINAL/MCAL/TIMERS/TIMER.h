/*
 * TIMER.h
 *
 * Created: 3/9/2022 8:42:30 PM
 *  Author: youss
 */ 


#ifndef TIMER_H_
#define TIMER_H_



/***************BASIC_LIBS***************/
#include <avr/interrupt.h>
#include "ATmega32_Register.h"
#include "TIMER_CFG.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
//#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
/***************HELPING_PROTOTYPES*********/

/***************PROTOTYPES*****************/
void TIMER1_INIT_IN_CAPTURE_MODE(uint8 MODE);
void TIMER1_IN_CAPTURE_MODE(uint8 MODE);
void TIMER1_INIT_OF_MODE();

/***************HELPING MACROS************/
#define NO_CLOCK			0
#define NO_PRESCALER		1
#define PRESCALER_8			2
#define PRESCALER_64		3
#define PRESCALER_256		4
#define PRESCALER_1024		5

#endif /* TIMER_H_ */