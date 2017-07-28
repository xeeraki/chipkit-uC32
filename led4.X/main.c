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
    int switches;
    TRISGbits.TRISG6 = 0;
    while(1){
        switches = (PORTGbits.RG6 = 1);
    }
}

