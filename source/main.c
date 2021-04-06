/*	Author: rchan123
 *  	Partner(s) Name: 
 *	Lab Section: 023
 *	Assignment: Lab 2  Exercise 2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	/* Insert DDR and PORT initializations */
	DDRA = 0x00; 
	PORTA = 0x00; 
	DDRC = 0xFF;
	PORTC = 0x00;
	/* Insert your solution below */
	// unsigned char tmpB = 0x00;
	unsigned char tmpA = 0x00;
	unsigned char cntavail = 0x00;
	// unsigned char allfull = 0x00;
	while (1) {
		tmpA = PINA & 0x0F;
		cntavail = (1-((tmpA & 0x08) >> 3)) + (1-((tmpA & 0x04) >> 2)) + (1-((tmpA & 0x02) >> 1)) + (1-(tmpA & 0x01));
		PORTC = cntavail;
	}
	return 0;
}
