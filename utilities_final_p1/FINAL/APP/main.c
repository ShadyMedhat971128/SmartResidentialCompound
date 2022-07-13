/*
 * FINAL.c
 *
 * Created: 3/9/2022 8:06:59 PM
 * Author : youss
 */ 

#include <avr/io.h>
#define  F_CPU 16000000UL
#include "util/delay.h"
#include "ADC.h"
#include "BUZZER.h"
#include "GAS.h"
#include "LCD.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ULTRASONIC_SENSOR.h"
#include "INTERRUPT.h"
#include "DIO.h"
#include "TIMER.h"
#include "ATmega32_Register.h"
#include "UART.h"
//#include "BOUNDARY_WATCH.h"

#define LPG 0
#define SMOKE 1

float32 x=10;
int GAS_MSG=0;
int ULTRA_MSG=0; 

void boundary_watch_init()
{
	LCD_INIT_4BIT();
	BUZZER_INIT();
	//LCD_INIT_4BIT();
	//BUZZER_ONCE_LONG();
	//LED_INIT(RIGHT_LED);
	PIN_MODE(PD2,INPUT);
	ENABLE_INT0(FALLING_EDGE_MODE);
}

int main(void)
{
	
    BUZZER_INIT();
	ADC_INIT();
	LCD_INIT_4BIT();
	ULTRASONIC_INIT();
	//WATER_INIT();
	boundary_watch_init();
	LCD_CLEAR();
	LCD_DISPLAY("LCD checked");

    while (1) 
    {
		 //----------------------//
		/**ULTRA SONIC SENSOR**/
	   //----------------------//
		ULTRASONIC_TRIG_PULSE();
		
		if(get_US_distance() < 3)
		{
			BUZZER_ON();
			if (ULTRA_MSG==0)
			{
				UART_INIT();
				_delay_ms(1000);
				//UART_TRANSMIT_STR("Sewage Problem*");
				UART_TRANSMIT_STR("s*");
				_delay_ms(500);
				LCD_CLEAR();
				LCD_DISPLAY("Sewage Problem");
				
				_delay_ms(500);
				LCD_CLEAR();
				ULTRA_MSG=1;
			}
		}
			else if ( get_US_distance()>=4) 
			{
				BUZZER_OFF();
				if (ULTRA_MSG==1)
				{
					UART_INIT();
					_delay_ms(1000);
					//UART_TRANSMIT_STR("Sewage Problem Cleared*");
					UART_TRANSMIT_STR("c*");
					_delay_ms(500);
					LCD_CLEAR();
					LCD_DISPLAY("Sewage Problem ");
					LCD_GO_TO(2,5);
					LCD_DISPLAY("cleared");
					_delay_ms(500);
					LCD_CLEAR();
					ULTRA_MSG=0;
				}
			}
	
		
		/*
		else if (get_US_distance()>=20)
		{
			BUZZER_OFF();
			if (ULTRA_MSG==1)
			{
				LCD_DISPLAY("Sewage Problem CLEAR");
				_delay_ms(2000);
				LCD_CLEAR();
				ULTRA_MSG=0;
			}
		}*/
	
//-------------------------------------------------
		//-------------------------------------------------
		/*
	    GAS = GAS_READ();
		
		
		LCD_floatToString(GAS_PERCENT(GAS/x,LPG));
		_delay_ms(1000);
		LCD_CLEAR();
		*/
		
		 //----------------------//
		/*    GAS SENSOR    */
	   //----------------------//
		 
		 
		 
		 
			if (ADC_READ()>200)
			{
				if(ADC_READ()>300)
				{
					BUZZER_ON();
					if (GAS_MSG==0)
					{
						UART_INIT();
						_delay_ms(1000);
						//UART_TRANSMIT_STR("GAS leak*");
						UART_TRANSMIT_STR("g*");
						LCD_CLEAR();
						LCD_DISPLAY("GAS leak");
						_delay_ms(1000);
						LCD_CLEAR();
						GAS_MSG=1;
					}
					
					
					
					
				}
				
				else if (ADC_READ()<=200)
				{
					BUZZER_OFF();
					if (GAS_MSG==1)
					{
						UART_INIT();
						_delay_ms(1000);
						//UART_TRANSMIT_STR("GAS leakage problem cleared*");
						UART_TRANSMIT_STR("j*");
						
						LCD_CLEAR();
						LCD_DISPLAY("GAS CLEAR");
						_delay_ms(1000);
						LCD_CLEAR();
						GAS_MSG=0;
					}
					
					
				}
				
			}
		
    
		
				
			}
		
    }
	




ISR(INT0_vect)
{
	
	//key=1;
	UART_INIT();
	_delay_ms(1000);
	//UART_TRANSMIT_STR("break in detected !!!*");
	UART_TRANSMIT_STR("b*");
	_delay_ms(500);
	LCD_CLEAR();
	LCD_DISPLAY("break in detected !!!");
	_delay_ms(2000);
    
	BUZZER_ON();
	_delay_ms(2000); // edited time later
	BUZZER_OFF();
	
}