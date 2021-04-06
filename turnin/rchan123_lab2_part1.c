/*	Author: rchan123
 *  	Partner(s) Name: 
 *	Lab Section: 023
 *	Assignment: Lab 2  Exercise 1
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
	DDRB = 0xFF;
	PORTB = 0x00;
	/* Insert your solution below */
	while (1) {
		if(!PA1 && !PA0){
			PORTB = 0;
		}
		else if(!PA1 && PA0){
			PORTB = 1;
		}
		else if(PA1 && !PA0){
			PORTB = 0;
		}
		else{
			PORTB = 0;
		}
	}
	return 1;
}
