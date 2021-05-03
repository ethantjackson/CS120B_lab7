/*	Author: ejack023
 *	Lab Section: 023
 *	Assignment: Lab #7  Exercise #3
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *	Demo Link: https://www.youtube.com/watch?v=pqtxM1-UFfY&ab_channel=EthanJackson
 *	        */

#include <avr/io.h>
#include <avr/interrupt.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned short MAX_g = 985;
unsigned short val = 0x0000;
unsigned char B = 0x00;

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void)
{
	DDRB = 0xFF; PORTB = 0x00;
	ADC_init();
	while(1) {
		val = ADC;
		if (val < MAX_g/8) B=0x01;
		else if (val < 2*(MAX_g/8)) B=0x03;
		else if (val < 3*(MAX_g/8)) B=0x07;
		else if (val < 4*(MAX_g/8)) B=0x0F;
		else if (val < 5*(MAX_g/8)) B=0x1F;
		else if (val < 6*(MAX_g/8)) B=0x3F;
		else if (val < 7*(MAX_g/8)) B=0x7F;
		else B=0xFF;
		PORTB = B;
	}
}
