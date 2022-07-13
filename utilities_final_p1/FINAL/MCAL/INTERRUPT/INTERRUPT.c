/*
 * INTERRUPT.c
 *
 * Created: 3/9/2022 8:40:07 PM
 *  Author: youss
 */ 



#include "INTERRUPT.h"
void ENABLE_INT0(uint8 MODE)
{
	SET_BIT(S_REG,I);
	SET_BIT(GIC_REG,INT0_PIN);
	PIN_MODE(INT0_DIO_PIN,INPUT);
	INT_MODE(INT_0,MODE);
}
void ENABLE_INT1(uint8 MODE)
{
	SET_BIT(S_REG,I);
	SET_BIT(GIC_REG,INT1_PIN);
	PIN_MODE(INT1_DIO_PIN,INPUT);
	INT_MODE(INT_1,MODE);
}
void ENABLE_INT2(uint8 MODE)
{
	SET_BIT(S_REG,I);
	SET_BIT(GIC_REG,INT2_PIN);
	PIN_MODE(INT2_DIO_PIN,INPUT);
	INT_MODE(INT_2,MODE);
}
void INT_MODE(uint8 INT_X,uint8 MODE)
{
	switch(INT_X)
	{
		case INT_0:
		switch(MODE)
		{
			case LOW_LEVEL_MODE:
			CLR_BIT(MCUC_REG,ISC00);
			CLR_BIT(MCUC_REG,ISC01);
			break;
			/****************************/
			case ANY_CHANGE_MODE:
			SET_BIT(MCUC_REG,ISC00);
			CLR_BIT(MCUC_REG,ISC01);
			break;
			/****************************/
			case FALLING_EDGE_MODE:
			CLR_BIT(MCUC_REG,ISC00);
			SET_BIT(MCUC_REG,ISC01);
			break;
			/**************************/
			case RISING_EDGE_MODE:
			SET_BIT(MCUC_REG,ISC00);
			SET_BIT(MCUC_REG,ISC01);
			break;
		}
		break;
		case INT_1:
		switch(MODE)
		{
			case LOW_LEVEL_MODE:
			CLR_BIT(MCUC_REG,ISC10);
			CLR_BIT(MCUC_REG,ISC11);
			break;
			/****************************/
			case ANY_CHANGE_MODE:
			SET_BIT(MCUC_REG,ISC10);
			CLR_BIT(MCUC_REG,ISC11);
			break;
			/****************************/
			case FALLING_EDGE_MODE:
			CLR_BIT(MCUC_REG,ISC10);
			SET_BIT(MCUC_REG,ISC11);
			break;
			/**************************/
			case RISING_EDGE_MODE:
			SET_BIT(MCUC_REG,ISC10);
			SET_BIT(MCUC_REG,ISC11);
			break;
		}
		break;
		case INT_2:
		switch(MODE)
		{
			case LOW_LEVEL_MODE:
			case ANY_CHANGE_MODE:
			case FALLING_EDGE_MODE:
			CLR_BIT(MCUCS_REG,ISC2);
			break;
			/**************************/
			case RISING_EDGE_MODE:
			SET_BIT(MCUCS_REG,ISC2);
			break;
		}
		break;
	}
}
void INT_SELECT(uint8 INT_X,uint8 MODE)
{
	switch(INT_X)
	{
		case 0:
		ENABLE_INT0(MODE);
		break;
		case 1:
		ENABLE_INT1(MODE);
		break;
		case 2:
		ENABLE_INT2(MODE);
		break;
	}
}
void DISABLE_INT()
{
	CLR_BIT(S_REG,I);
}
void DISABLE_INT0()
{
	CLR_BIT(GIC_REG,INT0_PIN);
}
void DISABLE_INT1()
{
	CLR_BIT(GIC_REG,INT1_PIN);
}
void DISABLE_INT2()
{
	CLR_BIT(GIC_REG,INT2_PIN);
}