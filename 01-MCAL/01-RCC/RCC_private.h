/********************************/
/* Author  :Engy Tahoon			*/
/*version:  V02					*/
/*Date :18 Aug 2020				*/
/********************************/


#ifndef RCC_PRIATE_H
#define RCC_PRIATE_H

/*Buses*/
#define AHB					0
#define APB2				1
#define APB1				2
#define RCC_U8_REG_SIZE 	32


/*Types of clocks*/
#define HSE_CRYSTAL_CLK		1
#define HSE_RC_CLK			2
#define HSI_CLK				3	
#define PLL_CLK				4

/*PLL Input*/
#define PLL_HSE_DIV_2		0
#define PLL_HSI_DIV_2		1
#define PLL_HSE				2

/*PLL multiplication factor*/
#define PLL_MUL_2			1
#define PLL_MUL_3			2
#define PLL_MUL_4			3
#define PLL_MUL_5			4
#define PLL_MUL_6			5
#define PLL_MUL_7			6
#define PLL_MUL_8			7
#define PLL_MUL_9			8
#define PLL_MUL_10			9
#define PLL_MUL_11			10
#define PLL_MUL_12			11	
#define PLL_MUL_13			12
#define PLL_MUL_14			13
#define PLL_MUL_15			14
#define PLL_MUL_16			15
 
/*Clock security system*/
#define CLK_SECURITY_ON		0
#define CLK_SECURITY_OFF	1

 
 
 
 
 
 
 
 #endif