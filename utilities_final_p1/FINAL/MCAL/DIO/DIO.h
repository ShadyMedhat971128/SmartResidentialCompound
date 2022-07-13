/*
 * DIO.h
 *
 * Created: 3/9/2022 8:51:15 PM
 *  Author: youss
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "DIO_CFG.h"
#include "STD_TYPES.h"

//       PORT A Macros
//      ---------------
#define PA0      10
#define PA1      11
#define PA2      12
#define PA3      13
#define PA4      14
#define PA5      15
#define PA6      16
#define PA7      17

//       PORT B Macros
//      ---------------
#define PB0      20
#define PB1      21
#define PB2      22
#define PB3      23
#define PB4      24
#define PB5      25
#define PB6      26
#define PB7      27

//       PORT C Macros
//      ---------------
#define PC0      30
#define PC1      31
#define PC2      32
#define PC3      33
#define PC4      34
#define PC5      35
#define PC6      36
#define PC7      37

//       PORT D Macros
//      ---------------
#define PD0      40
#define PD1      41
#define PD2      42
#define PD3      43
#define PD4      44
#define PD5      45
#define PD6      46
#define PD7      47

//       PORTS  Macros
//      ---------------
#define A        1
#define B        2
#define C        3
#define D        4

//       Control Macros
//      ----------------
#define INPUT    0
#define OUTPUT   1

#define LOW      0
#define HIGH     1

#define DISABLE  0
#define ENABLE   1

//         Prototypes
//        ------------
void  PIN_MODE     (uint8,uint8);   // to make the pin be input --> 0 or output --> 1
void  PIN_WRITE    (uint8,uint8);   // to make the pin either LOW --> 0 or HIGH --> 1
void  PIN_TOG      (uint8);         // to toggle the pin as if it is 0 --> 1 and vise versa
uint8 PIN_READ     (uint8);         // reads the input data on that pin (in case of input)
void  PIN_PULL_UP  (uint8,uint8);   // turn on the pull up resistance connection inside the micro controller to the assigned pin

void  PORT_MODE    (uint8,uint8);   // to make the all the pins in the chosen port be input --> 0 or output --> 1
void  PORT_WRITE   (uint8,uint8);   // to make all the pins in the chosen port either LOW --> 0 or HIGH --> 1
void  PORT_TOG     (uint8);         // to toggle all the pins in the chosen port as if it is 0 --> 1 and vise versa
uint8 PORT_READ    (uint8);         // reads the input data on from all the pins in the chosen port (in case of input)
void  PORT_PULL_UP (uint8,uint8);   // turn on the pull up resistance connection inside the micro controller in the chosen port






#endif /* DIO_H_ */