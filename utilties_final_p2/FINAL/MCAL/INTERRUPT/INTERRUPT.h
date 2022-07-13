/*
 * INTERRUPT.h
 *
 * Created: 3/9/2022 8:40:16 PM
 *  Author: youss
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

/************************************************************************/
/*                                                                      */
/************************************************************************/
#include "INTERRUPT_CFG.h"
#include "ATmega32_Register.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "STD_TYPES.h"
//#include <avr/io.h>
//PB2
void ENABLE_INT0(uint8 MODE);
void ENABLE_INT1(uint8 MODE);
void ENABLE_INT2(uint8 MODE);
void INT_MODE(uint8 INT_X,uint8 MODE);
void INT_SELECT(uint8 INT_X,uint8 MODE);
void DISABLE_INT();
void DISABLE_INT0();
void DISABLE_INT1();
void DISABLE_INT2();



#endif /* INTERRUPT_H_ */