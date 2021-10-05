/*	Author: christopherluu
 *  Partner(s) Name: 
 *	Lab Section: 22
 *	Assignment: Lab #3  Exercise #5
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
    DDRB = 0xFE; PORTB = 0x01;
    DDRD = 0x00; PORTD = 0xFF;
    /* Insert your solution below */
    while (1) {
        
        unsigned int tempD = PIND;
        unsigned char tempBout = PINB & 0x01;
        if(tempBout == 0){
            tempD = tempD << 1;    
        }
        else{
            tempD = (tempD << 1) + 1;
        }
        
        unsigned int weight = tempD;
        tempBout = 0;

        if(weight >= 70){
            tempBout = tempBout | 0x02;
        }
        if(weight > 5 && weight < 70){
            tempBout = tempBout | 0x04;
        }
        PORTB = tempBout;
    }
    return 1;
}
