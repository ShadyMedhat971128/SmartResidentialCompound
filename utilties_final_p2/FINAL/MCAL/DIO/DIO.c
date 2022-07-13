/*
 * DIO.c
 *
 * Created: 3/9/2022 8:47:08 PM
 *  Author: youss
 */ 



#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATmega32_Register.h"
#include "DIO.h"


/********************************************************************* PINS *********************************************************************/
/************************************************************************************************************************************************/

//                                                       PIN MODE Function
//                                                      -------------------
void  PIN_MODE(uint8 pin,uint8 mode)          // takes the port and pin number in variable PIN, take the mode of the pin in variable mode
{
	uint8 port = pin/10 ;                     // to get the port number we use integer to ignore the remainder of pin/10 so the output is 1,2,3,4
	
	switch(mode)                              // checking the value of mode to enter either output or input
	{
		case OUTPUT:                          // in case of output
		switch(port)                          // checking the port value either 1,2,3,4
		{
			case 1:                           // case 1 = A
			pin=pin%10;                       // this function takes the remainder of the sent number in variable PIN and save it in it ex: PIN = 14, PIN = 4
			SET_BIT(MODE_A,pin);              // setting assigned bit to be 1 --> OUTPUT
			break;                            // breaks the 1st case
			
			case 2:                           // case 2 = B
			pin=pin%20;                       // this function takes the remainder of the sent number in variable PIN and save it in it ex: PIN = 27, PIN = 7
			SET_BIT(MODE_B,pin);              // setting assigned bit to be 1 --> OUTPUT
			break;                            // breaks the 2nd case
			
			case 3:                           // case 3 = C
			pin=pin%30;                       // this function takes the remainder of the sent number in variable PIN and save it in it ex: PIN = 37, PIN = 7
			SET_BIT(MODE_C,pin);              // setting assigned bit to be 1 --> OUTPUT
			break;                            // breaks the 3rd case
			
			case 4:                           // case 4 = D
			pin=pin%40;                       // this function takes the remainder of the sent number in variable PIN and save it in it ex: PIN = 48, PIN = 8
			SET_BIT(MODE_D,pin);              // setting assigned bit to be 1 --> OUTPUT
			break;                            // breaks the 4th case
		}
		break;                                // ends the OUTPUT case
		
		case INPUT:                           // in case of input
		switch(port)                          // checking the port value either 1,2,3,4
		{
			case 1:                           // case 1 = A
			pin=pin%10;                       // this function takes the remainder of the sent number in variable PIN and save it in it ex: PIN = 14, PIN = 4
			CLR_BIT(MODE_A,pin);              // setting assigned bit to be 0 --> INPUT
			break;                            // breaks the 1st case
			
			case 2:                           // case 2 = B
			pin=pin%20;                       // this function takes the remainder of the sent number in variable PIN and save it in it ex: PIN = 27, PIN = 7
			CLR_BIT(MODE_B,pin);              // setting assigned bit to be 0 --> INPUT
			break;                            // breaks the 2nd case
			
			case 3:                           // case 3 = C
			pin=pin%30;                       // this function takes the remainder of the sent number in variable PIN and save it in it ex: PIN = 37, PIN = 7
			CLR_BIT(MODE_C,pin);              // setting assigned bit to be 0 --> INPUT
			break;                            // breaks the 3rd case
			
			case 4:                           // case 4 = D
			pin=pin%40;                       // this function takes the remainder of the sent number in variable PIN and save it in it ex: PIN = 48, PIN = 8
			CLR_BIT(MODE_D,pin);            // setting assigned bit to be 0 --> INPUT
			break;                            // breaks the 4th case
		}
		break;                                // ends the input case
	}
}


