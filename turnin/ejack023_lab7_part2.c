/*	Author: ejack023
 *	Lab Section: 023
 *	Assignment: Lab #7  Exercise #2
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *	Demo Link: https://www.youtube.com/watch?v=TkIg5K_rw2M&ab_channel=EthanJackson
 *	        */

#include <avr/io.h>
#include <avr/interrupt.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned short val = 0x0000;
unsigned char B = 0x00;
unsigned char D = 0x00;

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void)
{
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	ADC_init();
	while(1) {
		val = ADC;
		B = (unsigned char)val;
		D = (unsigned char)(val >> 4);
		PORTB = B;
		PORTD = D;
	}
}
