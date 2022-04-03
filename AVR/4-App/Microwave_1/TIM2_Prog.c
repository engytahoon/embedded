
#include <util/delay.h>
#include "STD_types.h"
#include "BIT_MATH.h"
#include "ERROR_STATUS.h"
/***********************DIO*******************/
#include "DIO_register.h"
#include "DIO_interface.h"
//MCAL>>TIMER driver
#include "TIM2_REG.h"
#include "Tim2_confg.h"
#include "TIM2_int.h"


volatile void((*pf)(void));

//initialization  include mode&prescaler&o/p compare enabled or not
void Timer2_Init( Timer2Mode_type mode,Timer2Scaler_type scaler ,OC2Mode_type oc_mode)
{
	switch (mode)
	{
		case TIMER2_NORMAL_MODE:
		CLR_BIT(TCCR2,WGM20);
		CLR_BIT(TCCR2,WGM21);
		break;
		case TIMER2_PHASECORRECT_MODE:
		SET_BIT(TCCR2,WGM20);
		CLR_BIT(TCCR2,WGM21);
		break;
		case TIMER2_CTC_MODE:
		CLR_BIT(TCCR2,WGM20);
		SET_BIT(TCCR2,WGM21);
		break;
		case TIMER2_FASTPWM_MODE:
		SET_BIT(TCCR2,WGM20);
		SET_BIT(TCCR2,WGM21);
		break;
	}
//1st 3bits determines the prescaller
	TCCR2&=0XF8;
	TCCR2|=scaler;

	switch (oc_mode)
		{
			case OC2_DISCONNECTED://normal mode
			CLR_BIT(TCCR2,COM20);
			CLR_BIT(TCCR2,COM21);
			break;
			//in this case i get pwm with const duty cycle and (variable frequency>>depending on oco value)
			case OC2_TOGGLE://ctc mode
			SET_BIT(TCCR2,COM20);
			CLR_BIT(TCCR2,COM21);
			break;
			case OC2_NON_INVERTING://ctc mode
			CLR_BIT(TCCR2,COM20);
			SET_BIT(TCCR2,COM21);
			break;
			case OC2_INVERTING://ctc mode
			SET_BIT(TCCR2,COM20);
			SET_BIT(TCCR2,COM21);
			break;
		}


	}
void Timer2_Disable(void)
{
	TCCR2 = 0;
	TCNT2 =0;
	CLR_BIT(TIMSK, TOIE2);
	CLR_BIT(TIMSK,OCIE2);
}
//Enable overflow interrupt in case of NORMAL MODE
void Timer2_OV_InterruptEnable(void)
{
	SET_BIT(TIMSK,TOIE2);
}
//Disable overflow interrupt in case of NORMAL MODE
void Timer2_OV_InterruptDisable(void)
{
	CLR_BIT(TIMSK,TOIE2);
}
//Enable output interrupt in case of NORMAL MODE
void Timer2_OC_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE2);
}
//Disable overflow interrupt in case of NORMAL MODE
void Timer2_OC_InterruptDisable(void)
{
	CLR_BIT(TIMSK,OCIE2);
}
void __vector_4() __attribute__((signal,used));//TIMER0 OVF
void __vector_4()
{
	pf();
}
void TIMER02_VCallback(void(*x)(void))
{
	pf=x;
}



