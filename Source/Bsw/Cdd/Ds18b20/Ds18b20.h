//******************************************************************************
//! \file        Ds18b20.h
//! \date        12-02-2023
//! \author      Nerad
//! \brief       <MODULE_DESCRIPTION>
//******************************************************************************
//   This module is classified as QM.
//******************************************************************************
#ifndef DS18B20_H
#define DS18B20_H

//******************************************************************************
//                      Include
//******************************************************************************

//******************************************************************************
//                      Define
//******************************************************************************
#define PDD7         0x80            // na PD7 je p�ipojeno �idlo
#define TX          DDRD |= PDD7
#define RX          DDRD &= ~PDD7
#define RXPIN       PIND&PDD7

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
//                      Declaration of global variable
//******************************************************************************
extern signed char teplota;
extern unsigned int desetiny;

//******************************************************************************
//                      Declaration of global function
//******************************************************************************
unsigned char ow_detect_presence(void);
void ow_write_one(void);
void ow_write_zero(void);
unsigned char ow_read_bit(void);
void ow_write_byte(unsigned char tosend);
unsigned char ow_read_byte(void);
void temp_in(void);

//******************************************************************************
//                      Declaration of inline function
//******************************************************************************

//******************************************************************************
//                      Definition of inline function
//******************************************************************************

#endif // DS18B20_H