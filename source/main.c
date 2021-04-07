/*	Author: rchan123
 *  	Partner(s) Name: 
 *	Lab Section: 023
 *	Assignment: Lab 2  Exercise 4
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
	unsigned char exceeds = 0x00;
	unsigned char unbalanced = 0x00;
	int total = 0;
	while (1) {
		//calculate the total weight
		total = PINA + PINB + PINC;
		exceeds = (total > 140)? 0x01 : 0x00;	//weight exceeds 140, then 1 to PD0
		unbalanced = ((PINA > 80 + PINC) || (PINC > 80 + PINA))? 0x02 : 0x00;
		tmpD = (total >> 2); 
		PORTD = tmpD | (exceeds | unbalanced);
	}
	return 0;
}
