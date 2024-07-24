/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_RIT.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    RIT.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "lpc17xx.h"
#include "RIT.h"
#include <string.h>
#include "lpc17xx.h"
#include "../GLCD/GLCD.h" 
#include "../TouchPanel/TouchPanel.h"


/******************************************************************************
** Function name:		RIT_IRQHandler
**
** Descriptions:		REPETITIVE INTERRUPT TIMER handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/

extern volatile int select=0;
extern volatile int left=0;
extern volatile int right=0; // queste variabili permetto di far capire al timer quado l'utente ha premuto i tasti.

void RIT_IRQHandler (void)
{					
	
	
	
	if((LPC_GPIO1->FIOPIN & (1<<27)) == 0){	
		/* Joytick left pressed */
		left=1;
		right=0;
	}

	if((LPC_GPIO1->FIOPIN & (1<<28)) == 0){	
		/* Joytick destra pressed */
		right=1;
		left=0;
	}
	
	if((LPC_GPIO1->FIOPIN & (1<<25)) == 0){	
		/* Joytick select pressed */
		select=1;
	}
	
	
	
	
	
	
	
  LPC_RIT->RICTRL |= 0x1;	/* clear interrupt flag */
	disable_RIT();
	reset_RIT();
	enable_RIT();
	
  return;
}

/******************************************************************************
**                            End Of File
******************************************************************************/
