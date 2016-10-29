/*
 * Exercise7.c
 *
 * Created: 4/3/2014 6:00:08 PM
 *  Author: Mohamed Tarek
 */ 

#include "lcd.h"

int main(void)
{
	LCD_init(); /* initialize LCD */
	LCD_displayStringRowColumn(0,2,"My LCD Driver");
	LCD_displayStringRowColumn(1,3,"Embedded WS");
	_delay_ms(2000); /* wait two seconds */
	
	LCD_clearScreen(); /* clear the LCD display */ 
	LCD_displayString("Interf. Course");
	LCD_intgerToString(10);
	
    while(1)
    {
		/* Note: we write the code before while(1) because we want to execute it only once */
    }
	
}