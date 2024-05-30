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


#define TIM_IRQ_POS 28


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

typedef struct nvic_t {
    unsigned volatile long iser[3];	// 0x0 to 0xB - interrupt set-enable registers
	unsigned volatile long icer[3];	// 0xC to 0x18 - interrupt clear-enable registers
	unsigned volatile long ispr[3];	// 0xC to 0x18 - interrupt set-pending registers
	unsigned volatile long icpr[3];	// 0xC to 0x18 - interrupt clear-pending registers
	unsigned volatile long iabr[3];	// 0xC to 0x18 - interrupt active bit registers
	// unsigned volatile long ipr[3];	// 0xC to 0x18 - interrupt priority registers
	// unsigned volatile long stir;	// 0xC to 0x18 - software trigger interrupt register
} nvic_t;

/*
 * Peripheral Clock setup
 */
void TIM_PeriClkCtrl(TIM_RegDef_t *pTIMx,uint8_t EnorDi);
void Timer_Init(TIM_Handle_t *pTIMHandle);

void nvic_enable(unsigned char irq_pos);

#endif /* INC_STM32F4XX_TIMER_DRIVER_H_ */
