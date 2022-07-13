/*
 * ULTRASONIC_SENSOR.h
 *
 * Created: 3/9/2022 8:36:30 PM
 *  Author: youss
 */ 


#ifndef ULTRASONIC_SENSOR_H_
#define ULTRASONIC_SENSOR_H_

/***************************BASIC_LIBS*********************/
#include <avr/interrupt.h>
#include <stdlib.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "TIMER.h"
#include "INTERRUPT.h"
#include "ULTRASONIC_SENSOR_CFG.h"
#include "DIO.h"


/***************************PROTOTYPES******************/
void ULTRASONIC_INIT();

void ULTRASONIC_TRIG_PULSE();
float64 ULTRASONIC_DISTANCE();
void ULTRASONIC_TIMER_RESET();
uint32 get_US_distance();
//
void timer0_init(void);
void enable_ex_interrupt(void);
//
#define ON  1
#define OFF	0
//




#endif /* ULTRASONIC_SENSOR_H_ */