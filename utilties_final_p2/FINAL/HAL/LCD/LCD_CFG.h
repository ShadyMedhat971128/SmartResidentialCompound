/*
 * LCD_CFG.h
 *
 * Created: 3/9/2022 8:29:52 PM
 *  Author: youss
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

/******************DEFINE_LCD***************/
// ETA 32

#define LCD_ENABLE_PIN		PA2			// if 0 =>lcd doesn't work
#define LCD_WRITE_PIN		PC2			//RW: 1=> write on LCD` ,0=> read from LCD
#define LCD_SELECTOR_PIN	PA1			//RS:register selector

#define LCD_PORT			 A

#define LCD_D4_PIN			PA3
#define LCD_D5_PIN			PA4
#define LCD_D6_PIN			PA5
#define LCD_D7_PIN			PA6

//AMIT kit
/*
#define LCD_ENABLE_PIN		PB3 // if 0 =>lcd doesn't work
#define LCD_WRITE_PIN		PB2 //RW: 1=> write on LCD` ,0=> read from LCD
#define LCD_SELECTOR_PIN	PB1	//RS:register selector

#define LCD_PORT			 A

#define LCD_D4_PIN			PA4
#define LCD_D5_PIN			PA5
#define LCD_D6_PIN			PA6
#define LCD_D7_PIN			PA7
*/
/******************EXTRA_MACROS***************/

#define SELECT_DATA		1
#define SELECT_COMMAND	0	// PIN_WRITE(LCD_SELECTOR,SELECT_DATA);
#define WRITE			1
/******************COMMANDS*****************/

#define CLEAR_SCREEN				0X01 //important
#define RETURN_HOME					0X02 //important
#define CURSOR_DECREMENT			0X04//(shift cursor to left)
#define DISPLAY_SHIFT_TO_RIGHT		0X05
#define CURSOR_INCREMENT			0X06//important (shift cursor to right) // write from left to right
#define	DISPLAY_SHIFT_TO_LEFT		0X07
#define CURSOR_AND_DISPLAY_OFF		0X08
#define CURSOR_POS_SHIFT_TO_LEFT	0X10
#define CURSOR_POS_SHIFT_TO_RIGHT	0X14
#define	DISPLAY_OFF_CURSOR_ON		0X0A
#define	DISPLAY_ON_CURSOR_OFF		0X0C // important
#define DISPLAY_ON_CURSOR_BLINK		0X0E
#define TWO_LINE_8BIT_MODE			0X38
#define	TWO_LINE_4BIT_MODE			0X28
#define ONE_LINE_8BIT_MODE			0X30
#define	ONE_LINE_4BIT_MODE			0X20
#define DISPLAY_DATA_CURSOR_BLINK	0X0F
#define SHIFT_DISPLAY_TO_LEFT_SIDE	0X18
#define SHIFT_DISPLAY_TO_RIGHT_SIDE	0X1C
#define CURSOR_GO_TO_ORIGIN_FIRST	0X80 // to go to the 2nd place in first row 0X81
#define CURSOR_GO_TO_ORIGIN_SECOND	0XC0



#endif /* LCD_CFG_H_ */