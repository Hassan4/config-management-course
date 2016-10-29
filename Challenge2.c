/*
 * Challenge2.c
 *
 * Created: 1/22/2014 6:15:47 PM
 *  Author: Mohamed Tarek
 */ 

#ifndef F_CPU
#define F_CPU 8000000UL // or whatever may be your frequency
#endif

#include <avr/io.h>
#include <util/delay.h>

void Timer0_PWM_Init(unsigned char set_duty_cycle){
	
	TCNT0 = 0; // Timer intial value
	
	/*Fast PWM mode with non inverted mode OC0 clear when compare match using prefcalar F_CPU/8 */
	/* configure the timer
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match (inverted mode) COM00=0 & COM01=1 
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */ 
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
	
	OCR0  = set_duty_cycle; 
	
	DDRB  = DDRB | (1<<PB3); //set OC0 as output pin --> pin where the PWM signal is generated from MC.
}
int main(void)
{
    Timer0_PWM_Init(128); //50% duty cycle
	
	while(1)
	{
		
	}
}