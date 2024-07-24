#include "LPC17xx.h"
#include "GLCD/GLCD.h" 
#include "TouchPanel/TouchPanel.h"
#include "timer/timer.h"
#include "RIT/RIT.h"
#include <string.h>
#include "joystick/joystick.h"

/*********************************************************************************************************
      funzione snack stampa lo snack (pizza) ¯\_(^.^)_/¯
*********************************************************************************************************/

void snack()
{
	LCD_DrawCircle(20,200,10,Yellow);
	LCD_DrawCircle(20,200,9,Red);
	LCD_DrawCircle(20,200,8,White);
	LCD_DrawCircle(20,200,7,Red);
	LCD_DrawCircle(20,200,6,Red);
	LCD_DrawCircle(20,200,5,Red);
	LCD_DrawCircle(20,200,4,White);
	LCD_DrawCircle(20,200,3,Red);
	LCD_DrawCircle(20,200,2,Red);
	LCD_DrawCircle(20,200,1,Red);
	LCD_DrawCircle(20,200,9,Red);
}


/*********************************************************************************************************
      funzione meal stampa il meal (cibo alieno blu) ¯\_(^.^)_/¯

*********************************************************************************************************/
void meal()
{
	LCD_DrawRectangle(20,200,10,10,Blue);
	LCD_DrawRectangle(20,200,10,10,Blue2);
	LCD_DrawRectangle(20,200,10,10,Blue);
	LCD_DrawRectangle(20,200,10,10,Blue2);
	LCD_DrawRectangle(20,200,10,10,Blue);
	LCD_DrawRectangle(20,200,10,10,Blue2);
	
}

/*********************************************************************************************************
      funzione mealnero cancella il meal 

*********************************************************************************************************/
void mealnero()
{
	LCD_DrawRectangle(20,200,10,10,Black);
	LCD_DrawRectangle(20,200,10,10,Black);
	LCD_DrawRectangle(20,200,10,10,Black);
	LCD_DrawRectangle(20,200,10,10,Black);
	LCD_DrawRectangle(20,200,10,10,Black);
	LCD_DrawRectangle(20,200,10,10,Black);
	
}


/*********************************************************************************************************
      funzione snacknero cancella lo snack

*********************************************************************************************************/
void snacknero()
{
	LCD_DrawCircle(20,200,10,Black);
	LCD_DrawCircle(20,200,9,Black);
	LCD_DrawCircle(20,200,8,Black);
	LCD_DrawCircle(20,200,7,Black);
	LCD_DrawCircle(20,200,6,Black);
	LCD_DrawCircle(20,200,5,Black);
	LCD_DrawCircle(20,200,4,Black);
	LCD_DrawCircle(20,200,3,Black);
	LCD_DrawCircle(20,200,2,Black);
	LCD_DrawCircle(20,200,1,Black);
	LCD_DrawCircle(20,200,9,Black);

}


/*********************************************************************************************************
      funzione alienoverdesinistra stampa l'alieno in posiszione a sinistra
*********************************************************************************************************/

void alienoverdesinistra()
{
	LCD_DrawRectangle(30,120,10,10,Green);
	LCD_DrawRectangle(90,120,10,10,Green);
	LCD_DrawRectangle(40,130,10,10,Green);
	LCD_DrawRectangle(80,130,10,10,Green);
	LCD_DrawRectangle(30,140,70,10,Green);
	LCD_DrawRectangle(20,150,20,10,Green);
	LCD_DrawRectangle(50,150,30,10,Green);
	LCD_DrawRectangle(90,150,20,10,Green);
	LCD_DrawRectangle(10,160,110,10,Green);
	LCD_DrawRectangle(20,150,20,10,Green); 
	LCD_DrawRectangle(10,170,10,20,Green); /*blackout after*/
	LCD_DrawRectangle(30,170,70,10,Green);
	LCD_DrawRectangle(110,170,10,20,Green); /*blackout after*/
	LCD_DrawRectangle(30,180,10,10,Green);
	LCD_DrawRectangle(90,180,10,10,Green);
	LCD_DrawRectangle(40,190,20,10,Green);/*blackout after*/
	LCD_DrawRectangle(70,190,20,10,Green);/*blackout after*/
}

