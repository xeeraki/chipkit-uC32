/* 
 * File:   led0main.c
 * Author: shafai
 *
 * Created on July 27, 2017, 12:24 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <p32xxxx.h>
#include <xc.h>
int main(void){
    int switches, LED0,OLED_VDD;
    TRISGbits.TRISG6 = 0;
    //TRISEbits.TRISE0 = 0;
    //the 4 least significant LED
    TRISE = 0xfff0;
    TRISFbits.TRISF6 = 0;
    int i;
    while(1){
        switches = (PORTGbits.RG6 = 1);
        //LED0 = PORTEbits.RE0 = 1;
        LED0 = (PORTE = 0xffff);
        OLED_VDD = (PORTFbits.RF6 = 1);
        for(i = 0; i < 400000; i++);
        
    }
}



