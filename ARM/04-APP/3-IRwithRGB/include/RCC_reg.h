/********************************/
/* Author  :Engy Tahoon			*/
/*version:  V02					*/
/*Date :18 Aug 2020				*/
/********************************/

#ifndef RCC_REG_H
#define RCC_REG_H


/* The first RCC driver */
/* Register Definitions */
/*
#define	RCC_CR			*((volatile u32 *)0x40021000)
#define	RCC_CFGR		*((volatile u32 *)0x40021004)
#define	RCC_CIR			*((volatile u32 *)0x40021008)
#define	RCC_APB2RSTR	*((volatile u32 *)0x4002100C)
#define	RCC_APB1RSTR	*((volatile u32 *)0x40021010)
#define	RCC_AHBENR		*((volatile u32 *)0x40021014)
#define	RCC_APB2ENR		*((volatile u32 *)0x40021018)
#define	RCC_APB1ENR		*((volatile u32 *)0x4002101C)
#define	RCC_BDCR		*((volatile u32 *)0x40021020)
#define	RCC_CSR		    *((volatile u32 *)0x40021024)
*/

/* The second RCC driver */

typedef struct
{
	volatile u32	CR		;
	volatile u32	CFGR	;
	volatile u32	CIR		;
	volatile u32	APB2RSTR;
	volatile u32	APB1RSTR;
	volatile u32	AHBENR	;
	volatile u32	APB2ENR	;
	volatile u32	APB1ENR	;
	volatile u32	BDCR	;
	volatile u32	CSR		;

}RCC_t;

#define RCC		((volatile RCC_t *)0x40021000)

/************************************ Clock Control Register (RCC_CR) ******************************************/
#define RCC_PLLRDY		25		/*PLL Clock Ready flag */ //Read only
#define RCC_PLLON		24		/*PLL Clock enable */
#define RCC_CSSON		19		/*Clock secuirty system enable */
#define RCC_HSEBYP		18		/*Eternal high-speed clock bypass*/
#define RCC_HSERDY		17		/*Eternal high-speed clock ready flag */ //Read only
#define RCC_HSEON		16		/*HSE clock enable */
#define RCC_HSIRDY		1		/*Inrenal high-speed clock Ready flag*/ //Read only
#define RCC_HSION		0		/*HSI clock enable*/

/************************************ Clock Configuraton Register(RCC_CFGR)*************************************/
#define RCC_MCO2		26		/*Microcontroller Clock Output*/
#define RCC_MCO1		25		
#define RCC_MCO0		24	
#define RCC_USBPRE		22		/*USB prescalar*/
#define RCC_PLLMUL3		21		/*PLL multiplication factor*/
#define RCC_PLLMUL2		20
#define RCC_PLLMUL1		19
#define RCC_PLLMUL0		18
#define RCC_PLLXTPRE	17		/*HSE divider for PLL entry*/
#define RCC_PLLSRC		16		/*PLL entry clock source*/
#define RCC_ADCPRE1		15		/*ADC prescalar*/
#define RCC_ADCPRE0		14	
#define RCC_PPRE2_2		13		/*APB high-speed prescalar (APB2)*/
#define RCC_PPRE2_1		12		
#define RCC_PPRE2_0		11
#define RCC_PPRE1_2		10		/*APB low-speed prescalar(APB1)*/
#define RCC_PPRE1_1		9
#define RCC_PPRE1_0		8
#define RCC_HPRE_3		7		/*AHB prescalar*/
#define RCC_HPRE_2		6
#define RCC_HPRE_1		5
#define RCC_HPRE_0		4
#define RCC_SWS_1		3		/*system clock switch status*/	//read only
#define	RCC_SWS_0		2
#define RCC_SW_1		1		/*system clock switch*/
#define RCC_SW_0		0

/************************************ Clock interrupt Register(RCC_CIR)*************************************/