/*********************************************************************************************************
      funzione alienonerosinistra cancella l'alieno in posiszione a sinistra
*********************************************************************************************************/
void alienonerosinistra()
{
	LCD_DrawRectangle(10,120,110,80,Black);
	
	/*LCD_DrawRectangle(30,120,10,10,Black);
	LCD_DrawRectangle(100,120,10,10,Black);
	LCD_DrawRectangle(40,130,10,10,Black);
	LCD_DrawRectangle(80,130,10,10,Black);
	LCD_DrawRectangle(30,140,70,10,Black);
	LCD_DrawRectangle(20,150,20,10,Black);
	LCD_DrawRectangle(50,150,30,10,Black);
	LCD_DrawRectangle(90,150,20,10,Black);
	LCD_DrawRectangle(10,160,110,10,Black);
	LCD_DrawRectangle(20,150,20,10,Black); 
	LCD_DrawRectangle(10,170,10,20,Black); 
	LCD_DrawRectangle(30,170,70,10,Black);
	LCD_DrawRectangle(110,170,10,20,Black); 
	LCD_DrawRectangle(30,180,10,10,Black);
	LCD_DrawRectangle(90,180,10,10,Black);
	LCD_DrawRectangle(40,190,20,10,Black);
	LCD_DrawRectangle(70,190,20,10,Black);*/

}

/*********************************************************************************************************
      funzione alienoverde stampa l'alieno in posiszione iniziale
*********************************************************************************************************/
void alienoverde1()
{
	LCD_DrawRectangle(90,120,10,10,Green);
	LCD_DrawRectangle(150,120,10,10,Green);
	LCD_DrawRectangle(100,130,10,10,Green);
	LCD_DrawRectangle(140,130,10,10,Green);
	LCD_DrawRectangle(90,140,70,10,Green);
	LCD_DrawRectangle(80,150,20,10,Green);
	LCD_DrawRectangle(110,150,30,10,Green);
	LCD_DrawRectangle(150,150,20,10,Green);
	LCD_DrawRectangle(70,160,110,10,Green);
	LCD_DrawRectangle(80,150,20,10,Green); 
	LCD_DrawRectangle(70,170,10,20,Green); /*blackout after*/
	LCD_DrawRectangle(90,170,70,10,Green);
	LCD_DrawRectangle(170,170,10,20,Green); /*blackout after*/
	LCD_DrawRectangle(90,180,10,10,Green);
	LCD_DrawRectangle(150,180,10,10,Green);
	LCD_DrawRectangle(100,190,20,10,Green);/*blackout after*/
	LCD_DrawRectangle(130,190,20,10,Green);
}


/*********************************************************************************************************
      funzione alienonero cancella l'alieno in posizione iniziale
*********************************************************************************************************/

void alienonero1()
{
	LCD_DrawRectangle(90,120,10,10,Black);
	LCD_DrawRectangle(150,120,10,10,Black);
	LCD_DrawRectangle(100,130,10,10,Black);
	LCD_DrawRectangle(140,130,10,10,Black);
	LCD_DrawRectangle(90,140,70,10,Black);
	LCD_DrawRectangle(80,150,20,10,Black);
	LCD_DrawRectangle(110,150,30,10,Black);
	LCD_DrawRectangle(150,150,20,10,Black);
	LCD_DrawRectangle(70,160,110,10,Black);
	LCD_DrawRectangle(80,150,20,10,Black); 
	LCD_DrawRectangle(70,170,10,20,Black); /*blackout after*/
	LCD_DrawRectangle(90,170,70,10,Black);
	LCD_DrawRectangle(170,170,10,20,Black); /*blackout after*/
	LCD_DrawRectangle(90,180,10,10,Black);
	LCD_DrawRectangle(150,180,10,10,Black);
	LCD_DrawRectangle(100,190,20,10,Black);/*blackout after*/
	LCD_DrawRectangle(130,190,20,10,Black);

}


/*********************************************************************************************************
      funzione alienoverde 2 stampa l'alieno nella seconda posizione
*********************************************************************************************************/

void alienoverde2()
{
	LCD_DrawRectangle(90,120,10,10,Green);
	LCD_DrawRectangle(150,120,10,10,Green);
	LCD_DrawRectangle(100,130,10,10,Green);
	LCD_DrawRectangle(140,130,10,10,Green);
	LCD_DrawRectangle(90,140,70,10,Green);
	LCD_DrawRectangle(80,150,20,10,Green);
	LCD_DrawRectangle(110,150,30,10,Green);
	LCD_DrawRectangle(150,150,20,10,Green);
	LCD_DrawRectangle(70,160,110,10,Green);
	LCD_DrawRectangle(80,150,20,10,Green); 
	LCD_DrawRectangle(90,170,70,10,Green);
	LCD_DrawRectangle(90,180,10,10,Green);
	LCD_DrawRectangle(150,180,10,10,Green);
	LCD_DrawRectangle(70,130,10,30,Green);/*blackout after*/
	LCD_DrawRectangle(170,130,10,30,Green);/*blackout after*/
	LCD_DrawRectangle(80,170,10,10,Green);/*blackout after*/
	LCD_DrawRectangle(160,170,10,10,Green);/*blackout after*/
	LCD_DrawRectangle(80,190,10,10,Green);/*blackout after*/
	LCD_DrawRectangle(160,190,10,10,Green);
}


