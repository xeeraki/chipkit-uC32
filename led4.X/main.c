/* 
 * File:   main.c
 * Author: shafai
 *
 * Created on July 28, 2017, 4:07 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <p32xxxx.h>
int main(void){
    /*LED4 on the uC32 have pin number 13 
     * (look at chipKit ref pin out table and PIC32 ref for functionality)
     * which means TRISG and PORTG with bit number 6 
     * should be used to control the LED4*/
    int led4;
    
    TRISGbits.TRISG6 = 0;
    while(1){
        led4 = (PORTGbits.RG6 = 1);
    }
}

