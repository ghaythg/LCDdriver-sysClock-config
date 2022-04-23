/********************************************************************************

@brief Systeme Clock Configigration 

                           the systheme clock is configured as follow :
                           ystheme clock source          : PLL (HSE)
                           Sysclock (hz)                 : 160000000
                           HCLK(hz)                      : 160000000
                           AHB prescaler                 : 1
                           APB1 Prescaler                : 4
                           APB2 prescaler                : 2
                           HSE Frequancy                 : 80
                           PLL_M                         : 4
                           PLL_N                         :160
                           PLL_P                         :2
                           VDD (v)                       :3.3v
                           main regulator output voltage : scalel mode 
                           Flash latency (WS)            : 5

@param None 
@retval NOne
***********************************************************************************/

#include "stm32f407xx.h"
#define PLL_N 160;
void sysClookConfig (void)
{
 /***********<<<< step followed >>>>******************************
	1- ENABLE HSE AND WAIT FOR HSE TO BE READY 
	2-SET THE POWER ENABLE CLOCK AND VOLTATGE RAGULATER SETTING
	3-CONFIG THE FLASH PREFTECH AND THE LATENCY RELATED SETTINGS
	4-CONFIG THE PRESCALER HCLK ,PLCK1 AND PLCK 2
	5-CONFIG THE MAIN PLL 
	6-ENABLE PLL AND WAIT FOR HSE TO BE READY
	7-SELECT THE CLOCK SOURCE AND WAIT TO BE READY 
	****************************************************************/
	
	
	/*1- ENABLE HSE AND WAIT FOR HSE TO BE READY*    Registre (RCC_CR)*/  
	RCC->CR |= RCC_CR_HSEON;
	while(!RCC->CR & RCC_CR_HSERDY );
	
	/*2-SET THE POWER ENABLE CLOCK AND VOLTATGE RAGULATER SETTING     Registre ( RCC_APB1ENR) /(PWR_CR)  */
	RCC->APB1ENR |=(RCC_APB1ENR_PWREN);
	PWR->CR |=(PWR_CR_VOS);
	
	/*3-CONFIG THE FLASH PREFTECH AND THE LATENCY RELATED SETTINGS  Registre (FLASH_ACR)           */ 
		/*****************************************************************
	*             VDD VOLTAGE : 3.3 V / FLASH LATENCY 5WS            *                                 
	******************************************************************
	*INSTRCTION CACHE / prefetch buffer / data cache ------> ENABLE  *
	*****************************************************************/ 
	FLASH->ACR |= FLASH_ACR_DCEN;
	FLASH->ACR |= FLASH_ACR_ICEN;
	FLASH->ACR |= FLASH_ACR_PRFTEN;
	FLASH->ACR |= FLASH_ACR_LATENCY_5WS;
	
	/*4-CONFIG THE PRESCALER HCLK ,PLCK1 AND PLCK 2  Registre <RCC_CFGR>*/
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1;
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV4;
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV2;
	
	/*5-CONFIG THE MAIN PLL / PLL_M: 4 /PLL_N :160 /PLL_P:2*/ 
	RCC->PLLCFGR |=RCC_PLLCFGR_PLLM_4;
	RCC->PLLCFGR |= PLL_N;
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLP_0 ;
	RCC->PLLCFGR |=RCC_PLLCFGR_PLLSRC_HSE ;
	
	/*6-ENABLE PLL AND WAIT FOR HSE TO BE READY   Registre  < RCC_CR>*/
	
	RCC->CR |= RCC_CR_PLLON;
  while (!(RCC->CR & RCC_CR_PLLRDY));
	
	/*7-SELECT THE CLOCK SOURCE AND WAIT TO BE READY  Registre<RCC_CFGR>   */
		
		RCC->CFGR |= RCC_CFGR_SWS_PLL;
	  while ((RCC->CFGR & RCC_CFGR_SWS ) != RCC_CFGR_SWS_PLL);
	                    
}