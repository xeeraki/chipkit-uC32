/* 
 * File:   main.c
 * Author: shafai
 *
 * Created on July 29, 2017, 10:39 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <p32xxxx.h>
#include <ctype.h>
#include <alloca.h>
#include <hitech.h>
#include <pthread.h>
#include <InstrumentedTrace.h>
#include <GenericTypeDefs.h>






#define prtVddCtrl  IOPORT_F
#define prtVbatCtrl IOPORT_F
#define prtDataCmd  IOPORT_F
#define prtReset    IOPORT_G
#define bitVddCtrl  BIT_6
#define bitVbatCtrl BIT_5
#define bitDataCmd  BIT_4
#define bitReset    BIT_9
/* ------------------------------------------------------------ */
// Symbols describing the geometry of the display.
#define cbOledDispMax 512
 //max number of bytes in display buffer
#define ccolOledMax 128
 //number of display columns
#define crowOledMax 32
//number of display rows
#define cpagOledMax 4
//number of display memory pages
/* ------------------------------------------------------------ */
/* This array is the off-screen frame buffer used for rendering.
** It isn't possible to read back from the OLED display device,
** so display data is rendered into this off-screen buffer and then
** copied to the display.
*/
BYTE rgbOledBmp[cbOledDispMax];

void
OledHostInit()
	{
	unsigned int	tcfg;

	/* Initialize SPI port 2.
	*/
	SPI2CON = 0;
	SPI2BRG = 15;				//8Mhz, with 80Mhz PB clock
	SPI2STATbits.SPIROV = 0;
	SPI2CONbits.CKP = 1;
	SPI2CONbits.MSTEN = 1;
	SPI2CONbits.ON = 1;

	/* Make pins RF4, RF5, and RF6 be outputs.
	*/
	PORTSetBits(IOPORT_F, bitVddCtrl|bitVbatCtrl|bitDataCmd);
	PORTSetPinsDigitalOut(prtDataCmd, bitDataCmd);		//Data/Command# select
	PORTSetPinsDigitalOut(prtVddCtrl, bitVddCtrl);		//VDD power control (1=off)
	PORTSetPinsDigitalOut(prtVbatCtrl, bitVbatCtrl);		//VBAT power control (1=off)

	/* Make the RG9 pin be an output. On the Basic I/O Shield, this pin
	** is tied to reset.
	*/
	PORTSetBits(prtReset, bitReset);
	PORTSetPinsDigitalOut(prtReset, bitReset);

}

void
OledDspInit()
	{

	/* We're going to be sending commands, so clear the Data/Cmd bit
	*/
	PORTClearBits(prtDataCmd, bitDataCmd);

	/* Start by turning VDD on and wait a while for the power to come up.
	*/
	PORTClearBits(prtVddCtrl, bitVddCtrl);
	DelayMs(1);

	/* Display off command
	*/
	Spi2PutByte(0xAE);

	/* Bring Reset low and then high
	*/
	PORTClearBits(prtReset, bitReset);
	DelayMs(1);
	PORTSetBits(prtReset, bitReset);

	/* Send the Set Charge Pump and Set Pre-Charge Period commands
	*/
	Spi2PutByte(0x8D);
	Spi2PutByte(0x14);

	Spi2PutByte(0xD9);
	Spi2PutByte(0xF1);

	/* Turn on VCC and wait 100ms
	*/
	PORTClearBits(prtVbatCtrl, bitVbatCtrl);
	DelayMs(100);

	/* Send the commands to invert the display. This puts the display origin
	** in the upper left corner.
	*/
	Spi2PutByte(0xA1);			//remap columns
	Spi2PutByte(0xC8);			//remap the rows

	/* Send the commands to select sequential COM configuration. This makes the
	** display memory non-interleaved.
	*/
	Spi2PutByte(0xDA);			//set COM configuration command
	Spi2PutByte(0x20);			//sequential COM, left/right remap enabled

	/* Send Display On command
	*/
	Spi2PutByte(0xAF);

}

void
OledUpdate()
	{
	int		ipag;
	int		icol;
	BYTE *	pb;

	pb = rgbOledBmp;

	for (ipag = 0; ipag < cpagOledMax; ipag++) {

		PORTClearBits(prtDataCmd, bitDataCmd);

		/* Set the page address
		*/
		Spi2PutByte(0x22);		//Set page command
		Spi2PutByte(ipag);		//page number

		/* Start at the left column
		*/
		Spi2PutByte(0x00);		//set low nybble of column
		Spi2PutByte(0x10);		//set high nybble of column

		PORTSetBits(prtDataCmd, bitDataCmd);

		/* Copy this memory page of display data.
		*/
		OledPutBuffer(ccolOledMax, pb);
		pb += ccolOledMax;

	}

}

void
OledUpdate()
	{
	int		ipag;
	int		icol;
	BYTE *	pb;

	pb = rgbOledBmp;

	for (ipag = 0; ipag < cpagOledMax; ipag++) {

		PORTClearBits(prtDataCmd, bitDataCmd);

		/* Set the page address
		*/
		Spi2PutByte(0x22);		//Set page command
		Spi2PutByte(ipag);		//page number

		/* Start at the left column
		*/
		Spi2PutByte(0x00);		//set low nybble of column
		Spi2PutByte(0x10);		//set high nybble of column

		PORTSetBits(prtDataCmd, bitDataCmd);

		/* Copy this memory page of display data.
		*/
		OledPutBuffer(ccolOledMax, pb);
		pb += ccolOledMax;

	}

}
