/*	Author: christopherluu
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #3  Exercise #1
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
    DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
    while (1) {
        unsigned char cnt = 0;
        unsigned char tempA = PINA;
        unsigned char tempB = PINB;

        for(unsigned char i = 0; i < 8; i++){
            if((tempA & 0x01) == 0x01){
                cnt++;
            }
            tempA = tempA >> 1;
        }

        for(unsigned char i = 0; i < 8; i++){
            if((tempB & 0x01) == 0x01){
                cnt++;
            }
            tempB = tempB >> 1;
        }
        PORTC = cnt;
    }
    return 1;
}