//                                                               PIN WRITE Function
//                                                              --------------------
void  PIN_WRITE(uint8 pin,uint8 mode)                     // takes the port and pin number in variable PIN, take the mode of the pin in variable mode
{
	uint8 port = pin/10 ;                             // to get the port number we use integer to ignore the remainder of pin/10 so the output is 1,2,3,4
	
	switch(mode)                                      // checking the value of mode to enter either output or input
	{
		case HIGH:                                // in case of HIGH
		switch(port)                              // checking the port value either 1,2,3,4
		{
			case 1:                           // case 1 = A
			pin=pin%10;                       // this function takes the remainder of the sent number in variable PIN and save it in it ex: PIN = 14, PIN = 4
			SET_BIT(WRITE_A,pin);             // setting assigned bit to be 1 --> 5V
			break;                            // breaks the 1st case
			
			case 2:                           // case 2 = B
			pin=pin%20;                       // this function takes the remainder of the sent number in variable PIN and save it in it ex: PIN = 27, PIN = 7
			SET_BIT(WRITE_B,pin);             // setting assigned bit to be 1 --> 5V
			break;                            // breaks the 2nd case
			
			case 3:                           // case 3 = C
			pin=pin%30;                       // this function takes the remainder of the sent number in variable PIN and save it in it ex: PIN = 37, PIN = 7
			SET_BIT(WRITE_C,pin);             // setting assigned bit to be 1 --> 5V
			break;                            // breaks the 3rd case
			
			case 4:                           // case 4 = D
			pin=pin%40;                       // this function takes the remainder of the sent number in variable PIN and save it in it ex: PIN = 48, PIN = 8
			SET_BIT(WRITE_D,pin);             // setting assigned bit to be 1 --> 5V
			break;                            // breaks the 4th case
		}
		break;	                                  // ends the high case
		
		case LOW:                                 // in case of LOW
		switch(port)                              // checking the port value either 1,2,3,4
		{
			case 1:                           // case 1 = A
			pin=pin%10;                       // this function takes the remainder of the sent number in variable PIN and save it in it ex: PIN = 14, PIN = 4
			CLR_BIT(WRITE_A,pin);             // setting assigned bit to be 0 --> 0V
			break;                            // breaks the 1st case
			
			case 2:                           // case 2 = B
			pin=pin%20;                       // this function takes the remainder of the sent number in variable PIN and save it in it ex: PIN = 27, PIN = 7
			CLR_BIT(WRITE_B,pin);             // setting assigned bit to be 0 --> 0V
			break;                            // breaks the 2nd case
			
			case 3:                           // case 3 = C
			pin=pin%30;                       // this function takes the remainder of the sent number in variable PIN and save it in it ex: PIN = 37, PIN = 7
			CLR_BIT(WRITE_C,pin);             // setting assigned bit to be 0 --> 0V
			break;                            // breaks the 3rd case
			
			case 4:                           // case 4 = D
			pin=pin%40;                       // this function takes the remainder of the sent number in variable PIN and save it in it ex: PIN = 48, PIN = 8
			CLR_BIT(WRITE_D,pin);             // setting assigned bit to be 0 --> 0V
			break;                            // breaks the 4th case
		}
		break;                                    // ends the low case
	}
}


//                                                       PIN READ Function
//                                                      -------------------
uint8 PIN_READ(uint8 pin)                 // takes the port and pin number in variable PIN and returns the input data through a variable
{
	uint8 port = pin/10 ;                 // to get the port number we use integer to ignore the remainder of pin/10 so the output is 1,2,3,4
	uint8 value = 0;                      // a variable to save the input data in it, setting it initially = 0
	switch(port)                          // checking the port value either 1,2,3,4
	{
		case 1:                           // case 1 = A
		pin=pin%10;                       // this function takes the remainder of the sent number in variable PIN and save it in it ex: PIN = 14, PIN = 4
		value = GET_BIT(READ_A,pin);      // storing the data from the assigned pin into variable "value"
		break;                            // breaks the first case
		
		case 2:                           // case 2 = B
		pin=pin%20;                       // this function takes the remainder of the sent number in variable PIN and save it in it ex: PIN = 27, PIN = 7
		value = GET_BIT(READ_B,pin);      // storing the data from the assigned pin into variable "value"
		break;                            // breaks the first case
		
		case 3:                           // case 3 = C
		pin=pin%30;                       // this function takes the remainder of the sent number in variable PIN and save it in it ex: PIN = 37, PIN = 7
		value = GET_BIT(READ_C,pin);      // storing the data from the assigned pin into variable "value"
		break;                            // breaks the first case
		
		case 4:                           // case 4 = D
		pin=pin%40;                       // this function takes the remainder of the sent number in variable PIN and save it in it ex: PIN = 48, PIN = 8
		value = GET_BIT(READ_D,pin);      // storing the data from the assigned pin into variable "value"
		break;                            // breaks the first case
	}
	return value;                         // returns the input data stored in value
}

