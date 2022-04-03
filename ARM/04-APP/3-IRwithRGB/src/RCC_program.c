/********************************/
/*Author :Engy Tahoon 			*/
/*version:  V02					*/
/*Date 	 :	18 Aug 2020			*/
/********************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_reg.h"
#include "RCC_private.h"
#include "RCC_config.h"

/* The first RCC driver */

/* This API shall enable the clock on certain peripheral */
//void RCC_voidEnableClock(u8 Copy_u8Bus, u8 Copy_u8Peripheral)
//{
//	switch (Copy_u8Bus)
//	{
//		case  0 : SET_BIT(RCC->AHBENR.ByteAccess , Copy_u8Peripheral); break;
//		case  1 : SET_BIT(RCC->APB1ENR.ByteAccess, Copy_u8Peripheral); break;
//		case  2 : SET_BIT(RCC->APB2ENR.ByteAccess, Copy_u8Peripheral); break;
//		default : /* no thing */ break;
//	}
//
//}
//
///* This API shall diable the clock on certain peripheral */
//void RCC_voidDisableClock(u8 Copy_u8Bus, u8 Copy_u8Peripheral)
//{
//	switch (Copy_u8Bus)
//	{
//		case  0 : CLR_BIT(RCC->AHBENR.ByteAccess , Copy_u8Peripheral); break;
//		case  1 : CLR_BIT(RCC->APB1ENR.ByteAccess, Copy_u8Peripheral); break;
//		case  2 : CLR_BIT(RCC->APB2ENR.ByteAccess, Copy_u8Peripheral); break;
//		default : /* no thing */ break;
//	}
//
//}
///* this function apply clock on processor*/
//void RCC_voidSysClkInit(void)
//{
//	/* HSE Enable with no bypass */
//	/* PLL Disable, HSI Disable */
//	/* CSS Disable */
//    /* Sysclk = HSE =8MHZ =AHB =APB1 = APB2 */
//	RCC->CR.ByteAccess   = 0x00010000;
//	RCC->CFGR.ByteAccess = 0x00000001;
//}


/* The second RCC driver */

