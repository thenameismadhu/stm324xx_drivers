/*
 * stm32f407xx.h
 *
 *  Created on: May 8, 2024
 *      Author: Madhu
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_
/*base addresses of Flash and SRAM memories*/
#define FLASH_BASEADDR				0x08000000U
#define SRAM1_BASEADDR				0x20000000U
/*How to calculate SRAM2 address from SRAM1 ?
Size if SRAM1 is 112KB,So 112 x1024 = 114,688
convert 114,688 to hex = 1 C000*/
#define SRAM2_BASEADDR				0x2001C000U
#define ROM							0x1FFF0000U
#define SRAM 						SRAM1_BASEADDR


#include<stdint.h>


#define __vo volatile

/*
 * AHBx and APBx Peripheral base addresses
 */
#define PERIH_BASEADDR					0x40000000U
#define APB1PERIPH_BASEADDR				PERIPHERAL_BASE
#define APB2PERIPH_BASEADDR				0x40010000U
#define AHB1PERIPH_BASEADDR				0x40020000U
#define AHB2PERIPH_BASEADDR				0x50000000U

/*
 * BAse addresses of peripherals on AHB1 bus
 */
#define GPIOA_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR				(AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR				(AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR				(AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR				(AHB1PERIPH_BASEADDR + 0x1C00)
#define GPIOI_BASEADDR				(AHB1PERIPH_BASEADDR + 0x2000)

#define RCC_BASEADDR                (AHB1PERIPH_BASEADDR + 0x3800)


/*
 * Base addresses of peripherals on APB1 bus
 */

#define I2C1_BASEADDR				(APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR				(APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR				(APB1PERIPH_BASEADDR + 0x5C00)

#define SPI2_BASEADDR				(APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR				(APB1PERIPH_BASEADDR + 0x3C00)

#define USART2_BASEADDR				(APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR				(APB1PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR				(APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR				(APB1PERIPH_BASEADDR + 0x5000)

/*
 * Base addresses of peripherals on APB2 bus
 */
#define EXTI_BASEADDR						(APB2PERIPH_BASEADDR + 0x3C00)
#define SPI1_BASEADDR						(APB2PERIPH_BASEADDR + 0x3000)
#define SYSCFG_BASEADDR        				(APB2PERIPH_BASEADDR + 0x3800)
#define USART1_BASEADDR						(APB2PERIPH_BASEADDR + 0x1000)
#define USART6_BASEADDR						(APB2PERIPH_BASEADDR + 0x1400)

/*
 * Register definition structure for GPIO
 */

typedef struct
{
	__vo uint32_t MODER;                        /*!< GPIO port mode register,                    	Address offset: 0x00      */
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];						/*!< AFR[0] : GPIO alternate function low register, AF[1] : GPIO alternate function high register    		Address offset: 0x20-0x24 */
}GPIO_RegDef_t;


/*
 * peripheral register definition structure for RCC
 */
