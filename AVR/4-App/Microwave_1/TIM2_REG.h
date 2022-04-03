
#ifndef TIM2_REG_H_
#define TIM2_REG_H_
#define TCCR2   *((volatile u8 *)0x45)
#define TCNT2   *((volatile u8 *)0x44)
#define OCR2    *((volatile u8 *)0x43)
#define TIMSK   *((volatile u8 *)0x59)
#define TIFR    *((volatile u8 *)0x58)
#define SREG    *((volatile u8*)0X5F)


#endif /* TIM_REG_H_ */
