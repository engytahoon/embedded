/********************************/
/* Author  :Engy				*/
/*version:  V02					*/
/*Date :18 AUG 2020				*/
/********************************/


#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

typedef struct
{
	volatile u32 GPIO_CRL ;
    volatile u32 GPIO_CRH ;
    volatile u32 GPIO_IDR ;
    volatile u32 GPIO_ODR ;
    volatile u32 GPIO_BSRR;
    volatile u32 GPIO_BRR ;
    volatile u32 GPIO_LCKR;
  
}GPIO_t;

#define GPIOA	((volatile GPIO_t *)0x40010800)
#define GPIOB	((volatile GPIO_t *)0x40010C00)
#define GPIOC	((volatile GPIO_t *)0x40011000)


#endif
