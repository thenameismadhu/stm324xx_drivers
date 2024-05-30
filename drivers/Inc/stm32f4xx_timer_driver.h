/*
 * stm32f4xx_timer_driver.h
 *
 *  Created on: May 20, 2024
 *      Author: Madhu
 */

#ifndef INC_STM32F4XX_TIMER_DRIVER_H_
#define INC_STM32F4XX_TIMER_DRIVER_H_

#include "stm32f407xx.h"

#define TIM_SR_UIF (1<<0)

/*
 *  Configuration structure for TIMx peripheral
 */
typedef struct
{
	uint32_t Prescaler;
	uint32_t CounterMode;
	uint32_t Period;
	uint32_t ClockDivision;
	uint32_t RepetitionCounter;
	uint32_t AutoReloadPreload;
}TIM_TimeBaseConfig_t;


/*
 *Handle structure for TIMx peripheral
 */
typedef struct
{
	TIM_RegDef_t 	*pTIMx;   /*!< This holds the base address of TIMx peripheral >*/
	TIM_TimeBaseConfig_t 	TIMConfig;
}TIM_Handle_t;



/*
 * Peripheral Clock setup
 */
void TIM_PeriClkCtrl(TIM_RegDef_t *pTIMx,uint8_t EnorDi);
void Timer_Init(TIM_Handle_t *pTIMHandle);



#endif /* INC_STM32F4XX_TIMER_DRIVER_H_ */