//                                                       PIN TOGGLE Function
//                                                      ---------------------
void  PIN_TOG(uint8 pin)                  // takes the port and pin number in variable PIN
{
	uint8 port = pin/10 ;                 // to get the port number we use integer to ignore the remainder of pin/10 so the output is 1,2,3,4
	switch(port)                          // checking the port value either 1,2,3,4
	{
		case 1:                           // case 1 = A
		pin=pin%10;                       // this function takes the remainder of the sent number in variable PIN and save it in it ex: PIN = 14, PIN = 4
		TOG_BIT(READ_A,pin);              // converts the assigned bit 1 --> 0 or 0 --> 1
		break;                            // breaks the first case
		
		case 2:                           // case 2 = B
		pin=pin%20;                       // this function takes the remainder of the sent number in variable PIN and save it in it ex: PIN = 27, PIN = 7
		TOG_BIT(READ_B,pin);              // converts the assigned bit 1 --> 0 or 0 --> 1
		break;                            // breaks the first case
		
		case 3:                           // case 3 = C
		pin=pin%30;                       // this function takes the remainder of the sent number in variable PIN and save it in it ex: PIN = 37, PIN = 7
		TOG_BIT(READ_C,pin);              // converts the assigned bit 1 --> 0 or 0 --> 1
		break;                            // breaks the first case
		
		case 4:                           // case 4 = D
		pin=pin%40;                       // this function takes the remainder of the sent number in variable PIN and save it in it ex: PIN = 48, PIN = 8
		TOG_BIT(READ_D,pin);              // converts the assigned bit 1 --> 0 or 0 --> 1
		break;                            // breaks the first case
	}
}

//                                                       PIN_PULL_UP Resistance Function(used when pin is input ONLY)
//                                                      --------------------------------------------------------------
void  PIN_PULL_UP(uint8 pin,uint8 mode)       // takes the port and pin number in variable PIN and returns the input data through a variable
{
	uint8 port = pin/10 ;                     // to get the port number we use integer to ignore the remainder of pin/10 so the output is 1,2,3,4
	
	switch(mode)                              // checking the value of mode to enter either output or input
	{
		case ENABLE:                          // in case of Enabling the pull up resistance circuit
		switch(port)                          // checking the port value either 1,2,3,4
		{
			case 1:                           // case 1 = A
			pin=pin%10;                       // this function takes the remainder of the sent number in variable PIN and save it in it ex: PIN = 14, PIN = 4
			SET_BIT(WRITE_A,pin);             // enable pull up resistance on the assigned pin
			break;                            // breaks the 1st case
			
			case 2:                           // case 2 = B
			pin=pin%20;                       // this function takes the remainder of the sent number in variable PIN and save it in it ex: PIN = 27, PIN = 7
			SET_BIT(WRITE_B,pin);             // enable pull up resistance on the assigned pin
			break;                            // breaks the 2nd case
			
			case 3:                           // case 3 = C
			pin=pin%30;                       // this function takes the remainder of the sent number in variable PIN and save it in it ex: PIN = 37, PIN = 7
			SET_BIT(WRITE_C,pin);             // enable pull up resistance on the assigned pin
			break;                            // breaks the 3rd case
			
			case 4:                           // case 4 = D
			pin=pin%40;                       // this function takes the remainder of the sent number in variable PIN and save it in it ex: PIN = 48, PIN = 8
			SET_BIT(WRITE_D,pin);             // enable pull up resistance on the assigned pin
			break;                            // breaks the 4th case
		}
		break;							      // ends the enable case
		
		case DISABLE:                         // in case of disabling the pull up resistance circuit
		switch(port)                          // checking the port value either 1,2,3,4
		{
			case 1:                           // case 1 = A
			pin=pin%10;                       // this function takes the remainder of the sent number in variable PIN and save it in it ex: PIN = 14, PIN = 4
			CLR_BIT(WRITE_A,pin);             // disable pull up resistance on the assigned pin
			break;                            // breaks the 1st case
			
			case 2:                           // case 2 = B
			pin=pin%20;                       // this function takes the remainder of the sent number in variable PIN and save it in it ex: PIN = 27, PIN = 7
			CLR_BIT(WRITE_B,pin);             // disable pull up resistance on the assigned pin
			break;                            // breaks the 2nd case
			
			case 3:                           // case 3 = C
			pin=pin%30;                       // this function takes the remainder of the sent number in variable PIN and save it in it ex: PIN = 37, PIN = 7
			CLR_BIT(WRITE_C,pin);             // disable pull up resistance on the assigned pin
			break;                            // breaks the 3rd case
			
			case 4:                           // case 4 = D
			pin=pin%40;                       // this function takes the remainder of the sent number in variable PIN and save it in it ex: PIN = 48, PIN = 8
			CLR_BIT(WRITE_D,pin);             // disable pull up resistance on the assigned pin
			break;                            // breaks the 4th case
		}
		break;							      // ends the disable case
	}
}

