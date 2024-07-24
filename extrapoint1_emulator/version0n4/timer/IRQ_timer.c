/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_timer.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    timer.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "lpc17xx.h"
#include "timer.h"
#include "../functions.h"
#include "../GLCD/GLCD.h"
#include "../RIT/RIT.h"



/******************************************************************************
** Function name:		Timer0_IRQHandler
**
** Descriptions:		Timer/Counter 0 interrupt handler
**                  ALL THE LOGIC OF THE TAMAGOTCHI IS INSIDE THIS FILE  
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/

/* defined in funct_led							*/

extern volatile int select;
extern volatile int left;
extern volatile int right;

void TIMER0_IRQHandler (void)
{
	static int hr,min,sec;
	static int counterfame=0;
	static int counterfelicita=0;
	static int countersecfame;
	static int countersecfelicita;	
	static int flaganimazionerunaway=0;
		static int flaganimazionerunaway2=0;

	

	
	//inizio match register 0
	/* All'interno di questo timer 
	*alterno l'animazione del frame uno e del frame due
	*conto con un contatore SEC i secondi che passano 
	* tramite delle if gestisco la formattazione del tempo e lo stampo a video 
	* le variabili COUNTERSECFAME e COUNTERSECFELICITA contano i secondi che passano per la felicita e la fame
	* quando COUNTERSECFAME e COUNTERSECFELICITA sono uguali a 5 con una if aumento COUNTERFAME e COUNTERFELICITA che sono le variabili che indicano quanto il tamagotchi sia triste o affamato
	* più COUNTERFAME/COUNTERFELICITA sono alti più il tamagotchi è affamato/triste
	* controllo che le variabili esterne e volatili siano uguali ad uno, queste variabili sono definite dal file 'IRQ_RIT.C', e sono dei flag che fanno capire quando l'utente preme i tasti del joystick
	*con delle if anniadate capisco quando i tasti meal o snack sono selezionati e in tal caso faccio partire l'animazione corrispettiva e aggiorno il valore di COUNTERFELICITA o COUNTERFAME, 
	** allo stesso tempo azzero COUNTERSECFAME e COUNTERSECFELICITA per resettare il tempo di diminuzione.
	**	se COUNTERFAME o COUNTERFELICITA arrivano al valore massimo cioè quattro la sequenza runaway ha inizio e quando finisce una pagina di gameover viene mostrata assiema a un pulsante di reset
	**non appena si preme il tasto select tutte le variabili sono reinizializzate e il programma riparte da capo.
	** DA NOTARE: durante la sequenza dove l'alieno mangia il RIT viene disabilitato per impedire all'utente di selezionare altri tasti durante l'animazione come da specifiche di progetto. 
	** 
	*/ 
	
	/* Match register 0 interrupt service routine */
	//inizio match registe 1
	if (LPC_TIM0->IR & 01)
	{
		// controllo se counterfame o counterfelicta sono al massimo 
		//se si l'alieno deve scappare
		if ((counterfame==4) || (counterfelicita==4))
		{
			ageTamagotchired(hr,min,sec);//mostro l'età finale
			gestiscifelicitared(counterfelicita);
			gestiscifamered(counterfame); //mostro il valore finale nella batteria
			
			
			if (flaganimazionerunaway==0)// flag per evitare che l'animazione runaway sia mostrata più di una volta 
			{
				
				buttonsneri();
				animazionerunaway(); // parte l'animazione della sequenza runway 
				flaganimazionerunaway=1; //impedisco esecuzione 

			}
			if (select==1)// controllo se il tasto select viene premuto per iniziare il reset
			{
				hr=0;
				min=0;
				sec=0;
				counterfame=0;
				counterfelicita=0;
				countersecfame=0;
				countersecfelicita=0;
				flaganimazionerunaway=0;
				flaganimazionerunaway2=0;
 				select=0;
				right=0;
				left=0;  // azzero tutti i valori per permettere al ciclo successivo un fresh start
				LCD_Clear(Black);
			}
				
		}
		else // se i contatori non sono al massimo eseguo il gioco normalmente.
		{
			// 
			//tramite queste if gestico il conteggio dei secondi e la formattazione 00:00:00 dove i minuti e i secondi non possono superare 60 e in tal caso  fanno aumentare il counter successivo 
			if (sec <= 59) 
			{
				ageTamagotchi (hr,min,sec);
				sec++;
				countersecfame++;
				countersecfelicita++;
			}
			else if (sec > 59 & min <= 59) 
			{
				min++;
				sec = 0;
				ageTamagotchi(hr,min, sec); 
				sec++;
				countersecfame++;
				countersecfelicita++;
				
			}
			else if(min > 59)
			{
				hr++;
				min=0;
				sec=0;
				ageTamagotchi(hr , min , sec);
			}
			//
			// finisco di gestire il timer^
			//
			
			
			frame1(); // mostro il primo frame dell'animazione
			if ((left==0)&&(right==0))// controllo se i tasti left o right sono stati selezionati senno mostro i tasti bianchi
			{
				buttons(); // mostro i tasti bianchi 
			}
			gestiscifame(counterfame);//stampo le batterie con i valori di counterfame e counterfelicita 
  			gestiscifelicita(counterfelicita);
	
			if( left == 1 ) // se ho selezionato sinistra sul joystick 
			{	
					buttonleft(); //mostro il bottone di sinistra in rosso per mostrare 
					if (select==1)// se il tasto select del joystick e stato selezionato 
					{
						disable_RIT(); // fermo il RIT per non permettere la selezione di altri tasti 
	
						mangiatameal();  // animo il mangiare del meal 
						if (counterfame>0)
						{
						counterfame--;// diminuisco il counter della fame 
						}
						gestiscifame(counterfame); // mostro nello schermo il nuovo valore nella batteria 
						countersecfame=0; // azzero il conteggio dei secondi di countersecfame
						select=0; // reimposto il select a zero 
						reset_RIT(); // resetto il RIT
						enable_RIT(); // permetto di nuovo di sentire se l'utente preme i pulsanti del joystick 
					}
			}
			
			if( right == 1 )// eseguo esattamenre le stesse istruzioni del blocco precedente ma per il pulsante di destra 
			{	
          buttonright();
          if (select==1)
					{
						disable_RIT();

						mangiatasnack();//animazione dello snack 
						if (counterfelicita>0)
						{
						counterfelicita--;
						}
						gestiscifelicita(counterfelicita);
						countersecfelicita=0;
						select=0;	
						reset_RIT();
						enable_RIT();
					}
			}
			
			if (countersecfame==5) // se sono passati 5 secondi da l'ultima volta che ha mangiato o dall'ultimo decremento della batteria allora viene decrementato di nuovo la batteria 
			{
				if (counterfame<4)
				{
				counterfame++;
				
				}
				countersecfame=0;
			}
			
			if (countersecfelicita==5) // se sono passati 5 secondi da l'ultima volta che ha mangiato o dall'ultimo decremento della batteria allora viene decrementato di nuovo la batteria
			{
				if(counterfelicita<4)
				{
				counterfelicita++;
				}	
				countersecfelicita=0;
			}
		}
		LPC_TIM0->IR = 1;			/* clear interrupt flag */
	
	}
	else 
	{
 		if (LPC_TIM0->IR & 02) //match register 2 
	{	
		// in questo match register controllo se l'animazione numero uno della sequenza runaway é stata mostrata a schermo 
		// in tal caso si ignifica che l'alieno è scappato e che bisogna far vedere la seconda parte dell'animazione, 
		// e poi mostrare la schermatat di reset, e aspettare che l'utente schiacci reset per ricominciare a giocare 
		if (flaganimazionerunaway==1)
		{
			if (flaganimazionerunaway2==0)
			{
			animazionerunaway2();
				displayreset();// mostra la schermata di gameover 
				flaganimazionerunaway2=1;// impedisce che il blocco sia rieseguito 
			}
			
			if (select==1)
			{
				hr=0;
				min=0;
				sec=0;
				counterfame=0;
				counterfelicita=0;
				countersecfame=0;
				countersecfelicita=0;
				flaganimazionerunaway=0;
				flaganimazionerunaway2=0;
 				select=0;
				right=0;
				left=0;
				LCD_Clear(Black); // reset completo delle variabili per un fresh start 
			}
				
		}
		else
		{
		
		frame2();  // animazione del frame due 
			
			
		
		}
		LPC_TIM0->IR = 2;			/* clear interrupt flag */
	}
}
  return;
}


/******************************************************************************
** Function name:		Timer1_IRQHandler
**
** Descriptions:		Timer/Counter 1 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
void TIMER1_IRQHandler (void)
{
  LPC_TIM1->IR = 1;			/* clear interrupt flag */
  return;
}

/******************************************************************************
** Function name:		Timer2_IRQHandler
**
** Descriptions:		Timer/Counter 2 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
void TIMER2_IRQHandler (void)
{
  LPC_TIM2->IR = 1;			/* clear interrupt flag */
  return;
}





/******************************************************************************
**                            End Of File
******************************************************************************/
