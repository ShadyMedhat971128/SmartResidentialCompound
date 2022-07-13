/*
 * LCD.c
 *
 * Created: 3/9/2022 8:29:18 PM
 *  Author: youss
 */ 


#include "LCD_CFG.h"
#include "DIO.h"
#include "LCD.h"
#define  F_CPU 16000000UL
#include "util/delay.h"
#include "STD_TYPES.h"


void LCD_INIT_4BIT(void)
{
	PIN_MODE(LCD_D4_PIN,OUTPUT);
	PIN_MODE(LCD_D5_PIN,OUTPUT);
	PIN_MODE(LCD_D6_PIN,OUTPUT);
	PIN_MODE(LCD_D7_PIN,OUTPUT);
	PIN_MODE(LCD_ENABLE_PIN,OUTPUT);
	PIN_MODE(LCD_SELECTOR_PIN,OUTPUT);
	PIN_MODE(LCD_WRITE_PIN,OUTPUT);
	_delay_ms(100);
	// we have to send these 3 commands to initialization 4-bit MODE
	LCD_COMMAND(0X33);
	LCD_COMMAND(0X32);
	LCD_COMMAND(TWO_LINE_4BIT_MODE);
	
	// the following commands to start the LCD
	LCD_COMMAND(DISPLAY_ON_CURSOR_OFF);
	LCD_CLEAR();
	LCD_COMMAND (CURSOR_INCREMENT);
	LCD_COMMAND (RETURN_HOME);
	
}
void LCD_SEND_CHAR_4BIT_MODE(uint8 character )
{
	//send the high part
	PORT_WRITE(LCD_PORT, high_word(character));
	LCD_ENABLE_ON;
	_delay_ms(1);
	LCD_ENABLE_OFF;
	// send the low part
	PORT_WRITE(LCD_PORT, low_word(character));
	LCD_ENABLE_ON;
	_delay_ms(1);
	LCD_ENABLE_OFF;
	_delay_ms(5);
	
}
void LCD_COMMAND (uint8 command)
{
	LCD_ENABLE_OFF;
	PIN_WRITE(LCD_SELECTOR_PIN,SELECT_COMMAND);
	LCD_SEND_CHAR_4BIT_MODE (command);
	
}
void LCD_DISPLAY_CHAR (uint8 character)
{
	LCD_ENABLE_OFF;
	PIN_WRITE(LCD_SELECTOR_PIN,SELECT_DATA);
	LCD_SEND_CHAR_4BIT_MODE (character);	
}
void LCD_CLEAR()
{
	LCD_COMMAND(CLEAR_SCREEN);
}
void LCD_DISPLAY_INT(uint32 number)
{
	uint8 unit = number % 10;
	uint32 tenth = number /10;
	if(tenth!=0)
	{
		LCD_DISPLAY_INT(tenth);
	}
	LCD_DISPLAY_CHAR(unit+48);
}
void LCD_DISPLAY(uint8* statment)
{
	for(uint32 i=0;statment[i]!= '\0';i++)
	{
		LCD_DISPLAY_CHAR(statment[i]);
	}
	_delay_ms(10);
}
void LCD_GO_TO (uint8 row,uint8 column)
{
	switch(row)
	{
		case 2:
		LCD_COMMAND((CURSOR_GO_TO_ORIGIN_SECOND|column));
		break;
		case 1:
		default:
		LCD_COMMAND((CURSOR_GO_TO_ORIGIN_FIRST|column));
		break;
		
	}
}
/********************for 8-bit mode*********************************/
/*void LCD_INIT_8BIT(void)
{
	PORT_MODE(LCD_PORT,HIGH)
	PIN_MODE(LCD_ENABLE_PIN,OUTPUT);
	PIN_MODE(LCD_SELECTOR_PIN,OUTPUT);
	PIN_MODE(LCD_WRITE_PIN,OUTPUT);
	_delay_ms(100);
	// we have to send these 3 commands to initialization 4-bit MODE
	//LCD_COMMAND(0X33);
	//LCD_COMMAND(0X32);
	LCD_COMMAND(TWO_LINE_8BIT_MODE);
	
	// the following commands to start the LCD
	LCD_COMMAND(DISPLAY_ON_CURSOR_OFF);
	LCD_CLEAR();
	LCD_COMMAND (CURSOR_INCREMENT);
	LCD_COMMAND (RETURN_HOME);
	
}*/
void LCD_floatToString(float data) // from 500 to "500"
{
	char buff[16]; /* String to hold the ascii result */
	dtostrf(data,6,2,buff); /* 10 for decimal */
	LCD_DISPLAY(buff);
}