/*
 * UART.h
 *
 * Created: 5/16/2022 6:31:48 PM
 *  Author: ahmed
 */ 


#ifndef UART_H_
#define UART_H_



#include "STD_TYPES.h"

void UART_INIT (void);
void UART_TRANSMIT_CHR (uint8);
void UART_TRANSMIT_STR (uint8*);
void UART_TRANSMIT_INT  (uint8);
uint8	 UART_RECEIVE (void);



#endif /* UART_H_ */