/*********************************************************************************************************
      funzione alienonero cancella l'alieno in seconda posizione 
*********************************************************************************************************/

void alienonero2()
{
	LCD_DrawRectangle(90,120,10,10,Black);
	LCD_DrawRectangle(150,120,10,10,Black);
	LCD_DrawRectangle(100,130,10,10,Black);
	LCD_DrawRectangle(140,130,10,10,Black);
	LCD_DrawRectangle(90,140,70,10,Black);
	LCD_DrawRectangle(80,150,20,10,Black);
	LCD_DrawRectangle(110,150,30,10,Black);
	LCD_DrawRectangle(150,150,20,10,Black);
	LCD_DrawRectangle(70,160,110,10,Black);
	LCD_DrawRectangle(80,150,20,10,Black); 
	LCD_DrawRectangle(90,170,70,10,Black);
	LCD_DrawRectangle(90,180,10,10,Black);
	LCD_DrawRectangle(150,180,10,10,Black);
	LCD_DrawRectangle(70,130,10,30,Black);/*blackout after*/
	LCD_DrawRectangle(170,130,10,30,Black);/*blackout after*/
	LCD_DrawRectangle(80,170,10,10,Black);/*blackout after*/
	LCD_DrawRectangle(160,170,10,10,Black);/*blackout after*/
	LCD_DrawRectangle(80,190,10,10,Black);/*blackout after*/
	LCD_DrawRectangle(160,190,10,10,Black);

}





/*********************************************************************************************************
funzione buttons stamapa i bottoni bianchi 
*********************************************************************************************************/

void buttons()
{
		//PULSANTI
	LCD_DrawLine(10,269,110,269,White);
	LCD_DrawLine(10,269,10,309,White);
	LCD_DrawLine(110,269,110,309,White);
	LCD_DrawLine(10,309,110,309,White);
	LCD_DrawLine(129,269,229,269,White);
	LCD_DrawLine(129,309,229,309,White);
	LCD_DrawLine(129,269,129,309,White);
	LCD_DrawLine(229,269,229,309,White);
	GUI_Text(45, 283,(uint8_t*)"MEAL",Black,White);
	GUI_Text(164, 283,(uint8_t*)"SNACK",Black,White);
}


/*********************************************************************************************************
      funzione buttonsneri cancella i bottoni
*********************************************************************************************************/

void buttonsneri()
{
	LCD_DrawLine(10,269,110,269,Black);
	LCD_DrawLine(10,269,10,309,Black);
	LCD_DrawLine(110,269,110,309,Black);
	LCD_DrawLine(10,309,110,309,Black);
	LCD_DrawLine(129,269,229,269,Black);
	LCD_DrawLine(129,309,229,309,Black);
	LCD_DrawLine(129,269,129,309,Black);
	LCD_DrawLine(229,269,229,309,Black);
	GUI_Text(45, 283,(uint8_t*)"MEAL",Black,Black);
	GUI_Text(164, 283,(uint8_t*)"SNACK",Black,Black);

}


/*********************************************************************************************************
      funzione buttonsreset stampa il bottone di reset
*********************************************************************************************************/

void buttonsreset()
{
	LCD_DrawLine(10,269,229,269,Red);
	LCD_DrawLine(229,269,229,309,Red);
	LCD_DrawLine(229,309,10,309,Red);
	LCD_DrawLine(10,309,10,269,Red);
	GUI_Text(110, 283,(uint8_t*)"RESET",Black,Red);
	
	
}
	


/*********************************************************************************************************
      funzione buttonleft stampa il bottone di sinistra in rosso per far capire che è selezionato 
*********************************************************************************************************/

void buttonleft()
{
	LCD_DrawLine(129,269,229,269,White);
	LCD_DrawLine(129,309,229,309,White);
	LCD_DrawLine(129,269,129,309,White);
	LCD_DrawLine(229,269,229,309,White);
	GUI_Text(164, 283,(uint8_t*)"SNACK",Black,White);
	LCD_DrawLine(10,269,110,269,Red);
	LCD_DrawLine(10,269,10,309,Red);
	LCD_DrawLine(110,269,110,309,Red);
	LCD_DrawLine(10,309,110,309,Red);
	GUI_Text(45, 283,(uint8_t*)"MEAL",Black,Red);
}


