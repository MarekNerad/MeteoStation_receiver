//******************************************************************************
//! \file        Ds18b20.c
//! \date        12-02-2023
//! \author      Nerad
//! \brief       <MODULE_DESCRIPTION>
//******************************************************************************
//   This module is classified as QM.
//******************************************************************************

//******************************************************************************
//                      Include
//******************************************************************************
#include "Ds18b20.h"

#include <avr/io.h>
#define F_CPU 8000000UL  // 8 MHz - takt MCU
#include <util/delay.h>
#include <avr/interrupt.h>

//******************************************************************************
//                      Define
//******************************************************************************

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
signed char teplota;
unsigned int desetiny;

//******************************************************************************
//                      Definition & Declaration of static variable
//******************************************************************************

//******************************************************************************
//                      Definition of static function
//******************************************************************************

//******************************************************************************
//                      Definition of global function
//******************************************************************************
// provede reset a test prezence ds-18b20 na sbernici
unsigned char ow_detect_presence(void) {
   unsigned char out=1;              // vychozi navratova hodnota
   RX;                               // vychozi stav sbernice
   _delay_us(1000);                  // pro ustaleni
   TX;                               // bus low
   _delay_us(480);                   // cas pro prikaz reset
   RX;                               // uvolneni sbernice
   _delay_us(70);                    // cekani na potvrzeni teplomerem
   if(RXPIN) out=0;                  // pokud detekovana log.1, tak teplomer na sbernici neni
   _delay_us(410);                   // pauza pred dalsi komunikaci
   return out;                       // vrati stav 1=teplomer nalezen,  0=teplomer nenalezen
}

// posle na sbernici log.1
void ow_write_one(void) {
   TX;                               // bus low
   _delay_us(6);                     // pauza definujici log.1
   RX;                               // uvolneni sbernice
   _delay_us(64);                    // pauza pred dalsi komunikaci
}

// posle na sbernici log.0
void ow_write_zero(void) {
   TX;                               // bus low
   _delay_us(60);                    // pauza definujici log.0
   RX;                               // uvolneni sbernice
   _delay_us(10);                    // pauza pred dalsi komunikaci
}

// precte jeden bit ze sbernice
unsigned char ow_read_bit(void) {
   unsigned char out=0;              // vychozi navratova hodnota bitu
   TX;                               // bus low
   _delay_us(6);                     // pauza pro stav cteni
   RX;                               // uvolneni sbernice
   _delay_us(9);                     // pauza pro reakci teplomeru
   if(RXPIN) out=1;                  // test stavu sbernice, vlastni cteni
   _delay_us(55);                    // pauza pred dalsi komunikaci
   return out;                       // prectena hodnota, 1 nebo 0
}

// odeslne na sbernici jeden byte. Odesila se prvni LSB
void ow_write_byte(unsigned char tosend) {
   int n=8;
   while(n--) {
      if(tosend&1) ow_write_one(); else ow_write_zero();
      tosend >>= 1;
   }
}

// prijde ze sbernice jeden byte. Prijima jako prvni LSB.
unsigned char ow_read_byte(void) {
   int n=8, out=0;
   while(n--) {
      out >>= 1;                       // bitovy posuv doprava
      if(ow_read_bit()) out |= 0x80;   // nastaveni nejvyssiho bitu na 1
   }
   return out;
}

// nacte teplotu z teplomeru a vrati ji ve formatu 1000+t*10
// priklad: 23.5°C = 1235,  -10.5°C = 895
// tento format lze snadneji zpracovavat nez nejake floaty (zerou moc pameti)
void temp_in(void) {
   unsigned char data_lo, data_hi;
   
   cli();
   ow_detect_presence();
   ow_write_byte(0xCC);
   ow_write_byte(0x44);
   _delay_ms(300);
   ow_detect_presence();
   ow_write_byte(0xCC);
   ow_write_byte(0xBE);
   data_lo=ow_read_byte();     // 1. byte scratchpadu teplomeru = spodni byte teploty
   data_hi=ow_read_byte();     // 2. byte scratchpadu teplomeru = horni byte teploty
   teplota = (data_lo & 0x0F0) >> 4 | (data_hi & 0x0F) << 4 ;   // signed teplota
   desetiny = (data_lo & 0x0F) * 0.625;
   sei();
}
