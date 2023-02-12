//******************************************************************************
//! \file        Lcd.c
//! \date        12-02-2023
//! \author      Nerad
//! \brief       <MODULE_DESCRIPTION>
//******************************************************************************
//   This module is classified as QM.
//******************************************************************************

//******************************************************************************
//                      Include
//******************************************************************************
#include "Lcd.h"

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <stdlib.h>

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

//******************************************************************************
//                      Definition & Declaration of static variable
//******************************************************************************

//******************************************************************************
//                      Definition of static function
//******************************************************************************

//******************************************************************************
//                      Definition of global function
//******************************************************************************

void enable(void)
{
   LCD_PORT |= (1<<LCD_E);		//E do jednicky

   _delay_us(1);

   LCD_PORT &= ~(1<<LCD_E);	//E do nuly
}

void lcd_instr(uint8 temp)
{
   uint8 temp_high = temp >> 4;
   
   LCD_PORT &= ~(1<<LCD_RS);        		//nulovani RS (prikaz)
   
   LCD_PORT &= ~((1<<DB4)|(1<<DB5)|(1<<DB6)|(1<<DB7));		//vynuluvani vystupnich pinu
   
   LCD_PORT |= (((temp_high & 0x08)>>3)<<DB7);
   LCD_PORT |= (((temp_high & 0x04)>>2)<<DB6);
   LCD_PORT |= (((temp_high & 0x02)>>1)<<DB5);
   LCD_PORT |= ((temp_high & 0x01)<<DB4);
   enable();
   
   LCD_PORT &= ~((1<<DB4)|(1<<DB5)|(1<<DB6)|(1<<DB7));		//vynuluvani vystupnich pinu
   
   LCD_PORT |= (((temp & 0x08)>>3)<<DB7);
   LCD_PORT |= (((temp & 0x04)>>2)<<DB6);
   LCD_PORT |= (((temp & 0x02)>>1)<<DB5);
   LCD_PORT |= ((temp & 0x01)<<DB4);
   enable();
   
   _delay_us(50);						//40us podle datasheetu
}

void lcd_char(uint8 temp)	//pro zobrazeni znaku
{
   uint8 temp_high = temp >> 4;
   
   LCD_PORT |= (1<<LCD_RS);	    		//RS=1 protoze posilame data
   
   LCD_PORT &= ~((1<<DB4)|(1<<DB5)|(1<<DB6)|(1<<DB7));		//vynuluvani vystupnich pinu
   
   LCD_PORT |= (((temp_high & 0x08)>>3)<<DB7);
   LCD_PORT |= (((temp_high & 0x04)>>2)<<DB6);
   LCD_PORT |= (((temp_high & 0x02)>>1)<<DB5);
   LCD_PORT |= ((temp_high & 0x01)<<DB4);
   enable();
   
   LCD_PORT &= ~((1<<DB4)|(1<<DB5)|(1<<DB6)|(1<<DB7));		//vynuluvani vystupnich pinu
   
   LCD_PORT |= (((temp & 0x08)>>3)<<DB7);
   LCD_PORT |= (((temp & 0x04)>>2)<<DB6);
   LCD_PORT |= (((temp & 0x02)>>1)<<DB5);
   LCD_PORT |= ((temp & 0x01)<<DB4);
   enable();
   
   _delay_us(50);						//40us podle datasheetu
}

void lcd_string(char *data)		//pro zobrazeni retezce
{
   while(*data) {
      lcd_char(*data);
      data++;
   }
}

void lcd_int(char temp)		//pro zobrazeni cisla
{
   char tmp[20];
   itoa(temp,tmp,10);			//prevede DDRddrcislo na retezec
   lcd_string(tmp);			//zobrazi retezec
}

void lcd_bin(char temp)		   //pro zobrazeni cisla
{
   char tmp[20];
   itoa(temp,tmp,2);			//prevede DDRddrcislo na retezec
   lcd_string(tmp);			//zobrazi retezec
}

void lcd_gotoxy(char x, char y)
{
   char tmp=0;
   if(y==1) tmp=(0x80+x);				//0x80-zacatek 1. radku + x-souradnice
   if(y==2) tmp=(0xC0+x);      		//0xC0-zacatek 2. radku
   if(y==3) tmp=(0x94+x);      		//0xC0-zacatek 2. radku
   if(y==4) tmp=(0xD4+x);      		//0xC0-zacatek 2. radku
   lcd_instr(tmp);
}

void display_clear(void)
{
   lcd_instr(0x01);
   _delay_ms(2);		//datasheet 1.53ms
}

void return_home(void)
{
   lcd_instr(0x02);

}

void entry_mode_set(void)
{
   lcd_instr(0x06);
}

void display_on_off(void)
{
   lcd_instr(0x0C);
}

void cursor_shift_right(void)
{
   lcd_instr(0x14);
}

void cursor_shift_left(void)
{
   lcd_instr(0x10);
}

void function_set(void)
{
   lcd_instr(0x28);
}

void marks_def(void)
{
   lcd_instr(0x40);
   lcd_char(0b00000010);		//vlastni­ znak "í" :-)
   lcd_char(0b00000100);
   lcd_char(0b00001110);
   lcd_char(0b00000100);
   lcd_char(0b00000100);
   lcd_char(0b00000100);
   lcd_char(0b00001110);
   lcd_char(0b00000000);

   lcd_instr(0x80);
}

void lcd_init(void)
{
   DDRD |= 0x7FU;
   
   _delay_ms(POWER_RAISES); //30ms nabech napajeni

   function_set();

   function_set();

   display_on_off();

   display_clear();

   entry_mode_set();
}

void lcd_switch(uint8 ligh_state)
{
   if(LCD_LIGHT_ON == ligh_state)
   {
      LCD_PORT |= (1U << LCD_LIGHT_SWITCH);
   }
   else
   {
      LCD_PORT &= ~(1U << LCD_LIGHT_SWITCH);
   }
}
