
#include "STD_types.h"
#include "BIT_MATH.h"
#include "ERROR_STATUS.h"
#include "DELAY.h"
//MCAL>> DIO driver
#include"DIO_register.h"
#include"DIO_interface.h"
//MCAL>>TIMER driver
#include "TIM_REG.h"
#include "Timer0_confg.h"
#include "TIM_int.h"


volatile void((*pf)(void));

//initialization  include mode&prescaler&o/p compare enabled or not
void Timer0_Init( Timer0Mode_type mode,Timer0Scaler_type scaler ,OC0Mode_type oc_mode)
{
	switch (mode)
	{
		case TIMER0_NORMAL_MODE:
			CLR_BIT(TCCR0,WGM00);
			CLR_BIT(TCCR0,WGM01);
		break;
		case TIMER0_PHASECORRECT_MODE:
		SET_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
		break;
		case TIMER0_CTC_MODE:
			CLR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
		case TIMER0_FASTPWM_MODE:
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
	}
//1st 3bits determines the prescaller
	TCCR0&=0XF8;
	TCCR0|=scaler;

	switch (oc_mode)
		{
			case OCO_DISCONNECTED://normal mode
				CLR_BIT(TCCR0,COM00);
				CLR_BIT(TCCR0,COM01);
			break;
			//in this case i get pwm with const duty cycle and (variable frequency>>depending on oco value)
			case OCO_TOGGLE://ctc mode
			SET_BIT(TCCR0,COM00);
			CLR_BIT(TCCR0,COM01);
			break;
			case OCO_NON_INVERTING://ctc mode
				CLR_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
			break;
			case OCO_INVERTING://ctc mode
			SET_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
			break;
		}


	}
void Timer0_Disable(void)
{
//	CLR_BIT(TCCR0,CS02);
//	CLR_BIT(TCCR0,CS01);
//	CLR_BIT(TCCR0,CSOO);
	TCCR0 =0;
	TCNT0 = 0;
	CLR_BIT(TIMSK,OCIE0);
	CLR_BIT(TIMSK,TOIE0);


}
//Enable overflow interrupt in case of NORMAL MODE
void Timer0_OV_InterruptEnable(void)
{
	SET_BIT(TIMSK,TOIE0);
}
//Disable overflow interrupt in case of NORMAL MODE
void Timer0_OV_InterruptDisable(void)
{
	CLR_BIT(TIMSK,TOIE0);
}
//Enable output interrupt in case of NORMAL MODE
void Timer0_OC_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE0);
}
//Disable overflow interrupt in case of NORMAL MODE
void Timer0_OC_InterruptDisable(void)
{
	CLR_BIT(TIMSK,OCIE0);
}
void __vector_11() __attribute__((signal,used));//TIMER0 OVF
void __vector_11()
{
	pf();
}
void TIMER00_VCallback(void(*x)(void))
{
	pf=x;
}



