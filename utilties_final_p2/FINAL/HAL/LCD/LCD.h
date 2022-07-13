/*
 * LCD.h
 *
 * Created: 3/9/2022 8:29:34 PM
 *  Author: youss
 */ 


#ifndef LCD_H_
#define LCD_H_


/**************BASIC_LIBS**************/
#include "LCD_CFG.h"
#include "ATmega32_Register.h"
#include "STD_TYPES.h"
#define F_CPU 16000000UL
#include <util/delay.h>
#include "DIO.h"
/**************PROTOTYPES**************/
/**************4BIT_MODE**************/
void LCD_INIT_4BIT			(void);
void LCD_SEND_CHAR_4BIT_MODE(uint8 character );
void LCD_COMMAND			(uint8 command);
void LCD_DISPLAY_INT		(uint32 number);
void LCD_DISPLAY_CHAR		(uint8 character);
void LCD_DISPLAY			(uint8* statment );
void LCD_GO_TO				(uint8 row,uint8 column);
void LCD_CLEAR				(void);
void LCD_floatToString		(float data);
/**************8BIT_MODE**************/
void LCD_INIT_8BIT();
void LCD_SEND_CHAR_8BIT_MODE(uint8 character );
/******************HELPING_MACROS***************/
#define LCD_ENABLE_ON			PIN_WRITE(LCD_ENABLE_PIN,HIGH)
#define LCD_ENABLE_OFF			PIN_WRITE(LCD_ENABLE_PIN,LOW)

//#define high_word(character)	((character&(0XF0))|(PORTA_REG & (0X0F)))//(character&(0XF0));
//#define low_word(character)		(((character<<4))|(PORTA_REG & (0X0F)))  // to insert the low 4 bits in the high 4 bits of the port
/************************************************************************/
/* for ETA32 mini kit #AHMED_WAEL                                                                      */
#define high_word(character)	(((character>>1)&(0b01111000))|(PORT_A & (0b00000111)))//(character&(0XF0));
#define low_word(character)		(((character<<3)&(0b01111000))|(PORT_A & (0b00000111)))  // to insert the low 4 bits in the high 4 bits of the port#define _4_BIT_MODE         0





#endif /* LCD_H_ */