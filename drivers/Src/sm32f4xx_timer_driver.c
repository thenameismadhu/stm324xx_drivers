/*
 * sm32f4xx_timer_driver.c
 *
 *  Created on: May 20, 2024
 *      Author: Madhu
 */

#include "stm32f4xx_timer_driver.h"


/*
 * Peripheral Clock setup
 */
void TIM_PeriClkCtrl(TIM_RegDef_t *pTIMx,uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
			{
				if(pTIMx == TIM6)
				{
					TIM6_PCLK_EN();
				}
			}
	else{
		if(pTIMx == TIM6)
		{
		TIM6_PCLK_DI();
		}
	}
}

/*
 * TIMER INit
 */

void Timer_Init(TIM_Handle_t *pTIMHandle)
{
	//enable the peripheral clock
	TIM_PeriClkCtrl(pTIMHandle->pTIMx,ENABLE);

	//Enable Timer6
		pTIMHandle->pTIMx->CR1 |= (1<<0);

	////Set Prescaler value
	pTIMHandle->pTIMx->PSC = pTIMHandle->TIMConfig.Prescaler;

	//Set Auto-reload value
	pTIMHandle->pTIMx->ARR =pTIMHandle->TIMConfig.AutoReloadPreload;

	//Clear counter
	pTIMHandle->pTIMx->CNT = 0;


	pTIMHandle->pTIMx->DIER = 1U;


}
