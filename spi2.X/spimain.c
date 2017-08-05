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
    int VDD, OLED_DATA,VBAT_EN, SDO2, SCK2, SDI,RESET,spiBuf;
      // analog to digital register
     AD1PCFG = 0xffff;
     // open drain registers (low as digital output)
     ODCE = 0x0;
     ODCF = 0x0;
     ODCG = 0x0;
   
    SPI2CONbits.ON = 0;
    spiBuf = SPI2BUF;
    SPI2BRG = 15;
    SPI2STATbits.SPIROV = 0;
    SPI2CONbits.CKP = 1;
    SPI2CONbits.MSTEN = 1;
    SPI2CONbits.ON = 1;
    SPI2BUF = 'A';
    
    
    
    
    //TRISF = 0x0000;
    //pin 39 DC data command (RF4)
    TRISFbits.TRISF4 = 0;
    //pin 38 VDD_EN (RF6)
    TRISFbits.TRISF6 = 0;
    //pin 40 VBAT_EN (RF5)
    TRISFbits.TRISF5 = 0;
    //pin 10 RES OLED reset (RG9)
    TRISGbits.TRISG9 = 0;
    /*
    //pin 11 SDO2 (RG8)
    TRISGbits.TRISG8 = 0;
    //pin 13 SCK2 (RG6)
    TRISGbits.TRISG6 = 0;
    //pin 10 RES OLED reset (RG9)
    TRISGbits.TRISG9 = 0;
    //pin 12 SDI (RG7)
    TRISGbits.TRISG7= 1;
    */
     
    
        
    VDD = (PORTFbits.RF6 = 0); 
      //VDD = PORTF = 0xffff;  
    RESET = PORTGbits.RG9 = 1;
    OLED_DATA = (PORTFbits.RF4 = 1);
    SDO2 = PORTGbits.RG8 = 1;
    SCK2 = PORTGbits.RG6 = 1;
    SDI  = PORTGbits.RG7 = 0;
    VBAT_EN = (PORTFbits.RF5 = 0);
    //VBAT_EN = PORTF = 0xffff;    
    OLED_DATA = (PORTFbits.RF4 = 0);
    
       
    
   
    
   
}



