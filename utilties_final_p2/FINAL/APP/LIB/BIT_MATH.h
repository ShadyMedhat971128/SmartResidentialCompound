/*
 * BIT_MATH.h
 *
 * Created: 3/9/2022 8:27:34 PM
 *  Author: youss
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(reg,bit)   (reg |= (1<<bit))   // setting assigned bit to be 1 --> OUTPUT
#define CLR_BIT(reg,bit)   (reg &= ~(1<<bit))  // setting assigned bit to be 0 --> INPUT
#define TOG_BIT(reg,bit)   (reg ^= (1<<bit))   // converts the bit 1 --> 0 or 0 --> 1
#define GET_BIT(REG,BIT)   ((REG >> BIT)&1)    // to know if the pin is INPUT or OUTPUT
#define BIT_IS_CLEAR(reg,bit)	(!((1<<bit)&(reg)))


#endif /* BIT_MATH_H_ */