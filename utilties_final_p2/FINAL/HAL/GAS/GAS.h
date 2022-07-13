/*
 * GAS.h
 *
 * Created: 3/9/2022 8:34:31 PM
 *  Author: youss
 */ 


#ifndef GAS_H_
#define GAS_H_

float GAS_INIT(void);
float SENSOR_CALIB(void);            // takes the first initial value for the R out of the air
float RESIST_CALCU(uint8);              // Calculates the R of the
float GAS_READ(void);
int   GAS_PERCENT(float32,uint8);
int   PERCENTAGE(float32, float32*);



#endif /* GAS_H_ */