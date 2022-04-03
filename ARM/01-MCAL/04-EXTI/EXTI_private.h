/********************************/
/*Author :  Engy Tahoon 		*/
/*version:  V02					*/
/*Date 	 :	22 Aug 2020			*/
/********************************/

#ifndef	EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

typedef struct{
	volatile u32 EXTI_IMR;
	volatile u32 EXTI_EMR;
	volatile u32 EXTI_RTSR;
	volatile u32 EXTI_FTSR;
	volatile u32 EXTI_SWIER;
	volatile u32 EXTI_PR;

}EXTI_t;

#define EXTI	((volatile EXTI_t *)0x40010400)

#define LINE0		0
#define LINE1		1
#define LINE2		2
#define LINE3		3
#define LINE4		4
#define LINE5		5
#define LINE6		6
#define LINE7		7
#define LINE8		8
#define LINE9		9
#define LINE10		10
#define LINE11		11
#define LINE12		12
#define LINE13		13
#define LINE14		14
#define LINE15		15


#define RISING		0
#define FALLING		1
#define ON_CHANGE	2



#endif