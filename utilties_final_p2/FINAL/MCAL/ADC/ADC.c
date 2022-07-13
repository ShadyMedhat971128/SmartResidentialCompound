/*
 * ADC.c
 *
 * Created: 3/9/2022 8:44:27 PM
 *  Author: youss
 */ 


#include "BIT_MATH.h"
#include "ATmega32_Register.h"
#include "ADC.h"
void ADC_INIT(void)
{
	CLR_BIT(DDRA_REG,0);
	/* to select AVCC in VREF (5V) */
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
	
	/* to select channel 0 */
	CLR_BIT(ADMUX,0);
	CLR_BIT(ADMUX,1);
	CLR_BIT(ADMUX,2);
	CLR_BIT(ADMUX,3);
	CLR_BIT(ADMUX,4);
	
	/* PRESCALER 1/128 */
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	
	/* ADC CONTROL */
	SET_BIT(ADCSRA,7); // ADC ENABLE
	SET_BIT(ADCSRA,5);  // AUTO TRIGGER
	
}

uint16 ADC_READ(void)
{
	SET_BIT(ADCSRA,6);  // START CONVERSION
	while(BIT_IS_CLEAR(ADCSRA,4))
	{
		
	}
	return ADC_VALUE;

}