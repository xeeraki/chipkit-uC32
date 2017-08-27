/* 
 * File:   function.c
 * Author: shafai
 *
 * Created on August 27, 2017, 12:05 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <p32xxxx.h>

int mytime = 0x5957;
char textstring[] = "text, more text";

void labinit( void )
{
    
    volatile int *trise = (volatile int*) 0xbf886100;
    //volatile int *porte = (volatile int*) 0xbf88611f;
    //volatile int *LED = (volatile int*) 0xbf886100;
    *trise &= ~0x00ff;
    //0000 1111 1110 0000
    TRISD = 0x0fe0;
    /*
    while(1){
        *LED = (*porte = 0xff);
    }
     */
    return;
}
/*
void delay(int ms){
    int i;
    for(i = ms; i > 0; i--);
}
*/

void labwork ( void){  
  volatile int *porte = (volatile int*) 0xbf886110;
  volatile int *LED = (volatile int*) 0xbf886110; 
  int btn, sw;
  
  btn = getbtns();
  sw = getsw();
  
  while(1){
    //button 4 (0100)
       if(btn == 4){
           *LED = *LED + 0x1;
       }
  
    
    delay(1000);
   //*LED = *LED + 0x1;
    
  time2string(textstring,mytime);
  }
  delay(1000);
}
