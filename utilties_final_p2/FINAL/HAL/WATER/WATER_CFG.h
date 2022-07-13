/*
 * WATER_CFG.h
 *
 * Created: 3/10/2022 1:36:05 PM
 *  Author: youss
 */ 


#ifndef WATER_CFG_H_
#define WATER_CFG_H_



#define   ECHO_DDR      DDRD
#define   ECHO		PB2

/************************************************************************/
/*                                                                      */
/************************************************************************/
#define FAST_PWM						        (1<<3)|(1<<6)
#define NON_INVERT						      (1<<5)
#define PRESCLR1_VALUE 		            0x01
#define PRESCLR8_VALUE 		            0x02
#define PRESCLR64_VALUE 	            0x03
#define PRESCLR256_VALUE 	            0x04
#define PRESCLR1024_VALUE 	          0x05
#define DISABLE_MODULE_VALUE 		      0x00
/* Timer DDR */
#define TIMER0_DDR						        DDRB
#define TIMER2_DDR					         	DDRD
/* to put in the PWM_init function */
#define TIMER_0                         0
#define TIMER_2                         2
/* Out compare pin */
#define OC0_OUTPUT_SETTER               3
#define OC2_OUTPUT_SETTER               7

#define ZER0_INITIALIZER                0x00
/* Max counts of timer0 is 2^8=255 */
#define TIMER_MAX_VALUE                 255
/* max Percentage Value (100%) */
#define DUTY_CYCLE_MAX_VALUE            100




#endif /* WATER_CFG_H_ */