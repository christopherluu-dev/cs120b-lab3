/*	Author: christopherluu
 *  Partner(s) Name: 
 *	Lab Section: 22
 *	Assignment: Lab #3  Exercise #4
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
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
    while (1) {
        unsigned char tempAlower = PINA & 0x0F;
        unsigned char tempAupper = PINA & 0xF0;
        unsigned char tempB = 0;
        unsigned char tempC = 0;

        tempB = tempAupper >> 4;
        tempC = tempAlower << 4;

        PORTB = tempB;
        PORTC = tempC;
    }
    return 1;
}