/*********************************************************************************************************
      funzione buttonright stampa il bottone di destra in rosso per far capire che è selezionato 
*********************************************************************************************************/
void buttonright()
{
	LCD_DrawLine(10,269,110,269,White);
	LCD_DrawLine(10,269,10,309,White);
	LCD_DrawLine(110,269,110,309,White);
	LCD_DrawLine(10,309,110,309,White);
	GUI_Text(45, 283,(uint8_t*)"MEAL",Black,White);
	LCD_DrawLine(129,269,229,269,Red);
	LCD_DrawLine(129,309,229,309,Red);
	LCD_DrawLine(129,269,129,309,Red);
	LCD_DrawLine(229,269,229,309,Red);
	GUI_Text(164, 283,(uint8_t*)"SNACK",Black,Red);

}
	


/*********************************************************************************************************
      funzione ageTamagotchi stampa l'età del tamagotchi 
*********************************************************************************************************/

void ageTamagotchi(int hr, int min, int sec)
{
	char vett[10];
	sprintf(vett, " %02d:%02d:%02d ", hr, min,sec);
		GUI_Text(80,10,(uint8_t *) vett,Black,White);
}

/*********************************************************************************************************
      funzione ageTamagotchired stampa l'età del tamagotchi rossa
*********************************************************************************************************/

void ageTamagotchired(int hr, int min, int sec)
{
	char vett[10];
	sprintf(vett, " %02d:%02d:%02d ", hr, min,sec);
		GUI_Text(80,10,(uint8_t *) vett,Black,Red);
}


/*********************************************************************************************************
      funzione batterie stampa le batterie  
*********************************************************************************************************/
void batterie()
{
	// left
	LCD_DrawLine(38,38,101,38,White);
	LCD_DrawLine(101,38,101,71,White);
	LCD_DrawLine(101,71,38,71,White);
	LCD_DrawLine(38,71,38,38,White);
	LCD_DrawRectangle(40,40,14,29,White);
	LCD_DrawRectangle(55,40,14,29,White);
	LCD_DrawRectangle(70,40,14,29,White);
	LCD_DrawRectangle(85,40,14,29,White);
	GUI_Text(40,73,(uint8_t *) "Happyness",Black,White);
	
	
	//right
	LCD_DrawLine(138,38,201,38,White);
	LCD_DrawLine(201,38,201,71,White);
	LCD_DrawLine(201,71,138,71,White);
	LCD_DrawLine(138,71,138,38,White);
	LCD_DrawRectangle(140,40,14,29,White);
	LCD_DrawRectangle(155,40,14,29,White);
	LCD_DrawRectangle(170,40,14,29,White);
	LCD_DrawRectangle(185,40,14,29,White);
	GUI_Text(140,73,(uint8_t *) "Satiety",Black,White);
	
}

/*********************************************************************************************************
      funzione batterie stampa le batterie  rosse
*********************************************************************************************************/
void batteriered()
{
LCD_DrawLine(38,38,101,38,Red);
	LCD_DrawLine(101,38,101,71,Red);
	LCD_DrawLine(101,71,38,71,Red);
	LCD_DrawLine(38,71,38,38,Red);
	LCD_DrawRectangle(40,40,14,29,Red);
	LCD_DrawRectangle(55,40,14,29,Red);
	LCD_DrawRectangle(70,40,14,29,Red);
	LCD_DrawRectangle(85,40,14,29,Red);
	GUI_Text(40,73,(uint8_t *) "Happyness",Black,Red);
	
	
	//right
	LCD_DrawLine(138,38,201,38,Red);
	LCD_DrawLine(201,38,201,71,Red);
	LCD_DrawLine(201,71,138,71,Red);
	LCD_DrawLine(138,71,138,38,Red);
	LCD_DrawRectangle(140,40,14,29,Red);
	LCD_DrawRectangle(155,40,14,29,Red);
	LCD_DrawRectangle(170,40,14,29,Red);
	LCD_DrawRectangle(185,40,14,29,Red);
	GUI_Text(140,73,(uint8_t *) "Satiety",Black,Red);

	
}


