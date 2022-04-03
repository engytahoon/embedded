
#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

/*************************************** EXTI Registers **********************************/
#define GICR          *((volatile u8*)0x5B)
#define GIFR          *((volatile u8*)0x5A)
#define MCUCR         *((volatile u8*)0x55)
#define MCUCSR        *((volatile u8*)0x54)
#define SREG          *((volatile u8*)0X5F)

#endif /* EXTI_PRIVATE_H_ */
