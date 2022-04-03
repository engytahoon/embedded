/********************************/
/* Author   : Engy Tahoon		*/
/* version  :  V02				*/
/* Date     : 5 Dec 2021 		*/
/********************************/

/**********************************
 * This Driver for STM32f10xxx
 ***********************************/

#ifndef GPIO_REG_H_
#define GPIO_REG_H_

typedef struct{

	volatile u32 CRL  ;
	volatile u32 CRH  ;
	volatile u32 IDR  ;
	volatile u32 ODR  ;
	volatile u32 BSRR ;
	volatile u32 BRR  ;
	volatile u32 LCKR ;

}GPIO;

#define MGPIOA ((volatile GPIO*)0x40010800)
#define MGPIOB ((volatile GPIO*)0x40010C00)
#define MGPIOC ((volatile GPIO*)0x40011000)

#endif /* GPIO_REG_H_ */
