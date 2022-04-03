
#include "STD_types.h"
#include "BIT_MATH.h"
#include "ERROR_STATUS.h"
#include<util/delay.h>

#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "TIM_REG.h"
#include "TIM_int.h"
#include "Timer0_confg.h"
/***********************TIM_2*****************/
#include "TIM2_REG.h"
#include "Tim2_confg.h"
#include "TIM2_int.h"

#include "lcd_inter.h"
#include "keybad_inter.h"
#include "motor.h"

#include "SW_Timer.h"

#include "header.h"
#include "serves.h"

/* LCD ---> portA for data , PIN0,1,4 (PortB) ---> for control */
/* KEYPAD ---> PortC */
/* Switch Door --->pin2 (portD), switch stop --> pin3(portD) */ /* interrupt*/
/* switch weight ---> pin1(portD) */
/* heater ---> pin3(portB), buzzer ---> pin7(portD) */			/* timer */
/* motor ---> pin5,6 (portB), led---> pin7(portB) */

int main(void)
{
	/* init for function */
	Init_Funs();
	while(1)
	{
		Microwave_Reg();
	}

	return 0;
}

