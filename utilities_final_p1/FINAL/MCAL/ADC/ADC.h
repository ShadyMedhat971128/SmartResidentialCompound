/*
 * ADC.h
 *
 * Created: 3/9/2022 8:44:38 PM
 *  Author: youss
 */ 


#ifndef ADC_H_
#define ADC_H_


#include "STD_TYPES.h"
/*
#define AVCC               0
#define AREF               1
#define _2V                2

#define RIGHT              0
#define LEFT               1

#define DISABLE            0
#define ENABLE             1

#define _64                0
#define _128               1

#define ADC_CHANNEL_0      0
#define ADC_CHANNEL_1      1
#define ADC_CHANNEL_2      2
#define ADC_CHANNEL_3      3
#define ADC_CHANNEL_4      4
#define ADC_CHANNEL_5      5
#define ADC_CHANNEL_6      6
#define ADC_CHANNEL_7      7*/


void      ADC_INIT(void);    // to initialize the ADC
uint16       ADC_READ(void);      // takes the pin number that will take the reading
// and returns the converted readings from the ADC



#endif /* ADC_H_ */