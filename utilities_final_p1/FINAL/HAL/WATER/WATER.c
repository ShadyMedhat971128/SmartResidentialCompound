/*
 * WATER.c
 *
 * Created: 3/10/2022 1:34:58 PM
 *  Author: youss
 */ 



#include "WATER.h"
#include "BUZZER.h"

uint8_t water_sensor_working=0;
uint8_t water_rising_edge=1;
uint32_t water_timer_counter=0;
uint32_t time;
double Water_flow;
uint8_t distance_str[10];


/*

void enable_ex_interrupt(void){

	MCUC_REG |= (1<<ISC10);		// Trigger INT1 on any logic change.
	GIC_REG  |= (1<<INT1);			// Enable INT1 interrupts.

	return;
}*/

/*

ISR(INT2_vect){
	if(water_rising_edge==1){
		
			TCNT2=0x00;
			water_rising_edge=0;
			water_timer_counter=0;
	}
	else
	{
		
	
	
			//LCD_CLEAR();
			//LCD_DISPLAY("hello");
			time=(water_timer_counter*256+TCNT2);
			Water_flow= 16000000/(time*5.5);
			
			
			LCD_GO_TO(2,0);
			//itoa(distance,distance_str,10);
			//strcat(distance_str, " cm ");
			LCD_floatToString(Water_flow);
			//LCD_DISPLAY("cm");
			
			
			_delay_ms(40);
			water_timer_counter=0;
			water_rising_edge=1;
			
		}
	}
	ISR(TIMER2_OVF_vect){
	
			water_timer_counter++;
			if(water_timer_counter >300){
				TCNT2=0x00;
				
				water_rising_edge=1;
				water_timer_counter=0;
			}
			
		
	}
	void timer2_init(void)
	{
		
		TCCR2 = DISABLE_MODULE_VALUE; // Disable Timer 2
		
		TCCR2 = (PRESCLR1_VALUE);     // Setting Pre scaler
		
		TCNT2 = ZER0_INITIALIZER;     // Initializing the timer with zero
		
		TIMSK |=(1<<TOIE2);           //Timer overflow interrupt enable

		return;
	}
	
	void WATER_INIT()
	{
		ENABLE_INT2(RISING_EDGE_MODE);  
		PIN_MODE(ECHO,INPUT);
		//PIN_PULL_UP(ECHO,ON);
		//enable_ex_interrupt();
		timer2_init();
	}
	*/