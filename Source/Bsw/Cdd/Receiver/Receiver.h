//******************************************************************************
//! \file        Nrf24l01.h
//! \date        12-02-2023
//! \author      Nerad
//! \brief       <MODULE_DESCRIPTION>
//******************************************************************************
//   This module is classified as QM.
//******************************************************************************
#ifndef NRF24L01_H
#define NRF24L01_H

//******************************************************************************
//                      Include
//******************************************************************************
#include <avr/io.h>
#include "Std_Types.h"

//******************************************************************************
//                      Define
//******************************************************************************
//CE and CSN port definitions
#define NRF24L01_DDR DDRB
#define NRF24L01_PORT PORTB
#define NRF24L01_CE PB1
#define NRF24L01_CSN PB2


//CE and CSN functions
#define nrf24l01_CSNhi NRF24L01_PORT |= (1<<NRF24L01_CSN);
#define nrf24l01_CSNlo NRF24L01_PORT &= ~(1<<NRF24L01_CSN);
#define nrf24l01_CEhi NRF24L01_PORT |=  (1<<NRF24L01_CE);
#define nrf24l01_CElo NRF24L01_PORT &= ~(1<<NRF24L01_CE);

//power setup
#define NRF24L01_RF24_PA_MIN 1
#define NRF24L01_RF24_PA_LOW 2
#define NRF24L01_RF24_PA_HIGH 3
#define NRF24L01_RF24_PA_MAX 4
#define NRF24L01_RF24_PA NRF24L01_RF24_PA_MAX

//speed setup
#define NRF24L01_RF24_SPEED_250KBPS 1
#define NRF24L01_RF24_SPEED_1MBPS 2
#define NRF24L01_RF24_SPEED_2MBPS 3
#define NRF24L01_RF24_SPEED NRF24L01_RF24_SPEED_1MBPS

//crc setup
#define NRF24L01_RF24_CRC_DISABLED 1
#define NRF24L01_RF24_CRC_8 2
#define NRF24L01_RF24_CRC_16 3
#define NRF24L01_RF24_CRC NRF24L01_RF24_CRC_16

//transmission channel
#define NRF24L01_CH 76	//76

//payload lenght
#define NRF24L01_PAYLOAD 5

//auto ack enabled
#define NRF24L01_ACK 1

//auto retransmit delay and count
#define NRF24L01_RETR (0b0100 << NRF24L01_REG_ARD) | (0b0111 << NRF24L01_REG_ARC) //1500uS, 15 times

//enable / disable pipe
#define NRF24L01_ENABLEDP0 1 //pipe 0
#define NRF24L01_ENABLEDP1 1 //pipe 1
#define NRF24L01_ENABLEDP2 0 //pipe 2
#define NRF24L01_ENABLEDP3 0 //pipe 3
#define NRF24L01_ENABLEDP4 0 //pipe 4
#define NRF24L01_ENABLEDP5 0 //pipe 5

//address size
#define NRF24L01_ADDRSIZE 5

//pipe address
//#define NRF24L01_ADDRP0 {0xE8, 0xE8, 0xF0, 0xF0, 0xE2} //pipe 0, 5 byte address
//#define NRF24L01_ADDRP1 {0xC1, 0xC2, 0xC2, 0xC2, 0xC2} //pipe 1, 5 byte address
#define NRF24L01_ADDRP0 {0xF0, 0xF0, 0xF0, 0xF0, 0xD2} //pipe 0, 5 byte address
#define NRF24L01_ADDRP1 {0xF0, 0xF0, 0xF0, 0xF0, 0xE1} //pipe 1, 5 byte address
#define NRF24L01_ADDRP2 {0xC1, 0xC2, 0xC2, 0xC2, 0xC3} //pipe 2, 5 byte address
#define NRF24L01_ADDRP3 {0xC1, 0xC2, 0xC2, 0xC2, 0xC4} //pipe 3, 5 byte address
#define NRF24L01_ADDRP4 {0xC1, 0xC2, 0xC2, 0xC2, 0xC5} //pipe 4, 5 byte address
#define NRF24L01_ADDRP5 {0xC1, 0xC2, 0xC2, 0xC2, 0xC6} //pipe 5, 5 byte address
//#define NRF24L01_ADDRTX {0xE8, 0xE8, 0xF0, 0xF0, 0xE2} //tx default address*/
#define NRF24L01_ADDRTX {0xF0, 0xF0, 0xF0, 0xF0, 0xE1} //tx default address*/

//enable print info function
#define NRF24L01_PRINTENABLE 0

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
extern void nrf24l01_init();
extern uint8 nrf24l01_getstatus();
extern uint8 nrf24l01_readready();
extern void nrf24l01_read(uint8 *data);
extern uint8 nrf24l01_write(uint8 *data);
extern void nrf24l01_setrxaddr(uint8 channel, uint8 *addr);
extern void nrf24l01_settxaddr(uint8 *addr);

//******************************************************************************
//                      Declaration of inline function
//******************************************************************************

//******************************************************************************
//                      Definition of inline function
//******************************************************************************

#endif // <FILENAME>_H

