
#ifndef _BIT_MATH_H_ 
#define _BIT_MATH_H_


#define SET_BIT(var,BIT_NO) var|=(1<<BIT_NO)
#define CLR_BIT(var,BIT_NO) var&=~(1<<BIT_NO)
#define TOG_BIT(var,BIT_NO) var^=(1<<BIT_NO)
#define GET_BIT(var,BIT_NO) ((var>>BIT_NO)&1)
#define ASSIGN_BIT(var,BIT_NO,value) var=((var&(~(1<<BIT_NO)))|(val<<BIT_NO)

#endif
