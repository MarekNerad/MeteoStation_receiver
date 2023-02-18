//******************************************************************************
//! \file        Lcd.h
//! \date        12-02-2023
//! \author      Nerad
//! \brief       <MODULE_DESCRIPTION>
//******************************************************************************
//   This module is classified as QM.
//******************************************************************************
#ifndef LCD_H
#define LCD_H

//******************************************************************************
//                      Include
//******************************************************************************
#include "Std_Types.h"

//******************************************************************************
//                      Define
//******************************************************************************
#define POWER_RAISES        30U
#define LCD_PORT            PORTD
#define DB4                 PD4
#define DB5                 PD3
#define DB6                 PD2
#define DB7                 PD1
#define LCD_E               PD5
#define LCD_RS              PD6
#define LCD_LIGHT_SWITCH    PD0 // switch the transistor on

#define LCD_LIGHT_OFF   0U
#define LCD_LIGHT_ON    1U

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
extern uint8 refresh;

//******************************************************************************
//                      Declaration of global function
//******************************************************************************
void enable(void);
void lcd_instr(uint8 temp);
void lcd_char(uint8 temp);
void lcd_string(char *data);
void lcd_int(char temp);
void lcd_bin(char temp);
void lcd_gotoxy(char x, char y);
void display_clear(void);
void return_home(void);
void entry_mode_set(void);
void display_on_off(void);
void cursor_shift_right(void);
void cursor_shift_left(void);
void function_set(void);
void marks_def(void);
void Lcd_Init(void);
void Lcd_Menu(void);
void lcd_switch(uint8 ligh_state);

//******************************************************************************
//                      Declaration of inline function
//******************************************************************************

//******************************************************************************
//                      Definition of inline function
//******************************************************************************

#endif // LCD_H
