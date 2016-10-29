/*
 * Exercise5.c
 *
 * Created: 11/23/2013 1:36:59 AM
 * Author: Mohamed Tarek
 */

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

int main(void)
{
	/* configure pin PA0, PA1 and PA2 as input pins */ 
	CLEAR_BIT(DDRA,PA0); 
	CLEAR_BIT(DDRA,PA1);
	CLEAR_BIT(DDRA,PA2);
	
	/* configure pin PC0 and PC1 as output pins */
	SET_BIT(DDRC,PC0);
	SET_BIT(DDRC,PC1); 
	
	/* Motor is stop at the beginning */
	CLEAR_BIT(PORTC,PC0);
	CLEAR_BIT(PORTC,PC1);
	 
    while(1)
    {
		/* check if the first switch is pressed (Rotate clock wise) */
		if(BIT_IS_SET(PINA,PA0))
		{
			CLEAR_BIT(PORTC,PC0);
			SET_BIT(PORTC,PC1);
		}
		
		/* check if the second switch is pressed (Rotate anti-clock wise) */
		else if(BIT_IS_SET(PINA,PA1))
		{
			SET_BIT(PORTC,PC0);
			CLEAR_BIT(PORTC,PC1);	
		}
				
		/* check if the third switch is pressed (turn off the motor) */
		else if(BIT_IS_SET(PINA,PA2))
		{
			CLEAR_BIT(PORTC,PC0);
			CLEAR_BIT(PORTC,PC1);
		}				    
    }
}