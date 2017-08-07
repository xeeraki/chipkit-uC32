/* 
 * File:   led0-7main.c
 * Author: shafai
 *
 * Created on August 6, 2017, 6:46 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int ms){
    int i;
    for(i = ms; i > 0; i--);
    
    }

    
int main(){
    int i;
    volatile int *trise = (volatile int*) 0xbf886100;
    //porte must be at an adress 4*4 below trise
    volatile int *porte = (volatile int*) 0xbf886110;
    //volatile int *push_buttons = (volatile int*) 0xbf886100;
    volatile int *LED = (volatile int*) 0xbf886100;
    *trise &= ~0xff;
    while(1){
        delay(1000000);
        *LED = (*porte = 0xff);
        delay(10000);
         *LED = (*porte = 0xfe);
        delay(10000);
         *LED = (*porte = 0xfd);
        delay(10000);
         *LED = (*porte = 0xfb);
        delay(10000);
         *LED = (*porte = 0xf7);
        delay(10000);
         *LED = (*porte = 0xef);
        delay(10000);
         *LED = (*porte = 0xdf);
        delay(10000);
         *LED = (*porte = 0xbf);
        delay(10000);
         *LED = (*porte = 0x7f);
        delay(100000);
        
         
    }
}



  