/******************************************************************** PORTS ********************************************************************/
/***********************************************************************************************************************************************/

//                                                       PORT MODE Function
//                                                      --------------------

void PORT_MODE(uint8 port,uint8 mode)         // takes the values of the port and the mode either output or input
{
	switch(port)                              // checking the port value either 1,2,3,4
	{
		case A:                               // case of using port A
		MODE_A = mode;                        // make all pins in port A = 1 --> OUTPUT or 0 --> INPUT
		break;                                // breaks case A
		
		case B:                               // case of using port B
		MODE_B = mode;                        // make all pins in port B = 1 --> OUTPUT or 0 --> INPUT
		break;                                // breaks case B
		
		case C:                               // case of using port C
		MODE_C = mode;                        // make all pins in port C = 1 --> OUTPUT or 0 --> INPUT
		break;                                // breaks case C
		
		case D:                               // case of using port D
		MODE_D = mode;                        // make all pins in port D = 1 --> OUTPUT or 0 --> INPUT
		break;                                // breaks case D
		
	}
}

//                                                       PORT WRITE Function
//                                                      ---------------------

void PORT_WRITE(uint8 port,uint8 mode)        // takes the values of the port and the mode either high or low
{
	switch(port)                              // checking the port value either 1,2,3,4
	{
		case A:                               // case of using port A
		WRITE_A = mode;                       // make all pins in port A = 1 --> HIGH or 0 --> LOW
		break;                                // breaks case A
		
		case B:                               // case of using port B
		WRITE_B = mode;                       // make all pins in port B = 1 --> HIGH or 0 --> LOW
		break;                                // breaks case B
		
		case C:                               // case of using port C
		WRITE_C = mode;                       // make all pins in port C = 1 --> HIGH or 0 --> LOW
		break;                                // breaks case C
		
		case D:                               // case of using port D
		WRITE_D = mode;                       // make all pins in port D = 1 --> HIGH or 0 --> LOW
		break;                                // breaks case D
		
	}
}

//                                                       PORT TOG Function
//                                                      -------------------

