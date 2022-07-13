/*
 * DIO_CFG.h
 *
 * Created: 3/9/2022 8:52:15 PM
 *  Author: youss
 */ 


#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#include "ATmega32_Register.h"
#define MODE_A    DDRA_REG
#define MODE_B    DDRB_REG
#define MODE_C    DDRC_REG
#define MODE_D    DDRD_REG


#define WRITE_A   PORT_A
#define WRITE_B   PORT_B
#define WRITE_C   PORT_C
#define WRITE_D   PORT_D

#define READ_A    PIN_A
#define READ_B    PIN_B
#define READ_C    PIN_C
#define READ_D    PIN_D



#endif /* DIO_CFG_H_ */