#define RCC_CSSC		23		/*Clock security system interrupt clear*/ //write only
#define RCC_PLLREYC		20		/*PLL ready interrupt clear*/	//write only
#define RCC_HSERDYC		19		/*HSE ready interrupt clear*/	//write only
#define RCC_HSIRDYC		18		/*HSI ready interrupt clear*/	//write only
#define RCC_LSERDYC		17		/*LSE ready interrupt clear*/	//write only 
#define	RCC_LSIRDYC		16		/*LSI ready interrupt clear*/	//write only
#define RCC_PLLRDYIE	12		/*PLL read interrupt enable*/
#define RCC_HSERDYIE	11		/*HSE ready interrut enable*/
#define RCC_HSIRDYIE	10		/*HSI ready interrut enable*/
#define RCC_LSERDYIE	9		/*LSE ready interrut enable*/
#define RCC_LSIRDYIE	8		/*LSI ready interrut enable*/
#define	RCC_CSSF		7		/*clock security system interrupt flag*/	//read only
#define RCC_PLLRDYF		4		/*PLL ready interrupt flag*/	//read only
#define RCC_HSERDYF		3		/*HSE ready interrupt flag*/	//read only
#define RCC_HSIRDYF		2		/*HSI ready interrupt flag*/	//read only
#define RCC_LSERDYF		1		/*LSE ready interrupt flag*/	//read only
#define RCC_LSIRDYF		0		/*LSI ready interrupt flag*/	//read only

/************************************** APB2 peripheral reset register(RCC_APB2RSTR)*************************/

#define RCC_TIM11RST	21		/*Timer11 reset*/
#define RCC_TIM10RST	20		/*Timer10 reset*/
#define RCC_TIM9RST		19		/*Timer9 reset*/
#define RCC_ADC3RST		15		/*ADC3 interface reset*/
#define RCC_USART1RST	14		/*USART1 reset*/
#define RCC_TIM8RST		13		/*Timer8 reset*/
#define RCC_SPI1RST		12		/*sPI1 reset*/
#define RCC_TIM1RST		11		/*Timer1 reset*/
#define RCC_ADC2RST		10		/*ADC3 interface reset*/
#define RCC_ADC1RST		9		/*ADC3 interface reset*/
#define RCC_IOPCRST		4		/*IO port C reset*/
#define RCC_IOPBRST		3		/*IO port B reset*/
#define RCC_IOPARST		2		/*IO port A reset*/
#define RCC_AFIORST		0		/*Alternate function IO reset*/

/************************************** APB1 peripheral reset register(RCC_APB1RSTR)*************************/

#define RCC_DACRST		29		/*DAC interface reset*/
#define RCC_PWRRST		28		/*Power interface reset*/
#define RCC_BKPRST		27		/*Backup interface reset*/
#define RCC_CANRST		25		/*CAN reset*/
#define RCC_USBRST		23		/*USB reset*/
#define RCC_I2C2RST		22		/*I2C2 reset*/
#define RCC_I2c1RST		21		/*I2C1 rreset*/
#define RCC_UART5RST	20		/*USART5 reset*/
#define RCC_UART4RST	19		/*USART4 reset*/
#define RCC_UART3RST	18		/*USART3 reset*/
#define RCC_UART2RST	17		/*USART2 reset*/
#define RCC_SPI3RST		15		/*SPI3 reset*/
#define RCC_SPI2RST		14		/*SPI2 reset*/
#define RCC_WWDGRST		11		/*Window watchdog reset*/
#define RCC_TIM14RST	8		/*Timer14 reset*/
#define RCC_TIM13RST	7		/*Timer13 reset*/
#define RCC_TIM12RST	6		/*Timer12 reset*/
#define RCC_TIM7RST		5		/*Timer7 reset*/
#define RCC_TIM6RST		4		/*Timer6 reset*/
#define RCC_TIM5RST		3		/*Timer5 reset*/
#define RCC_TIM4RST		2		/*Timer4 reset*/
#define RCC_TIM3RST		1		/*Timer3 reset*/
#define RCC_TIM2RST		0		/*Timer2 reset*/

/************************************** AHB peripheral clock enable register(RCC_AHBENR)*************************/

#define RCC_SDIOEN		10		/*SDIO clock enable*/
#define RCC_FSMCEN		8		/*FSMC clock enable*/
#define RCC_CRCEN		6		/*CRC clock enable*/
#define RCC_FLITFEN		4		/*FLITF clock enable*/
#define RCC_SRAMEN		2		/*SRAM interface clock enable*/
#define RCC_DMA2EN		1		/*DMA2 clock enable*/
#define RCC_DMA1EN		0		/*DMA1 clock enable*/

