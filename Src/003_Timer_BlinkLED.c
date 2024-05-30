/*
 * 003_Timer_BlinkLED.c
 *
 *  Created on: May 24, 2024
 *      Author: Madhu
 */
#include "stm32f407xx.h"


void delay(void)
{
	for(uint32_t i = 0 ; i < 500000/2 ; i++);
}


int main(void)
{

	GPIO_Handle_t GpioLed;

	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClkCtrl(GPIOD,ENABLE);

	GPIO_Init(&GpioLed);

	TIM_Handle_t Tim10ms;

	Tim10ms.pTIMx = TIM6;
	Tim10ms.TIMConfig.Prescaler = 24;
	Tim10ms.TIMConfig.AutoReloadPreload = 64000-1;

	Timer_Init(&Tim10ms);

	while(1)
		{
			/* Loop until the update event flag is set */
			while( ! (Tim10ms.pTIMx->SR & TIM_SR_UIF) );
			/* The required time delay has been elapsed */

			//User code can be executed
			Tim10ms.pTIMx->SR = 0;
			GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_12);
			delay();

		}
	return 0;
}


