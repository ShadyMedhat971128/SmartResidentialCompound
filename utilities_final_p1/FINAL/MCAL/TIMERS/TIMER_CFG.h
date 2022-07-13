/*
 * TIMER_CFG.h
 *
 * Created: 3/9/2022 8:42:42 PM
 *  Author: youss
 */ 


#ifndef TIMER_CFG_H_
#define TIMER_CFG_H_
/************************************************************************/
/*                         TIMSK_reg                                    */
/************************************************************************/
#define INPUT_CAPTURE_INTERRUPT_ENABLE_PIN	TICIE1	// in reg TIMSK
#define TIMER_1_OVERFLOW_INTR_ENABLE		TOIE1

/************************************************************************/
/*                                TCCR1B                                */
/************************************************************************/
#define FALLING_EDGE_ENABLE_PIN				ICES1	// in reg TCCR1B
#define FALLING_EDGE_MODE	0
#define	RISING_EDGE_MODE	1

#define TIMER1_COUNTER TCNT1




#endif /* TIMER_CFG_H_ */