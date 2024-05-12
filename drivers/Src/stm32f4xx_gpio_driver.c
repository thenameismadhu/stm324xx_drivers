/*
 * stm32f4xx_gpio_driver.c
 *
 *  Created on: May 8, 2024
 *      Author: Madhu
 */


#include "stm32f4xx_gpio_driver.h"

/*
 * Peripheral Clock setup
 */
/*********************************************************************
 * @fn      		  - GPIO_PeriClockControl
 *
 * @brief             - This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]         - base address of the gpio peripheral
 * @param[in]         - ENABLE or DISABLE macros
 * @param[in]         -
 *
 * @return            -  none
 *
 * @Note              -  none

 */
void GPIO_PeriClkCtrl(GPIO_RegDef_t *pGPIOx,uint8_t EnorDi)
{
		if(EnorDi == ENABLE)
		{
			if(pGPIOx == GPIOA)
			{
				GPIOA_PCLK_EN();
			}else if (pGPIOx == GPIOB)
			{
				GPIOB_PCLK_EN();
			}else if (pGPIOx == GPIOC)
			{
				GPIOC_PCLK_EN();
			}else if (pGPIOx == GPIOD)
			{
				GPIOD_PCLK_EN();
			}else if (pGPIOx == GPIOE)
			{
				GPIOE_PCLK_EN();
			}else if (pGPIOx == GPIOF)
			{
				GPIOF_PCLK_EN();
			}else if (pGPIOx == GPIOG)
			{
				GPIOG_PCLK_EN();
			}else if (pGPIOx == GPIOH)
			{
				GPIOH_PCLK_EN();
			}else if (pGPIOx == GPIOI)
			{
				GPIOI_PCLK_EN();
			}
		}
		else
		{
			if(pGPIOx == GPIOA)
			{
				GPIOA_PCLK_DI();
			}else if (pGPIOx == GPIOB)
			{
				GPIOB_PCLK_DI();
			}else if (pGPIOx == GPIOC)
			{
				GPIOC_PCLK_DI();
			}else if (pGPIOx == GPIOD)
			{
				GPIOD_PCLK_DI();
			}
			else if (pGPIOx == GPIOE)
			{
				GPIOE_PCLK_DI();
			}
			else if (pGPIOx == GPIOF)
			{
				GPIOF_PCLK_DI();
			}
			else if (pGPIOx == GPIOG)
			{
				GPIOG_PCLK_DI();
			}
			else if (pGPIOx == GPIOH)
			{
				GPIOH_PCLK_DI();
			}
			else if (pGPIOx == GPIOI)
			{
				GPIOI_PCLK_DI();
			}
		}

}

/*
 * Data Init and Deinit
 */
/*********************************************************************
 * @fn      		  - GPIO_Init
 *
 * @brief             -Function to initialise GPIO Pin and GPIO Port
 *
 * @param[in]         -HAndle structure of GPIO pin which holds base addr of the GPIO pin and pin config
 * @param[in]         -None
 * @param[in]         -None
 *
 * @return            -None
 *
 * @Note              -NOne

 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp=0; //temp. register

		 //enable the peripheral clock

		 GPIO_PeriClkCtrl(pGPIOHandle->pGPIOx, ENABLE);

		//1 . configure the mode of gpio pin

		if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
		{
			//the non interrupt mode
			temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber ) );
			pGPIOHandle->pGPIOx->MODER &= ~( 0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); //clearing
			pGPIOHandle->pGPIOx->MODER |= temp; //setting

		}

		//2. configure the speed
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << ( 2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber) );
		pGPIOHandle->pGPIOx->OSPEEDR &= ~( 0x3 << ( 2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); //clearing
		pGPIOHandle->pGPIOx->OSPEEDR |= temp;

		//3. configure the pupd settings
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << ( 2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber) );
		pGPIOHandle->pGPIOx->PUPDR &= ~( 0x3 << ( 2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); //clearing
		pGPIOHandle->pGPIOx->PUPDR |= temp;


		//4. configure the optype
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber );
		pGPIOHandle->pGPIOx->OTYPER &= ~( 0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber); //clearing
		pGPIOHandle->pGPIOx->OTYPER |= temp;

		//5. configure the alt functionality
		if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
		{
			//configure the alt function registers.
			uint8_t temp1, temp2;

			temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
			temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber  % 8;
			pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << ( 4 * temp2 ) ); //clearing
			pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << ( 4 * temp2 ) );
		}

}
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)//peri reset register availabe in RCC
{
	if(pGPIOx == GPIOA)
		{
			GPIOA_REG_RESET();
		}else if (pGPIOx == GPIOB)
		{
			GPIOB_REG_RESET();
		}else if (pGPIOx == GPIOC)
		{
			GPIOC_REG_RESET();
		}else if (pGPIOx == GPIOD)
		{
			GPIOD_REG_RESET();
		}else if (pGPIOx == GPIOE)
		{
			GPIOE_REG_RESET();
		}else if (pGPIOx == GPIOF)
		{
			GPIOF_REG_RESET();
		}else if (pGPIOx == GPIOG)
		{
			GPIOG_REG_RESET();
		}else if (pGPIOx == GPIOH)
		{
			GPIOH_REG_RESET();
		}else if (pGPIOx == GPIOI)
		{
			GPIOI_REG_RESET();
		}
}


/*
 * Data Read and Write
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber)
{
	uint8_t value;

	value = (uint8_t )((pGPIOx->IDR  >> PinNumber) & 0x00000001 ) ;

	return value;

}

uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;

	value = (uint16_t)pGPIOx->IDR;

	return value;
}

void GPIO_WritetoOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber,uint8_t Value)
{
	if(Value == GPIO_PIN_SET)
		{
			//write 1 to the output data register at the bit field corresponding to the pin number
			pGPIOx->ODR |= ( 1 << PinNumber);
		}else
		{
			//write 0
			pGPIOx->ODR &= ~( 1 << PinNumber);
		}
}

void GPIO_WritetoOutputPort(GPIO_RegDef_t *pGPIOx,uint16_t Value)
{
	pGPIOx->ODR  = Value;

}
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber)
{
	pGPIOx->ODR  ^= ( 1 << PinNumber);

}

/*
 * IRQ Configuration and ISR handling
 */
void GPIO_IRQConfig(uint8_t IRQNumber,uint8_t IRQPriority,uint8_t EnorDi)
{

}
void GPIO_IRQHandling(uint8_t PinNumber)
{

}
