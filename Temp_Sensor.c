/*
 * Temp_Sensor.c
 *
 * Created: 24/04/2014 02:55:48 م
 *  Author: Mohamed Tarek
 */ 

#include "ADC.h"
#include "LCD.h"

int main(void)
{
	uint32 temp;
	LCD_init(); /* initialize LCD driver */
	ADC_init(); /* initialize ADC driver */
	LCD_clearScreen(); /* clear LCD at the beginning */
	/* display this string "Temp =    " only once at LCD */
	LCD_displayString("Temp = ");
	LCD_goToRowColumn(0,10);
	LCD_displayCharacter('C');
    while(1)
    {
		LCD_goToRowColumn(0,7); /* display the number every time at this position */
		temp = ADC_read(0); /* read channel zero where the temp sensor is connect */
		temp = (temp*150*5)/(1023*1.5); /* calculate the temp from the ADC value*/
		LCD_intgerToString(temp); /* display the temp on LCD screen */
    }
}