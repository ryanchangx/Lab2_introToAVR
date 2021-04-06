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
	DDRA = 0x00; PORTA = 0x00;
	DDRB = 0x00; PORTB = 0x00; 
	DDRC = 0x00; PORTC = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	/* Insert your solution below */
	unsigned char tmpD = 0x00;
	int total = 0;
	while (1) {
		//calculate the total weight
		tmpD = PINA + PINB + PINC;
		if((tmpD >> 7) != 0){
			tmpD = tmpD >> 2;
		}
		else if((tmpD >> 6) != 0){
			tmpD = tmpD >> 1;
		}
		tmpD = tmpD << 2;
		if(total > 140){
			tmpD = tmpD | 0x01;
		}
		if(PORTA - PORTC > 80){
			tmpD = tmpD | 0x02;
		}
		PORTD = tmpD;
	}
	return 0;
}
