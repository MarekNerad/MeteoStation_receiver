//******************************************************************************
//! \file        Os.c
//! \date        12-02-2023
//! \author      Nerad
//! \brief       <MODULE_DESCRIPTION>
//******************************************************************************
//   This module is classified as QM.
//******************************************************************************

//******************************************************************************
//                      Include
//******************************************************************************
#include "Os.h"
#include "Std_Types.h"
#include "Lcd.h"
#include "Dallas.h"

#include <avr/interrupt.h>

//******************************************************************************
//                      Define
//******************************************************************************
#define OS_10MS_TO_1MS  10U   /**< Scale factor between 1ms and 10ms task */
#define OS_100MS_TO_1MS 100U  /**< Scale factor between 1ms and 100ms task */
#define OS_1S_TO_1MS    1000U /**< Scale factor between 1ms and 1sms task */

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
static void Os_Call_1ms_tasks(void);   /**< Scheduler_ 1ms tasks list */
static void Os_Call_10ms_tasks(void);  /**< Scheduler_ 10ms tasks list */
static void Os_Call_100ms_tasks(void); /**< Scheduler_ 100ms tasks list */
static void Os_Call_1s_tasks(void);    /**< Scheduler_ 1s tasks list */

//******************************************************************************
//                      Definition & Declaration of global variable
//******************************************************************************

//******************************************************************************
//                      Definition & Declaration of static variable
//******************************************************************************
static uint32         Os_cnt_ms_mdu32; /**< Scheduler_ 1ms counter */
static volatile uint8 Os_isrFlag_mdu8;
//******************************************************************************
//                      Definition of static function
//******************************************************************************

static void Os_Call_1ms_tasks(void)
{
   ;
}

static void Os_Call_10ms_tasks(void)
{
   // Refresh the LCD menu
   Lcd_Menu();
}

static void Os_Call_100ms_tasks(void)
{
   ;
}

static void Os_Call_1s_tasks(void)
{
   // Inside temperature measurement
   Dallas_Temp_In();
   
   refresh++;
}

//******************************************************************************
//                      Definition of global function
//******************************************************************************

// doxy todo
void Os_Init(void)
{
   ;
}

// todo doxy
void Os_cyclic(void)
{
   if (TRUE == Os_isrFlag_mdu8)
   {
      
      // Reset ISR flag
      Os_isrFlag_mdu8 = FALSE;

      // Increment counter (for other tasks)
      Os_cnt_ms_mdu32++;

      /** 1 ms Task trigger */
      Os_Call_1ms_tasks();

      /** 10 ms Task trigger */
      if ((Os_cnt_ms_mdu32 % OS_10MS_TO_1MS) == 0U)
      {
         Os_Call_10ms_tasks();
      }

      /** 100 ms Task trigger */
      if ((Os_cnt_ms_mdu32 % OS_100MS_TO_1MS) == 0U)
      {
         Os_Call_100ms_tasks();
      }

      /** 1s Task trigger */
      if ((Os_cnt_ms_mdu32 % OS_1S_TO_1MS) == 0U)
      {
         Os_Call_1s_tasks();
      }
   }
}

/*! TIMER0 overflow interrupt. Event to be executed every 1ms here */
ISR (TIMER1_COMPA_vect)
{
   Os_isrFlag_mdu8 = TRUE;
}
