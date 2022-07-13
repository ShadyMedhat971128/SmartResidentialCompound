/*
 * WATER.h
 *
 * Created: 3/10/2022 1:35:12 PM
 *  Author: youss
 */ 


#ifndef WATER_H_
#define WATER_H_



#include <avr/interrupt.h>
#include <stdlib.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "TIMER.h"
#include "INTERRUPT.h"
#include "WATER_CFG.h"
#include "DIO.h"


/***************************PROTOTYPES******************/
void WATER_INIT();


float64 ULTRASONIC_DISTANCE();
void ULTRASONIC_TIMER_RESET();
uint32 get_US_distance();
//
void timer2_init(void);
void enable_ex_interrupt(void);
//
#define ON  1
#define OFF	0
//


#endif /* WATER_H_ */