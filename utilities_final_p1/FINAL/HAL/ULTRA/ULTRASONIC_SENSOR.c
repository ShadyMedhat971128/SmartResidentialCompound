/*
 * ULTRASONIC_SENSOR.c
 *
 * Created: 3/9/2022 8:36:16 PM
 *  Author: youss
 */ 


#include "ULTRASONIC_SENSOR.h"
#include "BUZZER.h"
uint8_t sensor_working=0;
uint8_t rising_edge=0;
uint32_t timer_counter=0;
uint32_t distance;
uint8_t distance_str[10];

uint32 get_US_distance()
{
	return distance;
}


void enable_ex_interrupt(void){

ENABLE_INT1(ANY_CHANGE_MODE);
/*
	MCUC_REG |= (1<<ISC10);		// Trigger INT1 on any logic change.
	GIC_REG  |= (1<<INT1);			// Enable INT1 interrupts.
*/
	return;
}



ISR(INT1_vect){
	if(sensor_working==1){
		if(rising_edge==0){
			TCNT0=0x00;
			rising_edge=1;
			timer_counter=0;
		}
		else{// falling edge
			
			//LCD_CLEAR();
			//LCD_DISPLAY("hello");
			distance=(timer_counter*256+TCNT0)/(932.94);
			//distance=(timer_counter*256+TCNT0)/466;
			
			//LCD_GO_TO(2,0);
			//itoa(distance,distance_str,10);
			//strcat(distance_str, " cm ");
			//LCD_DISPLAY_INT(distance);
			//LCD_DISPLAY("cm");
			//LCD_DISPLAY(distance_str);
			
			
			
			_delay_ms(40);
			timer_counter=0;
			rising_edge=0;
			sensor_working=0;
		}
	}}
ISR(TIMER0_OVF_vect){
		timer_counter++;
		if(timer_counter >730){
			TCNT0=0x00;
			sensor_working=0;
			rising_edge=0;
			timer_counter=0;
		}
	}
void timer0_init(void)
{
	/* Disable Timer 0 */
	TCCR0 = DISABLE_MODULE_VALUE;
	/* Setting pre scaler */
	TCCR0 = (PRESCLR1_VALUE);
	/* Initializing the timer with zero */
	TCNT0 = ZER0_INITIALIZER;
	/* Timer overflow interrupt enable*/
	TIMSK |=(1<<TOIE0);

	return;
}
void ULTRASONIC_INIT()
{
	
	PIN_MODE(TRIGER,OUTPUT);
	PIN_MODE(ECHO,INPUT);
	PIN_PULL_UP(ECHO,ON);
	enable_ex_interrupt();
	timer0_init();
	return;
	}

void ULTRASONIC_TRIG_PULSE()
{
	if(!sensor_working)
	{
	PIN_WRITE(TRIGER,HIGH);
	_delay_ms(30);
	PIN_WRITE(TRIGER,LOW);
	sensor_working=1;	
	}
	
}
/*float64 ULTRASONIC_DISTANCE()
{
	uint32 ULTRASONIC_TIMER_READING =0;
	float32	DISTANCE =0;
	TCNT1 = 0;	/* Clear Timer counter */
	

	/*Calculate width of Echo by Input Capture (ICP) */
	/*
	while ((TIFR & (1 << ICF1)) == 0);/* Wait for rising edge */
	//TCNT1 = 0;	/* Clear Timer counter */
//	TCCR1B = 0x01;	/* Capture on falling edge, No prescaler */
	//TIFR = 1<<ICF1;	/* Clear ICP flag (Input Capture flag) */
	//TIFR = 1<<TOV1;	/* Clear Timer Overflow flag */
	//OVER_FLOW_COUNTER = 0;/* Clear Timer overflow count */

//	while ((TIFR & (1 << ICF1)) == 0);/* Wait for falling edge */
//	ULTRASONIC_TIMER_READING = ICR1 + (65535 * OVER_FLOW_COUNTER);	/* Take count */
	/* 8MHz Timer freq, sound speed =343 m/s */
//	DISTANCE = ((double)ULTRASONIC_TIMER_READING*344 )/ (F_CPU*2);
//	return DISTANCE ;
	
/*
void ULTRASONIC_TIMER_RESET()
{
	TIMER1_COUNTER=0;
	OVER_FLOW_COUNTER=0;
}*/
/*
ISR(TIMER1_OVF_vect)
{
	OVER_FLOW_COUNTER++;
}*/
/*
ISR(INT0_vect)
{
	static uint8 key;
	key =ON;
	//TIMER_1_REG = ULTRASONIC0_TIMER_READING;
}*/