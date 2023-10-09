 /*	______________________________________________________________________________
   |																			  |
   | Layer : APP																  |
   |																			  |
   | File Name: app.c															  |
   |																			  |
   | Description: Source file of the main application							  |
   |																			  |
   | Author: Youssif Hossam														  |
   |______________________________________________________________________________|
   */


#include "HAL/LCD/lcd.h"
#include "HAL/HC-SR04/hr_sr04.h"
#include "LIB/std_types.h"
#include <avr/io.h>

int main (void){

	uint16 distance = 0;

	/* Enabling the global interrupt service */
	SREG |= (1<<7);

	LCD_init();

	Ultrasonic_init();

	LCD_displayString("Distance= ");

	while(1){

		distance = Ultrasonic_readDistance();

		LCD_moveCursor(0,10);

		LCD_intgerToString(distance);

		if(distance < 10 )
			LCD_displayString("  ");
		else if (distance < 100)
			LCD_displayString(" ");

		LCD_displayString(" cm");

	}
	return 0;
}