/*********************************************************************************************************
      funzione gestiscifame gestisce quanto sono piene le batterie a seconda del valore counterfame
			valore 0 batteria piena
			valore 4 batteria vuota
*********************************************************************************************************/
void gestiscifame(int counterfame)
{
	if(counterfame==0)
	{
	LCD_DrawLine(138,38,201,38,White);
	LCD_DrawLine(201,38,201,71,White);
	LCD_DrawLine(201,71,138,71,White);
	LCD_DrawLine(138,71,138,38,White);
	LCD_DrawRectangle(140,40,14,29,White);
	LCD_DrawRectangle(155,40,14,29,White);
	LCD_DrawRectangle(170,40,14,29,White);
	LCD_DrawRectangle(185,40,14,29,White);
			GUI_Text(140,73,(uint8_t *) "Satiety",Black,White);
		
	}
	
	if(counterfame==1)
	{
LCD_DrawLine(138,38,201,38,White);
	LCD_DrawLine(201,38,201,71,White);
	LCD_DrawLine(201,71,138,71,White);
	LCD_DrawLine(138,71,138,38,White);
	LCD_DrawRectangle(140,40,14,29,White);
	LCD_DrawRectangle(155,40,14,29,White);
	LCD_DrawRectangle(170,40,14,29,White);
	LCD_DrawRectangle(185,40,14,29,Black);
			GUI_Text(140,73,(uint8_t *) "Satiety",Black,White);
	}
	
	if(counterfame==2)
	{
LCD_DrawLine(138,38,201,38,White);
	LCD_DrawLine(201,38,201,71,White);
	LCD_DrawLine(201,71,138,71,White);
	LCD_DrawLine(138,71,138,38,White);
	LCD_DrawRectangle(140,40,14,29,White);
	LCD_DrawRectangle(155,40,14,29,White);
	LCD_DrawRectangle(170,40,14,29,Black);
	LCD_DrawRectangle(185,40,14,29,Black);
			GUI_Text(140,73,(uint8_t *) "Satiety",Black,White);
	}
	
	if(counterfame==3)
	{
	LCD_DrawLine(138,38,201,38,White);
	LCD_DrawLine(201,38,201,71,White);
	LCD_DrawLine(201,71,138,71,White);
	LCD_DrawLine(138,71,138,38,White);
	LCD_DrawRectangle(140,40,14,29,White);
	LCD_DrawRectangle(155,40,14,29,Black);
	LCD_DrawRectangle(170,40,14,29,Black);
	LCD_DrawRectangle(185,40,14,29,Black);
			GUI_Text(140,73,(uint8_t *) "Satiety",Black,White);
	}
	
	if(counterfame==4)
	{
	LCD_DrawLine(138,38,201,38,White);
	LCD_DrawLine(201,38,201,71,White);
	LCD_DrawLine(201,71,138,71,White);
	LCD_DrawLine(138,71,138,38,White);
	LCD_DrawRectangle(140,40,14,29,Black);
	LCD_DrawRectangle(155,40,14,29,Black);
	LCD_DrawRectangle(170,40,14,29,Black);
	LCD_DrawRectangle(185,40,14,29,Black);
			GUI_Text(140,73,(uint8_t *) "Satiety",Black,White);
	}
}

/*********************************************************************************************************
      funzione gestiscifamered gestisce quanto sono piene le batterie a seconda del valore counterfame
			valore 0 batteria piena
			valore 4 batteria vuota
*********************************************************************************************************/
void gestiscifamered(int counterfame)
{
	
	
	if(counterfame==0)
	{
	LCD_DrawLine(138,38,201,38,Red);
	LCD_DrawLine(201,38,201,71,Red);
	LCD_DrawLine(201,71,138,71,Red);
	LCD_DrawLine(138,71,138,38,Red);
	LCD_DrawRectangle(140,40,14,29,Red);
	LCD_DrawRectangle(155,40,14,29,Red);
	LCD_DrawRectangle(170,40,14,29,Red);
	LCD_DrawRectangle(185,40,14,29,Red);
			GUI_Text(140,73,(uint8_t *) "Satiety",Black,Red);
		
	}
	
	if(counterfame==1)
	{
LCD_DrawLine(138,38,201,38,Red);
	LCD_DrawLine(201,38,201,71,Red);
	LCD_DrawLine(201,71,138,71,Red);
	LCD_DrawLine(138,71,138,38,Red);
	LCD_DrawRectangle(140,40,14,29,Red);
	LCD_DrawRectangle(155,40,14,29,Red);
	LCD_DrawRectangle(170,40,14,29,Red);
	LCD_DrawRectangle(185,40,14,29,Black);
			GUI_Text(140,73,(uint8_t *) "Satiety",Black,Red);
	}
	
	if(counterfame==2)
	{
LCD_DrawLine(138,38,201,38,Red);
	LCD_DrawLine(201,38,201,71,Red);
	LCD_DrawLine(201,71,138,71,Red);
	LCD_DrawLine(138,71,138,38,Red);
	LCD_DrawRectangle(140,40,14,29,Red);
	LCD_DrawRectangle(155,40,14,29,Red);
	LCD_DrawRectangle(170,40,14,29,Black);
	LCD_DrawRectangle(185,40,14,29,Black);
			GUI_Text(140,73,(uint8_t *) "Satiety",Black,Red);
	}
	
	if(counterfame==3)
	{
	LCD_DrawLine(138,38,201,38,Red);
	LCD_DrawLine(201,38,201,71,Red);
	LCD_DrawLine(201,71,138,71,Red);
	LCD_DrawLine(138,71,138,38,Red);
	LCD_DrawRectangle(140,40,14,29,Red);
	LCD_DrawRectangle(155,40,14,29,Black);
	LCD_DrawRectangle(170,40,14,29,Black);
	LCD_DrawRectangle(185,40,14,29,Black);
			GUI_Text(140,73,(uint8_t *) "Satiety",Black,Red);
	}
	
	if(counterfame==4)
	{
	LCD_DrawLine(138,38,201,38,Red);
	LCD_DrawLine(201,38,201,71,Red);
	LCD_DrawLine(201,71,138,71,Red);
	LCD_DrawLine(138,71,138,38,Red);
	LCD_DrawRectangle(140,40,14,29,Black);
	LCD_DrawRectangle(155,40,14,29,Black);
	LCD_DrawRectangle(170,40,14,29,Black);
	LCD_DrawRectangle(185,40,14,29,Black);
			GUI_Text(140,73,(uint8_t *) "Satiety",Black,Red);

	
	}
}




