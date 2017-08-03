/* 
 * File:   spimain.c
 * Author: shafai
 *
 * Created on August 3, 2017, 12:02 AM
 */


#include <stdio.h>
#include <stdlib.h>
#include <p32xxxx.h>
#include <xc.h>

int main(void){
    int VDD, OLED_DATA,VBAT_EN, SDO2, SCK2,RESET;
    
    //pin 38 VDD_EN (RF6)
    TRISFbits.TRISF6 = 0;
    //pin 39 DC data command (RF4)
    TRISFbits.TRISF4 = 0;
    //pin 40 VBAT_EN (RF5)
    TRISFbits.TRISF5 = 0;
    //pin 11 SDO2 (RG8)
    TRISGbits.TRISG8 = 0;
    //pin 13 SCK2 (RG6)
    TRISGbits.TRISG6 = 0;
    //pin 10 RES OLED reset (RG9)
    TRISGbits.TRISG9 = 0;
     
    //while(1){
    VDD = (PORTFbits.RF6 = 1);   
    RESET = PORTGbits.RG9 = 0;
    OLED_DATA = (PORTFbits.RF4 = 0);
    int spiBuf;
    SPI2CONbits.ON = 0;
    spiBuf = SPI2BUF;
    SPI2BRG = 4;
    SPI2STATbits.SPIROV = 0;
    SPI2CONbits.CKP = 1;
    SPI2CONbits.MSTEN = 1;
    SPI2CONbits.ON = 1;
    SPI2BUF = 'A';
    
    SDO2 = PORTGbits.RG8 = 1;
    SCK2 = PORTGbits.RG6 = 1;
    VBAT_EN = (PORTFbits.RF5 = 1);    
    OLED_DATA = (PORTFbits.RF4 = 1);
    
       
    //}
   
    
   
}



