/* 
 * File:   led0-7main.c
 * Author: shafai
 *
 * Created on August 6, 2017, 6:46 PM
 */

#include <stdio.h>
#include <stdlib.h>
int main(){
volatile int *trise = (volatile int*) 0xbf886100;
    volatile int *porte = (volatile int*) 0xbf88611f;
    volatile int *LED = (volatile int*) 0xbf886100;
    *trise &= ~0xff;
    while(1){
        *LED = (*porte = 0xff);
    }
  }