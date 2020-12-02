/********************************/
/*Author :	Engy Tahoon 		*/
/*version:  V02					*/
/*Date 	 :	22 Aug 2020			*/
/********************************/



#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

/*
#define NVIC_ISER0	*((volatile u32*)0xE000E100)	//enable external interrupts from 0 -->32
#define NVIC_ISER1	*((volatile u32*)0xE000E104)	//enable external interrupts from 32 -->63

#define NVIC_ICER0	*((volatile u32*)0xE000E180)
#define NVIC_ICER1	*((volatile u32*)0xE000E184)

#define NVIC_ISPR0	*((volatile u32*)0xE000E200)
#define NVIC_ISPR1	*((volatile u32*)0xE000E204)

#define NVIC_ICPR0	*((volatile u32*)0xE000E280)
#define NVIC_ICPR1	*((volatile u32*)0xE000E284) 

#define NVIC_IABR0	*((volatile u32*)0xE000E300)
#define NVIC_IABR1  *((volatile u32*)0xE000E304)
#define SCB_AIRCR	*((volatile u32*)0xE000ED0C)  

#define NVIC_IPR	((u8*)0xE000E400) 		//byte  accessiablity
*/

typedef struct{
	volatile u32 NVIC_ISER[3] ;
	volatile u32 RESERVED0[29];
	volatile u32 NVIC_ICER[3] ;
	volatile u32 RESERVED1[29];
	volatile u32 NVIC_ISPR[3] ;
	volatile u32 RESERVED2[29];
	volatile u32 NVIC_ICPR[3] ;
	volatile u32 RESERVED3[29];
	volatile u32 NVIC_IABR[3] ;
	volatile u32 RESERVED4[61];
	volatile u8  NVIC_IPR[80] ;
}NVIC_t;

#define NVIC	((volatile NVIC_t*)0xE000E100)

/*App. interrupt and reset control register */
#define SCB_AIRCR	*((volatile u32*)0xE000ED0C)  


/*we must write 0x05FA to VectorKey in the SCB_AIRCR to write on the register*/
#define NVIC_GROUP_4_SUB_0		0x05FA0300	
#define NVIC_GROUP_3_SUB_1		0x05FA0400
#define NVIC_GROUP_2_SUB_2		0x05FA0500
#define NVIC_GROUP_1_SUB_3		0x05FA0600
#define NVIC_GROUP_0_SUB_4		0x05FA0700




#endif 