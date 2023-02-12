//******************************************************************************
//! \file        Spi.c
//! \date        12-02-2023
//! \author      Nerad
//! \brief       <MODULE_DESCRIPTION>
//******************************************************************************
//   This module is classified as QM.
//******************************************************************************

//******************************************************************************
//                      Include
//******************************************************************************
#include "Spi.h"

#include <avr/io.h>
#include <avr/interrupt.h>
//******************************************************************************
//                      Define
//******************************************************************************
#define BIT(x)	           (1 << (x))
#define SETBIT(x, y)   	   (x |= y)
#define CLEARBIT(x, y) 	   (x &= ~y)
#define CHECKBIT(x, y) 	   (x & y)
#define BIT7 0x80
#define BIT6 0x40
#define BIT5 0x20
#define BIT4 0x10
#define BIT3 0x08
#define BIT2 0x04
#define BIT1 0x02
#define BIT0 0x01
#define nRF24L01_CSN        BIT2
#define nRF24L01_SCK        BIT5
#define nRF24L01_MOSI       BIT3
#define nRF24L01_CE         BIT1
#define nRF24L01_MISO 	    BIT4
//#define nRF24L01_IRQ  	    BIT0
#define nRF24L01_CSNH       SETBIT(PORTB, nRF24L01_CSN)
#define nRF24L01_CSNL       CLEARBIT(PORTB, nRF24L01_CSN)

#define nRF24L01_CSN_DIR    SETBIT(DDRB, nRF24L01_CSN)  //OUTPUT

#define nRF24L01_SCKH       SETBIT(PORTB,nRF24L01_SCK)
#define nRF24L01_SCKL       CLEARBIT(PORTB,nRF24L01_SCK)
#define nRF24L01_SCK_DIR   SETBIT(DDRB,nRF24L01_SCK)  //OUTPUT

#define nRF24L01_MOSIH      SETBIT(PORTB,nRF24L01_MOSI)
#define nRF24L01_MOSIL	    CLEARBIT(PORTB,nRF24L01_MOSI)
#define nRF24L01_MOSI_DIR   SETBIT(DDRB,nRF24L01_MOSI)

#define nRF24L01_CEH        SETBIT(PORTB,nRF24L01_CE)  //OUTPUT
#define nRF24L01_CEL        CLEARBIT(PORTB,nRF24L01_CE)
#define nRF24L01_CE_DIR     SETBIT(DDRB,nRF24L01_CE)

#define nRF24L01_IRQ_DIR     CLEARBIT(DDRB,nRF24L01_IRQ) //INPUT

#define nRF24L01_MISO_DIR    CLEARBIT(DDRB,nRF24L01_MISO) //INPUT

//******************************************************************************
//                      Define with parameter
//******************************************************************************

//******************************************************************************
//                      Enumeration
//******************************************************************************

//******************************************************************************
//                      Structure
//******************************************************************************

//******************************************************************************
//                      Typedef
//******************************************************************************

//******************************************************************************
//                      Declaration of static function
//******************************************************************************

//******************************************************************************
//                      Definition & Declaration of global variable
//******************************************************************************

//******************************************************************************
//                      Definition & Declaration of static variable
//******************************************************************************

//******************************************************************************
//                      Definition of static function
//******************************************************************************

//******************************************************************************
//                      Definition of global function
//******************************************************************************

// todo doxy
void delay(void)
{
   asm("NOP");
   asm("NOP");
   asm("NOP");
   asm("NOP");
   asm("NOP");
   asm("NOP");
   asm("NOP");
   asm("NOP");
}

//todo doxy
void delayms(uint16 dly)
{
   for(;dly>0;dly--);
}

// todo doxy
void spi_init()
{
   /*    SPI_DDR &= ~((1<<SPI_MOSI) | (1<<SPI_MISO) | (1<<SPI_SS) | (1<<SPI_SCK)); //input
   SPI_DDR |= ((1<<SPI_MOSI) | (1<<SPI_SS) | (1<<SPI_SCK)); //output

   SPCR = ((1<<SPE)|               // SPI Enable
   (0<<SPIE)|              // SPI Interupt Enable
   (0<<DORD)|              // Data Order (0:MSB first / 1:LSB first)
   (1<<MSTR)|              // Master/Slave select
   (0<<SPR1)|(1<<SPR0)|    // SPI Clock Rate
   (0<<CPOL)|              // Clock Polarity (0:SCK low / 1:SCK hi when idle)
   (0<<CPHA));             // Clock Phase (0:leading / 1:trailing edge sampling)

   SPSR = (1<<SPI2X); // Double SPI Speed Bit
   */

   // nRF24L01_IRQ_DIR;
   nRF24L01_MISO_DIR;
   nRF24L01_CE_DIR;
   nRF24L01_SCK_DIR;
   nRF24L01_CSN_DIR;
   nRF24L01_MOSI_DIR;
}

/*
* spi write one byte and read it back
*/
uint8 spi_writereadbyte(uint8 byte)
{
   //    SPDR = data;
   //    while((SPSR & (1<<SPIF)) == 0);
   //    return SPDR;

   uint8  bit_ctr;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   	// output 8-bit
   {
      if(byte & 0x80)
      nRF24L01_MOSIH;
      else
      nRF24L01_MOSIL;
      delay();
      byte = (byte << 1);           		// shift next bit into MSB..
      nRF24L01_SCKH;
      delay();
      if(PINB&nRF24L01_MISO) byte |= 1;
      nRF24L01_SCKL;
      delay();
   }

   return(byte);

}
