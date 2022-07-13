/*
 * UART.c
 *
 * Created: 5/16/2022 6:31:18 PM
 *  Author: ahmed
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATmega32_Register.h"

#include <stdlib.h>

#include "UART.h"
#include "UART_CFG.h"

// (\r as \n for virtual terminal)
void UART_INIT (void)
{
	SET_BIT(UCSRB,3);	//Tx enable
	SET_BIT(UCSRB,4);	//Rx enable
	

	
	
	CLR_BIT(UCSRA,1); //ASync, Normal Mode
	//UBRRL=160000000/(16*(BAUD_RATE)) - 1;
	
	//Baud Rate = 9600bps & f=16MHz, UBRR=103
	UBRRL=103;  //<=255 else UBRRH
}

void UART_TRANSMIT_CHR (uint8 data)
{
	//pooling
	//UDRE FLAG INITIALLY 1
	//while(!(UCSRA & (1<<UDRE)))
	while(!GET_BIT(UCSRA,5)); //Check UDR Buffer if ready to receive data
	UDR = data;
	
}

void UART_TRANSMIT_STR (uint8*str)
{
	uint8 i=0;
	while(str[i]!='\0')
	{
		UART_TRANSMIT_CHR(str[i]);
		i++;
	}
}

void UART_TRANSMIT_INT  (uint8 num)
{
	uint8 str[10]={0};
	itoa(num,str,10); //integer to array
	UART_TRANSMIT_STR(str);
}

uint8 UART_RECEIVE()
{
	//while (!(UCSRA & (1<<RXC)));
	while(!GET_BIT(UCSRA,7));
	return UDR;
}