/*********************************************************************************************************
      funzione gestiscifelicitared gestisce quanto sono piene le batterie a seconda del valore counterfame
			valore 0 batteria piena
			valore 4 batteria vuota
*********************************************************************************************************/
void gestiscifelicitared(int counterfelicita)
{
	if(counterfelicita==0)
	{
	LCD_DrawLine(38,38,101,38,Red);
	LCD_DrawLine(101,38,101,71,Red);
	LCD_DrawLine(101,71,38,71,Red);
	LCD_DrawLine(38,71,38,38,Red);
	LCD_DrawRectangle(40,40,14,29,Red);
	LCD_DrawRectangle(55,40,14,29,Red);
	LCD_DrawRectangle(70,40,14,29,Red);
	LCD_DrawRectangle(85,40,14,29,Red);
		GUI_Text(40,73,(uint8_t *) "Happyness",Black,Red);
	}
	
	if(counterfelicita==1)
	{
	LCD_DrawLine(38,38,101,38,Red);
	LCD_DrawLine(101,38,101,71,Red);
	LCD_DrawLine(101,71,38,71,Red);
	LCD_DrawLine(38,71,38,38,Red);
	LCD_DrawRectangle(40,40,14,29,Red);
	LCD_DrawRectangle(55,40,14,29,Red);
	LCD_DrawRectangle(70,40,14,29,Red);
	LCD_DrawRectangle(85,40,14,29,Black);
		GUI_Text(40,73,(uint8_t *) "Happyness",Black,Red);
	}
	
	if(counterfelicita==2)
	{
LCD_DrawLine(38,38,101,38,Red);
	LCD_DrawLine(101,38,101,71,Red);
	LCD_DrawLine(101,71,38,71,Red);
	LCD_DrawLine(38,71,38,38,Red);
	LCD_DrawRectangle(40,40,14,29,Red);
	LCD_DrawRectangle(55,40,14,29,Red);
	LCD_DrawRectangle(70,40,14,29,Black);
	LCD_DrawRectangle(85,40,14,29,Black);
		GUI_Text(40,73,(uint8_t *) "Happyness",Black,Red);
	}
	
	if(counterfelicita==3)
	{
	LCD_DrawLine(38,38,101,38,Red);
	LCD_DrawLine(101,38,101,71,Red);
	LCD_DrawLine(101,71,38,71,Red);
	LCD_DrawLine(38,71,38,38,Red);
	LCD_DrawRectangle(40,40,14,29,Red);
	LCD_DrawRectangle(55,40,14,29,Black);
	LCD_DrawRectangle(70,40,14,29,Black);
	LCD_DrawRectangle(85,40,14,29,Black);
		GUI_Text(40,73,(uint8_t *) "Happyness",Black,Red);
	}
	
	if(counterfelicita==4)
	{
LCD_DrawLine(38,38,101,38,Red);
	LCD_DrawLine(101,38,101,71,Red);
	LCD_DrawLine(101,71,38,71,Red);
	LCD_DrawLine(38,71,38,38,Red);
	LCD_DrawRectangle(40,40,14,29,Black);
	LCD_DrawRectangle(55,40,14,29,Black);
	LCD_DrawRectangle(70,40,14,29,Black);
	LCD_DrawRectangle(85,40,14,29,Black);
		GUI_Text(40,73,(uint8_t *) "Happyness",Black,Red);
	}

}

