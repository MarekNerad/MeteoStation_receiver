//******************************************************************************
//! \file        Spi.h
//! \date        12-02-2023
//! \author      Nerad
//! \brief       <MODULE_DESCRIPTION>
//******************************************************************************
//   This module is classified as QM.
//******************************************************************************
#ifndef SPI_H
#define SPI_H

//******************************************************************************
//                      Include
//******************************************************************************
#include <avr/io.h>

//******************************************************************************
//                      Define
//******************************************************************************

//spi ports
#define SPI_DDR DDRB
#define SPI_PORT PORTB
#define SPI_MISO PB4
#define SPI_MOSI PB3
#define SPI_SCK PB5
#define SPI_SS PB2

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

//******************************************************************************
//                      Declaration of global function
//******************************************************************************
extern void spi_init();
extern uint8_t spi_writereadbyte(uint8_t data);

//******************************************************************************
//                      Declaration of inline function
//******************************************************************************

//******************************************************************************
//                      Definition of inline function
//******************************************************************************

#endif // SPI_H