/* this function apply clock on processor*/
void RCC_voidSysClkInit(void)
{
	#if SET_CLOCK == HSI_CLK
		SET_BIT(RCC ->CR, RCC_HSION);			//enable the HSI
		CLR_BIT(RCC->CFGR, RCC_SW_1);			//To select the HSI as a system clock, SW[1:0]=00
		CLR_BIT(RCC->CFGR, RCC_SW_0);

		while (!GET_BIT(RCC->CR,RCC_HSIRDY)); 	//check on the HSI ready flag
	#elif SET_CLOCK == HSE_CRYSTAL_CLK
		SET_BIT(RCC ->CR, RCC_HSEON);			//enable the HSE
		CLR_BIT(RCC ->CR, RCC_HSEBYP);			//select HSE crystal

		CLR_BIT(RCC->CFGR, RCC_SW_1);			//To select the HSE as a system clock, SW[1:0]=01
		SET_BIT(RCC->CFGR, RCC_SW_0);

		while (!GET_BIT(RCC->CR,RCC_HSERDY)); 	//check on the HSE ready flag
	#elif SET_CLOCK == HSE_RC_CLK
		CLR_BIT(RCC ->CR.ByteAccess, RCC_HSEON);			//HSE Bypass can be written only if the HSE is disable
		SET_BIT(RCC ->CR.ByteAccess, RCC_HSEBYP);			//select HSE bypass

		CLR_BIT(RCC->CFGR.ByteAccess, RCC_SW_1);			//To select the HSE as a system clock, SW[1:0]=01
		SET_BIT(RCC->CFGR.ByteAccess, RCC_SW_0);

		SET_BIT(RCC ->CR.ByteAccess, RCC_HSEON);			//enable the HSE
		while (!GET_BIT(RCC->CR.ByteAccess,RCC_HSERDY)); 	//check on the HSE ready flag

	#elif SET_CLOCK == PLL_CLK

		SET_BIT(RCC->CFGR.ByteAccess, RCC_SW_1);			//To select the PLL as a system clock, SW[1:0]=10
		CLR_BIT(RCC->CFGR.ByteAccess, RCC_SW_0);
		/*PLL input clock*/
		#if PLL_INPUT == PLL_HSE_DIV_2
			CLR_BIT(RCC ->CR.ByteAccess, RCC_PLLON);		//PLL must be disabled

			SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLSRC);		//select the HSE as PLL input clock
			SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLXTPRE);	//HSE divided by 2
		#elif PLL_INPUT == PLL_HSI_DIV_2
			CLR_BIT(RCC ->CR.ByteAccess, RCC_PLLON);		//PLL must be disabled
			CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLSRC);		//select the HSI as PLL input clock
		#elif PLL_INPUT == PLL_HSE
			CLR_BIT(RCC ->CR.ByteAccess, RCC_PLLON);		//PLL must be disabled
			SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLSRC); 	//select the HSE as PLL input clock
			CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLXTPRE);	//HSE clock not divided
		#endif
			/*PLL Multiplication factor*/
			#if PLL_MUL_FACTOR == PLL_MUL_2

				CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL3);
				CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL2);
				CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL1);
				CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL0);
			#elif PLL_MUL_FACTOR == PLL_MUL_3
				CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL3);
				CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL2);
				CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL1);
				SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL0);
			#elif PLL_MUL_FACTOR == PLL_MUL_4
				CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL3);
				CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL2);
				SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL1);
				CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL0);
			#elif PLL_MUL_FACTOR == PLL_MUL_5
				CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL3);
				CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL2);
				SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL1);
				SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL0);
			#elif PLL_MUL_FACTOR == PLL_MUL_6
				CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL3);
				SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL2);
				CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL1);
				CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL0);
			#elif PLL_MUL_FACTOR == PLL_MUL_7
				CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL3);
				SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL2);
				CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL1);
				SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL0);
			#elif PLL_MUL_FACTOR == PLL_MUL_8
				CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL3);
				SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL2);
				SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL1);
				CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL0);
			#elif PLL_MUL_FACTOR == PLL_MUL_9
				CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL3);
				SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL2);
				SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL1);
				SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL0);
			#elif PLL_MUL_FACTOR == PLL_MUL_10
				SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL3);
				CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL2);
				CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL1);
				CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL0);
			#elif PLL_MUL_FACTOR == PLL_MUL_11
				SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL3);
				CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL2);
				CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL1);
				SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL0);
			#elif PLL_MUL_FACTOR == PLL_MUL_12
				SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL3);
				CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL2);
				SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL1);
				CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL0);
			#elif PLL_MUL_FACTOR == PLL_MUL_13
				SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL3);
				CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL2);
				SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL1);
				SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL0);
			#elif PLL_MUL_FACTOR == PLL_MUL_14
				SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL3);
				SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL2);
				CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL1);
				CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL0);
			#elif PLL_MUL_FACTOR == PLL_MUL_15
				SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL3);
				SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL2);
				CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL1);
				SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL0);
			#elif PLL_MUL_FACTOR == PLL_MUL_16
				SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL3);
				SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL2);
				SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL1);
				CLR_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL0);
			#elif PLL_MUL_FACTOR == PLL_MUL_16
				SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL3);
				SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL2);
				SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL1);
				SET_BIT(RCC->CFGR.ByteAccess, RCC_PLLMUL0);
			#endif

		SET_BIT(RCC->CRByteAccess, RCC_PLLON);
		while (!GET_BIT(RCC->CR.ByteAccess,RCC_PLLRDY)); 	//check on the HSI ready flag

	#endif

/*Clock security system for HSE if HSE clock failure is detected, The CSSON will be disabled the HSE and enabled HSI*/
	#if CLK_SECURITY_SYSTEM	== CLK_SECURITY_ON

		SET_BIT(RCC->CR.ByteAccess, RCC_CSSON);
	#elif CLK_SECURITY_SYSTEM	== CLK_SECURITY_OFF

		CLR_BIT(RCC->CR, RCC_CSSON);
	#endif

}
/* This API shall enable the clock on certain peripheral */
void RCC_voidEnableClock(u8 Copy_u8PeripheralIdx)
{
	u8 Local_u8Bus = Copy_u8PeripheralIdx / RCC_U8_REG_SIZE;
	u8 Local_u8Pripheral = Copy_u8PeripheralIdx % RCC_U8_REG_SIZE;

	switch(Local_u8Bus)
	{
		case AHB	:	SET_BIT(RCC->AHBENR, Local_u8Pripheral);break;
		case APB2	:	SET_BIT(RCC->APB2ENR, Local_u8Pripheral);break;
		case APB1	:	SET_BIT(RCC->APB1ENR, Local_u8Pripheral);break;
	}
}

/* This API shall disable the clock on certain peripheral */
void RCC_voidDisableClock(u8 Copy_u8PeripheralIdx)
{
	u8 Local_u8Bus = Copy_u8PeripheralIdx / RCC_U8_REG_SIZE;
	u8 Local_u8Pripheral = Copy_u8PeripheralIdx % RCC_U8_REG_SIZE;

	switch(Local_u8Bus)
	{
		case AHB	:	CLR_BIT(RCC->AHBENR , Local_u8Pripheral);break;
		case APB2	:	CLR_BIT(RCC->APB2ENR, Local_u8Pripheral);break;
		case APB1	:	CLR_BIT(RCC->APB1ENR, Local_u8Pripheral);break;
	}
}