/*********************************************************************************************************
      funzione gestiscifelicita gestisce quanto sono piene le batterie a seconda del valore counterfelicita
			valore 0 batteria piena
			valore 4 batteria vuota
*********************************************************************************************************/
void gestiscifelicita(int counterfelicita)
{
	if(counterfelicita==0)
	{
	LCD_DrawLine(38,38,101,38,White);
	LCD_DrawLine(101,38,101,71,White);
	LCD_DrawLine(101,71,38,71,White);
	LCD_DrawLine(38,71,38,38,White);
	LCD_DrawRectangle(40,40,14,29,White);
	LCD_DrawRectangle(55,40,14,29,White);
	LCD_DrawRectangle(70,40,14,29,White);
	LCD_DrawRectangle(85,40,14,29,White);
		GUI_Text(40,73,(uint8_t *) "Happyness",Black,White);
	}
	
	if(counterfelicita==1)
	{
	LCD_DrawLine(38,38,101,38,White);
	LCD_DrawLine(101,38,101,71,White);
	LCD_DrawLine(101,71,38,71,White);
	LCD_DrawLine(38,71,38,38,White);
	LCD_DrawRectangle(40,40,14,29,White);
	LCD_DrawRectangle(55,40,14,29,White);
	LCD_DrawRectangle(70,40,14,29,White);
	LCD_DrawRectangle(85,40,14,29,Black);
		GUI_Text(40,73,(uint8_t *) "Happyness",Black,White);
	}
	
	if(counterfelicita==2)
	{
LCD_DrawLine(38,38,101,38,White);
	LCD_DrawLine(101,38,101,71,White);
	LCD_DrawLine(101,71,38,71,White);
	LCD_DrawLine(38,71,38,38,White);
	LCD_DrawRectangle(40,40,14,29,White);
	LCD_DrawRectangle(55,40,14,29,White);
	LCD_DrawRectangle(70,40,14,29,Black);
	LCD_DrawRectangle(85,40,14,29,Black);
		GUI_Text(40,73,(uint8_t *) "Happyness",Black,White);
	}
	
	if(counterfelicita==3)
	{
	LCD_DrawLine(38,38,101,38,White);
	LCD_DrawLine(101,38,101,71,White);
	LCD_DrawLine(101,71,38,71,White);
	LCD_DrawLine(38,71,38,38,White);
	LCD_DrawRectangle(40,40,14,29,White);
	LCD_DrawRectangle(55,40,14,29,Black);
	LCD_DrawRectangle(70,40,14,29,Black);
	LCD_DrawRectangle(85,40,14,29,Black);
		GUI_Text(40,73,(uint8_t *) "Happyness",Black,White);
	}
	
	if(counterfelicita==4)
	{
LCD_DrawLine(38,38,101,38,White);
	LCD_DrawLine(101,38,101,71,White);
	LCD_DrawLine(101,71,38,71,White);
	LCD_DrawLine(38,71,38,38,White);
	LCD_DrawRectangle(40,40,14,29,Black);
	LCD_DrawRectangle(55,40,14,29,Black);
	LCD_DrawRectangle(70,40,14,29,Black);
	LCD_DrawRectangle(85,40,14,29,Black);
		GUI_Text(40,73,(uint8_t *) "Happyness",Black,White);
	}
}


/*********************************************************************************************************
      funzione mangiatasnack anima la mangiata dello snack
*********************************************************************************************************/

void mangiatasnack()
{
	buttons();
	snack();
	alienonero1();
	alienonero2();
	alienoverdesinistra();
}


/*********************************************************************************************************
      funzione mangiatameal anima la mangiata del meal
*********************************************************************************************************/
void mangiatameal()
{
	
	buttons();
	meal();
	alienonero1();
	alienonero2();
	alienoverdesinistra();
	
}




/*********************************************************************************************************
      funzione frame1 anima il frame uno dell'animazione 
*********************************************************************************************************/
void frame1(void)
{	
	//mealnero();
	//snacknero();	
	//alienonerosinistra();
	alienonero2();	
	

	alienoverde1();

	
}

/*********************************************************************************************************
      funzione frame2 anima il frame due dell'animazione 
*********************************************************************************************************/
void frame2(void)
{
	mealnero();
	snacknero();
	alienonerosinistra();
	alienonero1();
	alienoverde2();
	

}



