/***********<<<< step followed >>>>******************************
**	@brief set the basics timer TIM6 OU TIM7                     **
**	                                                             **
**	                 TIM 6 : connect to the APB1 bus             ** 
**	                 APB1 Timer clock frenquancy : 8000000 HZ    **
**	                                                             **
**  @param none	                                                 **
**	@retval none                                                 **
	****************************************************************/
	
	
#include "Delay.h"
 void TIM6_config (void)
	
	{
	
		/*************** STEP FOLLOW ***************************
		 1-ENABLE TIMER CLOCK
		 2-SET THE PRESCALER AND THE ARR
		 3-ENABLE THE TIMER AND WAIT FOR THE UPDATE FLAG TO SET
		*******************************************************/
		
		RCC->AHB1ENR |=RCC_APB1ENR_TIM6EN;
		TIM6->PSC = 80-1 ;                 /*80MHZ/80 = 1MHZ ~~ 1us delay*/
		TIM6->ARR = 0xffff;                /* MAX ARR FOR THE VALUE*/
		TIM6->CR1 |= (1<<0);
		while (! (TIM6->CR1) & (TIM6->SR = (1<<0)));
	
	}
 
	
 void Delay_us (uint16_t us) 
	{
		 
		/*************** STEP FOLLOW ***************************
		 1-RESET THE COUNTER
		 2-WAIT THE COUNTER TO REACH THE ENTERED VALUE.AS EACH WILL TAKE 1US
		    THE TOTAL WAITING WILL BE REQUIRED US DELAY
		*******************************************************/
		TIM6->CNT |=0;
		while (! (TIM6->CNT <us));
	}
 
	void Delay_ms (uint16_t ms) 
	{
		 
		/*************** STEP FOLLOW ***************************
		 1-RESET THE COUNTER
		 2-WAIT THE COUNTER TO REACH THE ENTERED VALUE.AS EACH WILL TAKE 1US
		    THE TOTAL WAITING WILL BE REQUIRED US DELAY
		*******************************************************/
		TIM6->CNT |=0;
     for(uint16_t i=0 ; i<ms ;i++)
		{ 
				Delay_us(1000);
		}
	}

	