typedef struct
{
  __vo uint32_t CR;            /* CR,     										Address offset: 0x00 */
  __vo uint32_t PLLCFGR;       /* PLLCFGR,     										Address offset: 0x04 */
  __vo uint32_t CFGR;          /* CFGR,     										Address offset: 0x08 */
  __vo uint32_t CIR;           /* CIR,     										Address offset: 0x0C */
  __vo uint32_t AHB1RSTR;      /* AHB1RSTR,     										Address offset: 0x10 */
  __vo uint32_t AHB2RSTR;      /* AHB2RSTR,     										Address offset: 0x14 */
  __vo uint32_t AHB3RSTR;      /* AHB3RSTR,     										Address offset: 0x18 */
  uint32_t      RESERVED0;     /* Reserved, 0x1C                                                       */
  __vo uint32_t APB1RSTR;      /* APB1RSTR,     										Address offset: 0x20 */
  __vo uint32_t APB2RSTR;      /* APB2RSTR,     										Address offset: 0x24 */
  uint32_t      RESERVED1[2];  /* Reserved, 0x28-0x2C                                                  */
  __vo uint32_t AHB1ENR;       /* AHB1ENR,     										Address offset: 0x30 */
  __vo uint32_t AHB2ENR;       /* AHB2ENR,     										Address offset: 0x34 */
  __vo uint32_t AHB3ENR;       /* AHB3ENR,     										Address offset: 0x38 */
  uint32_t      RESERVED2;     /* Reserved, 0x3C                                                       */
  __vo uint32_t APB1ENR;       /* APB1ENR,     										Address offset: 0x40 */
  __vo uint32_t APB2ENR;       /* APB2ENR,     										Address offset: 0x44 */
  uint32_t      RESERVED3[2];  /* Reserved, 0x48-0x4C                                                  */
  __vo uint32_t AHB1LPENR;     /* AHB1LPENR,     										Address offset: 0x50 */
  __vo uint32_t AHB2LPENR;     /* AHB2LPENR,     										Address offset: 0x54 */
  __vo uint32_t AHB3LPENR;     /* AHB3LPENR,     										Address offset: 0x58 */
  uint32_t      RESERVED4;     /* Reserved, 0x5C                                                       */
  __vo uint32_t APB1LPENR;     /* APB1LPENR,     										Address offset: 0x60 */
  __vo uint32_t APB2LPENR;     /* APB2LPENR,     										Address offset: 0x64 */
  uint32_t      RESERVED5[2];  /* Reserved, 0x68-0x6C                                                  */
  __vo uint32_t BDCR;          /* BDCR,     										Address offset: 0x70 */
  __vo uint32_t CSR;           /* CSR,     										Address offset: 0x74 */
  uint32_t      RESERVED6[2];  /* Reserved, 0x78-0x7C                                                  */
  __vo uint32_t SSCGR;         /* SSCGR,     										Address offset: 0x80 */
  __vo uint32_t PLLI2SCFGR;    /* PLLI2SCFGR,     										Address offset: 0x84 */
  __vo uint32_t PLLSAICFGR;    /* PLLSAICFGR,     										Address offset: 0x88 */
  __vo uint32_t DCKCFGR;       /* DCKCFGR,     										Address offset: 0x8C */
  __vo uint32_t CKGATENR;      /* CKGATENR,     										Address offset: 0x90 */
  __vo uint32_t DCKCFGR2;      /* DCKCFGR2,     										Address offset: 0x94 */

} RCC_RegDef_t;


/*
 * peripheral definitions ( Peripheral base addresses typecasted to xxx_RegDef_t)
 */

#define GPIOA  				((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB  				((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC  				((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD  				((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE  				((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF  				((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG  				((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH  				((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI  				((GPIO_RegDef_t*)GPIOI_BASEADDR)
#define RCC 				((RCC_RegDef_t*)RCC_BASEADDR)


/*
 * Clock Enable Macros for GPIOx peripherals
 */

#define GPIOA_PCLK_EN()    	(RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()		(RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()		(RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()		(RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()		(RCC->AHB1ENR |= (1 << 4))
#define GPIOF_PCLK_EN()		(RCC->AHB1ENR |= (1 << 5))
#define GPIOG_PCLK_EN()		(RCC->AHB1ENR |= (1 << 6))
#define GPIOH_PCLK_EN()		(RCC->AHB1ENR |= (1 << 7))
#define GPIOI_PCLK_EN()		(RCC->AHB1ENR |= (1 << 8))

/*
 * Clock Disable Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 4))
#define GPIOF_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 5))
#define GPIOG_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 6))
#define GPIOH_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 7))
#define GPIOI_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 8))

/*
 * Macros to reset GPIOx peripheral
 */

#define GPIOA_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); }while(0)
#define GPIOB_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1)); }while(0)
#define GPIOC_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2)); }while(0)
#define GPIOD_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3)); }while(0)
#define GPIOE_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4)); }while(0)
#define GPIOF_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 5)); (RCC->AHB1RSTR &= ~(1 << 5)); }while(0)
#define GPIOG_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 6)); (RCC->AHB1RSTR &= ~(1 << 6)); }while(0)
#define GPIOH_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7)); }while(0)
#define GPIOI_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 8)); (RCC->AHB1RSTR &= ~(1 << 8)); }while(0)


//Generic Macros

#define ENABLE 1
#define DISABLE 0
#define SET					ENABLE
#define RESET				DISABLE
#define GPIO_PIN_SET		SET
#define GPIO_PIN_RESET		RESET

#include "stm32f4xx_gpio_driver.h"


#endif /* INC_STM32F407XX_H_ */
