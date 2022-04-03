
#include"STD_types.h"
#include"BIT_MATH.h"
#include"ERROR_STATUS.h"
#include"EXTI_interface.h"
#include"EXTI_Config.h"
#include"EXTI_private.h"
#define nul    0
volatile void ((*pf0)(void))= nul;
volatile void ((*pf1)(void))= nul;
volatile void ((*pf2)(void))= nul;

/************************************* EXTI0 ****************************************/
/******************Init Interrupt**************************/
ErrorStatus EXTI0_enumInit(void)
{
	ErrorStatus error=ES_NOK;
 #if 	SENSE_MODE  ==  LOW
        CLR_BIT(MCUCR,0);
        CLR_BIT(MCUCR,1);
 #elif 	SENSE_MODE  ==  LOGIC_CHANGE
        SET_BIT(MCUCR,0);
        CLR_BIT(MCUCR,1);
 #elif 	SENSE_MODE  ==  FALLING
        CLR_BIT(MCUCR,0);
        SET_BIT(MCUCR,1);
 #elif 	SENSE_MODE  ==  RISING
        SET_BIT(MCUCR,0);
        SET_BIT(MCUCR,1);

#endif
        //ENABLE GIF
        	SET_BIT(SREG,7);
 return error;
}

/******************Enable Interrupt**************************/

ErrorStatus EXTI0_enumEnable (void)
{
	ErrorStatus error=ES_NOK;
	SET_BIT(GICR,6);
	return error;
}

/******************Disable Interrupt**************************/

ErrorStatus EXTI0_enumDisable (void)
{
	ErrorStatus error=ES_NOK;
	CLR_BIT(GICR,6);
	return error;
}


void __vector_1()__attribute__((signal,used));
void __vector_1()
{
	pf0();
}
void EXTI0_enumSetCallBack (void(*x)(void))
{
	pf0=x;
}

/********************************************** EXTI1 ****************************************/

ErrorStatus EXTI1_enumInit(void)
{
	ErrorStatus error=ES_NOK;
 #if 	SENSE_MODE1  ==  LOW
        CLR_BIT(MCUCR,2);
        CLR_BIT(MCUCR,3);
 #elif 	SENSE_MODE1  ==  LOGIC_CHANGE
        SET_BIT(MCUCR,2);
        CLR_BIT(MCUCR,3);
 #elif 	SENSE_MODE1  ==  FALLING
        CLR_BIT(MCUCR,2);
        SET_BIT(MCUCR,3);
 #elif 	SENSE_MODE1  ==  RISING
        SET_BIT(MCUCR,2);
        SET_BIT(MCUCR,3);
// #else
  //   #error "Wrong sense mode"
#endif
 error=ES_OK;
 //ENABLE GIF
 	SET_BIT(SREG,7);
 return error;
}
ErrorStatus EXTI1_enumEnable (void)
{
	ErrorStatus error=ES_NOK;
	SET_BIT(GICR,7);
	return error;
}
ErrorStatus EXTI1_enumDisable (void)
{
	ErrorStatus error=ES_NOK;
	CLR_BIT(GICR,7);
	return error;
}
void EXTI1_enumSetCallBack (void(*x)(void))
{
	pf1=x;
}

void __vector_2()__attribute__((signal,used));
void __vector_2()
{
	pf1();
}

/********************************************** EXTI2 ****************************************/

ErrorStatus EXTI2_enumInit(void)
{
	ErrorStatus error=ES_NOK;
 #if 	SENSE_MODE2  == FALLING
        CLR_BIT(MCUCSR,6);

 #elif 	SENSE_MODE2  ==  RISING
        SET_BIT(MCUCSR,6);
#endif
 error=ES_OK;
 //ENABLE GIF
 	SET_BIT(SREG,7);
 return error;
}
ErrorStatus EXTI2_enumEnable (void)
{
	ErrorStatus error=ES_NOK;
	SET_BIT(GICR,5);
	return error;
}
ErrorStatus EXTI2_enumDisable (void)
{
	ErrorStatus error=ES_NOK;
	CLR_BIT(GICR,5);
	return error;
}
void EXTI2_enumSetCallBack (void(*x)(void))
{
	pf2=x;
}

void __vector_3()__attribute__((signal,used));
void __vector_3()
{
	pf2();
}
