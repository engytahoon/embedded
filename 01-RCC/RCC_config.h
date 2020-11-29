/********************************/
/* Author  :Engy Tahoon			*/
/*version:  V02					*/
/*Date :18 Aug 2020				*/
/********************************/


#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/*option: 1- HSE_CRYSTAL_CLK
		  2- HSE_RC_CLK
		  2- HSI_CLK
		  3- PLL_CLK 
*/
#define SET_CLOCK		HSE_CRYSTAL_CLK


/*option: 1- PLL_HSE_DIV_2	
		  2- PLL_HSI_DIV_2			
		  3- PLL_HSE
*/		
#define	PLL_INPUT		PLL_HSE_DIV_2
/*****The PLL output frequency must not exceed 72 MHz*****/
/* option for PLL multiplication factor:
		  1-  PLL_MUL_2		2-  PLL_MUL_3
		  3-  PLL_MUL_4		4-  PLL_MUL_5
		  5-  PLL_MUL_6		6-  PLL_MUL_7
		  7-  PLL_MUL_8		8-  PLL_MUL_9
		  9-  PLL_MUL_10	10- PLL_MUL_11
		  11- PLL_MUL_12	12- PLL_MUL_13
		  13- PLL_MUL_14	14- PLL_MUL_15
		  15- PLL_MUL_16	16- PLL_MUL_16
		  
*/
#define PLL_MUL_FACTOR		PLL_MUL_2


/*option for Clock security system:
		1- CLK_SECURITY_ON
		2- CLK_SECURITY_OFF
*/

#define CLK_SECURITY_SYSTEM		CLK_SECURITY_OFF



#endif
