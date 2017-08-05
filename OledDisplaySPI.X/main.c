/* 
 * File:   main.c
 * Author: shafai
 *
 * Created on July 29, 2017, 9:29 AM
 */

#include <stdio.h>
#include <p32xxxx.h>
#include <stdlib.h>
#include <xc.h>
#include <plib.h>



void powerON(){
    int VDD, OLED_DATA,VBAT_EN;
    //Power to vdd pin 38(RF6)
    TRISFbits.TRISF6 = 0;
    TRISFbits.TRISF4 = 0;
    TRISFbits.TRISF5 = 0;
    while(1){
       VDD = (PORTFbits.RF6 = 1);
       OLED_DATA = (PORTFbits.RF4 = 1);
       VBAT_EN = (PORTFbits.RF5 = 1);   
    }
}
void displayOF(){
    
    
    
}

void initDisplay(){
    SPI2CON = 0;   
    SPI2BRG = 4;
    SPI2STATbits.SPIROV = 0;
    SPI2CONbits.CKP = 1;
    SPI2CONbits.MSTEN = 1;
    SPI2CONbits.ON = 1;


}

void delay(int ms){
  int i;
	for(i = ms; i > 0; i--);
}

int main ( void){
    
    powerON();
    delay(1000);
   // displayOF();
    initDisplay();
    
   //power to vbat pin 40(RF5)
}