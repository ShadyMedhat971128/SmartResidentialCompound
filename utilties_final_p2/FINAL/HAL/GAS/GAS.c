/*
 * GAS.c
 *
 * Created: 3/9/2022 8:34:19 PM
 *  Author: youss
 */ 


#include "ADC.h"
#include "GAS.h"
#include "GAS_CFG.h"
#define  F_CPU 16000000UL
#include "util/delay.h"

float32 LPG_CURVE[3]={2.3,0.20,-0.45};
float32 SMOKE_CURVE[3]={2.3,0.53,-0.43};


#define RO_CLEAN_AIR 9.83
#define LPG 0
#define SMOKE 1
float32 RL=10;


//float GAS_INIT(void);
float SENSOR_CALIB(void)            // takes the first initial value for the R out of the air
{
	int i;                                   // This function assumes that sensor is in clean air.
	float val=0;
	
	for (i=0;i<50;i++)
	{
		//take multiple samples and calculate the average value
		val += RESIST_CALCU(ADC_READ());
	}
	
	val = val/50;
	val = val/RO_CLEAN_AIR;           //divided by RO_CLEAN_AIR_FACTOR yields the Ro according to the chart in the datasheet
	return val;
}

float RESIST_CALCU(uint8 raw_adc)              // Calculates the R of the
{
	return ( ((float)RL*(1023-raw_adc)/raw_adc));  
}

float GAS_READ(void)
{
	int i;
	float rs=0;

	for (i=0;i<5;i++)
	{                                 // take multiple readings and average it.
		rs += RESIST_CALCU(ADC_READ());   // rs changes according to gas concentration.
		_delay_ms(50);
	}

	rs = rs/5;
	

	
	return rs;
}

int   GAS_PERCENT(float32 ratio,uint8 gas_id)
{
	if ( gas_id == LPG )
	{
		return PERCENTAGE(ratio,LPG_CURVE);
	}
	else if( gas_id == SMOKE )
	{
		return PERCENTAGE(ratio,SMOKE_CURVE);
	}

	return 0;
}

int   PERCENTAGE(float32 ratio, float32*curve)
{
	//return (pow(10,( ((log(ratio)-curve[1])/curve[2]) + curve[0])));
	float x = (((log(ratio)-curve[1])/curve[2])+curve[0]);
	float y= pow(10,x);
	return y;
}

//Using slope,ratio(y2) and another point(x1,y1) on line we will find
// gas concentration(x2) using x2 = [((y2-y1)/slope)+x1]
// as in curves are on logarithmic coordinate, power of 10 is taken to convert result to non-logarithmic.