/*********************************************************************************************************
      funzione navicella disegna la navicella in posizione centrale
*********************************************************************************************************/
void navicella()
{
	LCD_DrawRectangle(90,120,60,10,Red);
	LCD_DrawRectangle(70,130,100,10,Red);
	LCD_DrawRectangle(60,140,120,10,Red);
	LCD_DrawRectangle(50,150,20,10,Red);
	LCD_DrawRectangle(80,150,20,10,Red);
	LCD_DrawRectangle(80,150,20,10,Red);
	LCD_DrawRectangle(110,150,20,10,Red);
	LCD_DrawRectangle(140,150,20,10,Red);
	LCD_DrawRectangle(170,150,20,10,Red);
	LCD_DrawRectangle(40,160,160,10,Red);
	LCD_DrawRectangle(60,170,30,10,Red);
	LCD_DrawRectangle(110,170,20,10,Red);
	LCD_DrawRectangle(150,170,30,10,Red);
	LCD_DrawRectangle(70,180,10,10,Red);
	LCD_DrawRectangle(160,180,10,10,Red);
}
/*********************************************************************************************************
      funzione navicella2 stampa la navicella nella posizione più in alto 
*********************************************************************************************************/

void navicella2()
{
	LCD_DrawRectangle(90,90,60,10,Red);
	LCD_DrawRectangle(70,100,100,10,Red);
	LCD_DrawRectangle(60,110,120,10,Red);
	LCD_DrawRectangle(50,120,20,10,Red);
	LCD_DrawRectangle(80,120,20,10,Red);
	LCD_DrawRectangle(80,120,20,10,Red);
	LCD_DrawRectangle(110,120,20,10,Red);
	LCD_DrawRectangle(140,120,20,10,Red);
	LCD_DrawRectangle(170,120,20,10,Red);
	LCD_DrawRectangle(40,130,160,10,Red);
	LCD_DrawRectangle(60,140,30,10,Red);
	LCD_DrawRectangle(110,140,20,10,Red);
	LCD_DrawRectangle(150,140,30,10,Red);
	LCD_DrawRectangle(70,150,10,10,Red);
	LCD_DrawRectangle(160,150,10,10,Red);
}


/*********************************************************************************************************
      funzione navicellanera cancella la navicella in posizione centrale
*********************************************************************************************************/

void navicellanera()
{
	LCD_DrawRectangle(90,120,60,10,Black);
	LCD_DrawRectangle(70,130,100,10,Black);
	LCD_DrawRectangle(60,140,120,10,Black);
	LCD_DrawRectangle(50,150,20,10,Black);
	LCD_DrawRectangle(80,150,20,10,Black);
	LCD_DrawRectangle(80,150,20,10,Black);
	LCD_DrawRectangle(110,150,20,10,Black);
	LCD_DrawRectangle(140,150,20,10,Black);
	LCD_DrawRectangle(170,150,20,10,Black);
	LCD_DrawRectangle(40,160,160,10,Black);
	LCD_DrawRectangle(60,170,30,10,Black);
	LCD_DrawRectangle(110,170,20,10,Black);
	LCD_DrawRectangle(150,170,30,10,Black);
	LCD_DrawRectangle(70,180,10,10,Black);
	LCD_DrawRectangle(160,180,10,10,Black);

}


/*********************************************************************************************************
      funzione navicellanera2 cancella la navicella in posizione più in alto
*********************************************************************************************************/
void navicellanera2()
{
	LCD_DrawRectangle(90,90,60,10,Black);
	LCD_DrawRectangle(70,100,100,10,Black);
	LCD_DrawRectangle(60,110,120,10,Black);
	LCD_DrawRectangle(50,120,20,10,Black);
	LCD_DrawRectangle(80,120,20,10,Black);
	LCD_DrawRectangle(80,120,20,10,Black);
	LCD_DrawRectangle(110,120,20,10,Black);
	LCD_DrawRectangle(140,120,20,10,Black);
	LCD_DrawRectangle(170,120,20,10,Black);
	LCD_DrawRectangle(40,130,160,10,Black);
	LCD_DrawRectangle(60,140,30,10,Black);
	LCD_DrawRectangle(110,140,20,10,Black);
	LCD_DrawRectangle(150,140,30,10,Black);
	LCD_DrawRectangle(70,150,10,10,Black);
	LCD_DrawRectangle(160,150,10,10,Black);

}
	
	

/*********************************************************************************************************
      funzione animazionerunaway anima il primo frame della sequenza run away 
*********************************************************************************************************/

void animazionerunaway()
{
	alienonero2();
	alienonero1();
	navicella();
	
}


/*********************************************************************************************************
      funzione animazionerunaway2 anima il secondo frame della sequenza run away 
*********************************************************************************************************/
void animazionerunaway2()
{
	navicellanera();
	navicella2();
}


/*********************************************************************************************************
      funzione displayreset mostra a schermo la schermata finale di gameover
*********************************************************************************************************/

void displayreset()
{
	
	navicellanera2();
	navicellanera();
	
	
	GUI_Text(110, 150,(uint8_t*)"GAME OVER",Black,Red);
	

	buttonsreset();
	
}	