void PORT_TOG(uint8 port)                     // takes the values of the port
{
	switch(port)                              // checking the port value either 1,2,3,4
	{
		case A:                               // case of using port A
		WRITE_A ^= 0xff;                      // xor the input with 0b11111111 where 0 xor 1 = 1, 1 xor 1 = 0
		break;                                // breaks case A
		
		case B:                               // case of using port B
		WRITE_B ^= 0xff;                      // xor the input with 0b11111111 where 0 xor 1 = 1, 1 xor 1 = 0
		break;                                // breaks case B
		
		case C:                               // case of using port C
		WRITE_C = 0xff;                       // xor the input with 0b11111111 where 0 xor 1 = 1, 1 xor 1 = 0
		break;                                // breaks case C
		
		case D:                               // case of using port D
		WRITE_D = 0xff;                       // xor the input with 0b11111111 where 0 xor 1 = 1, 1 xor 1 = 0
		break;                                // breaks case D
		
	}
}

//                                                       PORT READ Function
//                                                      --------------------

uint8 PORT_READ(uint8 port)                   // takes the port in variable port and returns the input data through a variable
{
	uint8 port_value = 0;                     // a variable to save the input data in it, setting it initially = 0
	switch(port)                              // checking the port value either 1,2,3,4
	{
		case A:                               // case of using port A
		port_value = READ_A;                  // xor the input with 0b11111111 where 0 xor 1 = 1, 1 xor 1 = 0
		break;                                // breaks case A
		
		case B:                               // case of using port B
		port_value = READ_B;                  // xor the input with 0b11111111 where 0 xor 1 = 1, 1 xor 1 = 0
		break;                                // breaks case B
		
		case C:                               // case of using port C
		port_value = READ_C;                  // xor the input with 0b11111111 where 0 xor 1 = 1, 1 xor 1 = 0
		break;                                // breaks case C
		
		case D:                               // case of using port D
		port_value = READ_D;                  // xor the input with 0b11111111 where 0 xor 1 = 1, 1 xor 1 = 0
		break;                                // breaks case D
		
	}
}

//                                              PORT_PULL_UP Resistance Function(used when pin is input ONLY)
//                                             ---------------------------------------------------------------
void  PORT_PULL_UP(uint8 pin,uint8 mode)      // takes the values of the port
{
	uint8 port = pin/10;
	switch(mode)                              // checking the value of mode to enter either output or input
	{
		case ENABLE:                          // in case of Enabling the pull up resistance circuit
		switch(port)                          // checking the port value either 1,2,3,4
		{
			case A:                           // case of using port A
			WRITE_A ^= 0xff;                  // xor the input with 0b11111111 where 0 xor 1 = 1, 1 xor 1 = 0
			break;                            // breaks case A
			
			case B:                           // case of using port B
			WRITE_B ^= 0xff;                  // xor the input with 0b11111111 where 0 xor 1 = 1, 1 xor 1 = 0
			break;                            // breaks case B
			
			case C:                           // case of using port C
			WRITE_C ^= 0xff;                  // xor the input with 0b11111111 where 0 xor 1 = 1, 1 xor 1 = 0
			break;                            // breaks case C
			
			case D:                           // case of using port D
			WRITE_D ^= 0xff;                  // xor the input with 0b11111111 where 0 xor 1 = 1, 1 xor 1 = 0
			break;                            // breaks the 4th case
		}
		break;                                // ends the enable case
		
		case DISABLE:                         // in case of disabling the pull up resistance circuit
		switch(port)                          // checking the port value either 1,2,3,4
		{
			case A:                           // case of using port A
			WRITE_A ^= 0x00;                  // xor the input with 0b11111111 where 0 xor 1 = 1, 1 xor 1 = 0
			break;                            // breaks case A
			
			case B:                           // case of using port B
			WRITE_B ^= 0x00;                  // xor the input with 0b11111111 where 0 xor 1 = 1, 1 xor 1 = 0
			break;                            // breaks case B
			
			case C:                           // case of using port C
			WRITE_C ^= 0x00;                  // xor the input with 0b11111111 where 0 xor 1 = 1, 1 xor 1 = 0
			break;                            // breaks case C
			
			case D:                           // case of using port D
			WRITE_D ^= 0x00;                  // xor the input with 0b11111111 where 0 xor 1 = 1, 1 xor 1 = 0
			break;                            // breaks case D
		}
		break;                                // ends the disable case
	}
}