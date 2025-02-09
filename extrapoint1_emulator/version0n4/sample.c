/****************************************Copyright (c)****************************************************
**                                      
**                                 http://www.powermcu.com
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               main.c
** Descriptions:            The GLCD application function
**
**--------------------------------------------------------------------------------------------------------
** Created by:              AVRman
** Created date:            2010-11-7
** Version:                 v1.0
** Descriptions:            The original version
**
**--------------------------------------------------------------------------------------------------------
** Modified by:             Paolo Bernardi
** Modified date:           03/01/2020
** Version:                 v2.0
** Descriptions:            basic program for LCD and Touch Panel teaching
**
*********************************************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "LPC17xx.h"
#include "GLCD/GLCD.h" 
#include "TouchPanel/TouchPanel.h"
#include "timer/timer.h"
#include "RIT/RIT.h"
#include <string.h>
#include "joystick/joystick.h"


#ifdef SIMULATOR
extern uint8_t ScaleFlag; // <- ScaleFlag needs to visible in order for the emulator to find the symbol (can be placed also inside system_LPC17xx.h but since it is RO, it needs more work)
#endif


int main(void)
 {

  SystemInit();  												/* System Initialization (i.e., PLL)  */
	
  LCD_Initialization();	
	joystick_init();											/* Joystick Initialization            */
	

	
															
	
	LCD_Clear(Black);										// preparo lo schermo con il colore corretto 
	
																					//TIMER0 inizializzazione del timer con rispettivi
	init_timer(0,0,0,1,25000000); 					// match register uno ogni 25Mhz e 50Mhz
	init_timer(0,0,1,3,50000000); 	
	enable_timer(0);
	
	
	init_RIT(0x004C4B40);									/* RIT Initialization 50 msec       	*/
	disable_RIT();												
	reset_RIT();
	enable_RIT();	
	
	
	LPC_SC->PCON |= 0x1;									/* power-down	mode										*/
	LPC_SC->PCON &= ~(0x2);						
	
  while (1)	
  {
		__ASM("wfi");
  }
}

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