/************************************** APB2 peripheral clock enable register(RCC_APB2ENR)*************************/

#define RCC_TIM11EN		21		/*Timer11 clock enable*/
#define RCC_TIM10EN		20		/*Timer10 clock enable*/
#define RCC_TIM9EN		19		/*Timer9 clock enable*/
#define RCC_ADC3EN		15		/*ADC3 interface enable*/
#define RCC_USART1EN	14		/*USART1 clock enable*/
#define RCC_TIM8EN		13		/*Timer8 clock enable*/
#define RCC_SPI1EN		12		/*sPI1   clock enable*/
#define RCC_TIM1EN		11		/*Timer1 clock enable*/
#define RCC_ADC2EN		10		/*ADC3 interface clock enable*/
#define RCC_ADC1EN		9		/*ADC3 interface clock enable*/
#define RCC_IOPCEN		4		/*IO port C clock enable*/
#define RCC_IOPBEN		3		/*IO port B clock enable*/
#define RCC_IOPAEN		2		/*IO port A clock enable*/
#define RCC_AFIOEN		0		/*Alternate function IO clock enable*/

/************************************** APB1 peripheral clock enable register(RCC_APB1ENR)*************************/

#define RCC_DACEN		29		/*DAC interface    clock enable*/
#define RCC_PWREN		28		/*Power interface  clock enable*/
#define RCC_BKPEN		27		/*Backup interface clock enable*/
#define RCC_CANEN		25		/*CAN    clock enable*/
#define RCC_USBEN		23		/*USB 	 clock enable*/
#define RCC_I2C2EN		22		/*I2C2   clock enable*/
#define RCC_I2c1EN		21		/*I2C1   clock enable*/
#define RCC_UART5EN		20		/*USART5 clock enable*/
#define RCC_UART4EN		19		/*USART4 clock enable*/
#define RCC_UART3EN		18		/*USART3 clock enable*/
#define RCC_UART2EN		17		/*USART2 clock enable*/
#define RCC_SPI3EN		15		/*SPI3   clock enable*/
#define RCC_SPI2EN		14		/*SPI2   clock enable*/
#define RCC_WWDGEN		11		/*Window watchdog clock enable*/
#define RCC_TIM14EN		8		/*Timer14 clock enable*/
#define RCC_TIM13EN		7		/*Timer13 clock enable*/
#define RCC_TIM12EN		6		/*Timer12 clock enable*/
#define RCC_TIM7EN		5		/*Timer7  clock enable*/
#define RCC_TIM6EN		4		/*Timer6  clock enable*/
#define RCC_TIM5EN		3		/*Timer5  clock enable*/
#define RCC_TIM4EN		2		/*Timer4  clock enable*/
#define RCC_TIM3EN		1		/*Timer3  clock enable*/
#define RCC_TIM2EN		0		/*Timer2  clock enable*/

/***************************************Backup domain control register(RCC_BDCR)***********************************/

#define RCC_BDRST		16		/*Backup domain software reset*/
#define RCC_RTCEN		15		/*RTC clock enable*/
#define RCC_RTCSEL_1	9		/*RTC clock source selection bit1*/
#define RCC_RTCSEL_0	8		/*RTC clock source selection bit0*/
#define RCC_LSEBYP		2		/*External low-speed oscillator bypass*/
#define RCC_LSERDY		1		/*External low-speed oscillator ready*/ //read only
#define RCC_LSEON		0		/*External low-speed oscillator enable*/

/***************************************Control/status register(RCC_CSR)*******************************************/

#define RCC_LPWRRSTF	31		/*Low-power reset flag*/
#define RCC_WWDGRSTF	30		/*Window watchdog reset flag*/
#define RCC_IWDGRSTF	29		/*independent watchdog reset flag*/
#define RCC_SFTRSTF		28		/*Software reset flag*/
#define RCC_PORRSTF		27		/*POR/PDR reset flag*/
#define RCC_PINRSTF		26		/*PIN reset flag*/
#define RCC_RMVF		24		/*Remove reset flag*/
#define RCC_LSIRDY		1		/*internal low-speed oscillator ready*/
#define RCC_LSION		0		/*internal low-speed oscillator enable*/

#endif
